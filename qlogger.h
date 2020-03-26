#ifndef QLOGGER_H
#define QLOGGER_H

#include "log4qt_global.h"

#include <QString>

class LOG4QT_EXPORT QLogger
{
public:
    static void init(QString path = nullptr);
};

#endif // QLOGGER_H
