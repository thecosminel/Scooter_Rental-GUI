#ifndef SCOOTER_RENTAL_GUI_MAINUI_H
#define SCOOTER_RENTAL_GUI_MAINUI_H

#include "../ConcreteUI.h"
#include "../../Utils/UI_enterData.h"

using namespace utils;
using ui::ConcreteUI;

namespace ui
{

    class MainUI : public ConcreteUI{
    public:
        // ------------------------
        // Constructors & destructors
        /// Default constructor
        MainUI() = default;

        /// Default copy constructor
        /// \param ui
        MainUI(const MainUI &ui) = default;

        /// Default assigment operator constructor
        /// \param ui
        /// \return
        MainUI &operator=(const MainUI &ui) = default;

        /// Default destructor
        ~MainUI() = default;

        // ------------------------
        // Control methods
        /// Run main
        void run();

        /// Run manager
        /// \return
        bool runManager();

        /// Run user
        /// \return
        bool runUser();

        /// Log in manager
        void logInAsManager();

        /// Log in user
        void logInAsUser();

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

        // Printing methods
        /// Print scooters container
        /// \param scooters
        void updateScooterContainer(vector<Scooter> scooters) override;

        /// Print message
        /// \param message
        void updateMessage(string message) override;

    };

} // ui

#endif //SCOOTER_RENTAL_GUI_MAINUI_H
