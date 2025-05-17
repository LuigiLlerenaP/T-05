#include <iostream>
#include <string>
using namespace std;

struct Newborn
{
    int id;
    string placeOfBirth;
    float weight;
    float height;
    char sex;
    int motherAge;
    Newborn *next; // Almacena la dirección en memoria del siguiente Nacido Vivo
};

void insertRecord(Newborn *&head, Newborn newRecord)
{
    Newborn *newNode = new Newborn;
    *newNode = newRecord;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode; // si es vació sera cabeza
    }
    else
    {
        Newborn *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode; // Insertar al final
    }
}

void inputData(Newborn *&list, int totalRecords)
{
    cout << "Enter data for " << totalRecords << " newborns:\n";

    for (int i = 0; i < totalRecords; i++)
    {
        Newborn newRecord;
        cout << "Record #" << (i + 1) << "\n";

        cout << "Identification number: ";
        cin >> newRecord.id;
        cin.ignore();

        cout << "Place of birth: ";
        getline(cin, newRecord.placeOfBirth);

        cout << "Birth weight (kg): ";
        cin >> newRecord.weight;

        cout << "Birth height (cm): ";
        cin >> newRecord.height;

        cout << "Sex (M/F): ";
        cin >> newRecord.sex;

        cout << "Mother's age: ";
        cin >> newRecord.motherAge;
        cin.ignore();

        newRecord.next = nullptr;

        insertRecord(list, newRecord);
        cout << "---------------------------\n";
    }
}

void calculateAveragesAndFree(Newborn *&list)
{
    if (list == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    float totalWeight = 0, totalHeight = 0;
    int totalMotherAge = 0;
    int count = 0;

    Newborn *current = list;
    while (current != nullptr)
    {
        totalWeight += current->weight;
        totalHeight += current->height;
        totalMotherAge += current->motherAge;
        count++;
        current = current->next;
    }

    cout << "\nAverage Results:\n";
    cout << "Average weight: " << totalWeight / count << " kg\n";
    cout << "Average height: " << totalHeight / count << " cm\n";
    cout << "Average mother's age: " << static_cast<float>(totalMotherAge) / count << " years\n";

    // Free memory
    while (list != nullptr)
    {
        Newborn *temp = list;
        list = list->next;
        delete temp;
    }
}

int main()
{
    Newborn *list = nullptr;
    int totalRecords = 3;

    inputData(list, totalRecords);

    calculateAveragesAndFree(list);

    return 0;
}
