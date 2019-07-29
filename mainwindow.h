#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <addressbookcontroller.h>

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}

class QListWidgetItem;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(AddressBookController *controller, QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void createEntry();
    void deleteEntry();
    void editEntry();
    void saveEntry();
    void discardEntry();
    void resetEntry();

private:
    Ui::MainWindow *ui;
    AddressBookController *_controller;
    QHash<QListWidgetItem*, AddressBookEntry *> _entryMap;

    void setupConnections();
};

#endif // MAINWINDOW_H
