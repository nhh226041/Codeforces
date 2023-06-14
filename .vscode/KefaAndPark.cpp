#include <iostream>
using namespace std;
int n, m;
int a[100000];
int count = 0;
struct Node{
    int data;
    int cat;
    Node* leftmost_child;
    Node* right_sibling;
};
typedef struct Node* node;
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

node find(node r, int u){
    if(r==NULL) return NULL;
    if(r->data == u) return r;
    else{
        node p = r->leftmost_child;
        while(p!=NULL){
            node result = find(p, u);
            if(result!=NULL) return result;
            p=p->right_sibling;
        }
    }
    return NULL;
}

void insert(node &r, int u, int v, int cat){
    if(r==NULL){
        r = makeNode(v, cat);
    }else{
        node parent = find(r, u);
        if(parent->leftmost_child==NULL){
            parent->leftmost_child = makeNode(v, cat);
        }else{
            node p = parent->leftmost_child;
            while(p->right_sibling!=NULL){
                p=p->right_sibling;
            }
            p->right_sibling = makeNode(v, cat);
        }
    }
}

void PreOrder(node r){
    if(r==NULL) return;
    cout<<r->data<<" ";
    cout<<r->cat<<"\n";
    node p = r->leftmost_child;
    while(p!=NULL){
        PreOrder(p);
        p=p->right_sibling;
    }
}

void solve(node r, int pathCat){
    if(r==NULL){
        return;
    }
    // if(r->cat==0 && r->leftmost_child!=NULL){
    //     solve(r->leftmost_child, 0);
    // }
    if(r->leftmost_child==NULL){
            if(pathCat<=m){
                cout<<r->data<<" ";
                count++;
            }
    }
    node p =r->leftmost_child;
    while(p!=NULL){
        solve(p, pathCat+p->cat);
        p=p->right_sibling;
    }
}
int main(){
    node root = NULL;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    insert(root,1,1,a[1]);
    int x, y;
    for(int i = 2; i <= n; i++){
        cin>>x>>y;
        insert(root, x, y, a[i]);
    }
    // cout<<"\n";
    // root = makeNode(1, 0);
    // root->leftmost_child = makeNode(2, 0);
    // root->leftmost_child->right_sibling = makeNode(3, 0);
    // root->leftmost_child->right_sibling->leftmost_child=makeNode(4, 0);
    // root->leftmost_child->right_sibling->leftmost_child->right_sibling=makeNode(5, 0);
    // PreOrder(root);
    cout<<"\n";
    solve(root, a[1]);
    cout<<"\n"<<count;
    // if(find(root, 3)!=NULL){
    //     cout<<"Yes";
    // }else cout<<"No";
}