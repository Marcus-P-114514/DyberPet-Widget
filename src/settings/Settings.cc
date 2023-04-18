#include "Settings.h"

class GlobalVariable;

void DyberPetSettings::SaveSettings() {
	QSettings* CreateConfig = new QSettings(GlobalVariable::ConfigPath, QSettings::IniFormat);
	CreateConfig->setValue("HDPI/OverrideHDPI", "Off");
	CreateConfig->setValue("HDPI/EnableHDPIScale", "On");
	CreateConfig->setValue("HDPI/CustomScale", "1.00");

	CreateConfig->setValue("StatusMonitor/ShowLogWindow", "Disabled");
	CreateConfig->setValue("StatusMonitor/ToggleLogWindow", "Disabled");
	CreateConfig->setValue("StatusMonitor/LogLevel", "Info");

	CreateConfig->setValue("DyberPet/Gravity", GlobalVariable::GravityRead);
	CreateConfig->setValue("DyberPet/FixDragSpeedX", GlobalVariable::FixDragSpeedXRead);
	CreateConfig->setValue("DyberPet/FixDragSpeedY", GlobalVariable::FixDragSpeedYRead);
	CreateConfig->setValue("DyberPet/TunableScale", GlobalVariable::TunableScaleRead);
	CreateConfig->setValue("DyberPet/Volume", GlobalVariable::VolumeRead);
	CreateConfig->setValue("DyberPet/OnTopHint", GlobalVariable::OnTopHintRead);
	CreateConfig->setValue("DyberPet/DefaultPet", GlobalVariable::DefaultPetRead);
	CreateConfig->setValue("DyberPet/defaultAct", GlobalVariable::defaultActRead);
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