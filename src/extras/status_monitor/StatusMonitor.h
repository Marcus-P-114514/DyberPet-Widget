#pragma once

#include <QWidget>
#include "ui_StatusMonitor.h"
#include "../../GlobalVariable.h"

class GlobalVariable;

QT_BEGIN_NAMESPACE
namespace Ui { class StatusMonitorClass; };
QT_END_NAMESPACE

class StatusMonitor : public QWidget
{
	Q_OBJECT

public:
	StatusMonitor(QWidget *parent = nullptr);
	~StatusMonitor();

private:
	Ui::StatusMonitorClass *ui;
};
