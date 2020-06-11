/*
    插入算法
*/

#include<iostream>
using namespace std;

bool smaller(int &, int &);

void exch(int *, int, int);

void printArr(int *, int &);

int main(){
    int n, a[100];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=1;i<n;i++){
        for(int j=i;j>0 && smaller(a[j], a[j-1]);j--){
            exch(a, j, j-1);
        }
    }

    printArr(a, n);

    cout << endl;

    return 0;
}

bool smaller(int &a, int &b){
    return a < b;
}

void exch(int *a, int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;   
}

void printArr(int *a, int &n){
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}