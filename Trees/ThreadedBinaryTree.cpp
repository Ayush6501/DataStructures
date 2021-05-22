#include <iostream>
using namespace std;

class node {
    char data;
    node *left = nullptr;
    node *right = nullptr;
    int lbit, rbit;
    friend class tbtree;
    node() {
        data = '\0';
        lbit = 1;
        rbit = 1;
    }
};

class tbtree {
    node *head;
    public:
        tbtree() {
            head = new node;
            head->data = '\0';
            head->left = head;
            head->right = head;
            head->rbit = 0;
        }
        void Creation();
        void PreOrderTransversal();
        void Inorder();
        node* InorderSuccessor(node*);
};

void tbtree :: Creation() {
    node* root;
    char ch, ch2;
    root = new node();
    cout<<"\nEnter root Data: ";
    cin >> root->data;
    head->lbit = 0;
    root->left = head;
    root->right = head;
    head->left = root;
    do {
        int flag = 0;
        node* temp = root;
        node *curr = new node();
        cout<<"\nEnter new node data: ";
        cin >> curr->data;
        while (flag == 0) {
            cout << "Add node to the left or right of " << temp->data <<": ";
            cin >> ch;
            if (ch == 'l') {
                if (temp->lbit == 1) {
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 0;
                    flag = 1;
                }
                else {
                    temp = temp->left;
                }
            }
            if (ch == 'r') {
                if (temp->rbit == 1) {
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 0;
                    flag = 1;
                }
                else {
                    temp = temp->right;
                }
            }
        }
        cout << "Add more nodes(y/n): ";
        cin >> ch2;
    }while(ch2 == 'y');
}

void tbtree :: Inorder() {
    node* temp = head;
    while(1) {
        temp = InorderSuccessor(temp);
        if(temp == head) {
            break;
        }
        cout << temp->data;
    }
}

node* tbtree ::InorderSuccessor(node * temp) {
    node* curr = temp->right;
    if (temp->rbit == 0) {
        while (curr->lbit == 0) {
            curr = curr->left;
        }
    }
    return curr;
}

void tbtree ::PreOrderTransversal() {
    node *temp = head->left;
    while (temp != head) {
        cout << temp->data;
        while (temp->lbit != 1) {
            temp = temp->left;
            cout << temp->data;
        }
        while (temp->rbit == 1) {
            temp = temp->right;
        }
        temp = temp->right;
    }
}

int main()
{
    tbtree tbt;
    int option;
    do
    {
        cout<<"\n\n------------------Menu-----------------------";
        cout<<"\n1.Create a Threaded Binary Tree";
        cout<<"\n2.Display the Threaded BinaryTree(Inorder)";
        cout<<"\n3.Display the Threaded BinaryTree(Preorder)";
        cout<<"\n4. Exit";
        cout<<"\nEnter your choice: ";
        cin>>option;
        switch(option)
        {
            case 1:
                tbt.Creation();
                break;

            case 2:
                tbt.Inorder();
                break;

            case 3:
                tbt.PreOrderTransversal();
                break;

            default:
                cout<<"\nInvalid Choice!";
                break;
        }
    }while(option != 4);
    return 0;
}
