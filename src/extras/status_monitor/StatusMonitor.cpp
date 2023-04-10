#include "StatusMonitor.h"

StatusMonitor::StatusMonitor(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::StatusMonitorClass())
{
	ui->setupUi(this);

	//¿¨Æ¬ÒõÓ°
	QGraphicsDropShadowEffect* CardShadow = new QGraphicsDropShadowEffect(this);
	CardShadow->setColor(QColor("#C1A6A5"));
	CardShadow->setBlurRadius(30);
	CardShadow->setOffset(0, 0);
	ui->app_container->setGraphicsEffect(CardShadow);
}

StatusMonitor::~StatusMonitor()
{
	delete ui;
}

void StatusMonitor::InsertLog(QString LogType, QString LogContent)
{
	ui->log_area->setReadOnly(0);
	QString DebugOut;

	if (LogType == "INFO") {
		ui->log_area->insertHtml("<span style = 'color: #2196F3'>[ INFO ] </span> ");
		DebugOut = "[INFO] ";
	}

	else if (LogType == "OK") {
		ui->log_area->insertHtml("<span style = 'color: #4CAF50'>[ OK ] </span> ");
		DebugOut = "[OK] ";
	}

	else if (LogType == "WARN") {
		ui->log_area->insertHtml("<span style = 'color: #FF9800'>[ WARN ] </span> ");
		DebugOut = "[WARN] ";
	}

	else if (LogType == "ERROR") {
		ui->log_area->insertHtml("<span style = 'color: #F44336'>[ ERROR ] </span> ");
		DebugOut = "[ERROR] ";
	}

	else {
		ui->log_area->insertHtml("<span style = 'color: #795548'>[ OTHER ] </span> ");
		DebugOut = "[OTHER] ";
	}

	ui->log_area->insertHtml("<span style = 'color: #607D8B' > " + LogContent + "</span>");
	ui->log_area->insertPlainText("\n");
	ui->log_area->setReadOnly(1);
	DebugOut = DebugOut + LogContent;
	qDebug() << DebugOut;
}