#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    
    int n = cards.size();
    vector<int> counts;
    
    for(int j = 0; j<n; j++){
        int cnt = 0;
        int i = j;
        while(true) {
            if(cards[i]==0) break;
            cnt += 1;
            int tmp = cards[i];
            cards[i] = 0;
            i = tmp-1;
            
        }
        counts.push_back(cnt);
    }
    sort(counts.rbegin(), counts.rend());
    return counts[0] * counts[1];
}