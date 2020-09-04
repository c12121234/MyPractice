#ifndef LOGFILELIB_H
#define LOGFILELIB_H

#include "LogFileLib_global.h"

//class LOGFILELIB_EXPORT LogFileLib
//{
//public:
//    LogFileLib();
//    void ErrorMessageHandler(QtMsgType type, const QMessageLogContext& ctx, const QString & msg);
//    void Init();
//};

LOGFILELIB_EXPORT void ErrorMessageHandler(QtMsgType type, const QMessageLogContext& ctx, const QString & msg);

#endif // LOGFILELIB_H
