/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: main.cpp - This file acts as a driver for the InfoSniffer program.
--
-- PROGRAM: InfoSniffer
--
-- FUNCTIONS:
-- int main(int argc, char *argv[]);
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
-- Launches the window.
--
----------------------------------------------------------------------------------------------------------------------*/

#include "application.h"
#include <QApplication>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: main
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
-- INTERFACE: int main(int argc, char *argv[])
-- int argc, char *argv[]: This application is not meant to be run from console, but is instead a desktop app.
--
-- RETURNS: Returns 0 for program exiting successfully, a non-zero value for failure.
--
-- NOTES:
-- This function drives the program and launches the window.
--
----------------------------------------------------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Application w;
    w.show();
    return a.exec();
}
