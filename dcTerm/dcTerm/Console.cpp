/*--------------------------------------------------------------------------------------------------
-- SOURCE FILE: Console.cpp - The main text area for the application. 
--
-- PROGRAM: dcTerm (Data Communication Terminal)
--
-- FUNCTIONS:
-- void displayData(const QByteArray &data);
--
-- void keyPressEvent(QKeyEvent* e);
-- 
-- void emitKeyPressed(QByteArray &data);
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- NOTES:
-- Is the main text area for the terminal program that displays the text typed by the other terminal
-- on the other side of the serial port. This class inherits from the QPlainTextEdit.
--------------------------------------------------------------------------------------------------*/
#include <QPlainTextEdit>

#include "Console.h"

/*--------------------------------------------------------------------------------------------------
-- FUNCTION: Constructor
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: Console (QWidget*)
--
-- NOTES:
-- Constructor for a console text area.
--
-- This constructor will set the background color to black and the text color to green. 
--------------------------------------------------------------------------------------------------*/
Console::Console(QWidget* parent)
	: QPlainTextEdit(parent)
{
	document()->setMaximumBlockCount(100);
	QPalette p = palette();
	p.setColor(QPalette::Base, Qt::black);
	p.setColor(QPalette::Text, Qt::green);
	setPalette(p);
}

/*--------------------------------------------------------------------------------------------------
-- FUNCTION: DisplayData
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: DisplayData (const QByteArray &data)
--
-- RETURNS: void.
-- 
-- NOTES:
-- Takes any QByteArray and turns it into a QString then displays it in the console.
--------------------------------------------------------------------------------------------------*/
void Console::DisplayData(const QByteArray &data)
{
	insertPlainText(QString(data));
}

/*--------------------------------------------------------------------------------------------------
-- FUNCTION: keyPressEvent
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: keyPressEvent (QKeyEvent* e)
--
-- RETURNS: void.
-- 
-- NOTES:
-- This function is called everytime the users press a key with the application in focus.
-- Information about the key pressed is stored in a QKeyEvent object, e, and if the key is not one
-- of the direcitonal arrow keys or the backspace, a QByteArray representing the keypress 
-- is emitted as a signal. 
--
-- The emitKeyPressed signal is connected to dcTerm::writeToPort.
--------------------------------------------------------------------------------------------------*/
void Console::keyPressEvent(QKeyEvent* e)
{
	switch (e->key())
	{
	case Qt::Key_Left:
	case Qt::Key_Right:
	case Qt::Key_Up:
	case Qt::Key_Down:
	case Qt::Key_Backspace:
		break;
	default:
		emit emitKeyPressed(e->text().toLocal8Bit());
	}
}
