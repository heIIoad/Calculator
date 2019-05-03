#include "Calculator.h"
#include <QtCore\QString>

Calculator::Calculator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->QWidget::setFixedSize(300, 333);
	QPushButton* numButtons[10];

	for (int i = 0; i < 10; i++)
	{
		QString buttonLabel;
		QString buttonName;
		buttonLabel = QString::number(i);
		buttonName = "button" + buttonLabel;
		numButtons[i] = Calculator::findChild<QPushButton*>(buttonName);
		connect(numButtons[i], SIGNAL(released()), this, SLOT(numberButton()));
	}
}

void Calculator::numberButton()
{
	QPushButton* currentButton =(QPushButton*)sender();
	QString buttonValue = currentButton->text();
	QString displayValue = ui.Display->text();
	if (displayValue == "0")
	{
		ui.Display->setText(buttonValue);
	}
	else
	{
		if (displayValue.size() < 11) {
		displayValue += buttonValue;
		}

		double newValue=displayValue.toDouble();
		ui.Display->setText(QString::number(newValue,'g',11));
		this->valueStored = displayValue.toDouble();
	}

}


