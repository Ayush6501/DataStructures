#include "iostream"
#include "string"
#include "stack"
#include "queue"

using namespace  std;

class GraphNode {
    int Id;
    string Username;
    GraphNode *next;
public:
    GraphNode() {
        Id = 0;
        Username = '\0';
        next = nullptr;
    }
    friend class Graph;
};

class Graph {
    int n;
    GraphNode *head[10];
public:
    Graph() {
        n = 0;
        cout << "Enter No. of users: " <<endl;
        cin >> n;
        for (int i = 1; i<= n; i++) {
            head[i] = new GraphNode;
            head[i]->Id = i;
            cout << "Enter Username of User "<< i <<": " <<endl;
            cin >> head[i]->Username;
        }
    }
    void Creation();
    void Display();
    void Display(GraphNode*);
    void BFT(int);
    void BFT();
    void DFT();
    void DFT(int, int*);
    void DFTNR(int);
};

void Graph :: Creation() {
    int FriendId;
    char choice;
    GraphNode *temp, *curr;
    for (int i = 1; i <= n; i++) {
        temp = head[i];
        do {
            cout << "Enter friend ID to create "<< head[i]->Username<< "'s friend: " << endl;
            cin >> FriendId;
            if (FriendId == i) {
                cout << "You can't friend yourself";
            }
            else {
                curr = new GraphNode;
                curr->Id = FriendId;
                curr->Username = head[FriendId]->Username;
                temp->next = curr;
                temp = temp->next;
            }
            cout << "Do you want to add more friends?" <<endl;
            cin >> choice;
        } while (choice == 'y');
    }
}

void Graph :: Display()                              //driver function for display function
{
    cout<<"\nYour list of friends are :"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<head[i]->Id<<": "<<head[i]->Username;
        Display(head[i]->next);
    }
}

void Graph :: Display(GraphNode* start)                     //function to display the graph nodes
{
    GraphNode *temp = start;
    while(temp != nullptr)
    {
        cout<<" ----> "<< temp->Id <<": "<< temp->Username;
        temp = temp->next;
    }
    cout<<endl;
}

void Graph :: BFT() {
    int id;
    cout<<"\nEnter the starting ID:- "<<endl;
    cin>>id;
    BFT(id);
}

void Graph :: BFT(int a) {
    int visited[10] = {0};
    queue<GraphNode*> Q;
    Q.push(head[a]);
    visited[a] = 1;
    GraphNode *temp;
    do
    {
        temp = Q.front();
        Q.pop();
        cout<<temp->Id<<" :- "<<temp->Username<<"\t";
        while(temp != nullptr)
        {
            if(visited[temp->Id] == 0)
            {
                Q.push(head[temp->Id]);
                visited[temp->Id] = 1;
            }
            temp = temp->next;
        }
    } while (!Q.empty());
}

void Graph :: DFT()                                              //driver function for dfs traversals
{
    int id,ch;
    cout<<"\nEnter the starting id:- "<<endl;
    cin>>id;
    cout<<"\nEnter Your choice\n1. Recursive\n2. Non-Recursive"<<endl;
    cin>>ch;
    if(ch==1)
    {
        int visited[10] = {0};
        DFT(id, visited);
    }
    else if(ch==2)
    {
        DFTNR(id);
    }
}

void Graph :: DFTNR(int i)                          //function for dfs non recursive traversal
{
    int visited[10] = {0};
    stack<GraphNode*> S;
    S.push(head[i]);
    visited[i] = 1;
    GraphNode *temp;
    do
    {
        temp = S.top();
        S.pop();
        cout<<temp->Id<<" :- "<<temp->Username<<"\t";
        while(temp != nullptr)
        {
            if(visited[temp->Id] == 0)
            {
                S.push(head[temp->Id]);
                visited[temp->Id] = 1;
            }
            temp = temp->next;
        }
    } while (!S.empty());
}

void Graph :: DFT(int s,int *visited)           //function for dfs recursive traversal
{
    cout<<s<<" :- "<<head[s]->Username<<"\t";
    visited[s] = 1;
    GraphNode *temp = head[s]->next;
    while(temp != nullptr)
    {
        if(visited[temp->Id] == 0) {
            DFT(temp->Id, visited);
        }
        temp = temp->next;
    }
}

int main () {
    Graph Fb;
    Fb.Creation();
    Fb.Display();
    Fb.BFT();
    Fb.DFT();
    Fb.DFT();
    return 0;
}
