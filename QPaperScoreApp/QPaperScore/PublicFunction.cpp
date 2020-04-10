#include "stdafx.h"
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
	dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
	QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息
	foreach(QFileInfo file, fileList) 
	{ //遍历文件信息
		if (file.isFile()) 
		{ // 是文件，删除
			file.dir().remove(file.fileName());
		}
		else 
		{ // 递归删除
			DelDir(file.absoluteFilePath());
		}
	}
	return dir.rmpath(dir.absolutePath()); // 删除文件夹
}
