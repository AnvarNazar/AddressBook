#ifndef ADDRESSBOOKCONTROLLER_H
#define ADDRESSBOOKCONTROLLER_H

#include "addressbook.h"

#include <QObject>

class AddressBookController : public QObject
{
    Q_OBJECT
public:
    explicit AddressBookController(AddressBook *addressBook, QObject *parent = nullptr);

    AddressBookEntry *createEntry();
    bool deleteEntry(AddressBookEntry *entry);

signals:

public slots:

private:
    AddressBook *_addressBook;

};

#endif // ADDRESSBOOKCONTROLLER_H
