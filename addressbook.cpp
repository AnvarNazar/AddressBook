#include "addressbook.h"

AddressBook::AddressBook(QObject *parent) : QObject(parent)
{

}

AddressBook::Entries AddressBook::entries() const
{
    return _entries;
}

AddressBookEntry *AddressBook::createEntry()
{
    auto result = new AddressBookEntry(this);
    if (result != nullptr) {
        _entries.append(result);
        emit entryAdded(result);
    }
    return result;
}

bool AddressBook::deleteEntry(AddressBookEntry *entry)
{
    if (_entries.contains(entry)) {
        _entries.removeOne(entry);
        emit entryRemoved(entry);
        delete entry;
        return true;
    }
    return false;
}
