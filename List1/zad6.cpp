#include <iostream>

struct lnode
{ 
    int key;
    lnode *next;
    lnode(int k, lnode* n=nullptr) : key(k), next(n) {}
};


// a)
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

// b)
int suma(lnode* L)
{
    int result = 0;
    lnode* current = L;

    while (current)
    {
        result += current->key;
        current = current->next;
    }
    return result;
}

// c)
int nty(int n, lnode* L)
{
    if (!L) { return 0; }

    int size = 0;
    lnode* current = L;

    while (current)
    {
        size++;
        current = current->next;
    }

    if (size > n) { return 0; }
    current = L;

    for (size_t i = 0; i < n; ++i)
    {
        current = current->next;
    }
    
    return current->key;
}

// d)
void insert(lnode* &L, int x)
{
    L = new lnode(x, L);
}

// e)
void insert_after_smaller(lnode *&L, int x)
{
    lnode* previous = nullptr;
    lnode* current = L;

    while (current && current->key < x)
    {
        previous = current;
        current = current->next;
    }

    lnode* result = new lnode(x, current);

    if (!previous) { L = result; }
    else
    {
        previous->next = result;
    }
}

// f)
void remove(lnode* &L, int x)
{
    lnode* previous = nullptr;
    lnode* current = L;

    while (current)
    {
        if (current->key == x)
        {
            if (!previous)
            {
                L = current->next;
                delete current;
                current = L;
            }
            else
            {
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

// g)
void filter(lnode* &L, bool(*cond)(int))
{
    lnode* previous = nullptr;
    lnode* current = L;

    while (current)
    {
        if (!cond(current->key))
        {
            if (!previous)
            {
                L = current->next;
                delete current;
                current = L;
            }
            else
            {
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

// h)
void destroy(lnode* &L)
{
    while (L)
    {
        lnode* element = L;
        L = L->next;
        delete element;
    }
}


bool filter_cond(int x) {
    return x % 2 == 0;
}


int main()
{
    int size = 10;
    lnode* List = nullptr;

    for (size_t i = 6; i < size; ++i)
    {
        insert(List, i);
    }

    std::cout << "Elementy listy: ";
    wypisz(List);
    std::cout << "Suma elementow: " << suma(List) << '\n';

    insert_after_smaller(List, 2);
    insert_after_smaller(List, 34);
    std::cout << "Po wstawieniu elementow: ";
    wypisz(List);

    remove(List, 7);
    std::cout << "Po usunieciu elementu o wartosci 7: ";
    wypisz(List);

    filter(List, filter_cond);
    std::cout << "Po wywolaniu funkcji filter (usuwa nieparzyste): ";
    wypisz(List);
    
    return 0;
}