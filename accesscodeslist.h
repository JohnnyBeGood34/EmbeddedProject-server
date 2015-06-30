#ifndef ACCESSCODESLIST_H
#define ACCESSCODESLIST_H
#include <QString>
#include <QStringList>
class AccessCodesList : public QStringList
{
public:
    AccessCodesList();
    void appendData(QString &data);
};

#endif // ACCESSCODESLIST_H
