#include <iostream>
#include <stack>
#define N 1000000001
using namespace std;
stack <int> a;
stack <int> b;
stack <int> c;
int t;
int n, x;
int k;
int main(){
    cin>>t;
    while(t!=0){
        int kl = 0;
        cin>>n>>x;
        for(int i = 1; i<= n; i++){
            cin>>k;
            a.push(k);
        }
        for(int i = 1; i <= n; i++){
            cin>>k;
            b.push(k);
        }
        for(int i = 1; i<= n; i++){
            cin>>k;
            c.push(k);
        }
        int i = n, j = n, q = n;
        while((i!=0 && j!=0 && q!=0) && kl<x){
            if(a.top()>=b.top() && a.top()>=b.top()){
                kl = kl|a.top();
                a.pop();
                i--;
            }else if(b.top()>=a.top()&&b.top()>=c.top()){
                kl = kl|b.top();
                b.pop();
                j--;
            }else if(c.top()>=a.top()&&c.top()>=b.top()){
                kl = kl|c.top();
                c.pop();
                q--;
            }
        if(kl==x){
            cout<<"Yes"<<endl;
        }else if(kl>x){
            cout<<"No"<<endl;
        }
        t--;
    }
}