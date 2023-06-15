#include <iostream>
using namespace std;
struct Node{
    int data;
    int cat;
    Node* leftmost_child;
    Node* right_sibling;
};
int n, m;
int a[100000], x[100000], y[100000];
typedef struct Node* node;

struct Array{
    int x;
    int y;
    Array* next;
};
typedef struct Array* array;
array makeArray(int x, int y){
    array newArray = new Array;
    if(newArray!=NULL){
        newArray->x = x;
        newArray->y = y;
        newArray->next = NULL;
    }
    return newArray;
}
void addLastArray(array &a, int x, int y){
    if(a==NULL){
        a=makeArray(x, y);
        a->next = a;
    }else{
        array p = a;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next = makeArray(x, y);
        p->next->next = a;
    }
}
array findPrevArray(array a, int x, int y){
    array p = a;
    while(p->next->x!=x || p->next->y!=y){
        p=p->next;
    }
    return p;
}

void deleteElementArray(array &a, int x, int y){
    array prev = findPrevArray(a, x, y);
    if(prev->next = prev){
        prev = NULL;
    }prev->next = prev->next->next;
}

node makeNode(int x, int cat){
    node newNode = new Node;
    if(newNode!=NULL){
        newNode->data = x;
        newNode->cat = cat;
        newNode->leftmost_child = NULL;
        newNode->right_sibling = NULL;
    }
    return newNode;
}

node findNode(node r, int u){
    if(r==NULL) return NULL;
    if(r->data == u) return r;
    else{
        node p = r->leftmost_child;
        while(p!=NULL){
            node result = findNode(p, u);
            if(result!=NULL) return result;
            p=p->right_sibling;
        }
    }
    return NULL;
}

void insert(node &r, array &a, int cat){
    
}

void print(array a){
    cout<<a->x<<" "<<a->y<<"\n";
    array p = a->next;
    while(p!=a){
        cout<<a->x<<" "<<a->y<<"\n";
        p=p->next;
    }
}

int main(){
    node root = NULL;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    root = makeNode(1, a[1]);
    array arr = NULL;
    int x, y;
    addLastArray(arr, 1, 1);
    for(int i = 2; i <= n; i++){
        cin>>x>>y;
        addLastArray(arr, x, y);
    }
    // cout<<"\n";
    // print(arr);
}

