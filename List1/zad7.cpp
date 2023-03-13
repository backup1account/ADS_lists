#include <iostream>

struct lnode
{ 
    int key;
    lnode *next;
    lnode(int k, lnode* n=nullptr) : key(k), next(n) {}
};

void wypisz(lnode* L)
{
    lnode* current = L;

    while (current)
    {
        std::cout << current->key << ' ';
        current = current->next;
    }
    std::cout << '\n';
}


void insert(lnode* &L, int x)
{
    L = new lnode(x, L);
}

// zadanie 7
void reverse(lnode* &L)
{
    lnode* previous = nullptr;
    lnode* current = L;
    lnode* next = nullptr;

    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    L = previous;
}


int main()
{
    int size = 6;
    lnode* List = nullptr;

    for (size_t i = 0; i < size; ++i)
    {
        insert(List, i);
    }

    std::cout << "Elementy listy przed odwroceniem: ";
    wypisz(List);

    std::cout << "Elementy listy po odwroceniu: ";
    reverse(List);
    wypisz(List);

    return 0;
}