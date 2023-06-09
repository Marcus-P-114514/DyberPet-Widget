#include "GlobalVariable.h"

//这些变量根据不同的系统而变化
#ifdef Q_OS_WIN
QString GlobalVariable::CurrentPlatform = "Windows";
QString GlobalVariable::BaseDir = "./";
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "config/config.conf";
#endif // Win32

#ifdef Q_OS_MACOS
QString GlobalVariable::CurrentPlatform = "macOS";
QString GlobalVariable::BaseDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "/DyberPet/config/config.conf";
#endif // macOS

#ifdef Q_OS_LINUX
QString GlobalVariable::CurrentPlatform = "Linux";
QString GlobalVariable::BaseDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "/DyberPet/config/config.conf";
# endif // Linux

#ifdef Q_OS_ANDROID
QString GlobalVariable::CurrentPlatform = "Android";
QString GlobalVariable::BaseDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "/DyberPet/config/config.conf";
#endif // Android

#ifdef Q_OS_IOS
QString GlobalVariable::CurrentPlatform = "iOS";
QString GlobalVariable::BaseDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "/DyberPet/config/config.conf";
#endif // iOS

//这些变量与运行的操作系统无关
QString GlobalVariable::DyberPetVersion = "v.0.2.2";
QString GlobalVariable::DyberPetWidgetVersion = "v.0.0.1";

//这些是配置的默认值
bool GlobalVariable::OverideHDPI = 0;
bool GlobalVariable::EnableHDPIScale = 1;
QString GlobalVariable::CustomScaleFactor = "1.00";
bool GlobalVariable::ShowLogWindow = 0;
bool GlobalVariable::ToggleLogWindow = 0;
QString GlobalVariable::GravityRead = "0.1";
QString GlobalVariable::FixDragSpeedXRead = "1.0";
QString GlobalVariable::FixDragSpeedYRead = "1.0";
QString GlobalVariable::TunableScaleRead = "1.0";
QString GlobalVariable::VolumeRead = "0.4";
QString GlobalVariable::OnTopHintRead = "Enabled";
QString GlobalVariable::DefaultPetRead = "";
QString GlobalVariable::DefaultActRead = "";
QString GlobalVariable::LanguageCodeRead = "CN";