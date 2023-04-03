#include "DyberPet.h"

DyberPet::DyberPet(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DyberPetClass())
{
    ui->setupUi(this);
}

DyberPet::~DyberPet()
{
    delete ui;
}
