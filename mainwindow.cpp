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
    }
}

void MainWindow::setupConnections()
{
    connect(ui->actionAdd, SIGNAL(triggered(bool)),
            this, SLOT(createEntry()));
}
