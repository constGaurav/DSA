// @MrGaurav
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define debug(x) cout<<#x<<" "<<x<<endl;
using namespace std;



int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output2.txt", "w", stdout);
// #endif
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
    
    while(1) {
        ll n, max_load = 0, load = 0;
        cin>>n;
        
        if(n==-1) break;
        
        ll a[n];
        for(int i=0;i<n;i++){
        	cin>>a[i];
        	load += a[i];
        }

        if(load%n != 0){
        	cout<<-1<<endl;
        	continue;
        }

        load = load/n;
        ll diff = 0;
        // Greedy Step
        for(int i=0;i<n;i++){
        	diff += (a[i]-load);
        	ll ans = abs(diff);
        	max_load = max(max_load, ans);
        }
        cout<<max_load<<endl;
    }
    return 0;
}

