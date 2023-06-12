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
#include <QMessageBox>
#include <QTextEdit>
#include <QTextBrowser>

#include <utility>
#include <vector>


#include "../ConcreteUI.h"
#include "../Utils/data_validation_functions.h"
#include "../Utils/UI_printFunctions.h"
#include "../Utils/GUI_enterData.h"
#include "../Utils/GUI_printFunctions.h"


using utils::doubleToString, utils::getScooterStatusString;
using ui::ConcreteUI;


namespace gui
{
    /// User type
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
        /// Print table
        /// \param scootersVec
        void populateTable(const vector<Scooter>& scootersVec);
        /// Initial table setting
        void setUpTable();

        /// Handle cell clicked in table
        /// \param row
        /// \param column
        void handleCellClicked(int row, int column);

    public:
        /// Constructor
        /// \param parent
        explicit MainGUI(QWidget *parent = nullptr);
        /// Destructor
        ~MainGUI() override;

        // ------------------------
        // Control methods
        /// Use to run the GUI
        void runGui();

        /// Run manager
        /// \return
        bool runManager();

        /// Run user
        /// \return
        bool runUser();

        /// Select user type Manager/User
        void selectUserType();

        /// Log in manager
        void logInAsManager();

        /// Log in user
        void logInAsUser();

        // Implement from abstract
        /// Implement print scooter container
        /// \param scootersVec
        void printScooterContainer(vector<Scooter> scootersVec) override;

        /// Print message
        /// \param message
        void printMessage(std::string message) override;

        // ------------------------
        // Manager & User methods
        // Sort all
        /// Sort by id
        void displayAllScootersSortedByID();

        /// Sort by km
        void displayAllScootersSortedByModel();
        /// Sort by age
        void displayAllScootersSortedByAge();
        /// Sort by km
        void displayAllScootersSortedByKm();
        /// Sort by location
        void displayAllScootersSortedByLocation();
        /// Sort by status
        void displayAllScootersSortedByStatus();
        // Filter
        /// Display all parked
        void displayAllParkedScooters();
        /// Search by loc
        void searchScooterByLocation();
        /// Filter dates
        void displayScootersFilteredByDates();
        /// Filter km
        void displayScootersFilteredByKm();

        // -------------------------
        // Manager UI only
        /// Add new scooter
        void addNewScooter();
        /// Delete scooter
        void deleteExistingScooter();
        /// Modify scooter
        void modifyExistingScooter();

        /// Show detailed scooter
        void showDetailed();

        // -------------------------
        // User UI only
        /// Reserve scooter
        void reserveScooter();
        /// Park scooter
        void parkScooter();
        /// Use scooter
        void useScooter();
        /// Display my scooter
        void displayMyScooters();
    };
}


#endif //SCOOTER_RENTAL_GUI_QT_MAINGUI_H
