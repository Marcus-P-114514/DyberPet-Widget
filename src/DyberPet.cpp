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
    QSettings* CreateConfig = new QSettings(GlobalVariable::ConfigPath, QSettings::IniFormat);
    CreateConfig->setValue("HDPI/OverrideHDPI", "Off");
    CreateConfig->setValue("HDPI/EnableHDPIScale", "On");
    CreateConfig->setValue("HDPI/CustomScale", "1.00");
    delete CreateConfig;
}