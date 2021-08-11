#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std; 

string attributeParser(map<string, map<string, string>> &HRML_source, string query){
    string answer = "Not Found!";

    string QtagName, QattributeName;

    int tilda_index = query.find_first_of('~');

    QtagName = query.substr(0, tilda_index);
    QattributeName = query.substr(tilda_index + 1);

    if(QtagName.find(".") == string::npos){
        answer = HRML_source[QtagName][QattributeName];
    }
    else{
        int last_dot_index = QtagName.find_last_of(".");
        QtagName = QtagName.substr(last_dot_index + 1);
        answer = HRML_source[QtagName][QattributeName];
    }

    return (answer != "") ? answer : "Not Found!";
}

void HRMLformat(vector<string> const &HRML, map<string, map<string, string>> &HRML_source, int const &size){
    string tag, attribute, value;
    int tag_start_index = 1, tag_end_index = 0, attribute_start_index = 0, attribute_end_index = 0, value_start_index = 0, value_end_index = 0;

    for (int i = 0; i <= size/2; ++i){
        string HRML_line = HRML.at(i);
        if(!HRML_line.empty()){
            map<string, string> attributeValue;

            //finding tag name
            tag_end_index = HRML_line.find_first_of(" ");
            if(tag_end_index != string::npos)
                tag = HRML_line.substr(tag_start_index, tag_end_index-1);
            else{
                tag_end_index = HRML_line.find(">");
                tag = HRML_line.substr(tag_start_index, tag_end_index-1);
                attributeValue.clear();
                HRML_source[tag] = attributeValue;
            }

            //trimming out the first tag name
            HRML_line = HRML_line.substr(tag_end_index + 1);

            while(HRML_line.at(0) != '>'){
                //finding attribute name
                //attribute_start_index = 0;
                attribute_end_index = HRML_line.find_first_of(" ");
                attribute = HRML_line.substr(attribute_start_index, attribute_end_index);

                //trimming out the first attribute name
                HRML_line = HRML_line.substr(attribute_end_index + 4);          // 3 chars are space, '=', space, '\"' 

                //finding attribute value
                //value_start_index = 0;
                value_end_index = HRML_line.find_first_of("\"");
                value = HRML_line.substr(value_start_index, value_end_index);

                //adding attribute and its value in attributValue map
                attributeValue[attribute] = value;

                //trimming out the first attribute value
                HRML_line = HRML_line.substr(value_end_index + 1);

                //check if the line ended or has more attributes. if more attributes, block repeates.
                if(HRML_line.size() > 2){
                    HRML_line = HRML_line.substr(1);
                }
            }

            HRML_source[tag] = attributeValue;
            attributeValue.clear();
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    string input, output;

    vector<string> HRML, Queries;
    
    map<string, map<string, string>> HRML_source;
    
    for(int i = 0; i <= n; ++i){
        getline(cin, input);
        HRML.push_back(input);
        input.clear();
    }
    
    for(int i = 0; i < q; ++i){
        getline(cin, input);
        Queries.push_back(input);
        input.clear();
    }

    HRMLformat(HRML, HRML_source, n);

    for(int i = 0; i < q; ++i){
        output = attributeParser(HRML_source, Queries.at(i));
        cout << output << endl;
    }

    return 0;
}
