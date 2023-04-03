#include "DyberPet.h"
#include "extras/status_monitor/StatusMonitor.h"

DyberPet::DyberPet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DyberPetClass())
{
    ui->setupUi(this);

    StatusMonitor* status_monitor = new StatusMonitor;
    status_monitor->show();
}

DyberPet::~DyberPet()
{
    delete ui;
}