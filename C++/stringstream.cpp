#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector <int> answer;
    
    int a;
    char ch;
    
    stringstream ss(str);
    
    while(!ss.eof()){
        ss >> a >> ch;
        answer.push_back(a);
    }
    
    
        
    return answer;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0; 
}
