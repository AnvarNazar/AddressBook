#include "addressbookcontroller.h"

AddressBookController::AddressBookController(AddressBook *addressBook,
                                             QObject *parent) :
    QObject(parent),
    _addressBook(addressBook)
{
    Q_ASSERT(addressBook != nullptr);
}

AddressBookEntry *AddressBookController::createEntry()
{
    auto result = _addressBook->createEntry();
    if (result != nullptr) {
        result->setName(tr("New Entry...."));
    }
    return result;
}

bool AddressBookController::deleteEntry(AddressBookEntry *entry)
{
    return _addressBook->deleteEntry(entry);
}
