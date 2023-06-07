#ifndef SCOOTER_RENTAL_GUI_GUI_ENTERDATA_H
#define SCOOTER_RENTAL_GUI_GUI_ENTERDATA_H

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
#include <QEventLoop>

#include <utility>
#include <string>

#include "data_validation_functions.h"
#include "GUI_printFunctions.h"

using std::string, std::pair;

namespace utils {
    /// Enter username and password
    /// \return
    pair<string, string> enterUsernameAndPassword();

    /// Enter identifier
    /// \return
    string enterIdentifierGUI();

    /// Enter model
    /// \return
    string enterModelGUI();

    /// Enter location
    /// \return
    string enterLocationGUI();

    /// Enter manufacturing date
    /// \return
    string enterManufacturingDateGUI();

    /// Enter km
    /// \return
    double enterKmGUI();

    /// Enter scooter status
    /// \return
    scooter::ScooterStatus enterStatusGUI();

    // Enter multiple

    /// Enter manufacturing dates (min, max)
    /// \return
    pair<string, string> enterManufacturingDatesGUI();

    /// Enter min and max km
    /// \return
    pair<double, double> enterKmMultipleGUI();

    // Modify function
    /// Choose attribute to modify
    /// \return
    char whatScooterAttributesToModifyGUI();

    // Manager menu
    /// Manager menu print and select
    /// \return
    char managerMenu();

    // User menu
    /// User menu print and select
    /// \return
    char userMenu();

    bool tryLogAgain();

} // utils

#endif //SCOOTER_RENTAL_GUI_GUI_ENTERDATA_H
