#pragma once

#include <QMainWindow>
#include "ui_DyberPet.h"
#include "GlobalVariable.h"
#include "QFile"
#include "QSettings"

class GlobalVariable;
class StatusMonitor;

QT_BEGIN_NAMESPACE
namespace Ui { class DyberPetClass; };
QT_END_NAMESPACE

class DyberPet : public QMainWindow
{
    Q_OBJECT

public:
    DyberPet(QWidget *parent = nullptr);
    ~DyberPet();

private:
    Ui::DyberPetClass *ui;

private slots:
    void CreateConfig();
};
