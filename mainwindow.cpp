#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(AddressBookController *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _controller(controller)
{
    ui->setupUi(this);

    setupConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createEntry()
{
    auto entry = _controller->createEntry();
    if (entry) {
        ui->listWidget->addItem(entry->name());
        auto row = ui->listWidget->count() - 1;
        auto listItem = ui->listWidget->item(row);
        _entryMap.insert(listItem, entry);
    }
}

void MainWindow::deleteEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = _entryMap.value(listItem);
        if (entry) {
            if (_controller->deleteEntry(entry)) {
                _entryMap.remove(listItem);
                delete listItem;
            }
        }
    }
}

void MainWindow::setupConnections()
{
    connect(ui->actionAdd, SIGNAL(triggered(bool)), this, SLOT(createEntry()));
    connect(ui->actionRemove, &QAction::triggered, this, &MainWindow::deleteEntry);
}
