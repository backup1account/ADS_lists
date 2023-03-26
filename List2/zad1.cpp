#include <iostream>

struct node
{
    int x; 
    node *left; 
    node *right; 
    node *parent;

    node(int x0,  node* p=nullptr, node* l=nullptr, node* r=nullptr) : x(x0), parent(p), left(l), right(r) {}
};

void inOrder(node *t)
{
	if (t)
	{
		inOrder(t->left);
		std::cout << t->x << " ";
		inOrder(t->right);
	}
}


void insert(node *&t, int x)
{
	int i = 0;
	node **t1 = &t; // wskaźnik na miejsce w pamięci, gdzie leży wskaźnik ktory pokazuje na adres w pamięci, gdzie leży t
    node *parent = nullptr;

    // znajdywanie wskaźnika na null, gdzie należy podczepić x
	while(*t1)
    {
		i++;
        parent = *t1; // przypisujemy wskaźnikowi rodzica wskaźnik na t1

        if(x < (*t1)->x) // (*t1) Dostęp do danych struktury za pośrednictwem wskaźnika wskazującego na nią
        {
			// std::cout << "Porównywanie: " << x << " z " << (*t1)->x << '\n';
            t1 = &((*t1)->left); // adres komórki zostaje przesunięty o 1 w lewo
		}
        else 
        {
			// std::cout << "Porównywanie: " << x << " z " << (*t1)->x << '\n';
            t1 = &((*t1)->right);
		}	
	}  
	*t1 = new node(x, parent); // w momencie wyjścia z pętli i natrafieniu na null zostaje doczepiony x
                            // nowy węzeł musi "znać" swojego rodzica. Inne już go znają

	// std::cout << "Liczba porównań: " << i << '\n';
}  


void remove(node *&t, int x)
{
	node **t1 = &t;
	while (*t1 && (*t1) -> x!=x) // znajdź wskaźnik na węzeł zawierający x
    {
        if(x < (*t1)->x) 
        {
            t1 = &(*t1)->left;
        }
        else 
        {
            t1 = &(*t1)->right;
        }
    }

	if(*t1) // jeśli wskaźnik znaleziono 
	{
		if((*t1)->right && (*t1)->left) // jeśli ma dwóch synów
		{                               
			node **t2 = &(*t1)->right; // zaczynając od prawego syna

			while ((*t2)->left)      // idź w lewo póki można
			{
            	t2 = &(*t2)->left;     // docelowo t2 to minimum prawego poddrzewa 
            }

			(*t1)->x = (*t2)->x;   // skopiuj klucz do "usuwanego" węzła 
			t1 = t2;                   // i zamiast niego przeznacz ten do usunięcia
		}	

		// tutaj *t1 ma już co najwyżej jednego syna
        node *son;
        if ((*t1)->right) {
            son = (*t1)->right;
        }
        else {
            son = (*t1)->left;
        }

		// *t1 jest  tym  wskaźnikiem w drzewie, który wskazuje na węzeł do usunięcia!
        if (son) { // jeśli nie jest nullem
		    son->parent = (*t1)->parent; //wskaźnik strzałkowy syna na rodzica któremy przypisujemy wskaźnik struktury (t1) na rodzica
        }
        
        delete *t1;  // usuwamy węzeł
		*t1 = son;     // i zastępujemy synem
	}
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

    inOrder(root);
    std::cout << '\n';

    remove(root, 30);

    inOrder(root);

    return 0;
}
