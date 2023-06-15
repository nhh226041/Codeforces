#include <bits/stdc++.h>
using namespace std;
vector <int> a[100010];
int n, m, total = 0;
int check[100010] = {0};
int cat[100010];
void solve(int s, int sum){
    //kiểm tra node này đã được xét chưua
    if(check[s]) return;
    check[s] = 1;
    //Tính tổng số cat trên đoạn
    if(cat[s]) sum++;
    else sum = 0;
    //kết thúc đệ quy khi sum>m
    if(sum>m) return;
    //Kiểm tra lá này có hợp lệ không
    if(s!=1 && a[s].size()==1) total++;
    //Đệ quy những theo DFS
    for(int i = 0; i < a[s].size(); i++){
        solve(a[s][i], sum);
    }
}
int main(){
    int u, v;
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>cat[i];
    }
    for(int i = 2; i <= n; i++){
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    solve(1, 0);
    cout<<total;
}