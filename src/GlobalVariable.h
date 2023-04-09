#pragma once
#include "QApplication"
#include "QString"
#include "QSettings"
#include "QStandardPaths"

class GlobalVariable
{
    public:
        //这些是全局变量
        static QString CurrentPlatform;
        static QString BaseDir;
        static QString ConfigPath;
        static bool override_hdpi;
        static QString DyberPetVersion;
        static QString DyberPetWidgetVersion;
};