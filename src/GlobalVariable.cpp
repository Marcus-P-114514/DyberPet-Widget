#include "GlobalVariable.h"

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