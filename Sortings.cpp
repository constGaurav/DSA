// #include <bits/stdc++.h>
#include <iostream>
#include <climits>
using namespace std;

void bubbleSort(int a[], int n){
	for(int i=0;i<n;i++){
		 for(int j=0;j<n-1-i;j++){
		 	if(a[j] > a[j+1]){
		 		int temp = a[j];
		 		a[j] = a[j+1];
		 		a[j+1] = temp;
		 	}
		 }
	}
}

void selectionSort(int a[], int n){
	for(int i=0;i<n-1;i++){
		int imin = i;
		for(int j=i+1;j<n;j++){
			if(a[j] < a[imin]){
				imin = j;
			}
		}
		int temp = a[i];
		a[i] = a[imin];
		a[imin] = temp;
	}
}


void insertionSort(int a[], int n){
	for(int i=0;i<n;i++){
		int value = a[i];
		int hole = i;
		while(hole > 0 && a[hole-1] > value){
			a[hole] = a[hole-1];
			hole = hole-1;
		}
		a[hole] = value;
	}
}

// merge Sort
void merge(int a[], int s, int mid, int e){
    // 1 5 6 | 2 3 4  
    int xSz = mid-s+1;
    int ySz = e-mid;
    int x[xSz];
    int y[ySz];

    for(int i=0;i<xSz;i++)
        x[i] = a[s+i];
    for(int i=0;i<ySz;i++)
        y[i] = a[mid+1+i];

    int i=0,j=0,k=s;
    while(i<xSz and j<ySz){
        if(x[i]<y[j]){
            a[k++] = x[i++];
        } else a[k++] = y[j++];
    }

    while(i<xSz)
        a[k++] = x[i++];
    while(j<ySz)
        a[k++] = y[j++];
}

void mergeSort(int a[],int s,int e){
    if(s<e){
        int mid = (s+e)/2;
        mergeSort(a,s,mid);
        mergeSort(a,mid+1,e);
        merge(a,s,mid,e);
    }   
    return;
}

// Quick Sort
int partition(int a[], int l, int h){
    int i = l, j = h;
    int pivot = a[l];
    while (i<j) {
        while (a[i] <= pivot && i<j)
            i++;
        while (a[j] > pivot && i<=j)
            j--;
        if (i<j)
            swap(a[i],a[j]);
    }
    swap(a[l], a[j]);
    return j;
}

void QuickSort(int a[], int l, int h){
    if(l<h){
        int pivot = partition(a, l, h);
        QuickSort(a, l, pivot-1);
        QuickSort(a, pivot + 1, h);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


	
	return 0;
}