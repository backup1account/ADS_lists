#include <iostream>

struct node
{
    int x; 
    node *left; 
    node *right; 
    node *parent;

    node(int x0,  node* p=nullptr, node* l=nullptr, node* r=nullptr) : x(x0), parent(p), left(l), right(r) {}
};


void insert(node *&t, int x)
{
	int i = 0;
	node **t1 = &t;
    node *parent = nullptr;

	while(*t1)
    {
		i++;
        parent = *t1;

        if(x < (*t1)->x) {
            t1 = &((*t1)->left);
		}
        else {
            t1 = &((*t1)->right);
		}	
	}

	*t1 = new node(x, parent);
}


class BSTiter
{
private: 
    node *t1;

public: 
    BSTiter(node *t = nullptr) : t1(t) {}

    bool operator!=(BSTiter t) const // operator porównywania 
    {
		return t1 != t.t1;
	}

    int operator*() const // zwracamy wartość wskazywaną przez wskaźnik
    {
        return t1->x; 
    }

    BSTiter operator++()
    {
        if (t1->right)
        {
            t1 = t1->right;
            while (t1->left) // szukamy najmniejszego elementu
            {
                t1 = t1->left;
            }
            return t1;
        }

        while (t1->parent && t1 == t1->parent->right) // sprawdzamy czy istnieje rodzic 
        {
			t1 = t1->parent;
		}

        if (!t1->parent)
        {
            t1 = nullptr;  
            return t1;
        }
        
        t1 = t1->parent;
        return t1;
    }
};


BSTiter begin(node *t) // zwraca wskaźnik do elementu o najmniejszej wartości
{
    while(t && t->left)
    {
        t = t->left;
    }
    return BSTiter(t);
}

BSTiter end(node *t) // zwracamy pusty wskaźnik
{
    return BSTiter(nullptr);
}


int main()
{
    node *root = nullptr;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    for (BSTiter i = begin(root); i != end(root); ++i)
    {
        std::cout << *i << '\t';
    }

    std::cout << '\n';

    for (auto x : root)
    {
        std::cout << x << '\t';
    }

    return 0;
}