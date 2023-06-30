#include<iostream>
#include<math.h>
using namespace std;
int t;

int solve() {
	int xB, yB, xA, yA, xC, yC;
	cin >> xA >> yA >> xB >> yB >> xC >> yC;
	int ans = 0;
	if (xA < xB && xA < xC|| xA > xB && xA > xC) {
		ans += min(abs(xB - xA), abs(xC - xA));
	}
	if (yA < yB && yA < yC|| yA > yB && yA > yC) {
		ans += min(abs(yB - yA), abs(yC - yA));
	}
	ans += 1;
	return ans;
}
int main(){
    int t;
    cin>>t;
    while(t!=0){
        cout<<solve()<<endl;
        t--;
    }
    

}