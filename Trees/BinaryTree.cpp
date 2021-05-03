#include <iostream>
#include <string>

using namespace std;
int const MAX = 20;

class treenode {
private:
    char data;
    treenode *left, *right;
    friend class tree;

public:
    treenode() {
        data = '\0';
        left = nullptr;
        right = nullptr;
    }
};

class QueueClass {
    int MAX = 10;
    treenode* Queue[10];
    int rear, front;
public:
    QueueClass () {
        rear = -1;
        front = -1;
    }
    int IsFull();
    int IsEmpty();
    void Enqueue(treenode*);
    treenode* Dequeue();
    friend class tree;
};

int QueueClass :: IsFull()
{
    if(rear == MAX -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int QueueClass :: IsEmpty()
{
    if(front == rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void QueueClass :: Enqueue(treenode* el)
{
    if(!IsFull()) {
        rear++;
        Queue[rear] = el;
    }
    else
    {
        return;
    }
}

treenode* QueueClass :: Dequeue()
{
    treenode* temp;
    if(!IsEmpty())
    {
        front++;
        temp = Queue[front];
        return temp;
    }
    else
    {
        return 0;
    }
}

class StackClass {
    int top;
    treenode *stack[20];
public: StackClass()
    {
        top = -1;
    }
    void push(treenode *temp);
    treenode *pop();
    int IsEmpty();
    int IsFull();
    friend class tree;
};

int StackClass :: IsFull() {
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int StackClass :: IsEmpty() {
    if (top == -1)
    {
        return 1;
    }
    else
    { return 0;
    }
}

void StackClass :: push(treenode *temp) {
    if(!IsFull())
    {
        top += 1;
        stack[top] = temp;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}

treenode* StackClass :: pop() {
    treenode *temp;
    if(!IsEmpty())
    {
        temp = stack[top];
        top -= 1;
        return temp;
    }
    else
    {
        return 0;
    }
}

class tree {
    treenode *root;
public:
    tree () {
        root = nullptr;
    }
    void createRecursive();
    void createRecursive(treenode *);
    void createNonRecursive();

    void InorderRecursion();
    void PreorderRecursion();
    void PostorderRecursion();
    void InorderRecursion(treenode*);
    void PreorderRecursion(treenode*);
    void PostorderRecursion(treenode*);
    void InorderNonRecursion();
    void PreorderNonRecursion();
    void PostorderNonRecursion();

    void TreeDepth();
    int TreeDepth(treenode*);
    void BFS();
};

void tree :: createRecursive() {
    root = new treenode;
    cout << "Enter root node data: " << endl;
    cin >> root->data;
    root->left = root->right = nullptr;
    createRecursive(root);
}

void tree :: createRecursive(treenode * temp) {
    treenode *curr;
    char ch;
    cout << "Add data to the left node of the tree: " << endl;
    cin >> ch;
    if (ch == 'y') {
        curr = new treenode;
        cout << "Enter node data: " << endl;
        cin >> curr -> data;
        temp->left = curr;
        createRecursive(curr);
    }

    cout << "Add data to the right node of the tree: " << endl;
    cin >> ch;
    if (ch == 'y') {
        curr = new treenode;
        cout << "Enter node data: " << endl;
        cin >> curr -> data;
        temp->right = curr;
        createRecursive(curr);
    }
}

void tree :: createNonRecursive() {
    char ch, ch2;
    if (root == NULL) {
        root = new treenode;
        cout << "Enter root node data: ";
        cin >> root->data;
    }
    do {
        treenode *temp, *curr;
        int flag = 0;
        temp = root;
        curr = new treenode;
        cout << "Enter node data: ";
        cin >> curr->data;
        while (flag == 0) {
            cout << "Add node to the left or right('l'/'r') of "<< temp->data <<": ";
            cin >> ch;
            if (ch == 'l') {
                if (temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                }
                temp = temp->left;
            }
            else {
                if (ch == 'r') {
                    if (temp->right == NULL) {
                        temp->right = curr; flag = 1;
                    }
                    temp = temp->right;
                }
            }
        }
        cout << "Add more nodes: ";
        cin >> ch2;
    } while(ch2 == 'y');
}

void tree :: InorderRecursion()
{
    InorderRecursion(root);
}
void tree :: PreorderRecursion()
{
    PreorderRecursion(root);
}
void tree :: PostorderRecursion()
{
    PostorderRecursion(root);
}

void tree :: PreorderRecursion(treenode *temp) {
    if (temp != nullptr) {
        cout << temp->data << "-->"; PreorderRecursion(temp->left);
        PreorderRecursion(temp->right);
    }
}
void tree :: PostorderRecursion(treenode *temp) {
    if (temp != nullptr) {
        PostorderRecursion(temp->left);
        PostorderRecursion(temp->right);
        cout << temp->data<<"-->";
    }
}
void tree :: InorderRecursion(treenode *temp) {
    if (temp != nullptr) {
        InorderRecursion(temp->left);
        cout << temp->data << "-->";
        InorderRecursion(temp->right);
    }
}

void tree :: PreorderNonRecursion() {
    StackClass s;
    treenode *temp;
    if (root == nullptr) {
        cout << "No tree to traverse.";
        return;
    }
    else {
        temp = root; }
    while (1) {
        while (temp != NULL) {
            cout << temp->data << "-->";
            s.push(temp);
            temp = temp->left;
        }
        if (s.IsEmpty()) {
            break;
        }
        temp = s.pop();
        temp = temp->right;
    }
}

void tree :: InorderNonRecursion() {
    StackClass s;
    treenode *temp;
    if (root == nullptr) {
        cout << "No tree to traverse.";
        return;
    }
    else {
        temp = root;
    }
    while (1) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp->left;
        } if (s.IsEmpty()) {
            break;
        }
        temp = s.pop();
        cout << temp->data << " --> ";
        temp = temp->right;
    }
}

void tree :: PostorderNonRecursion() {
    StackClass s;
    treenode *temp;
    if (root == nullptr) {
        cout << "No tree to traverse.";
        return;
    }
    else {
        temp = root;
    }
    while (1) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp->left;
        }
        if (s.stack[s.top]->right == NULL) {
            temp = s.pop();
            cout << temp->data << " --> ";
        }
        while (!s.IsEmpty() && s.stack[s.top]->right == temp) {
            temp = s.pop(); cout << temp->data << " --> ";
        }
        if (s.IsEmpty()) {
            break;
        }
        temp = s.stack[s.top]->right;
    }
}

void tree :: TreeDepth()
{
    int depth = TreeDepth(root);
    cout << depth;
}

int tree :: TreeDepth(treenode *temp) {
    if (temp == NULL) {
        return 0;
    }
    else {
        return (1 + max(TreeDepth(temp->left), TreeDepth(temp->right)));
    }
}

void tree :: BFS()
{
    treenode* temp = root;
    //Insert temp into queue;
    QueueClass Q; Q.Enqueue(temp);
    while (!Q.IsEmpty()) {
        //Remove from queue into temp;
        temp = Q.Dequeue();
        cout << temp->data << " --> ";
        if (temp->left != NULL) {
            //insert temp->left into queue;
            Q.Enqueue(temp->left);
        }
        if (temp->right != NULL) {
            //insert temp->left into queue;
            Q.Enqueue(temp->right);
        }
    }
}

int main()
{
    tree btr, btnr;
    int choice;
    do
    {
        cout << "\n\n****MENU****" << endl;
        cout << "\n****RECURSIVE****" << endl;
        cout << "\n1. Create Binary Tree (Recursion)";
        cout << "\n2. Display Binary Tree Inorder traversal(Recursion)";
        cout << "\n3. Display Binary Tree Preorder traversal(Recursion)";
        cout << "\n4. Display Binary Tree Postorder traversal(Recursion)";
        cout << "\n\n****NON RECURSIVE****" << endl; cout << "\n5. Create Binary Tree (Non-Recursion)";
        cout << "\n6. Display Binary Tree Inorder traversal(Non-Recursion)";
        cout << "\n7. Display Binary Tree Preorder traversal(Non-Recursion)";
        cout << "\n8. Display Binary Tree Postorder traversal(Non-Recursion)";
        cout << "\n\n****UTILITY****" << endl;
        cout << "\n9. Display Binary Tree Depth(Recursion)";
        cout << "\n10. BFS";
        cout << "\nEnter your choice: " <<endl;
        cin >>choice;
        switch(choice) {
            case 1:
                btr.createRecursive();
                cout << "\nBinary Tree Created.";
                break;
            case 5:
                btnr.createNonRecursive();
                cout << "\nBinary Tree Created Non-recursively.";
                break;
            case 2:
                cout << "\nInorder traversal (Recursively): ";
                btr.InorderRecursion();
                break;
            case 3:
                cout << "\nPreorder traversal (Recursively): ";
                btr.PreorderRecursion();
                break;
            case 4:
                cout << "\nPostorder traversal (Recursively): ";
                btr.PostorderRecursion(); break;
            case 6:
                cout << "\nInorder traversal (Non-recursively): ";
                btnr.InorderNonRecursion();
                break;
            case 7:
                cout << "\nPreorder traversal (Non-recursively): ";
                btnr.PreorderNonRecursion();
                break;
            case 8:
                cout << "\nPostorder traversal (Non-recursively): ";
                btnr.PostorderNonRecursion();
                break;
            case 9:
                cout << "\nThe Depth of the Tree is: ";
                btr.TreeDepth();
                break;
            case 10:
                cout << "\nBFS: ";
                btr.BFS();
                break;
        }
    }while(choice != 15);
    return 0;
}
