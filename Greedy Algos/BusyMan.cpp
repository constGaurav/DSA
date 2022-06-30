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

// https://www.spoj.com/problems/BUSYMAN/

bool cmp(pii p1, pii p2){
    return p1.s < p2.s;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output2.txt", "w", stdout);
// #endif
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
    
    int T; cin>>T;
    // cin.ignore(); must be there when using getline(cin, s)
    int s,e,n;
    vector<pii> v; 
    while(T--) {
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s>>e;
            v.eb(mp(s,e));
        }

        // Activity Selection Algo
        sort(all(v),cmp);

        // start picking activities
        int res = 1;
        int fin = v[0].s;

        // iterate over remaining activities
        for(int i=1;i<n;i++){
            if(v[i].f >= fin){
                fin = v[i].s;
                res++;
            }
        }
        cout<<res<<endl;
    v.clear();
    }
    return 0;
}

