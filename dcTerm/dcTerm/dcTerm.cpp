/*--------------------------------------------------------------------------------------------------
-- SOURCE FILE: dcTerm.cpp - An application that sends and recieves bits over a serial port.
--
-- PROGRAM: dcTerm (Data Communication Terminal)
--
-- FUNCTIONS:
-- void initMenuConnections();
-- void populatePortMenu();
-- void createConsole();
-- void initStatusBarLabels();
--
-- void startConnection();
-- void stopConnection();
--
-- void setBitRate();
-- void setDataBits();
-- void setParity();
-- void setStopBits();
-- void setFlowControl();
--
-- void selectPort();
--
-- void writeToPort(QByteArray &data);
-- void readFromPort();
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
-- This program is a dumb terminal for a serial port connection. The design uses a 3 level approach
-- and is implemented with the C++ GUI framework Qt which relies on signals and slots for
-- communication between different parts of the program.
--
-- Because the Qt signal-slot system is asynchronous, the program can have multithreaded performance
-- without the designer/programmer having to implement their own threads. Simply, a signal is
-- emitted when their are bytes on the serial port that are ready to be read by the program.
-- Likewise, a signal is emitted to write to the serial port when a keystroke is pressed.
--
-- When a serial port is selected and connected with another terminal at the other end of the serial
-- port all keypresses are sent to the other terminal and vice versa. At this point the user can
-- either continue to send characters to the other terminal or close the connection.
--------------------------------------------------------------------------------------------------*/
#include <QAction>
#include <QMessageBox>

#include "dcTerm.h"

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
-- INTERFACE: dcTerm (QWidget*)
--
-- NOTES:
-- Constructor for the main window of the appliaction.
--
-- The constructor sets these basic settings for the serial port:
-- - Port Name: NULL
-- - Baud Rate: 2400 bps
-- - Data Bits: 8
-- - Parity: No Parity
-- - Stop Bits: 1
-- - Flow Control: Hardware
--
-- It also serves as the main entry point for the program and calls various program set-up
-- functions.
--------------------------------------------------------------------------------------------------*/
dcTerm::dcTerm(QWidget* parent)
	: QMainWindow(parent)
	, mPortName("")
	, mBitRate(2400)
	, mDataBits(QSerialPort::Data8)
	, mParity(QSerialPort::NoParity)
	, mStopBits(QSerialPort::OneStop)
	, mControl(QSerialPort::HardwareControl)
{
	ui.setupUi(this);
	mPort = new QSerialPort(this);
	setWindowTitle(TITLE_DISCONNECTED);
	initMenuConnections();
	initStatusBarLabels();
	populatePortMenu();
	createConsole();

	// Conencting port functionality
	connect(mPort, &QSerialPort::readyRead, this, &dcTerm::readFromPort);
	connect(console, &Console::emitKeyPressed, this, &dcTerm::writeToPort);
}

/*--------------------------------------------------------------------------------------------------
-- FUNCTION: Deconstructor
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: dcTerm ()
--
-- NOTES:
-- Deconstructor for the main window of the appliaction.
--
-- Deletes all the UI elements before closing the application to prevent any memory leaks.
--------------------------------------------------------------------------------------------------*/
dcTerm::~dcTerm()
{
	delete console;

	delete mPortLabel;
	delete mBitRateLabel;
	delete mDataBitsLabel;
	delete mParityLabel;
	delete mStopBitsLabel;
	delete mControlLabel;

	delete mPort;
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: initMenuConnections
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void initMenuConnections (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Creates all the signal-slot connections for the menu elements.
--
-- Signal and slots are the way components talk to each other when using Qt.
--------------------------------------------------------------------------------------------------*/
void dcTerm::initMenuConnections()
{
	// Closing the Window
	connect(ui.actionClose, &QAction::triggered, this, &QWidget::close);

	// Starting and stopping connection
	connect(ui.actionConnect, &QAction::triggered, this, &dcTerm::startConnection);
	connect(ui.actionDisconnect, &QAction::triggered, this, &dcTerm::stopConnection);

	// Setting bit rate 
	connect(ui.action1200, &QAction::triggered, this, &dcTerm::setBitRate);
	connect(ui.action2400, &QAction::triggered, this, &dcTerm::setBitRate);
	connect(ui.action4800, &QAction::triggered, this, &dcTerm::setBitRate);
	connect(ui.action9600, &QAction::triggered, this, &dcTerm::setBitRate);
	connect(ui.action19200, &QAction::triggered, this, &dcTerm::setBitRate);
	connect(ui.action38400, &QAction::triggered, this, &dcTerm::setBitRate);
	connect(ui.action57600, &QAction::triggered, this, &dcTerm::setBitRate);
	connect(ui.action115200, &QAction::triggered, this, &dcTerm::setBitRate);

	// Setting Data Bits
	connect(ui.action5, &QAction::triggered, this, &dcTerm::setDataBits);
	connect(ui.action6, &QAction::triggered, this, &dcTerm::setDataBits);
	connect(ui.action7, &QAction::triggered, this, &dcTerm::setDataBits);
	connect(ui.action8, &QAction::triggered, this, &dcTerm::setDataBits);

	// Setting Parity
	connect(ui.actionEven, &QAction::triggered, this, &dcTerm::setParity);
	connect(ui.actionOdd, &QAction::triggered, this, &dcTerm::setParity);
	connect(ui.actionNone, &QAction::triggered, this, &dcTerm::setParity);

	// Setting Stop Bits
	connect(ui.action1, &QAction::triggered, this, &dcTerm::setStopBits);
	connect(ui.action2, &QAction::triggered, this, &dcTerm::setStopBits);

	// Setting Flow Control
	connect(ui.actionNo_Flow_Control, &QAction::triggered, this, &dcTerm::setFlowControl);
	connect(ui.actionHardware_Control, &QAction::triggered, this, &dcTerm::setFlowControl);
	connect(ui.actionSoftware_Control, &QAction::triggered, this, &dcTerm::setFlowControl);
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: initStatusBarLabels
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void initStatusBarLabels (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Creates QLabels and places them in the status bar. These QLabels display the currently selected
-- port settings.
--------------------------------------------------------------------------------------------------*/
void dcTerm::initStatusBarLabels()
{
	mPortLabel = new QLabel(ui.statusBar);
	mBitRateLabel = new QLabel(ui.statusBar);
	mDataBitsLabel = new QLabel(ui.statusBar);
	mParityLabel = new QLabel(ui.statusBar);
	mStopBitsLabel = new QLabel(ui.statusBar);
	mControlLabel = new QLabel(ui.statusBar);

	mPortLabel->setText(PORT_LABEL_TEXT.arg("N/A"));
	mBitRateLabel->setText(BIT_RATE_LABEL_TEXT.arg(mBitRate));
	mDataBitsLabel->setText(DATA_BIT_LABEL_TEXT.arg(8));
	mParityLabel->setText(PARITY_LABEL_TEXT.arg("None"));
	mStopBitsLabel->setText(STOP_BITS_LABEL_TEXT.arg(1));
	mControlLabel->setText(FLOW_CONTROL_LABEL_TEXT.arg("Hardware Control"));

	ui.statusBar->addWidget(mPortLabel);
	ui.statusBar->addWidget(mBitRateLabel);
	ui.statusBar->addWidget(mDataBitsLabel);
	ui.statusBar->addWidget(mParityLabel);
	ui.statusBar->addWidget(mStopBitsLabel);
	ui.statusBar->addWidget(mControlLabel);
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: populatePortMenu
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void populatePortMenu (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Populates the port menu with the list of available communication ports on the computer.
--------------------------------------------------------------------------------------------------*/
void dcTerm::populatePortMenu()
{
	QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
	if (ports.size() == 0)
	{
		ui.menuPort->setEnabled(false);
		setWindowTitle(TITLE_UNDETECTABLE);
		return;
	}

	QAction* action;

	for (int i = 0; i < ports.size(); i++)
	{
		action = new QAction(this);
		action->setObjectName(ports[i].portName());
		action->setText(ports[i].portName());

		ui.menuPort->addAction(action);

		connect(action, &QAction::triggered, this, &dcTerm::selectPort);
	}
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: createConsole
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void createConsole (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Creates the console where incoming characters are displayed.
--------------------------------------------------------------------------------------------------*/
void dcTerm::createConsole()
{
	console = new Console(this);
	setCentralWidget(console);
	console->setEnabled(false);
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: startConnection
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void startConnection (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Creats a new QSerialPort object, sets the settings chosen by the users, and starts the serial
-- port connection. If the port has openned, menu items are disabled/enabled accordingly and
-- the window title is changed to show that the connection is openned.
--
-- QSerialPort is the Qt interface for interaction with a serial port on a computer.
--------------------------------------------------------------------------------------------------*/
void dcTerm::startConnection()
{
	mPort->setPortName(mPortName);
	mPort->setBaudRate(mBitRate);
	mPort->setDataBits(mDataBits);
	mPort->setParity(mParity);
	mPort->setStopBits(mStopBits);
	mPort->setFlowControl(mControl);

	setWindowTitle(TITLE_CONNECTING);
	bool openned = mPort->open(QIODevice::ReadWrite);
	

	if (openned)
	{
		ui.actionConnect->setEnabled(false);
		ui.actionDisconnect->setEnabled(true);
		console->setEnabled(true);
		ui.menuSettings->setEnabled(false);
		ui.menuPort->setEnabled(false);
		setWindowTitle(TITLE_CONNECTED.arg(mPortName));
	}
	else
	{
		QMessageBox::critical(this, tr("Error"), mPort->errorString());
		ui.statusBar->showMessage(ERROR_CANNOT_OPEN);
	}
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: stopConnection
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void stopConnection (void)
--
-- RETURNS: void.
--
-- NOTES:
-- Closes the serial port connection if it is open. If a port was closed, menu items are
-- enabled/disabled accordingly and the window title is changed to show that the port has been
-- disconnected.
--------------------------------------------------------------------------------------------------*/
void dcTerm::stopConnection()
{
	if (mPort->isOpen())
	{
		mPort->flush();
		mPort->close();
		ui.actionConnect->setEnabled(true);
		ui.actionDisconnect->setEnabled(false);
		console->setEnabled(false);
		ui.menuSettings->setEnabled(true);
		ui.menuPort->setEnabled(true);
		setWindowTitle(TITLE_DISCONNECTED);
	}
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: setBitRate
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void setBitRate (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function is a Qt slot and is triggered when a menu item concerning baud rate is selected.
--
-- Saves the selected bit rate to a variable and changes the label in the status bar to reflect the
-- change.
--------------------------------------------------------------------------------------------------*/
void dcTerm::setBitRate()
{
	QString bitRate(((QAction*)QObject::sender())->text());
	mBitRate = bitRate.toInt();
	mBitRateLabel->setText(BIT_RATE_LABEL_TEXT.arg(bitRate));
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: setDataBits
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void setDataBits (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function is a Qt slot and is triggered when a menu item concerning the number of data
-- bits used is selected.
--
-- Saves the number of data bits to a variable and changes the label in the status bar to reflect
-- the change.
--------------------------------------------------------------------------------------------------*/
void dcTerm::setDataBits()
{
	QString dataBits(((QAction*)QObject::sender())->text());
	mDataBits = static_cast<QSerialPort::DataBits> (dataBits.toInt());
	mDataBitsLabel->setText(DATA_BIT_LABEL_TEXT.arg(dataBits));
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: setParity
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void setParity (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function is a Qt slot and is triggered when a menu item concerning signal parity is
-- selected.
--
-- Saves the number of parity bits to a variable and changes the label in the status bar to reflect
-- the change.
--------------------------------------------------------------------------------------------------*/
void dcTerm::setParity()
{
	QString parity(((QAction*)QObject::sender())->text());
	mParityLabel->setText(PARITY_LABEL_TEXT.arg(parity));
	if (parity == QString("Even"))
	{
		mParity = QSerialPort::EvenParity;
	}
	if (parity == QString("Odd"))
	{
		mParity = QSerialPort::OddParity;
	}
	if (parity == QString("None"))
	{
		mParity = QSerialPort::NoParity;
	}
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: setStopBits
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void setStopBits (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function is a Qt slot and is triggered when a menu item concerning the number of stop bits
-- is selected.
--
-- Saves the number of stop bits to a variable and changes the label in the status bar to reflect
-- the change.
--------------------------------------------------------------------------------------------------*/
void dcTerm::setStopBits()
{
	QString stopBits(((QAction*)QObject::sender())->text());
	mStopBits = static_cast<QSerialPort::StopBits> (stopBits.toInt());
	mStopBitsLabel->setText(STOP_BITS_LABEL_TEXT.arg(stopBits));
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: setFlowControl
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void setFlowControl (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function is a Qt slot and is triggered when a menu item concerning flow control is selected.
--
-- Saves the flow control setting to a variable and changes the label in the status bar to reflect
-- the change.
--------------------------------------------------------------------------------------------------*/
void dcTerm::setFlowControl()
{
	QString flowControl(((QAction*)QObject::sender())->text());
	mControlLabel->setText(FLOW_CONTROL_LABEL_TEXT.arg(flowControl));
	if (flowControl == QString("No Flow Control"))
	{
		mControl = QSerialPort::NoFlowControl;
	}
	if (flowControl == QString("Hardware Control"))
	{
		mControl = QSerialPort::HardwareControl;
	}
	if (flowControl == QString("Software Control"))
	{
		mControl = QSerialPort::SoftwareControl;
	}
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: selectPort
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void selectPort (void)
--
-- RETURNS: void.
--
-- NOTES:
-- This function is a Qt slot and is triggered when the user selects a serial port.
--
-- Saves the name of the port to a variable and changes the label in the status bar to reflect the
-- change.
--------------------------------------------------------------------------------------------------*/
void dcTerm::selectPort()
{
	mPortName = ((QAction*)QObject::sender())->text();
	mPortLabel->setText(PORT_LABEL_TEXT.arg(mPortName));
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: writeToPort
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void writeToPort (QByteArray &data)
--
-- RETURNS: void.
--
-- NOTES:
-- This function is a Qt slot and is triggered when the console detects a keypress and wants to
-- send it through the serial port.
--
-- Writes the bits, data, to the serial port. The data is encoded in the machine's local 8 bit text
-- encoding.
--------------------------------------------------------------------------------------------------*/
void dcTerm::writeToPort(QByteArray &data)
{
	mPort->write(data);
}

/*-------------------------------------------------------------------------------------------------
-- FUNCTION: readFromPort
--
-- DATE: September 29, 2017
--
-- REVISIONS: N/A
--
-- DESIGNER: Benny Wang
--
-- PROGRAMMER: Benny Wang
--
-- INTERFACE: void readFromPort (void)
--
-- RETURNS: void.
--
-- NOTES:
-- THis funciton is a Qt slot and is triggered when the serial port emit's the signal
-- QSerialPort::ReadReady which signals that there are data bits to be read from the incoming port.
--
-- Reads all the bits from the serial port and sends them to the console to be displayed.
--------------------------------------------------------------------------------------------------*/
void dcTerm::readFromPort()
{
	QByteArray data = mPort->readAll();
	console->DisplayData(data);
	mPort->clear(QSerialPort::Input);
}
