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


lnode* merge(lnode* L1, lnode* L2)
{
    // sprawdzenie czy listy sa puste
    if (!L1) { return L2; }
    else if (!L2) { return L1; }

    lnode* result = nullptr; // wskazanie na pierwszy element
    lnode* current = nullptr; // wskazanie na element biezacy

    // dodanie pierwszego elementu (result nie moze byc nullptr)
    if (L1->key < L2->key) {
        result = L1;
        L1 = L1->next;
    } else {
        result = L2;
        L2 = L2->next;
    }

    current = result;

    while (L1 && L2)
    {
        if (L1->key <= L2->key)
        {
            current->next = L1;
            L1 = L1->next;
        }
        else
        {
            current->next = L2;
            L2 = L2->next;
        }

        current = current->next;
    }

    // nie trzeba porownywac, zostaje ostatni element
    if (!L1) { current->next = L2; }
    else { current->next = L1; }

    return result;
}


int main()
{
    lnode* L1 = new lnode(4, new lnode(5, new lnode(6)));
    lnode* L2 = new lnode(2, new lnode(7, new lnode(8)));

    lnode* result = merge(L1, L2);
    wypisz(result);

    return 0;
}