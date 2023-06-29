#include <iostream>
using namespace std;
int t;
int n, m;
int a[51], b[51];
int main(){
    cin>>t;
    while(t!=0){
        cin>>n>>m;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        for(int i = 1; i <= m; i++){
            cin>>b[i];
        }
        int i = n, j = m;
        while(i>0 && j>0){
            if(a[i]==b[j]){
                i--;
                j--;
            }else if(a[i]>b[j]){
                a[i]-=b[j];
                j--;
            }else{
                b[j]-=a[i];
                i--;
            }
        }
        if(i>0){
            cout<<"Tsondu"<<endl;
        }else if(j>0){
            cout<<"Tenzing"<<endl;
        }else{
            cout<<"Draw"<<endl;
        }
        t--;
    }
}
