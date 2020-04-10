
#include "PublicFunction.h"

bool DelDir(const QString &path)
{
	if (path.isEmpty()) 
	{
		return false;
	}
	QDir dir(path);
	if (!dir.exists()) 
	{
		return true;
	}
	dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //���ù���
	QFileInfoList fileList = dir.entryInfoList(); // ��ȡ���е��ļ���Ϣ
	foreach(QFileInfo file, fileList) 
	{ //�����ļ���Ϣ
		if (file.isFile()) 
		{ // ���ļ���ɾ��
			file.dir().remove(file.fileName());
		}
		else 
		{ // �ݹ�ɾ��
			DelDir(file.absoluteFilePath());
		}
	}
	return dir.rmpath(dir.absolutePath()); // ɾ���ļ���
}
