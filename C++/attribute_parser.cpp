// using vector - not good.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string attributeParser(vector<string> const &HRML_source, string query){
    string answer = "Not Found!";
    
    int HRML_source_size = HRML_source.size();
    int query_size = query.size();

    string QtagName, HtagName;
    string QattributeName, HattributeName;

    int tilda_index = query.find_first_of('~');

    QtagName = query.substr(0, tilda_index);
    QattributeName = query.substr(tilda_index + 1);

    if(QtagName.find(".") == string::npos){
        auto tag_index = find(HRML_source.begin(), HRML_source.end(), QtagName);
        //find_first_of(HRML_source.operator[tag_index], HRML_source.end(), QattributeName.begin(), QattributeName.end());
    }

    
    return answer;
}

void HRMLformat(vector<string> const &HRML, vector<string> &HRML_source, int size){
    string tag, attribute, value;
    int tag_start_index = 1, tag_end_index = 0, attribute_start_index = 0, attribute_end_index = 0, value_start_index = 0, value_end_index = 0;

    for (int i = 0; i < size/2; ++i){
        string HRML_line = HRML.at(i);
        
        //finding tag name
        tag_end_index = HRML_line.find_first_of(" ");
        tag = HRML_line.substr(tag_start_index, tag_end_index);

        //pushing tag in HRML_source
        HRML_source.push_back(tag);

        //trimming out the first tag name
        HRML_line = HRML_line.substr(tag_end_index + 1);

        while(HRML_line.at(0) != '>'){
            //finding attribute name
            //attribute_start_index = 0;
            attribute_end_index = HRML_line.find_first_of(" ");
            attribute = HRML_line.substr(attribute_start_index, attribute_end_index);

            //pushing attribute in HRML_source
            HRML_source.push_back(attribute);

            //trimming out the first attribute name
            HRML_line = HRML_line.substr(attribute_end_index + 4);          // 3 chars are space, '=', space, '\"' 

            //finding attribute value
            //value_start_index = 0;
            value_end_index = HRML_line.find_first_of("\"");
            value = HRML_line.substr(value_start_index, value_end_index);

            //pushing value in HRML_source
            HRML_source.push_back(value);

            //trimming out the first attribute value
            HRML_line = HRML_line.substr(value_end_index + 1);

            //check if the line ended or has more attributes. if more attributes, block repeates.
            if(HRML_line.size() > 2){
                HRML_line = HRML_line.substr(1);
            }
        }

    }
}

int main() {
    int n, q;
    cin >> n >> q;

    string input, output;

    vector<string> HRML = {"<tag1 value = \"HelloWorld\" final = \"final5\">", 
                            "<tag2 name = \"Name1\">",
                            "</tag2>",
                            "</tag1>"}, 
                Queries = {"tag1.tag2~name", "tag1~name", "tag1~value"},
                HRML_source;
    
    //vector<string> HRML, Queries = {"tag1.tag2~name", "tag1~name", "tag1~value"}, HRML_source;

    
    
    /* for(int i = 0; i < n; ++i){
        getline(cin, input);
        HRML.push_back(input);
        input.clear();
    } */ 
    
    /* for(int i = 0; i < q; ++i){
        getline(cin, input);
        Queries.push_back(input);
        input.clear();
    } */

    HRMLformat(HRML, HRML_source, n);

    /* for(int i = 0; i < HRML_source.size(); ++i){
        cout << HRML_source.at(i) << endl;
    } */

    for(int i = 0; i < q; ++i){
        /* output = attributeParser(HRML, Queries.at(i));
        cout << output; */
    }

    return 0;
}
