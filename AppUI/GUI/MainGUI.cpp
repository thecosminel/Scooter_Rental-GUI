#include "MainGUI.h"

namespace gui
{
    MainGUI::MainGUI(QWidget *parent)
    {
        tableWidget_ = new QTableWidget(this);
//        Scooter scooter1("abc", "Cube", "30.10.2010", 300, "Bosanci", scooter::PARKED);
//        Scooter scooter2("xyz", "MTB", "12.11.2022", 300, "Ipotesti", scooter::MAINTENANCE);
//        scooters.push_back(scooter1);
//        scooters.push_back(scooter2);
        setUpTable();
    }

    MainGUI::~MainGUI()
    {
        delete tableWidget_;
    }

    void MainGUI::runGui()
    {
        setGeometry(200, 200, 1000, 600);
        callVectorSort(Operations::SortedId);
        show();
    }

    // Qt stuff
    void MainGUI::setUpTable()
    {
        auto *layout = new QVBoxLayout(this);

        tableWidget_->setColumnCount(6);
        tableWidget_->setHorizontalHeaderLabels(
                {"Identifier", "Model", "Commissioned Date", "Km", "Location", "Status"});
        tableWidget_->horizontalHeader()->setStretchLastSection(true);
        tableWidget_->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        tableWidget_->verticalHeader()->setVisible(false);
        tableWidget_->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_->setStyleSheet("QTableView { border: none; background-color: #ffffff; }"
                                    "QTableView::item { padding: 10px; }"
                                    "QHeaderView::section { background-color: #f0f0f0; }");

        //Connect stuff
        connect(tableWidget_, &QTableWidget::cellClicked, this, &MainGUI::handleCellClicked);
        // End connect

        layout->addWidget(tableWidget_);
        setLayout(layout);
        setStyleSheet("QWidget { background-color: #f5f5f5; }");
    }

    void MainGUI::populateTable(const vector<Scooter>& scootersVec)
    {
//        delete tableWidget_;
//        tableWidget_ = new QTableWidget(this);
//        setUpTable();
        // Clear old table
        tableWidget_->clear();


        int rowSize = static_cast<int>(scootersVec.size());
        tableWidget_->setRowCount(rowSize);
        for (int i = 0; i < rowSize; ++i)
        {
            const Scooter& scooter = scootersVec[i];
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

    void MainGUI::handleCellClicked(int row, int column)
    {
        // Sort the table based on the clicked column
//        tableWidget_->sortByColumn(column, Qt::AscendingOrder);
        switch (column) 
        {
            case 0:
                ui::ConcreteUI::callVectorSort(Operations::SortedId);
                break;
            case 1:
                ui::ConcreteUI::callVectorSort(Operations::SortedModel);
                break;
            case 2:
                ui::ConcreteUI::callVectorSort(Operations::SortedDate);
                break;
            case 3:
                ui::ConcreteUI::callVectorSort(Operations::SortedKm);
                break;
            case 4:
                ui::ConcreteUI::callVectorSort(Operations::SortedLocation);
                break;
            case 5:
                ui::ConcreteUI::callVectorSort(Operations::SortedStatus);
                break;
            default:
                break;
        }
    }


    // Implement from abstract
    void MainGUI::printScooterContainer(vector<Scooter> scootersVec)
    {
        populateTable(scootersVec);
    }

    void MainGUI::printMessage(std::string message)
    {
        cout << "To be implemented";
    }




}