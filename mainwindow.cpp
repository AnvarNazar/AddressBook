#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>

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

void MainWindow::editEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = _entryMap.value(listItem);
        if (entry) {
            ui->stackedWidget->setCurrentWidget(ui->detailsPage);
            ui->menuEntries->setEnabled(false);
            resetEntry();
        }
    }
}

void MainWindow::saveEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = _entryMap.value(listItem);
        if (entry) {
            entry->setName(ui->nameEdit->text());
            // ui->nameEdit->setText(entry->name());

            entry->setBirthday(ui->birthDayEdit->date());
            // ui->birthDayEdit->setDate(entry->birthday());

            entry->setAddress(ui->addressEdit->toPlainText());
            // ui->addressEdit->setPlainText(entry->address());

            entry->setPhoneNumbers(ui->phoneNumbersEdit->toPlainText().split("\n"));
            // ui->phoneNumbersEdit->setPlainText(entry->phoneNumbers().join("\n"));

            // update address entry name in the listWidget item
            listItem->setText(entry->name());

            // this will cause stack widget to return to the listPage
            discardEntry();
        }
    }
}

void MainWindow::discardEntry()
{
    ui->stackedWidget->setCurrentWidget(ui->listPage);
    ui->menuEntries->setEnabled(true);
}

void MainWindow::resetEntry()
{
    auto listItem = ui->listWidget->currentItem();
    if (listItem) {
        auto entry = _entryMap.value(listItem);
        if (entry) {
            ui->nameEdit->setText(entry->name());
            ui->birthDayEdit->setDate(entry->birthday());
            ui->addressEdit->setPlainText(entry->address());
            ui->phoneNumbersEdit->setPlainText(entry->phoneNumbers().join("\n"));
        }
    }
}

void MainWindow::setupConnections()
{
    connect(ui->actionAdd, SIGNAL(triggered(bool)), this, SLOT(createEntry()));
    connect(ui->actionRemove, &QAction::triggered, this, &MainWindow::deleteEntry);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::editEntry);

    connect(ui->buttonBox->button(QDialogButtonBox::Save),&QPushButton::clicked,
            this,&MainWindow::saveEntry);
    connect(ui->buttonBox->button(QDialogButtonBox::Discard),&QPushButton::clicked,
            this,&MainWindow::discardEntry);
    connect(ui->buttonBox->button(QDialogButtonBox::Reset),&QPushButton::clicked,
            this,&MainWindow::resetEntry);
}
