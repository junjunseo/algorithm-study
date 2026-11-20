#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n>s) {
        vector<int> fault;
        fault.push_back(-1);
        return fault;
    }
    
    int x = s/n;
    int y = s%n;
    
    for(int i=0; i<n-y; i++) {
        answer.push_back(x);
    }
    for(int j=0; j<y; j++) {
        answer.push_back(x+1);
    }
    
    return answer;
}