#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    
    sort(score.rbegin(), score.rend());
        
    int tmp = k;
    int result = 0;
    for(int i=0; i<(score.size()/m); i++){
        for(int j=0; j<m; j++) {
            if(tmp>score[i*m+j]) tmp = score[i*m+j];
        }
        result += (tmp * m);
    }
    
    return result;
}