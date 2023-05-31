#ifndef SCOOTER_RENTAL_GUI_MAINUI_H
#define SCOOTER_RENTAL_GUI_MAINUI_H

#include "ConcreteUI.h"
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

        void run();

        bool runManager();

        bool runUser();

        void logIn();

    };

} // ui

#endif //SCOOTER_RENTAL_GUI_MAINUI_H
