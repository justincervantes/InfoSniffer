/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: session.cpp - This file contains all the Winsock 2 API calls.
--
-- PROGRAM: InfoSniffer
--
-- FUNCTIONS:
-- QString hostNameToIP(QString input);
-- QString ipToHostName(QString input);
-- QString serviceNameProtocolToPortNumber(QString input);
-- QString PortNumberToServiceNameProtocol(QString input);
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- NOTES:
-- All API calls have error handling, however the return for all methods, which is a QString (Qt version of
-- std::string), will give a bit more details to the UI via the calling method, so it will return the
-- error for the user. The calling method from the application layer (application.cpp) is on_pushButton_clicked().
-- All code in this file has been adapted from Aman Abdulla's samples on Winsock 2.
--
----------------------------------------------------------------------------------------------------------------------*/

#include "session.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: hostNameToIP
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Aman Abdulla
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: QString hostNameToIP(QString input)
-- QString input: the query to be processed.
--
-- RETURNS: Returns the IP address(es) of the provided host name as a QString.
-- Returns an error message provided by h_errno if gethostbyname fails.
-- NOTES:
-- This function is used to determine the IP address(es) of a hostname.
----------------------------------------------------------------------------------------------------------------------*/
QString hostNameToIP(QString input) {
    QString retval = "Resolving the hostname's IP: \n";
    const char *str;
    QByteArray ba;
    ba = input.toLatin1();
    str = ba.data();

    struct hostent *hp;
    struct in_addr my_addr, *addr_p;
    char **p;

    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;

    // Open a Winsock v2.2 session
    WSAStartup(wVersionRequested, &wsaData);

    addr_p = (struct in_addr*)malloc(sizeof(struct in_addr));
    addr_p = &my_addr;

    // Queries the hostname, error is stored in h_errno if failed
    if((hp=gethostbyname(str)) == NULL) {

        switch(h_errno) {
            case HOST_NOT_FOUND:
                return "No such host";
            case TRY_AGAIN:
                return "Try again later";
            case NO_RECOVERY:
                return "DNS Error";
            case NO_ADDRESS:
                return "No IP Address for the given host";
            default:
                QString unknownError = "Unknown error: ";
                unknownError.append(h_errno);
                return unknownError;
        }
    }

    // Checks the address list of the hostname lookup and provides all known IP addresses
    for(p = hp->h_addr_list; *p != 0; p++) {
        struct in_addr in;
        memcpy(&in.s_addr, *p, sizeof (in.s_addr));
        retval.append(inet_ntoa(in));
        retval.append("\n");
    }

    return retval;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ipToHostName
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Aman Abdulla
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: QString ipToHostName(QString input)
-- QString input: the IP address to be processed.
--
-- RETURNS: Returns the host name of the provided IP address as a QString.
-- Returns an error message if the input is not in correct IP format (x.x.x.x) or if the query fails to retrieve
-- a valid host name.
-- NOTES:
-- This function is used to determine the host name of an IP address.
----------------------------------------------------------------------------------------------------------------------*/
QString ipToHostName(QString input) {
    QString retval = "Resolving the IP address' hostname: \n";
    const char *str;
    QByteArray ba;
    ba = input.toLatin1();
    str = ba.data();

    int a;
    struct hostent *hp;
    struct in_addr my_addr, *addr_p;
    char **p;
    char ip_address[256]; // String for IP address

    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;

    // Open a Winsock v2.2 session
    WSAStartup(wVersionRequested, &wsaData);

    addr_p = (struct in_addr*)malloc(sizeof(struct in_addr));
    addr_p = &my_addr;

    if(isdigit(*str)) {
        if((a = inet_addr(str)) == 0) {
            return "IP Address must be of the form x.x.x.x\n";
        }

        strcpy(ip_address, str);
        addr_p->s_addr=inet_addr(ip_address);
        hp = gethostbyaddr((char *) addr_p, PF_INET, sizeof(my_addr));
        if(hp == NULL) {
            return "Host information not found\n";
        }
    } else {
        return "IP's must begin with a digit";
    }

    // Checks the address list of the IP lookup and provides all known host names
    for(p = hp->h_addr_list; *p != 0; p++) {
        struct in_addr in;

        memcpy(&in.s_addr, *p, sizeof (in.s_addr));
        retval.append(hp->h_name);
        retval.append("\n");
    }

    WSACleanup();

    return retval;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: serviceNameProtocolToPortNumber
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Aman Abdulla
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: QString serviceNameProtocolToPortNumber(QString input)
-- QString input: the query to be processed. The input must have the delimeter ','. Leading and trailing
-- whitespace is trimmed for the second parameter. Valid input form: "<service name>, <protocol>"
--
-- RETURNS: Returns a message which explains the port number of the provided service name and protocol.
-- Returns a usage reminder if a valid input is not received.
-- Returns an error update if getservbyname was unable to retrieve the port number.
--
-- NOTES:
-- This function is used to determine the port number of a service.
----------------------------------------------------------------------------------------------------------------------*/
QString serviceNameProtocolToPortNumber(QString input) {
    QString retval = "";
    QStringList elements = input.split(',');

    // Ensure only 2 parameters are entered
    if(elements.length() != 2) {
        return "Invalid input received, Usage: service, protocol";
    }

    struct servent *sv;
    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;

    const char *service;
    const char *protocol;

    //Converts a QString to a char*
    QByteArray ba;
    ba = elements[0].toLatin1();
    service = ba.data();
    ba = elements[1].trimmed().toLatin1();
    protocol = ba.data();

    // Open a Winsock v2.2 session
    WSAStartup(wVersionRequested, &wsaData);

    sv = getservbyname(service, protocol);

    if(sv == NULL) {
        return "Error in getservbyname\n";
    }
    retval.append("The port number for service ");
    retval.append(service);
    retval.append(" is: ");
    retval.append(QString::number(ntohs(sv->s_port)));
    WSACleanup();
    return retval;
}


/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: PortNumberToServiceNameProtocol
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Aman Abdulla
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: QString PortNumberToServiceNameProtocol(QString input)
-- QString input: the query to be processed. The input must have the delimeter ','. Leading and trailing
-- whitespace is trimmed for the second parameter. Valid input form: "<service name>, <protocol>"
--
-- RETURNS: Returns a message which explains the service name of the provided port number and protocol.
-- Returns a usage reminder if a valid input is not received.
-- Returns an error update if getservbyport was unable to resolve the service name.
--
-- NOTES:
-- This function is used to determine the name of a service.
----------------------------------------------------------------------------------------------------------------------*/
QString PortNumberToServiceNameProtocol(QString input) {
    QString retval = "";
    QStringList elements = input.split(',');

    // Ensure only 2 parameters are entered
    if(elements.length() != 2) {
        return "Usage: service, protocol";
    }

    struct servent *sv;
    int s_port;
    WORD wVersionRequested = MAKEWORD(2,2);
    WSADATA wsaData;

    const char *port;
    const char *protocol;

    //Converts a QString to a char*
    QByteArray ba;
    ba = elements[0].toLatin1();
    port = ba.data();
    ba = elements[1].trimmed().toLatin1();
    protocol = ba.data();

    // Open a Winsock v2.2 session
    WSAStartup(wVersionRequested, &wsaData);

    s_port = atoi(port);
    sv = getservbyport(htons(s_port), protocol);
    if(sv == NULL) {
        return "Error in getservbyport\n";
    }

    retval.append("The service for port ");
    retval.append(QString::number(s_port));
    retval.append(" is: ");
    retval.append(sv->s_name);
    WSACleanup();
    return retval;

}

