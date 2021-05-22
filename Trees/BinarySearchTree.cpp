#include <iostream>
#include <string>
using namespace std;

class node {
    string word;
    string meaning;
    node *left = nullptr;
    node *right = nullptr;
    friend class tree;
};

class tree {
    node *root;
public:
    tree() {
        root = NULL;
    }
    void Creation();
    void InOrder();
    void InOrder(node*);
    void search(string);
    int SearchRecursion(node*, string);
    void SearchKey(node*&, string, node*&);
    void Deletion(string);
    node* CopyTree();
    node* CopyTree(node*);
    void MirrorTree();
    void MirrorTree(node*);
};

void tree :: Creation() {
    root = new node();
    cout<<"\nEnter root Word: ";
    cin >> root->word;
    cout<<"\nEnter corresponding meaning of the word: ";
    cin.ignore();
    getline(cin, root->meaning);

    char ch = 'y';
    do {
        node* temp = root;
        int flag = 0;
        node* curr = new node();

        cout<<"\nEnter word for the next node: ";
        cin>>curr->word;
        cout<<"\nEnter corresponding meaning for the next node: ";
        cin.ignore();
        getline(cin, curr->meaning);

        while(flag == 0) {
            if(curr->word[0] < temp->word[0]) {
                if(temp->left == nullptr) {
                    temp->left = curr;
                    flag = 1;
                } else {
                    temp = temp->left;
                }
            } else {
                if(temp->right == nullptr) {
                    temp->right = curr;
                    flag = 1;
                } else {
                    temp = temp->right;
                }
            }
        }
        cout << "\nDo you want to add more? (y/n)";
        cin >> ch;
    } while(ch == 'y');
}


void tree :: InOrder() {
    InOrder(root);
}

void tree :: InOrder(node* root) {
    if(root == NULL) {
        return;
    }
    InOrder(root -> left);
    cout << "\nWord: " << root -> word << ", Meaning: " << root -> meaning;
    InOrder(root -> right);
}

void tree :: search(string elt) {
    int flag = 0;
    flag = SearchRecursion(root, elt);

    if (flag == 1) {
        cout << "\n"<< elt <<" " << "was found!";
    }
    else {
        cout << "\n"<< elt <<" " << "was not found!";
    }
}

int tree :: SearchRecursion(node* temp, string element) {
    int f = 0;
    if (temp != nullptr) {
        if (element == temp->word) {
            return 1;
        }
        if (element.compare(temp->word) < 0) {
            f = SearchRecursion(temp->left, element);
        }
        if (element.compare(temp->word) > 0) {
            f = SearchRecursion(temp->right, element);
        }
    }
    return f;
}

void tree :: Deletion(string element) {
    if (root == nullptr) {
        return;
    }
    node *curr = root;
    node *parent = nullptr;
    SearchKey(curr, element, parent);
    if (curr != nullptr) {
        //Leaf Node
        if (curr->left == nullptr && curr->right == nullptr) {
            if (curr != root) {
                if (parent->left == curr) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
            } else {
                root = nullptr;
            }
            delete(curr);
        }
        // Two Child Nodes
        else if(curr->left != nullptr && curr->right != nullptr) {
            node *successor = curr->right;
            //Finding inorder successor
            while (successor -> left != nullptr) {
                successor = successor->left;
            }
            string val = successor->word;
            Deletion(successor->word);
            curr->word = val;
        }
        //One Child
        else {
            node *child;
            if (curr->left == nullptr) {
                child = curr->right;
            }
            else {
                child = curr->left;
            }

            if (curr != root) {
                if (curr == parent->left) {
                    parent->left = child;
                }
                else {
                    parent->right = child;
                }
            }
            else {
                root = child;
            }
            delete(curr);
        }
        cout<<"\nElement Deleted: ";
    }
    else {
        cout << "\nElement can't be found";
        return;
    }
}

void tree :: SearchKey(node* &curr, string key, node* &parent) {
    while (curr != nullptr && curr->word != key)
    {
        parent = curr;
        if (key < curr->word) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }
}

node* tree :: CopyTree() {
    node* copied_root = CopyTree(root);
    return copied_root;
}

node* tree :: CopyTree(node* r) {
    node* temp = nullptr;
    if (r != nullptr) {
        temp = new node();
        temp->word = r->word;
        temp->meaning = r->meaning;
        temp->left = CopyTree(r->left);
        temp->right = CopyTree(r->right);
    }
    return temp;
}

void tree :: MirrorTree() {
    MirrorTree(root);
}

void tree :: MirrorTree(node* root) {
    if (root == nullptr) {
        return;
    }
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    MirrorTree(root->left);
    MirrorTree(root->right);
}

int main() {
    tree bst;
    node *copyroot;
    string element;
    int option;
    do
    {
        cout<<"\n\n------------------Menu-----------------------";
        cout<<"\n1.Create a Binary Search Tree";
        cout<<"\n2.Display the Binary Search Tree(Inorder)";
        cout<<"\n3.Search for an Element Recursively";
        cout<<"\n4.Delete an Element";
        cout<<"\n5.Copy the Tree";
        cout<<"\n6.Mirror the Tree";
        cout<<"\n7.Exit";
        cout<<"\nEnter your choice: ";
        cin>>option;
        switch(option)
        {
            case 1:
                bst.Creation();
                break;

            case 2:
                bst.InOrder();
                break;

            case 3:
                cout<<"\nEnter the Word to be searched: ";
                cin >> element;
                bst.search(element);
                break;

            case 4:
                cout<<"\nEnter the Word to be Deleted: ";
                cin >> element;
                bst.Deletion(element);
                bst.InOrder();
                break;

            case 5:
                copyroot = bst.CopyTree();
                cout<<"\n-------------Copied Tree---------------------";
                bst.InOrder(copyroot);
                break;

            case 6:
                bst.MirrorTree();
                cout<<"\n-------------Mirrored Tree---------------------";
                bst.InOrder();
                break;

            default:
                cout<<"\nInvalid Choice!";
                break;
        }
    }while(option != 7);
    return 0;
}
