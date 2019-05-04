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
	double conditionCheck = 0.000000000000021;
	double secondNumberStored = 0.000000000000021;
	QString currentMath="";
	bool problemSolved = false;
	bool mathButtonPressed = false;

	bool double_equals(double a, double b, double epsilon = 0.001)
	{
		return std::abs(a - b) < epsilon;
	}

private slots:
	void numberButton();
	void mathButton();
	void equalButton();
	void Clear();
	void plusMinus();
};
