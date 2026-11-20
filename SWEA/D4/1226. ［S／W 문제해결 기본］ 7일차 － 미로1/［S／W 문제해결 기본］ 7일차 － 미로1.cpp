#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{

	for(int test_case = 1; test_case <= 10; ++test_case)
	{
        int tc;
        cin>>tc;
        // 답 저장 flag
		int flag = 0;
        
        // 문자열 16줄 짜리 미로 입력받기
        vector<string> maze(16);
		for(int i=0; i<16; i++) {
            cin>>maze[i];
        }
        
        // 방문한 노드 기록용 2차원 벡터
        vector<vector<int>> visited(16, vector<int>(16, -1));
        
        // 초기 위치 (1,1)
        int x=1;
        int y=1;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;
        
        while(!q.empty() && flag==0) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            
            for(int d=0; d<4; d++) {
                int nx=x+dx[d];
                int ny=y+dy[d];
                
                if(nx<0 || nx>=16 || ny<0 || ny>= 16) continue;
                if(visited[nx][ny] == 1) continue;
                if(maze[nx][ny] == '1') continue;
                
                if(maze[nx][ny] == '3') {
                    flag = 1;
                    break;
                }
                
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        cout<<"#"<<test_case<<' '<<flag<<"\n";
    }
	return 0;
}