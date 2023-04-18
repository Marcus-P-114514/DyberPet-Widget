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
#include "../variables/GlobalVariable.h"

class DyberPetSettings
{
public slots:
	void SaveSettings();
	void GetPetList(QString DirName);

private:
	QStringList Folders;
	QStringList SubPet;
};