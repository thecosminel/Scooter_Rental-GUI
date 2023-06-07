#include "MainGUI.h"

namespace gui
{
    MainGUI::MainGUI(QWidget *parent)
    {
        tableWidget_ = new QTableWidget(this);
        Scooter scooter1("abc", "Cube", "30.10.2010", 300, "Bosanci", scooter::PARKED);
        Scooter scooter2("xyz", "MTB", "12.11.2022", 300, "Ipotesti", scooter::MAINTENANCE);
        scooters.push_back(scooter1);
        scooters.push_back(scooter2);
        populateTable();
    }

    MainGUI::~MainGUI()
    {
        delete tableWidget_;
    }

    // Qt stuff
    void MainGUI::populateTable()
    {
        int rowSize = static_cast<int>(scooters.size());
        tableWidget_->setRowCount(rowSize);
        for (int i = 0; i < rowSize; ++i)
        {
            const Scooter& scooter = scooters[i];
            auto* id = new QTableWidgetItem(QString::fromStdString(scooter.getIdentifier()));
            auto* model = new QTableWidgetItem(QString::fromStdString(scooter.getModel()));
            auto* date = new QTableWidgetItem(QString::fromStdString(scooter.getDate()));
            auto* km = new QTableWidgetItem(QString::fromStdString(doubleToString(scooter.getKilometers())));
            auto* location = new QTableWidgetItem(QString::fromStdString(scooter.getLocation()));
            auto* status = new QTableWidgetItem(QString::fromStdString(getScooterStatusString(scooter.getStatus())));

            tableWidget_->setItem(i, 0, id);
            tableWidget_->setItem(i, 1,  model);
            tableWidget_->setItem(i, 2, date);
            tableWidget_->setItem(i, 3, km);
            tableWidget_->setItem(i, 4, location);
            tableWidget_->setItem(i, 5, status);
        }

        // Resize to fit
        tableWidget_->resizeColumnsToContents();
    }


    // Implement from abstract
    void MainGUI::printScooterContainer(vector<scooter::Scooter>)
    {
        cout << "To be implemented";
    }

    void MainGUI::printMessage(std::string message)
    {
        cout << "To be implemented";
    }

}