#include <cmath>
#include <cstdio>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>
using namespace std;

void query(const vector<int> &v, int n, int i, int j, int *k_index){
    // j + 1 to account for the fact that array index are counted from 0
    cout << v.at(*(k_index + i) + j + 1) << endl;
}

int main() {
    
    // declare the variables that will be used
    int n, q, k, i, j;
    int element;
    vector <int> v;
    
    // take the values of n and q
    cin >> n >> q;
    
    // for loop to take the input of all arrays and storing in vector v
    // first store index of array a[n], followed by the number of elements the array referenced at that location is going to have, k and then the elements of that array.
    for (int x = 0; x < n; ++x){
        v.push_back(x);
        cin >> k;
        v.push_back(k);
        for (int y = 0; y < k; ++y) {
            cin >> element;
            v.push_back(element);
        }
    }
    
    // creating an array to hold the indices the value of k is stored at
    int k_index[n];
    k_index[0] = 1;
    for (int index = 1; index < n; ++index){
        k_index[index] = k_index[index-1] + v.at(k_index[index-1]) + 2;
    }
    
    for (int z = 0; z < q; ++z){
        cin >> i >> j;
        query(v, n, i, j, k_index);
    }
    
    return 0;
}