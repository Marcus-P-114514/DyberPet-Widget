#pragma once
#include "QApplication"
#include "QString"
#include "QSettings"
#include "QStandardPaths"

class GlobalVariable
{
    public:
        //��Щ��ȫ�ֱ���
        static QString CurrentPlatform;
        static QString BaseDir;
        static QString ConfigPath;
        static bool OverideHDPI;
        static QString DyberPetVersion;
        static QString DyberPetWidgetVersion;
        static QString ShowLogWindow;
        static QString ToggleLogWindow;
        static QString LogLevel;
};