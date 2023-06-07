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
#include <utility>
#include <vector>

namespace gui
{
    class MainGUI : public QWidget {
    private:
        QTableWidget *tableWidget_;
    };
}


#endif //SCOOTER_RENTAL_GUI_QT_MAINGUI_H
