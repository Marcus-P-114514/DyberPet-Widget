#include "DyberPet.h"
#include "extras/status_monitor/StatusMonitor.h"

QString GlobalVariable::ShowLogWindow;
QString GlobalVariable::ToggleLogWindow;
QString GlobalVariable::LogLevel;

DyberPet::DyberPet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DyberPetClass())
{
    ui->setupUi(this);

    //实例化日志输出
    StatusMonitor* StatusMonitorMain = new StatusMonitor;

    StatusMonitorMain->InsertLog("INFO", "DyberPet Version: " + GlobalVariable::DyberPetVersion);
    StatusMonitorMain->InsertLog("INFO", "DyberPet-Widget Version: " + GlobalVariable::DyberPetWidgetVersion);

    //检查配置
    if (QFile(GlobalVariable::ConfigPath).exists()) {
        StatusMonitorMain->InsertLog("INFO", "Config has been created, skiping generating config...");
    } //配置存在
    else {
        StatusMonitorMain->InsertLog("WARN", "Config not found, generating new config file...");
        DyberPet::CreateConfig();
        StatusMonitorMain->InsertLog("INFO", "Config has been created.");
    }   //配置不存在

    //读取配置
    QSettings* ReadConfig = new QSettings(GlobalVariable::ConfigPath, QSettings::IniFormat);
    GlobalVariable::ShowLogWindow = ReadConfig->value("StatusMonitor/ShowLogWindow").toString();
    GlobalVariable::ToggleLogWindow = ReadConfig->value("StatusMonitor/ToggleLogWindow").toString();
    GlobalVariable::LogLevel = ReadConfig->value("StatusMonitor/LogLevel").toString();
    delete ReadConfig;

    if (GlobalVariable::ShowLogWindow == "Enabled") {
        StatusMonitorMain->show();
    }
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

    CreateConfig->setValue("StatusMonitor/ShowLogWindow", "Disabled");
    CreateConfig->setValue("StatusMonitor/ToggleLogWindow", "Disabled");
    CreateConfig->setValue("StatusMonitor/LogLevel", "Info");

    delete CreateConfig;
}