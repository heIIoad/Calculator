#include "Calculator.h"

Calculator::Calculator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->QWidget::setFixedSize(300, 333);
}

