#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 스도쿠 맵 생성 및 입력
		vector<vector<int>> map(9, vector<int>(9));
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cin>>map[i][j];
            }
        }
        
        // 답 기본 값 1
        int answer=1;
        
        // 모든 칸에 대해 검사
        for(int i=0; i<9 && answer==1; i++) {
            for(int j=0; j<9 && answer==1; j++) {
                for(int k=0; k<9; k++) {
                    // 행 검사
                    if(k!=j && map[i][k] == map[i][j]) {
                        answer = 0;
                        break;
                    }
                    // 열 검사
                    if(k!=i && map[k][j] == map[i][j]) {
                        answer = 0;
                        break;
                    }
                }
                // 9칸 검사
                int isection = i/3;
                int jsection = j/3;
                for(int irange = isection*3; irange<isection*3+3; irange++) {
                    for(int jrange = jsection*3; jrange<jsection*3+3; jrange++) {
                        if(irange != i && jrange != j && map[irange][jrange] == map[i][j]) {
                            answer = 0;
                            break;
                        }
                    }
                    if(answer==0) break;
           		}
        	}
		}
        cout<<"#"<<test_case<<' '<<answer<<"\n";
    }
	return 0;
}