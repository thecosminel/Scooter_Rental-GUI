#ifndef SCOOTER_RENTAL_GUI_QT_MAINGUI_H
#define SCOOTER_RENTAL_GUI_QT_MAINGUI_H

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

#include <utility>
#include <vector>


#include "../UI/ConcreteUI.h"
#include "../Utils/data_validation_functions.h"
#include "../Utils/UI_printFunctions.h"
#include "../Utils/GUI_enterData.h"
#include "../Utils/GUI_printFunctions.h"


using utils::doubleToString, utils::getScooterStatusString;
using ui::ConcreteUI;


namespace gui
{
    enum UserType
    {
        Manager,
        User
    };


    class MainGUI : public ConcreteUI, public QWidget {
    private:
        QTableWidget *tableWidget_;
        vector<Scooter> scooters;
        UserType me;

    // Qt stuff
        void populateTable(const vector<Scooter>& scootersVec);
        void setUpTable();

        void handleCellClicked(int row, int column);

    public:
        explicit MainGUI(QWidget *parent = nullptr);
        ~MainGUI() override;

        // ------------------------
        // Control methods
        void runGui();

        /// Run manager
        /// \return
        bool runManager();

        /// Run user
        /// \return
        bool runUser();

        void selectUserType();

        /// Log in manager
        void logInAsManager();

        /// Log in user
        void logInAsUser();

        // Implement from abstract
        void printScooterContainer(vector<Scooter> scootersVec) override;

        void printMessage(std::string message) override;
    };
}


#endif //SCOOTER_RENTAL_GUI_QT_MAINGUI_H
