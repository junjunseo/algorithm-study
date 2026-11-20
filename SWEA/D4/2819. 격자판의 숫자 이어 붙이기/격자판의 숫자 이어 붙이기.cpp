#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>

using namespace std;

void dfs(int startx, int starty, string s, const vector<vector<int>>& board, unordered_set<string>& result) {
    
    if(s.size()==7) {
        result.insert(s);
        return;
    }
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    for(int d=0; d<4; d++) {
        int nx = startx + dx[d];
        int ny = starty + dy[d];
        
        // 보드 범위 벗어나는지 검사
        if(nx>=4 || nx<0 || ny>=4 || ny<0) continue;
        
        dfs(nx, ny, s + to_string(board[nx][ny]), board, result);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 4*4 보드 생성
        vector<vector<int>> board(4, vector<int>(4));
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                cin>>board[i][j];
            }
        }
        
        unordered_set<string> result;
        
        // 각 위치에서 시작하는 모든 경우 16가지
        for(int i=0; i<16; i++) {
            int dx[4] = {1, 0, -1, 0};
            int dy[4] = {0, -1, 0, 1};
            int x = i/4;
            int y = i%4;
            
            dfs(x, y, to_string(board[x][y]), board, result);
        }
        cout<<"#"<<test_case<<' '<<result.size()<<"\n";
    }
    return 0;
}