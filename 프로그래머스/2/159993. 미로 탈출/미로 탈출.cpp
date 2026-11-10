#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<string> & maps, int startX, int startY, int endX, int endY) {
    
    int n = maps.size();
    int m = maps[0].size();
    
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({startX, startY});
    dist[startX][startY] = 0;
    
    while(!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        
        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m)
                continue;
            
            if(dist[nx][ny] != -1)
                continue;
            
            if(maps[nx][ny] == 'X')
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }
    return dist[endX][endY];
}


int solution(vector<string> maps) {
    
    int n = maps.size();
    int m = maps[0].size();
    
    int startX, startY, endX, endY, resultX, resultY;
    
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(maps[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            
            if(maps[i][j] == 'L') {
                endX = i;
                endY = j;
            }
            
            if(maps[i][j] == 'E') {
                resultX = i;
                resultY = j;
            }
        }
    }
    
    int answer1 = bfs(maps, startX, startY, endX, endY);
    int answer2 = bfs(maps, endX, endY, resultX, resultY);
    
    if(answer1 == -1 || answer2 == -1) return -1;
    
    else return answer1+ answer2;
    
}