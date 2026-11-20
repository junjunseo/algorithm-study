#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(maps[i][j] == 'X' || visited[i][j]) {
                continue;
            }
            
            int sum = 0;
            
            q.push({i, j});
            visited[i][j] = true;
            
            while(!q.empty()) {
                auto[x,y] = q.front();
                q.pop();
                
                sum += maps[x][y] - '0';
                
                for(int d = 0; d < 4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    
                    if(maps[nx][ny] == 'X')
                        continue;
                    
                    if(visited[nx][ny])
                        continue;
                    
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }           
            answer.push_back(sum);
        }
    }
    if(answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}