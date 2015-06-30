#include "accesscodeslist.h"

AccessCodesList::AccessCodesList()
{
}


void AccessCodesList::appendData(QString &data){
    this->push_back(data);
}
