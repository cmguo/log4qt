#include "qlogger.h"

#include <log4qt/propertyconfigurator.h>
#include <log4qt/basicconfigurator.h>

#include <QCoreApplication>
#include <QFileInfo>
#include <QMetaType>
#include <QTextCodec>
#include <QThread>

Q_DECLARE_METATYPE(QTextCodec*)

void QLogger::init(QString path)
{
    QMetaType::registerConverter<QString, QTextCodec*>([=](QString const & encoding) {
        return QTextCodec::codecForName(encoding.toUtf8());
    });
    if (path == nullptr)
        path = QCoreApplication::applicationDirPath() + "/logger.properties";
    if (!QFileInfo::exists(path))
        path = ":/log4qt/logger.properties";
    Log4Qt::PropertyConfigurator::configure(path);
}
