#pragma once

#include <QWidget>
#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
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

public slots:
	void StatusMonitor::InsertLog(QString LogType, QString LogContent);

private:
	Ui::StatusMonitorClass *ui;
	bool MouseMovement = 0;
	QPoint MousePos;
	bool WindowMaximized = 0;

private slots:
	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void TrigMaximize();
	void mouseDoubleClickEvent(QMouseEvent* event);
};
