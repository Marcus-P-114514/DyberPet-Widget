#include "StatusMonitor.h"

StatusMonitor::StatusMonitor(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::StatusMonitorClass())
{
	ui->setupUi(this);
	
}

StatusMonitor::~StatusMonitor()
{
	delete ui;
}
