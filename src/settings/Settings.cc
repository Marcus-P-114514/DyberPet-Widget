#include "Settings.h"

class GlobalVariable;
//StatusMonitor* StatusMonitorSettings = new StatusMonitor;

void DyberPetSettings::InitPet() {
	//��Ҫ����Conf�е�PetData()��������һ���ֻ�ûд��
	DyberPetSettings::InitSettings();
	DyberPetSettings::SaveSettings();
}

void DyberPetSettings::InitSettings() {
	//�������
	if (QFile(GlobalVariable::ConfigPath).exists()) {
		//StatusMonitorSettings->InsertLog("INFO", "Config has been created, skiping generating config...");
		QSettings* ReadConfig = new QSettings(GlobalVariable::ConfigPath, QSettings::IniFormat);

		if (ReadConfig->value("HDPI/OverrideHDPI").toString() == "On") {
			GlobalVariable::OverideHDPI = 1;
		}	//OverrideHDPIΪOnʱ������Override
		else {
			GlobalVariable::OverideHDPI = 0;
		}	//OverrideHDPIΪOff��������ֵʱ����ֹOverride

		if (ReadConfig->value("HDPI/EnableHDPIScale").toString() == "Off") {
			GlobalVariable::EnableHDPIScale = 0;
		}	//EnableHDPIScaleΪOffʱ���ر�HDPI֧��
		else {
			GlobalVariable::EnableHDPIScale = 1;
		}	//EnableHDPIScaleΪOn��������ֵʱ������HDPI֧��

		GlobalVariable::CustomScaleFactor = ReadConfig->value("HDPI/CustomScale").toString();

		if (ReadConfig->value("StatusMonitor/ShowLogWindow").toString() == "Enabled") {
			GlobalVariable::ShowLogWindow = 1;
		}	//ShowLogWindowΪEnabledʱ��������־����
		else {
			GlobalVariable::ShowLogWindow = 0;
		}	//ShowLogWindowΪDisabled��������ֵʱ���ر���־����

		if (ReadConfig->value("StatusMonitor/ToggleLogWindow").toString() == "Enabled") {
			GlobalVariable::ToggleLogWindow = 1;
		}	//ToggleLogWindowΪEnabledʱ�������л���־����
		else {
			GlobalVariable::ToggleLogWindow = 0;
		}	//ToggleLogWindowΪDisabled��������ֵʱ����ֹ�л���־����

		GlobalVariable::LogLevel = ReadConfig->value("StatusMonitor/LogLevel").toString();

		GlobalVariable::GravityRead = ReadConfig->value("DyberPet/Gravity").toString();
		GlobalVariable::FixDragSpeedXRead = ReadConfig->value("DyberPet/FixDragSpeedX").toString();
		GlobalVariable::FixDragSpeedYRead = ReadConfig->value("DyberPet/FixDragSpeedY").toString();
		GlobalVariable::TunableScaleRead = ReadConfig->value("DyberPet/TunableScale").toString();
		GlobalVariable::VolumeRead = ReadConfig->value("DyberPet/Volume").toString();
		GlobalVariable::OnTopHintRead = ReadConfig->value("DyberPet/OnTopHint").toString();
		GlobalVariable::DefaultPetRead = ReadConfig->value("DyberPet/DefaultPet").toString();
		GlobalVariable::DefaultActRead = ReadConfig->value("DyberPet/DefaultAct").toString();
		GlobalVariable::LanguageCodeRead = ReadConfig->value("DyberPet/LanguageCode").toString();

		delete ReadConfig;
	} //���ô���
	else {
		//StatusMonitorSettings->InsertLog("WARN", "Config not found, generating new config file...");
		DyberPetSettings::SaveSettings();
		//StatusMonitorSettings->InsertLog("INFO", "Config has been created.");
	}   //���ò�����
}

void DyberPetSettings::SaveSettings() {
	QSettings* CreateConfig = new QSettings(GlobalVariable::ConfigPath, QSettings::IniFormat);

	if (GlobalVariable::OverideHDPI == 1) {
		CreateConfig->setValue("HDPI/OverrideHDPI", "On");
	}	//��OverrideHDPIΪ1ʱ������Override
	else {
		CreateConfig->setValue("HDPI/OverrideHDPI", "Off");
	}	//��OverrideHDPIΪ0ʱ����ֹOverride
	
	if (GlobalVariable::EnableHDPIScale == 1) {
		CreateConfig->setValue("HDPI/EnableHDPIScale", "On");
	}	//EnableHDPIScaleΪ1ʱ������HDPI֧��
	else {
		CreateConfig->setValue("HDPI/EnableHDPIScale", "Off");
	}	//EnableHDPIScaleΪ0ʱ���ر�HDPI֧��

	CreateConfig->setValue("HDPI/CustomScale", "1.00");

	if (GlobalVariable::ShowLogWindow == 1) {
		CreateConfig->setValue("StatusMonitor/ShowLogWindow", "Enabled");
	}	//ShowLogWindowΪ1ʱ��������־����
	else {
		CreateConfig->setValue("StatusMonitor/ShowLogWindow", "Disabled");
	}	//ShowLogWindowΪ0ʱ���ر���־����

	if (GlobalVariable::ToggleLogWindow == 1) {
		CreateConfig->setValue("StatusMonitor/ToggleLogWindow", "Enabled");
	}	//ToggleLogWindowΪ1ʱ�������л���־����
	else {
		CreateConfig->setValue("StatusMonitor/ToggleLogWindow", "Disabled");
	}	//ToggleLogWindowΪ0ʱ����ֹ�л���־����
	
	CreateConfig->setValue("StatusMonitor/LogLevel", "Info");

	CreateConfig->setValue("DyberPet/Gravity", GlobalVariable::GravityRead);
	CreateConfig->setValue("DyberPet/FixDragSpeedX", GlobalVariable::FixDragSpeedXRead);
	CreateConfig->setValue("DyberPet/FixDragSpeedY", GlobalVariable::FixDragSpeedYRead);
	CreateConfig->setValue("DyberPet/TunableScale", GlobalVariable::TunableScaleRead);
	CreateConfig->setValue("DyberPet/Volume", GlobalVariable::VolumeRead);
	CreateConfig->setValue("DyberPet/OnTopHint", GlobalVariable::OnTopHintRead);
	CreateConfig->setValue("DyberPet/DefaultPet", GlobalVariable::DefaultPetRead);
	CreateConfig->setValue("DyberPet/defaultAct", GlobalVariable::DefaultActRead);
	CreateConfig->setValue("DyberPet/LanguageCode", GlobalVariable::LanguageCodeRead);

	delete CreateConfig;
}

void DyberPetSettings::GetPetList(QString DirName) {
	//������ȡ�����б�
	QDir TargetDir(DirName);
	Folders = TargetDir.entryList(QDir::Dirs);
	Folders.removeOne("sys");
	Folders.removeOne(".");
	Folders.removeOne("..");

	//��ȡ�������б�
	for (int i = 0; i < (TargetDir.entryList().size() - 4); i++) {
		//��pet_conf.json
		QString PetConfPath = DirName + "/" + Folders[i] + "/pet_conf.json";
		QFile SubPetJson(PetConfPath);
		SubPetJson.open(QIODevice::ReadOnly);
		QByteArray SubPetJsonContent = SubPetJson.readAll();
		QJsonDocument SubPetJsonDocument = QJsonDocument::fromJson(SubPetJsonContent);
		QJsonObject CurrentObject = SubPetJsonDocument.object();

		//��ȡsubpet
		if (CurrentObject.contains("subpet")) {
			//ת��subpet���������ݵ�QJsonObject
			QJsonValue SubPetVal = CurrentObject.value("subpet");
			QJsonObject SubPetObj = SubPetVal.toObject();

			//������ȡ�������б����ظ��
			QStringList SubPetTemp;
			SubPetTemp.append(SubPetObj.keys());

			//ȥ���ظ�������������б�
			for (int a = 0; a < SubPetTemp.length(); a++) {
				if (SubPet.contains(SubPetTemp[a])) {
					qDebug() << "Ignored repeated value.";
				}
				else {
					SubPet.append(SubPetTemp[a]);
				}
			}
			
		}	//���pet_conf.json�к���subpet

		//�ر��ĵ�
		SubPetJson.close();
	}

	//�������б���ȥ��������
	for (int RemoveSubPet = 0; RemoveSubPet < SubPet.length(); RemoveSubPet++) {
		Folders.removeOne(SubPet[RemoveSubPet]);
	}
}