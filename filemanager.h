#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QFile>
#include "accesscodeslist.h"
#include <QPair>
class FileManager
{
public:
    FileManager(QString &pathToAccessFile);
    QPair<bool,AccessCodesList> getAccessCodes();
private:
    QString &accessFilePath_;
};

#endif // FILEMANAGER_H
