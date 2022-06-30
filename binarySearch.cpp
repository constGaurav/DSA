// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;

int binarySearch(int a[], int n, int key){
	int start = 0;
	int end = n-1;

	while(start<=end){
		int mid = start + (end - start)/2;

		if(a[mid] == key) 
			return mid;
		else if(a[mid]<key)
			start = mid+1;
		else end = mid-1;
	}

	return -1;
}

// Find First and Last Occuerence of a key
int first_Occurence(int a[], int n, int key){
	int start = 0;
	int end = n-1;
	int occur = -1;
	
	while(start <= end){
		int mid = start + (end-start)/2;
		if(a[mid] == key){
			occur = mid;
			end = mid-1;
		}
		else if(a[mid] < key)
			start = mid+1;
		else end = mid-1;
	}
	return occur;
}

int last_Occurence(int a[], int n, int key){
	int start = 0;
	int end = n-1;
	int occur = -1;

	while(start<=end){
		int mid = start + (end-start)/2;
		if(a[mid] == key){
			occur = mid;
			start = mid+1;
		}
		else if(a[mid] < key)
			start = mid+1;
		else end = mid-1;
	}
	return occur;
}

int find_key_in_rotated_array(int a[], int n, int key){
	int start = 0;
	int end = n-1;

	while(start<=end){
		int mid = start + (end-start)/2;
		if(a[mid] == key){
			return mid;
		} else if(a[start] <= a[mid]){
			if(key >= a[start] && key <= a[mid]){
				end = mid-1;
			} else{
				start = mid+1;
			}

		} else {
			if(key >= a[mid] && key <= a[end]){
				start = mid+1;
			} else {
				end = mid-1;
			}
		}
	}

	return -1;
}


double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

double getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout << low << " " << high << endl; 
    
    // just to check
    cout << pow(m, (double)(1.0/(double)n)); 
}


// book allocation 
bool isPossible(int a[], int n, int m, int mxVal){
    int allocateStudents = 1;
    int pages = 0;
    for(int i=0;i<n;i++){
        if(a[i] > mxVal) return false;
        if(pages+a[i] > mxVal){
            pages = a[i];
            allocateStudents++;
        } else pages += a[i];
    }
    
    if(allocateStudents > m) return false;
    return true;
}

int findPages(int a[], int n, int m) {
    if(n<m) return -1;
    int end = 0;
    int start = a[n-1];
    
    for(int i=0;i<n;i++){
        end+=a[i];
    }
    
    int ans = end;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossible(a,n,m,mid)){
            end = mid-1;
            ans = min(ans,mid);
        } else start = mid+1;
    }
    return ans;
}

// Aggressive Cows
bool isPossibleC(vector<int> &a, int k, int m){
    int cows=1;
    int cord=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]-cord >= m){
            cows++;
            cord = a[i];
        }
        if(cows==k) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &a, int k){
    sort(a.begin(),a.end());
    int start = 1;
    int end = a[a.size()-1]-a[0];
    int ans = 0;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossibleC(a,k,mid)){
            ans = max(mid,ans);
            start = mid+1;
        } else end = mid-1;
    }
    return ans;
}

int main() {

	int a[] = {4,5,1,2,3};
	int n=5;
	getNthRoot(6,4096);
	// cout<<find_key_in_rotated_array(a,n,2);
    return 0;
}

