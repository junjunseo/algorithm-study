#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    int tmp = brown + yellow;
    
    vector<int> divisor;
    
    for(int i = 1; i<tmp; i++) {
        if(tmp%i==0) divisor.push_back(i);
    }
    
    int length = 0;
    int height = 0;
    
    for(int i = 0; i<divisor.size(); i++) {
        for(int j = i; j<divisor.size(); j++) {
            if((divisor[i]*divisor[j] == tmp) 
               && divisor[i]*divisor[i]<=tmp 
               && (divisor[j]-2) * (divisor[i]-2) == yellow) {
                length = divisor[j];
                height = divisor[i];
            }
        }
    }
    
    vector<int> answer;
    answer.push_back(length);
    answer.push_back(height);
    
    return answer;
}