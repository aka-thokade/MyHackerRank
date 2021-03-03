#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int a[1000], n;

    cin>>n;
    
    //take inputs in array
    for (int i = 0; i < n; ++i){
        cin>>a[i];
    }

    //print array in rev order
    for (int i = n-1; i >= 0; --i){
        cout<<a[i]<<" ";
    }

    return 0;
}