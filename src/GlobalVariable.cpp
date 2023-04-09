#include "GlobalVariable.h"

//这些变量根据不同的系统而变化
#ifdef Q_OS_WIN
QString GlobalVariable::CurrentPlatform = "Windows";
QString GlobalVariable::BaseDir = "./";
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "config/config.json";
#endif // Win32

#ifdef Q_OS_MACOS
QString GlobalVariable::CurrentPlatform = "macOS";
QString GlobalVariable::BaseDir = QString DataDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "/config/config.json";
#endif // macOS

#ifdef Q_OS_LINUX
QString GlobalVariable::CurrentPlatform = "Linux";
QString GlobalVariable::BaseDir = QString DataDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "/config/config.json";
# endif // Linux

#ifdef Q_OS_ANDROID
QString GlobalVariable::CurrentPlatform = "Android";
QString GlobalVariable::BaseDir = QString DataDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "/config/config.json";
#endif // Android

#ifdef Q_OS_IOS
QString GlobalVariable::CurrentPlatform = "iOS";
QString GlobalVariable::BaseDir = QString DataDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
QString GlobalVariable::ConfigPath = GlobalVariable::BaseDir + "/config/config.json";
#endif // iOS

//这些变量与运行的操作系统无关
QString GlobalVariable::DyberPetVersion = "v.0.2.2";
QString GlobalVariable::DyberPetWidgetVersion = "v.0.0.1";