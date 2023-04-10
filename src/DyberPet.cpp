#include "DyberPet.h"
#include "extras/status_monitor/StatusMonitor.h"

DyberPet::DyberPet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DyberPetClass())
{
    ui->setupUi(this);

    //ʵ������־���
    StatusMonitor* StatusMonitorMain = new StatusMonitor;
    StatusMonitorMain->show();

    StatusMonitorMain->InsertLog("INFO", "DyberPet Version: " + GlobalVariable::DyberPetVersion);
    StatusMonitorMain->InsertLog("INFO", "DyberPet-Widget Version: " + GlobalVariable::DyberPetWidgetVersion);

    //�������
    if (QFile(GlobalVariable::ConfigPath).exists()) {
        StatusMonitorMain->InsertLog("INFO", "Config has been created, skiping generating config...");
    } //���ô���
    else {
        StatusMonitorMain->InsertLog("WARN", "Config not found, generating new config file...");
        DyberPet::CreateConfig();
    }   //���ò�����
}

DyberPet::~DyberPet()
{
    delete ui;
}

void DyberPet::CreateConfig()
{
    QJsonObject ConfigObject;
    QJsonArray HDPIConfigArray;
    QJsonObject HDPIConfigDetail;
    HDPIConfigDetail.insert("OverrideHDPI", "Off");
    HDPIConfigDetail.insert("EnableHDPI", "On");
    HDPIConfigDetail.insert("CustomHDPIScale", "1.00");
    HDPIConfigArray.append(QJsonValue(HDPIConfigDetail));
    ConfigObject.insert("HDPI", QJsonValue(HDPIConfigArray));

    QJsonDocument WriteConfig(ConfigObject);
    QByteArray ConfigContent = WriteConfig.toJson();
    QFile TargetConfigPath (GlobalVariable::ConfigPath);
    
    if (TargetConfigPath.open(QIODevice::WriteOnly))
    {
        TargetConfigPath.write(ConfigContent);
        TargetConfigPath.close();
        }
        else
        {
            qDebug() << "write error!" << endl;
        }
}