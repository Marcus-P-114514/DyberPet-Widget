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

	//Í¸Ã÷±³¾°
	setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
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

void StatusMonitor::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		if (WindowMaximized == 0) {
			MouseMovement = 1;
			MousePos = event->globalPos() - this->pos();
		}
	}
}

void StatusMonitor::mouseMoveEvent(QMouseEvent* event)
{
	if (MouseMovement == 1) {
		move(event->globalPos() - MousePos);
	}
}

void StatusMonitor::mouseReleaseEvent(QMouseEvent* event)
{
	MouseMovement = 0;
}

void StatusMonitor::TrigMaximize()
{
	if (WindowMaximized == 0) {
		this->showMaximized();
		WindowMaximized = 1;

		QGraphicsDropShadowEffect* NoCardShadow = new QGraphicsDropShadowEffect(this);
		NoCardShadow->setColor(QColor("#C1A6A5"));
		NoCardShadow->setBlurRadius(0);
		NoCardShadow->setOffset(0, 0);
		ui->app_container->setGraphicsEffect(NoCardShadow);

		ui->gridLayout->setMargin(0);
	}
	else {
		this->showNormal();
		WindowMaximized = 0;

		QGraphicsDropShadowEffect* CardShadow = new QGraphicsDropShadowEffect(this);
		CardShadow->setColor(QColor("#C1A6A5"));
		CardShadow->setBlurRadius(30);
		CardShadow->setOffset(0, 0);
		ui->app_container->setGraphicsEffect(CardShadow);

		ui->gridLayout->setMargin(11);
	}
	
}

void StatusMonitor::mouseDoubleClickEvent(QMouseEvent* event) 
{
	StatusMonitor::TrigMaximize();
}

void StatusMonitor::on_minimize_app_clicked()
{
	this->showMinimized();
}

void StatusMonitor::on_maximize_app_clicked()
{
	StatusMonitor::TrigMaximize();
}

void StatusMonitor::on_close_app_clicked()
{
	this->hide();
}