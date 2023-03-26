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


// zadanie 2 - funkcja rekurencyjna
void inorder_do(node *t, void f(node*)) 
{
    if (t) 
    {
        inorder_do(t->left, f);
        f(t);
        inorder_do(t->right, f);
    }
}


void print_node(node* root) {
    std::cout << root->x << " ";
}


int main()
{
    node *root = nullptr;
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    inorder_do(root, print_node);
    std::cout << '\n';
    
    return 0;
}