#include "Calculator.h"
#include <QtCore\QString>
#include <QtDebug>

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
		connect(numButtons[i], SIGNAL(released()),SLOT(numberButton()));
		connect(ui.buttonDiv, SIGNAL(released()),SLOT(mathButton()), Qt::UniqueConnection);
		connect(ui.buttonSum, SIGNAL(released()),SLOT(mathButton()), Qt::UniqueConnection);
		connect(ui.buttonSub, SIGNAL(released()),SLOT(mathButton()), Qt::UniqueConnection);
		connect(ui.buttonMulti, SIGNAL(released()),SLOT(mathButton()), Qt::UniqueConnection);
		connect(ui.buttonEqual, SIGNAL(released()),SLOT(equalButton()), Qt::UniqueConnection);
		connect(ui.buttonClear, SIGNAL(released()),SLOT(Clear()), Qt::UniqueConnection);
		connect(ui.buttonSign, SIGNAL(released()),SLOT(plusMinus()), Qt::UniqueConnection);
	}
}

void Calculator::numberButton()
{
	QPushButton* currentButton =(QPushButton*)sender();
	if (this->problemSolved == true)
	{
		this->problemSolved = false;
		ui.Display->setText("0");
		this->secondNumberStored = this->conditionCheck;
	}
	if (this->mathButtonPressed == true)
	{
		this->mathButtonPressed = false;
		ui.Display->setText("0");
	}
	QString buttonValue = currentButton->text();
	QString displayValue = ui.Display->text();
	if (displayValue == "0")
	{
		ui.Display->setText(buttonValue);
	}
	else
	{
		if (displayValue.size() < 12) {
		displayValue += buttonValue;
		}

		double newValue=displayValue.toDouble();
		ui.Display->setText(QString::number(newValue,'g',12));
	}
}

void Calculator::mathButton()
{
	QPushButton* currentButton = (QPushButton*)sender();
	QString displayValue = ui.Display->text();
	if(displayValue!="")
	{
		this->valueStored = displayValue.toDouble();
		this->problemSolved = false;
	}
	QString buttonValue = currentButton->text();
	this->currentMath = buttonValue;
	this->mathButtonPressed = true;
}

void Calculator::equalButton()
{
	QString displayValue = ui.Display->text();
	if (this->double_equals(displayValue.toDouble(),this->valueStored) && this->problemSolved == true)
	{
		if (this->secondNumberStored != this->conditionCheck)
			displayValue = QString::number(this->secondNumberStored);
		else
			displayValue = QString::number(this->valueStored);
	}
	double secondNumber = displayValue.toDouble();
	this->secondNumberStored = secondNumber;
	if (this->currentMath == "+")
		this->valueStored += secondNumber;
	else if (this->currentMath == "-")
		this->valueStored -= secondNumber;
	else if (this->currentMath == "/")
		this->valueStored /= secondNumber;
	else if (this->currentMath == "*")
		this->valueStored *= secondNumber;
	ui.Display->setText(QString::number(valueStored, 'g', 12));
	this->problemSolved = true;
}

void Calculator::Clear()
{
	this->valueStored = 0;
	this->secondNumberStored = this->conditionCheck;
	this->currentMath = "";
	ui.Display->setText("0");
	this->problemSolved = false;
}

void Calculator::plusMinus()
{
	QString displayValue = ui.Display->text();
	double value = displayValue.toDouble();
	value *= -1;
	ui.Display->setText(QString::number(value));
}
