#include "Settings.h"

class GlobalVariable;
//StatusMonitor* StatusMonitorSettings = new StatusMonitor;

void DyberPetSettings::InitSettings() {
	//检查配置
	if (QFile(GlobalVariable::ConfigPath).exists()) {
		//StatusMonitorSettings->InsertLog("INFO", "Config has been created, skiping generating config...");
		QSettings* ReadConfig = new QSettings(GlobalVariable::ConfigPath, QSettings::IniFormat);

		if (ReadConfig->value("HDPI/OverrideHDPI").toString() == "On") {
			GlobalVariable::OverideHDPI = 1;
		}	//OverrideHDPI为On时，允许Override
		else {
			GlobalVariable::OverideHDPI = 0;
		}	//OverrideHDPI为Off或者其他值时，禁止Override

		if (ReadConfig->value("HDPI/EnableHDPIScale").toString() == "Off") {
			GlobalVariable::EnableHDPIScale = 0;
		}	//EnableHDPIScale为Off时，关闭HDPI支持
		else {
			GlobalVariable::EnableHDPIScale = 1;
		}	//EnableHDPIScale为On或者其他值时，开启HDPI支持

		GlobalVariable::CustomScaleFactor = ReadConfig->value("HDPI/CustomScale").toString();

		if (ReadConfig->value("StatusMonitor/ShowLogWindow").toString() == "Enabled") {
			GlobalVariable::ShowLogWindow = 1;
		}	//ShowLogWindow为Enabled时，开启日志窗口
		else {
			GlobalVariable::ShowLogWindow = 0;
		}	//ShowLogWindow为Disabled或者其他值时，关闭日志窗口

		if (ReadConfig->value("StatusMonitor/ToggleLogWindow").toString() == "Enabled") {
			GlobalVariable::ToggleLogWindow = 1;
		}	//ToggleLogWindow为Enabled时，允许切换日志窗口
		else {
			GlobalVariable::ToggleLogWindow = 0;
		}	//ToggleLogWindow为Disabled或者其他值时，禁止切换日志窗口

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
	} //配置存在
	else {
		//StatusMonitorSettings->InsertLog("WARN", "Config not found, generating new config file...");
		DyberPetSettings::SaveSettings();
		//StatusMonitorSettings->InsertLog("INFO", "Config has been created.");
	}   //配置不存在
}

void DyberPetSettings::SaveSettings() {
	QSettings* CreateConfig = new QSettings(GlobalVariable::ConfigPath, QSettings::IniFormat);

	if (GlobalVariable::OverideHDPI == 1) {
		CreateConfig->setValue("HDPI/OverrideHDPI", "On");
	}	//当OverrideHDPI为1时，允许Override
	else {
		CreateConfig->setValue("HDPI/OverrideHDPI", "Off");
	}	//当OverrideHDPI为0时，禁止Override
	
	if (GlobalVariable::EnableHDPIScale == 1) {
		CreateConfig->setValue("HDPI/EnableHDPIScale", "On");
	}	//EnableHDPIScale为1时，开启HDPI支持
	else {
		CreateConfig->setValue("HDPI/EnableHDPIScale", "Off");
	}	//EnableHDPIScale为0时，关闭HDPI支持

	CreateConfig->setValue("HDPI/CustomScale", "1.00");

	if (GlobalVariable::ShowLogWindow == 1) {
		CreateConfig->setValue("StatusMonitor/ShowLogWindow", "Enabled");
	}	//ShowLogWindow为1时，开启日志窗口
	else {
		CreateConfig->setValue("StatusMonitor/ShowLogWindow", "Disabled");
	}	//ShowLogWindow为0时，关闭日志窗口

	if (GlobalVariable::ToggleLogWindow == 1) {
		CreateConfig->setValue("StatusMonitor/ToggleLogWindow", "Enabled");
	}	//ToggleLogWindow为1时，允许切换日志窗口
	else {
		CreateConfig->setValue("StatusMonitor/ToggleLogWindow", "Disabled");
	}	//ToggleLogWindow为0时，禁止切换日志窗口
	
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
	//初步获取桌宠列表
	QDir TargetDir(DirName);
	Folders = TargetDir.entryList(QDir::Dirs);
	Folders.removeOne("sys");
	Folders.removeOne(".");
	Folders.removeOne("..");

	//获取子桌宠列表
	for (int i = 0; i < (TargetDir.entryList().size() - 4); i++) {
		//打开pet_conf.json
		QString PetConfPath = DirName + "/" + Folders[i] + "/pet_conf.json";
		QFile SubPetJson(PetConfPath);
		SubPetJson.open(QIODevice::ReadOnly);
		QByteArray SubPetJsonContent = SubPetJson.readAll();
		QJsonDocument SubPetJsonDocument = QJsonDocument::fromJson(SubPetJsonContent);
		QJsonObject CurrentObject = SubPetJsonDocument.object();

		//读取subpet
		if (CurrentObject.contains("subpet")) {
			//转换subpet中所有内容到QJsonObject
			QJsonValue SubPetVal = CurrentObject.value("subpet");
			QJsonObject SubPetObj = SubPetVal.toObject();

			//初步获取子桌宠列表（含重复项）
			QStringList SubPetTemp;
			SubPetTemp.append(SubPetObj.keys());

			//去除重复项并导出子桌宠列表
			for (int a = 0; a < SubPetTemp.length(); a++) {
				if (SubPet.contains(SubPetTemp[a])) {
					qDebug() << "Ignored repeated value.";
				}
				else {
					SubPet.append(SubPetTemp[a]);
				}
			}
			
		}	//如果pet_conf.json中含有subpet

		//关闭文档
		SubPetJson.close();
	}

	//在桌宠列表中去除子桌宠
	for (int RemoveSubPet = 0; RemoveSubPet < SubPet.length(); RemoveSubPet++) {
		Folders.removeOne(SubPet[RemoveSubPet]);
	}
}