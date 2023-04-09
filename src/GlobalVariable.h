#pragma once
#include "QApplication"
#include "QString"
#include "QSettings"

class GlobalVariable
{
    public:
        //这些是全局变量
        static QString CurrentPlatform;
        static bool override_hdpi;
};