#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < sizes.size(); i++) {
        int longer = max(sizes[i][0], sizes[i][1]);
        int shorter = min(sizes[i][0], sizes[i][1]);

        maxRow = max(maxRow, longer);
        maxCol = max(maxCol, shorter);
    }

    return maxRow * maxCol;
}