#pragma once
#include "QApplication"
#include "QString"
#include "QSettings"

//��Щ��ȫ�ֱ���
extern QString current_platform;
extern bool override_hdpi;

//GlobalVariable.cpp��ΪһЩȫ�ֱ�����ֵ������ı��������GlobalVariable.cpp��ǰϵͳ
#ifdef Q_OS_WIN
QString current_system = "windows";
#endif //Win32ƽ̨

class GlobalVariable
{
    public:
        void init_variable();
};