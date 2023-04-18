#pragma once
#include "QString"
#include "QStringList"
#include "QDir"
#include "QByteArray"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QDebug"
#include "../extras/status_monitor/StatusMonitor.h"

class DyberPetSettings
{
public slots:
	void GetPetList(QString DirName);
};