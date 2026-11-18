#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    
    vector<int> first{1, 2, 3, 4, 5};
    vector<int> second{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    
    for(int i=0; i<answers.size(); i++) {
        if(first[i%5]==answers[i]) cnt1++;
        if(second[i%8]==answers[i]) cnt2++;
        if(third[i%10]==answers[i]) cnt3++;
    }
    
    vector<int> answer;
    
    int highest = max({cnt1, cnt2, cnt3});
    
    if(cnt1 == highest) answer.push_back(1);
    if(cnt2 == highest) answer.push_back(2);
    if(cnt3 == highest) answer.push_back(3);
    
    return answer;
    
}