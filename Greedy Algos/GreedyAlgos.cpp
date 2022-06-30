// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

int make_change(vector<int> &coins, int money){
	int count = 0;

	while(money>0){
		int idx = upper_bound(coins.begin(),coins.end(),money)-coins.begin()-1;
		cout<<coins[idx]<<" + ";
		money -= coins[idx];
		count++;
	}
	return count;
}

int connectingWires(vector<int> &a, vector<int> &b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int n = a.size();
	int s=0;
	for(int i=0;i<n;i++){
		s += abs(a[i]-b[i]);
	}
	return s;
}

int main() {
	vector<int> v= {1,2,5,10,20,50,100,200,500,2000};
	
	// int c = make_change(v, 100);
	// cout<<endl<<"Number of Coins: "<<c;
    
	// vector<int> a= {3,4,1};
	// vector<int> b= {2,5,6};
	// cout<<connectingWires(a,b);

	



	
    return 0;
}