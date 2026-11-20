#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string, int> count;
    for(const vector<string>& cloth:clothes) {
        count[cloth[1]] += 1;
    }
    
    int result = 1;
    
    for(const pair<const string, int> x:count) {
        result = result * (x.second + 1);
    }
    
    return result-1;
}