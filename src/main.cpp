#include "DyberPet.h"
#include <QtWidgets/QApplication>
#include <QSettings>
#include "GlobalVariable.h"

class GlobalVariable;

int main(int argc, char *argv[])
{
    QSettings* ReadConfig = new QSettings(GlobalVariable::ConfigPath, QSettings::IniFormat);
    QString OverrideHDPIRead = ReadConfig->value("HDPI/OverrideHDPI").toString();
    QString EnableHDPIScaleRead = ReadConfig->value("HDPI/EnableHDPIScale").toString();
    QString CustomHDPIScaleRead = ReadConfig->value("HDPI/CustomScale").toString();
    delete ReadConfig;

    if (EnableHDPIScaleRead == "On") {
        if (OverrideHDPIRead == "On") {
            if (CustomHDPIScaleRead == "1.00") {
                qputenv("QT_SCALE_FACTOR", "1.0");
            }   //����1x

            else if (CustomHDPIScaleRead == "1.25") {
                qputenv("QT_SCALE_FACTOR", "1.25");
            }   //����1.25x

            else if (CustomHDPIScaleRead == "1.50") {
                qputenv("QT_SCALE_FACTOR", "1.5");
            }   //����1.50x

            else if (CustomHDPIScaleRead == "1.75") {
                qputenv("QT_SCALE_FACTOR", "1.75");
            }   //����1.75x

            else if (CustomHDPIScaleRead == "2.00") {
                qputenv("QT_SCALE_FACTOR", "2.0");
            }   //����2x

            else if (CustomHDPIScaleRead == "2.25") {
                qputenv("QT_SCALE_FACTOR", "2.25");
            }   //����2.25x

            else if (CustomHDPIScaleRead == "2.50") {
                qputenv("QT_SCALE_FACTOR", "2.5");
            }   //����2.50x

            else if (CustomHDPIScaleRead == "2.75") {
                qputenv("QT_SCALE_FACTOR", "2.75");
            }   //����2.75x

            else if (CustomHDPIScaleRead == "3.00") {
                qputenv("QT_SCALE_FACTOR", "3.0");
            }   //����3x

            else {
                qputenv("QT_SCALE_FACTOR", "1.0");
            }   //Fallback������1x

        }   //����HDPI֧��
        else {
            QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        }
    }   //����HDI֧��
    else {
        QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    }   //������HDPI֧��

    QApplication a(argc, argv);
    DyberPet w;
    w.show();
    return a.exec();
}
