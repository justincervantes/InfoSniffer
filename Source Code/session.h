#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <QtCore>
#include <stdio.h>
#include <winsock2.h>

QString hostNameToIP(QString input);
QString ipToHostName(QString input);
QString serviceNameProtocolToPortNumber(QString input);
QString PortNumberToServiceNameProtocol(QString input);

#endif // PHYSICAL_H
