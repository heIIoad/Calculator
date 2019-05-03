#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Calculator.h"

class Calculator : public QMainWindow
{
	Q_OBJECT

public:
	Calculator(QWidget *parent = Q_NULLPTR);

private:
	Ui::CalculatorClass ui;
	double valueStored=0;

private slots:
	void numberButton();
	//void mathButton();
	//void sumButton();
	//void plusMinus();
};
