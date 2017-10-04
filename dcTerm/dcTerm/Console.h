#pragma once
#include <QPlainTextEdit>

class Console
	: public QPlainTextEdit
{
	Q_OBJECT

public:
	explicit Console(QWidget *parent = nullptr);

	void DisplayData(const QByteArray &data);

protected:
	void keyPressEvent(QKeyEvent* e) Q_DECL_OVERRIDE;

signals:
	void emitKeyPressed(QByteArray &data);
};