#pragma once

#include <QLabel>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtWidgets/QMainWindow>

#include "Console.h"
#include "ui_dcTerm.h"

class dcTerm : public QMainWindow
{
	Q_OBJECT

public:
	dcTerm(QWidget *parent = Q_NULLPTR);
	~dcTerm();

private:
	const QString TITLE_UNDETECTABLE = "dcTerm - Unable to Detect Any Ports";
	const QString TITLE_CONNECTED = "dcTerm - Connected on %1";
	const QString TITLE_CONNECTING = "dcTerm - Connecting...";
	const QString TITLE_DISCONNECTED = "dcTerm - Disconnected";

	const QString ERROR_CANNOT_OPEN = "An error occured while openning port.";

	const QString PORT_LABEL_TEXT = " Port: %1 ";
	const QString BIT_RATE_LABEL_TEXT = " Baud Rate: %1 ";
	const QString DATA_BIT_LABEL_TEXT = " Data Bits: %1 ";
	const QString PARITY_LABEL_TEXT = " Parity: %1 ";
	const QString STOP_BITS_LABEL_TEXT = " Stop Bits: %1 ";
	const QString FLOW_CONTROL_LABEL_TEXT = " Flow Control: %1 ";

	Ui::dcTermClass ui;
	Console* console;

	QLabel* mPortLabel;
	QLabel* mBitRateLabel;
	QLabel* mDataBitsLabel;
	QLabel* mParityLabel;
	QLabel* mStopBitsLabel;
	QLabel* mControlLabel;

	QSerialPort* mPort;

	QString mPortName;
	qint32 mBitRate;
	QSerialPort::DataBits mDataBits;
	QSerialPort::Parity mParity;
	QSerialPort::StopBits mStopBits;
	QSerialPort::FlowControl mControl;

	void initMenuConnections();
	void populatePortMenu();
	void createConsole();
	void initStatusBarLabels();

private slots:
	void startConnection();
	void stopConnection();

	void setBitRate();
	void setDataBits();
	void setParity();
	void setStopBits();
	void setFlowControl();

	void selectPort();

	void writeToPort(QByteArray &data);
	void readFromPort();
};
