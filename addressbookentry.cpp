#include "addressbookentry.h"

AddressBookEntry::AddressBookEntry(QObject *parent) : QObject(parent)
{

}

QString AddressBookEntry::name() const
{
    return _name;
}

void AddressBookEntry::setName(const QString &name)
{
    if (_name != name) {
        _name = name;
        emit nameChanged();
    }
}

QString AddressBookEntry::address() const
{
    return _address;
}

void AddressBookEntry::setAddress(const QString &address)
{
    if (_address != address) {
        _address = address;
        emit addressChanged();
    }
}

QDate AddressBookEntry::birthday() const
{
    return _birthday;
}

void AddressBookEntry::setBirthday(const QDate &birthday)
{
    if (_birthday != birthday) {
        _birthday = birthday;
        emit birthdayChanged();
    }
}

QStringList AddressBookEntry::phoneNumbers() const
{
    return _phoneNumbers;
}

void AddressBookEntry::setPhoneNumbers(const QStringList &phoneNumbers)
{
    if (_phoneNumbers != phoneNumbers) {
        _phoneNumbers = phoneNumbers;
        emit phoneNumbersChanged();
    }
}
