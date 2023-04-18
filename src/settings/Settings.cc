#include "Settings.h"

void DyberPetSettings::GetPetList(QString DirName) {
	//初步获取桌宠列表
	QDir TargetDir(DirName);
	QStringList Folders = TargetDir.entryList(QDir::Dirs);
	QStringList SubPet;
	Folders.removeOne("sys");
	Folders.removeOne(".");
	Folders.removeOne("..");

	//获取子桌宠列表
	for (int i = 0; i < (TargetDir.entryList().size() - 4); i++) {
		//打开pet_conf.json
		QString PetConfPath = DirName + "/" + Folders[i] + "/pet_conf.json";
		QFile SubPetJson(PetConfPath);
		SubPetJson.open(QIODevice::ReadOnly);
		QByteArray SubPetJsonContent = SubPetJson.readAll();
		QJsonDocument SubPetJsonDocument = QJsonDocument::fromJson(SubPetJsonContent);
		QJsonObject CurrentObject = SubPetJsonDocument.object();

		//读取subpet
		if (CurrentObject.contains("subpet")) {
			//转换subpet中所有内容到QJsonObject
			QJsonValue SubPetVal = CurrentObject.value("subpet");
			QJsonObject SubPetObj = SubPetVal.toObject();

			//初步获取子桌宠列表（含重复项）
			QStringList SubPetTemp;
			SubPetTemp.append(SubPetObj.keys());

			//去除重复项并导出子桌宠列表
			for (int a = 0; a < SubPetTemp.length(); a++) {
				if (SubPet.contains(SubPetTemp[a])) {
					qDebug() << "Ignored repeated value.";
				}
				else {
					SubPet.append(SubPetTemp[a]);
				}
			}
			
		}	//如果pet_conf.json中含有subpet

		//关闭文档
		SubPetJson.close();
	}

	//在桌宠列表中去除子桌宠
	for (int RemoveSubPet = 0; RemoveSubPet < SubPet.length(); RemoveSubPet++) {
		Folders.removeOne(SubPet[RemoveSubPet]);
	}
}