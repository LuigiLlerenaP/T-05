#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

void insert(Node *&head, int number)
{
    Node *newNode = new Node{number, nullptr};

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->value << " -> ";
        head = head->next;
    }
}

void loadMultiplesOfFive(Node *&list, int limit)
{
    for (int i = 5; i <= limit; i += 5)
    {
        insert(list, i);
    }
}
void loadEvenNumbers(Node *&list, int limit)
{
    for (int i = 2; i <= limit; i += 2)
    {
        insert(list, i);
    }
}
bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

void loadPrimes(Node *&list, int limit)
{
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime(i))
        {
            insert(list, i);
        }
    }
}
void loadFibonacci(Node *&list, int limit)
{
    int a = 0, b = 1;
    while (a <= limit)
    {
        insert(list, a);
        int next = a + b;
        a = b;
        b = next;
    }
}

int main(int argc, char const *argv[])
{
    Node *multiplesOfFive = nullptr;
    Node *evenNumbers = nullptr;
    Node *primes = nullptr;
    Node *fibonacci = nullptr;

    int limit = 25;

    loadMultiplesOfFive(multiplesOfFive, limit);
    loadEvenNumbers(evenNumbers, limit);
    loadPrimes(primes, limit);
    loadFibonacci(fibonacci, limit);

    cout << "Multiplos de 5: ";
    printList(multiplesOfFive);
    cout << endl;

    cout << "Numeros pares: ";
    printList(evenNumbers);
    cout << endl;

    cout << "Numeros primos: ";
    printList(primes);
    cout << endl;

    cout << "Secuencia de Fibonacci: ";
    printList(fibonacci);
    cout << endl;

    return 0;
}
