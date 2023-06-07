#ifndef SCOOTERRENTAL_GUI_GUI_PRINTFUNCTIONS_H
#define SCOOTERRENTAL_GUI_GUI_PRINTFUNCTIONS_H

#include <QApplication>
#include <QDebug>
#include <QVBoxLayout>
#include <QWidget>
#include <QHeaderView>
#include <QDate>
#include <QTableWidget>
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QCheckBox>
#include <QLabel>
#include <QRadioButton>
#include <QButtonGroup>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>


#include <string>

using std::string;

namespace utils
{
    void printMessageWithQt(const std::string& errorMessage);


} // utils

#endif //SCOOTERRENTAL_GUI_GUI_PRINTFUNCTIONS_H
