#pragma once
#include "QScreen"
#include "QApplication"

#ifdef Q_OS_WIN
	QScreen *primary_screen_info = qApp->primaryScreen();
	//qreal system_dpi = primary_screen_info->logicalDotsPerInch();
#endif