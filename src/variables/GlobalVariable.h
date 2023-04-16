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
        static bool OverideHDPI;
        static QString DyberPetVersion;
        static QString DyberPetWidgetVersion;
        static QString ShowLogWindow;
        static QString ToggleLogWindow;
        static QString LogLevel;
        static QString GravityRead;
        static QString FixDragSpeedXRead;
        static QString FixDragSpeedYRead;
        static QString TunableScaleRead;
        static QString VolumeRead;
        static QString OnTopHintRead;
        static QString DefaultPetRead;
        static QString defaultActRead;
        static QString LanguageCodeRead;
};