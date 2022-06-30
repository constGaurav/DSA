#include <bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
	return ((n & (1<<pos)) != 0);
}

int setBit(int n, int pos){ // SET BIT '1' AT GIVEN POSITION.
	return (n | (1<<pos));
}

int clearBit(int n, int pos){ // SET BIT '0' AT GIVEN POSITION.
	int temp = ~(1<<pos);
	return (n&temp);
}

int updateBit(int n, int pos, int bit){
	int temp = ~(1<<pos);
	n = n&temp;
	return (n | (bit<<pos));
}

bool isPowerOf2(int n){
	if(n == 0){
		return false;
	}
	return ((n&(n-1)) == 0); 
}

bool isPowerOfFour(int n) {
    return (n>0) && ((n&(n-1)) == 0) && (n%3==1);
}

int countNumberOfOnes(int n){
	int count = 0;
	while(n){
		n = n&(n-1);
		count++;
	}
	return count;
} 

void subsets(int a[], int n){
	for(int i=0;i<(1<<n);i++){
		for (int j = 0; j < n; ++j){
			if(getBit(i,j)){
				cout<<a[j]<<" ";
			}
		}
		cout<<"\n";
	}
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output1.txt", "w", stdout);
// #endif

    // cout<<countNumberOfOnes(19);
    // int a[] = {1,2,3};
    // subsets(a,3);

	isPowerOfFour(5);

	return 0;
}