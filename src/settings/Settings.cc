#include "Settings.h"

void DyberPetSettings::GetPetList(QString DirName) {
	//������ȡ�����б�
	QDir TargetDir(DirName);
	QStringList Folders = TargetDir.entryList(QDir::Dirs);
	QStringList SubPet;
	Folders.removeOne("sys");
	Folders.removeOne(".");
	Folders.removeOne("..");

	//��ȡ�������б�
	for (int i = 0; i < (TargetDir.entryList().size() - 4); i++) {
		//��pet_conf.json
		QString PetConfPath = DirName + "/" + Folders[i] + "/pet_conf.json";
		QFile SubPetJson(PetConfPath);
		SubPetJson.open(QIODevice::ReadOnly);
		QByteArray SubPetJsonContent = SubPetJson.readAll();
		QJsonDocument SubPetJsonDocument = QJsonDocument::fromJson(SubPetJsonContent);
		QJsonObject CurrentObject = SubPetJsonDocument.object();

		//��ȡsubpet
		if (CurrentObject.contains("subpet")) {
			//ת��subpet���������ݵ�QJsonObject
			QJsonValue SubPetVal = CurrentObject.value("subpet");
			QJsonObject SubPetObj = SubPetVal.toObject();

			//������ȡ�������б����ظ��
			QStringList SubPetTemp;
			SubPetTemp.append(SubPetObj.keys());

			//ȥ���ظ�������������б�
			for (int a = 0; a < SubPetTemp.length(); a++) {
				if (SubPet.contains(SubPetTemp[a])) {
					qDebug() << "Ignored repeated value.";
				}
				else {
					SubPet.append(SubPetTemp[a]);
				}
			}
			
		}	//���pet_conf.json�к���subpet

		//�ر��ĵ�
		SubPetJson.close();
	}

	//�������б���ȥ��������
	for (int RemoveSubPet = 0; RemoveSubPet < SubPet.length(); RemoveSubPet++) {
		Folders.removeOne(SubPet[RemoveSubPet]);
	}
}