// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

int main() {
    int number_of_friends, number_of_Transactions;
    cin>>number_of_friends>>number_of_Transactions;

    int net[number_of_friends]={0};
    while(number_of_Transactions--){
        int x,y,amt; cin>>x>>y>>amt;
        net[x] -= amt;
        net[y] += amt;
    }

    multiset<int> m;
    for(int i=0;i<number_of_friends;i++){
        if(net[i]!=0) 
            m.insert(net[i]);
    }

    int ans = 0;

    while(!m.empty()){
        auto first = m.begin();
        auto last = prev(m.end());
        int debit = *first;
        int credit = *last;

        m.erase(first);
        m.erase(last);

        // Settlement
        int settlement_amount = min(-debit, credit);

        // Settlement amount from donor to accepter
        debit += settlement_amount;
        credit -= settlement_amount;
        ans++;

        if(debit!=0)
            m.insert(debit);

        if(credit!=0)
            m.insert(credit);
    }
    cout<<ans;
    return 0;
}

