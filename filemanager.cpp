#include "filemanager.h"
#include <iostream>

using namespace std;
FileManager::FileManager(QString &pathToAccessFile):accessFilePath_(pathToAccessFile)
{

}

QPair<bool,AccessCodesList> FileManager::getAccessCodes(){
    QFile qFile(this->accessFilePath_);
    AccessCodesList accessCodesList;
    QPair<bool,AccessCodesList> qPair;
    if(qFile.open(QIODevice::ReadOnly)){
        //populate AccessCodesList
        while (!qFile.atEnd())
        {
            QByteArray lineData = qFile.readLine();
            QString line(lineData);
            cout << "LINE READ : " << line.toStdString() << endl;
            accessCodesList.appendData(line); // populate the stringlist
        }
        qPair.first = true;
    }else{
        cout << "PROBLEM WITH ACCESS CODES FILE " << endl;
        qPair.first = false;
    }

    qPair.second = accessCodesList;
    return qPair;
}
