#include<iostream>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)	{
        int N, M;
        cin>>N>>M;
        // N*N 보드 생성, 초기값 -1
        vector<vector<int>> board(N, vector<int>(N, -1));
        // 초기 4개의 말 생성
        board[N/2-1][N/2-1] = 2;
        board[N/2][N/2] = 2;
        board[N/2-1][N/2] = 1;
        board[N/2][N/2-1] = 1;
        
        int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        
        for(int i=0; i<M; i++) {
            int x, y, color;
            cin>>x>>y>>color;
            --x;
            --y;
            board[x][y] = color;
            for(int dir = 0; dir<8; dir++) {
               	int nx = x+dx[dir];
                int ny = y+dy[dir];
                queue<pair<int, int>> q;
                while(true) {
                    // 보드 범위 벗어나면 해당 방향 탐색 종료
                    if(nx>=N || nx<0 || ny>=N || ny<0) break;
                    
                    // 빈 칸 발견하면 해당 방향 탐색 종료
                    if(board[nx][ny] == -1) break;
                    
                    // 본인과 다른 색이면 큐에 넣고 다음 위치로
                    if(board[nx][ny] != color) {
                        q.push({nx, ny});
                        nx += dx[dir];
                        ny += dy[dir];
                        continue;
                    }
                    
                    // 본인과 같은 색 말을 발견하면 이전 말들을 본인과 같은 색깔로
                    if(board[nx][ny] == color) {
                        while(!q.empty()) {
                            int tmpx = q.front().first;
                            int tmpy = q.front().second;
                            board[tmpx][tmpy] = color;
                            q.pop();
                        }
                        break;
                    }
                }
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j]==1) cnt1++;
                if(board[i][j]==2) cnt2++;
            }
        }
        cout<<"#"<<test_case<<' '<<cnt1<<' '<<cnt2<<"\n";
    }
    return 0;
}