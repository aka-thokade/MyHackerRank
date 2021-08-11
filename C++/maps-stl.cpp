#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int test_case, type, marks;
    string name;

    map <string, int> stud_marks;
    stud_marks.clear();

    cin >> test_case;

    for(int i = 0; i < test_case; ++i){
        cin >> type;
        switch (type)
        {
            case 1:
                cin >> name;
                cin >> marks;
                stud_marks[name] += marks;
                break;

            case 2:
                cin >> name;
                stud_marks[name] = 0;
                break;

            case 3:
                cin >> name;
                cout << stud_marks[name] << endl;
                break;

            default:
                break;
        }
    }

    return 0;
}