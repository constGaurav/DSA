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
using namespace std;


int recBinarySearch(vector<int> v, int s, int e, int f){
    // Base Case.
    if(s>e) return -1;

    int m = (e+s)/2;
    if(v[m] == f) return m;
    else if(v[m] > f) return recBinarySearch(v, s, m-1, f);
    else return recBinarySearch(v, m+1, e, f);
}

int recPower(int a, int b){
    if(b==1) return a;
    return a*recPower(a,b-1);
}

int fastPower(int a, int b){
    if(b==0) return 1;

    int smaller_ans = fastPower(a,b/2);
    smaller_ans *= smaller_ans;

    if(b&1) return smaller_ans*a;
    return smaller_ans;
}

int recMul(int a, int b){
    if(b==1) return a;
    return a+recMul(a,b-1);
}

int firstOccur(int a[], int n, int e){
    if(n==0) return -1;
    if(a[0] == e) return 0;

    int i = firstOccur(a+1, n-1, e);
    if(i == -1) return -1;
    return i+1;
}

int lastOccur(int a[], int n, int e){
    if(n == 0) return -1;

    int i = lastOccur(a+1, n-1, e);
    if(i == -1){
        if(a[0] == e) return 0;
        return -1;
    }
    return i+1;
}

void allOccurs(int a[], int i, int n, int e){
    if(i == n) return;

    if(a[i] == e) {
        cout<<i<<" ";
    }
    allOccurs(a,i+1,n,e);
}

//-----------------------------------
            // BUBBLE SORT
void bubble_sort(int a[], int n){
    if(n==1) return;

    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1])
            swap(a[i],a[i+1]);
    }
    bubble_sort(a,n-1);
}

void bubble_sort_fully_recursive(int a[], int i, int n){
    if(n == 1) return;

    if(i == n-1){
        return bubble_sort_fully_recursive(a, 0, n-1);
    }

    if(a[i]>a[i+1]){
        swap(a[i],a[i+1]);
    }
    bubble_sort_fully_recursive(a, i+1, n);
    return;
}
// ---------------------------

        // MERGE SORT

void merge(int a[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100];

    while(i<=mid && j<=e){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }

    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }

    for(i=s;i<=e;i++){
        a[i] = temp[i];
    }
} 

void mergeSort(int a[], int s, int e){
    if(s>=e) return;

    //Follow 3 steps.
    // 1. Divide 
    int mid = (s+e)/2;

    //2. Recursively sort the array - [s,mid] and [mid+1,e]
    mergeSort(a,s,mid);//1
    mergeSort(a,mid+1,e);//2

    //3. Merge the two parts.
    merge(a,s,e);
}

// ---------------------------

int rmerge(int a[], int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100000];
    int cnt = 0;

    while(i<=mid and j<=e){
        if(a[i]>a[j]){
            temp[k++] = a[j++];
            cnt += mid-i+1;
        } else {
            temp[k++] = a[i++]; 
        }
    }

    while(i<=mid) 
        temp[k++] = a[i++];
    while(j<=e)
        temp[k++] = a[j++];

    for(i=s;i<=e;i++){
        a[i] = temp[i];
    }
    return cnt;
}

int reversePairs(int a[], int s, int e) {
    if(s>=e) return 0;

    int mid = (s+e)/2;
    int x = reversePairs(a, s, mid);
    int y = reversePairs(a, mid+1, e);
    int z = rmerge(a,s,e);
    return x+y+z;
}
//----------------------------
        // QUICK SORT
int partition(int a[], int s, int e){
    //Inplace (Can't take extra array)
    int i = s-1;
    int j = s;
    int pivot = a[e];

    while(j<=e-1){
        if(a[j]<=pivot){
            //merge the smaller element in the region-1
            i = i+1;
            swap(a[i],a[j]);
        }
        // expand the larger region-2
        j = j+1;
    }
    // Place the pivot element in the correct position.
    swap(a[i+1],a[e]);
    return i+1;
}

void quicksort(int a[], int s, int e){
    //base case
    if(s>=e) return;

    //recursive case
    int p = partition(a, s, e);
    //left part
    quicksort(a, s, p-1);
    //right part
    quicksort(a, p+1, e);
}
//----------------------------

void spellNumber(int n){
    if(n==0) return;

    spellNumber(n/10);
    int r = n%10;
    if(r==0) cout<<" Zero";
    else if(r==1) cout<<" One";
    else if(r==2) cout<<" Two";    
    else if(r==3) cout<<" Three";
    else if(r==4) cout<<" Four";
    else if(r==5) cout<<" Five";
    else if(r==6) cout<<" Six";
    else if(r==7) cout<<" Seven";
    else if(r==8) cout<<" Eight";
    else if(r==9) cout<<" Nine";    
}

int stringToInt(string s, int n){
    if(n==0) return 0;
    int num = (s[n-1]-'0');
    int small_ans = stringToInt(s,n-1);
    return small_ans*10 + num;
}

int tilingProblem(int n){
    if(n<4) return 1;

    int ans = tilingProblem(n-1)+tilingProblem(n-4);
    return ans;
}

int ladderProblem(int n){
    if(n==0) return 1;
    if(n < 0) return 0; 
    int a = ladderProblem(n-1) + ladderProblem(n-2) + ladderProblem(n-3);
    return a;
}

int ladderProblemKSteps(int n, int k){
    if(n==0) return 1;
    if(n<0) return 0;

    int a = 0;
    for(int i=1;i<=k;i++){
        a += ladderProblemKSteps(n-i, k);
    }
    return a;
}

int friendsPairingProblem(int n){
    if(n==0 || n==1) return 1;
    else if(n==2) return 2;
    return friendsPairingProblem(n-1) + (n-1)*friendsPairingProblem(n-2);
}

int countStrings(int n, int last_digit){
    // base case
    if (n == 0) {
        return 0;
    }
 
    // if only one digit is left
    if (n == 1){
        if (last_digit) {   // if the last digit is 1
            return 1;
        }
        else {  // otherwise, if the last digit is 0
            return 2;
        }
    }
 
    // if the last digit is 0, we can have both 0 and 1 at the current position
    if (last_digit == 0) {
        return countStrings(n - 1, 0) + countStrings(n - 1, 1);
    }
    // if the last digit is 1, we can have only 0 at the current position
    else {
        return countStrings(n - 1, 0);
    }
}

void towerOfHanoi(int n, char scr, char dest, char helper){
    if(n==0) return;
    
    towerOfHanoi(n-1, scr, helper, dest);
    cout<<"Move from "<<scr<<" to "<<dest<<endl;
    towerOfHanoi(n-1, helper, dest, scr);
}

void generateSubsequence(char *in, char *out, int i, int j){
    //Base Case
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<" ";
        return;
    }

    //rec case
    // include the current character
    out[j] = in[i];
    generateSubsequence(in, out, i+1, j+1);

    //Exclude the current character
    generateSubsequence(in, out, i+1, j);
}

void generateBrackets(int open, int close, string s, vector<string> &ans){
    if(open == 0 && close == 0){
        ans.push_back(s);
        return;
    }
    if(open != 0){
        string s1 = s;
        s1.push_back('(');
        generateBrackets(open-1,close,s1,ans);
    }
    if(close>open){
        string s2 = s;
        s2.push_back(')');
        generateBrackets(open,close-1,s2,ans);
    }
    return;
}

int knapsack01(int n, int c, int *wt, int *prices){
    if(n==0 || c == 0)
        return 0;

    //rec case
    int ans = 0;
    int inc,exc;
    inc = exc = 0;

    if(wt[n-1] <= c){
        inc = prices[n-1] + knapsack01(n-1, c, wt, prices);
    }
    exc = knapsack01(n-1, c, wt, prices);
    ans = max(inc, exc);
    return ans;
}

// Keypad-Problem -----------
string keys[10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void keypad(char in[], char out[], int i, int j){
    //base case
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
    }

    // rec case
    int digit = in[i]-'0';
    if(digit == 1 || digit == 0){
        keypad(in, out, i+1,j);
    }
    for(int k=0;keys[digit][k]!='\0';k++){
        out[j] = keys[digit][k];
        //fill the remaining part
        keypad(in, out, i+1, j+1);
    }
    return;
}

//Generate Strings
void generateStrings(char *in, char *out, int i, int j){
    if(in[i] == '\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    //rec case
    //1. One digit at a time
    int digit = in[i]-'0';
    if(digit != 0){
        char  ch = digit + 'A' - 1;
        out[j] = ch;
        generateStrings(in, out, i+1, j+1);
    }

    //2. Two digit at a time
    if(in[i+1] != '\0'){
        int secondDigit = in[i+1] - '0';
        int no = digit*10+secondDigit;
        if(no<=26){
            char ch = no + 'A' - 1;
            out[j] = ch;
            generateStrings(in, out, i+2, j+1);
        }
    }
    return;
}

// ##### BACKTRACKING #####
bool ratInMaze(char maze[10][10], int sol[][10], int i, int j, int m, int n){
    if(i == m && j == n){
        sol[m][n] = 1;
        //Print the Path.
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    //Rat should be inside Grid.
    if(i>m || j>n) return false;
    if(maze[i][j] == 'X') return false;

    //Assume solution exists through current cell.
    sol[i][j] = 1;

    bool rightSuccess = ratInMaze(maze, sol, i, j+1, m, n);
    bool downSuccess = ratInMaze(maze, sol, i+1, j, m, n);
    
    //Backtraking
    sol[i][j] = 0;

    if(rightSuccess || downSuccess) return true;

    return false;    
}

//Permutations
void permute(char *in, int i){
    //Base case
    if(in[i] == '\0'){
        cout<<in<<" ";
        return;
    }

    //Rec Case
    for(int j=i;in[j]!='\0';j++){
        swap(in[i],in[j]);
        permute(in, i+1);

        //Backtracking - To restore the original array.
        swap(in[i],in[j]);
    }
}


int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output2.txt", "w", stdout);
// #endif
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
    
    // int a[] = {1,5,2,6,3,0};
    // cout<<firstOccur(a,9,7)<<endl;
    // cout<<lastOccur(a,9,7)<<endl;
    // allOccurs(a,0,9,7);
    // cout<<fastPower(2,10);
    // mergeSort(a,0,9);
    // for(int i=0;i<9;i++)
    //     cout<<a[i]<<" ";
    // quicksort(a,0,5);
    // for(int i=0;i<6;i++) cout<<a[i]<<" ";
    // spellNumber(1000);
    // cout<<stringToInt("123",3);
    // cout<<friendsPairingProblem(3);
    char a[100]; cin>>a;
    // char b[100];
    // generateStrings(a,b,0,0);
    permute(a, 0);
 }