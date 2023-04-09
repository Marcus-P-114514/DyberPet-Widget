#pragma once
#include "QApplication"
#include "QString"
#include "QSettings"

//这些是全局变量
extern QString current_platform;
extern bool override_hdpi;

//GlobalVariable.cpp会为一些全局变量赋值，下面的变量会告诉GlobalVariable.cpp当前系统
#ifdef Q_OS_WIN
QString current_system = "windows";
#endif //Win32平台

class GlobalVariable
{
    public:
        void init_variable();
};