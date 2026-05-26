#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string randomName();
string randomPhone();
string randomDate();
int randomIndex();
int dateSum(string date);

string firstNames[10] = {
    "Artem", "Dmitry", "Nikita", "Roman", "Olga",
    "Anna", "Elena", "Pavel", "Diana", "Sergey"
};

string lastNames[10] = {
    "Smirnov", "Volkov", "Kuznetsov", "Orlov", "Morozov",
    "Sokolov", "Lebedev", "Novikov", "Fedorov", "Makarov"
};

string middleNames[10] = {
    "Andreevich", "Petrovich", "Olegovich", "Denisovich", "Romanovich",
    "Igorevich", "Viktorovich", "Pavlovich", "Nikolaevich", "Mikhailovich"
};

string phoneList[10] = {
    "79001234567", "79117654321", "79223334455", "79339876543", "79445556677",
    "79551239876", "79663451278", "79774567890", "79885673412", "79996784523"
};

string birthDates[10] = {
    "12/03/1995", "25/11/1988", "07/06/2002", "19/01/1999", "30/09/1991",
    "03/04/1985", "14/12/1996", "22/08/2000", "09/10/1993", "17/05/1987"
};

int collisions = 0;

struct Person
{
    string fullName;
    string phone;
    string birthDate;

    Person()
    {
        fullName = "EMPTY";
        phone = "EMPTY";
        birthDate = "EMPTY";
    }
};

struct HashTable
{
    Person* data;

    HashTable(int size)
    {
        data = new Person[size];
    }

    ~HashTable()
    {
        delete[] data;
    }

    bool insertPerson(Person person, int size);
    void deletePerson(string birthDate, int size);
    void findPerson(string birthDate, int size);
};

Person createPerson()
{
    Person person;

    person.fullName = randomName();
    person.phone = randomPhone();
    person.birthDate = randomDate();

    return person;
}

int hashFunction(string date, int size)
{
    double value = 0.271 * dateSum(date);
    double fractionalPart = value - int(value);

    return int(fractionalPart * size);
}

bool HashTable::insertPerson(Person person, int size)
{
    int index = hashFunction(person.birthDate, size);
    int startIndex = index;

    while (data[index].fullName != "EMPTY")
    {
        collisions++;
        index = (index + 1) % size;

        if (index == startIndex)
        {
            return false;
        }
    }

    data[index] = person;
    return true;
}

void HashTable::deletePerson(string birthDate, int size)
{
    int index = hashFunction(birthDate, size);
    int startIndex = index;

    do
    {
        if (data[index].birthDate == birthDate)
        {
            data[index] = Person();
            cout << "Record with date " << birthDate << " deleted." << endl;
            return;
        }

        index = (index + 1) % size;

    } while (index != startIndex);

    cout << "Record with date " << birthDate << " not found." << endl;
}

void HashTable::findPerson(string birthDate, int size)
{
    int index = hashFunction(birthDate, size);
    int startIndex = index;

    do
    {
        if (data[index].birthDate == birthDate)
        {
            cout << "Found date: " << birthDate << endl;
            cout << "Hash table index: " << index << endl;
            return;
        }

        index = (index + 1) % size;

    } while (index != startIndex);

    cout << "Date " << birthDate << " not found." << endl;
}

void fillArray(Person* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = createPerson();
    }
}

void printPerson(Person person)
{
    cout << "------------------------------" << endl;
    cout << "Full name: " << person.fullName << endl;
    cout << "Phone: " << person.phone << endl;
    cout << "Birth date: " << person.birthDate << endl;
    cout << "------------------------------" << endl;
}

void printTable(HashTable& table, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Index: " << i << endl;
        printPerson(table.data[i]);
    }
}

int dateSum(string date)
{
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    return day + month + year;
}

string randomName()
{
    return lastNames[randomIndex()] + " " + firstNames[randomIndex()] + " " + middleNames[randomIndex()];
}

string randomPhone()
{
    return phoneList[randomIndex()];
}

string randomDate()
{
    return birthDates[randomIndex()];
}

int randomIndex()
{
    return rand() % 10;
}

int main()
{
    srand(time(0));

    int size;
    string date;

    cout << "Enter hash table size: ";
    cin >> size;

    Person* people = new Person[size];
    HashTable table(size);

    fillArray(people, size);

    for (int i = 0; i < size; i++)
    {
        if (!table.insertPerson(people[i], size))
        {
            cout << "Hash table is full. Element was not added." << endl;
            break;
        }
    }

    cout << endl << "Hash table:" << endl;
    printTable(table, size);

    cout << endl << "Enter date to search: ";
    cin >> date;

    cout << endl;
    table.findPerson(date, size);

    cout << endl << "Enter date to delete: ";
    cin >> date;

    cout << endl;
    table.deletePerson(date, size);

    cout << endl << "Hash table after deleting:" << endl;
    printTable(table, size);

    cout << endl << "Number of collisions: " << collisions << endl;

    delete[] people;

    return 0;
}