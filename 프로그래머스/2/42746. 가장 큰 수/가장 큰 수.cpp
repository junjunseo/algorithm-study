#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    
    vector<string> values;
    
    for(int num : numbers) {
        values.push_back(to_string(num));
    }
    
    sort(values.begin(), values.end(), compare);
    
    if(values[0] == "0") {
        return "0";
    }
    
    string answer = "";
    
    for(int i=0;i<values.size();i++) {
        answer+=values[i];
    }
    
    return answer;
}