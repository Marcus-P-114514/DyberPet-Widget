#pragma once
#include "QApplication"
#include "QString"
#include "QSettings"

class GlobalVariable
{
    public:
        //��Щ��ȫ�ֱ���
        static QString CurrentPlatform;
        static bool override_hdpi;
};