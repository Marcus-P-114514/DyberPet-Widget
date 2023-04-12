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
            }   //缩放1x

            else if (CustomHDPIScaleRead == "1.25") {
                qputenv("QT_SCALE_FACTOR", "1.25");
            }   //缩放1.25x

            else if (CustomHDPIScaleRead == "1.50") {
                qputenv("QT_SCALE_FACTOR", "1.5");
            }   //缩放1.50x

            else if (CustomHDPIScaleRead == "1.75") {
                qputenv("QT_SCALE_FACTOR", "1.75");
            }   //缩放1.75x

            else if (CustomHDPIScaleRead == "2.00") {
                qputenv("QT_SCALE_FACTOR", "2.0");
            }   //缩放2x

            else if (CustomHDPIScaleRead == "2.25") {
                qputenv("QT_SCALE_FACTOR", "2.25");
            }   //缩放2.25x

            else if (CustomHDPIScaleRead == "2.50") {
                qputenv("QT_SCALE_FACTOR", "2.5");
            }   //缩放2.50x

            else if (CustomHDPIScaleRead == "2.75") {
                qputenv("QT_SCALE_FACTOR", "2.75");
            }   //缩放2.75x

            else if (CustomHDPIScaleRead == "3.00") {
                qputenv("QT_SCALE_FACTOR", "3.0");
            }   //缩放3x

            else {
                qputenv("QT_SCALE_FACTOR", "1.0");
            }   //Fallback，缩放1x

        }   //覆盖HDPI支持
        else {
            QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        }
    }   //开启HDI支持
    else {
        QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    }   //不开启HDPI支持

    QApplication a(argc, argv);
    DyberPet w;
    //w.show();
    return a.exec();
}
