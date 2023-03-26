#include <iostream>
#include <stack>

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


template<typename Node>
class BSTiter
{
private:
    Node* t1;
    std::stack<Node*> stack;

public:
    BSTiter(Node* node = nullptr) : t1(node)
    {
        while (t1 != nullptr)
        {
            stack.push(t1);
            t1 = t1->left;
        }
        if (!stack.empty())
        {
            t1 = stack.top();
        }
    }

    bool operator!=(BSTiter<Node> other) const
    {
        return t1 != other.t1;
    }

    int operator*() const
    {
        return t1->x;
    }

    BSTiter<Node> operator++()
    {
        if (t1->right) // jesli istnieje prawe poddrzewo
        {
            t1 = t1->right;
            while (t1->left) // szukamy najmniejszego elementu
            {
                stack.push(t1);
                t1 = t1->left;
            }
            return t1;
        }

        while (!stack.empty() && t1 == stack.top()->right)
        {
            t1 = stack.top();
            stack.pop();
        }
        
        if (stack.empty())
        {
            t1 = nullptr;
            return t1;
        }

        t1 = stack.top();
        stack.pop();

        return t1;
    }
};

template<typename Node>
BSTiter<Node> begin(Node* t)
{
    return BSTiter<Node>(t);
}

template<typename Node>
BSTiter<Node> end(Node* t)
{
    return BSTiter<Node>(nullptr);
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

    for (BSTiter<node> i = begin(root); i != end(root); ++i)
    {
        std::cout << *i << '\t';
    }

    std::cout << '\n';

    // for (auto x : root)
    // {
    //     std::cout << x << '\t';
    // }

    return 0;
}