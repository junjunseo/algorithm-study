#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    for(int i=0; i<sizes.size(); i++) {
        if(sizes[i][0]<sizes[i][1]) {
            int tmp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = tmp;
        }
    }
    
    vector<int> rows;
    vector<int> cols;
    
    for(int i = 0; i<sizes.size(); i++) {
        rows.push_back(sizes[i][0]);
        cols.push_back(sizes[i][1]);
    }
    
    sort(rows.begin(), rows.end(), greater<int>());
    sort(cols.begin(), cols.end(), greater<int>());
    
    return rows[0] * cols[0];
}