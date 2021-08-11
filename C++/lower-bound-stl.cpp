#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    
    int size, input, no_of_key, key;
    cin >> size;

    for(int i = 0; i < size; ++i){
        cin >> input;
        v.push_back(input);
    }

    cin >> no_of_key;

    for(int i = 0; i < no_of_key; ++i){
        cin >> key;
        auto low = lower_bound(v.begin(), v.end(), key); 
        if(v[(low - v.begin())] == key){
            cout << "Yes " << (low - v.begin()) + 1 << endl;
        }
        else
            cout << "No " << (low - v.begin()) + 1<< endl;
    }


    return 0;
}
