#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 테스트케이스 개수 입력 없이 총 10개
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int N;
        cin >> N;

        vector<string> board(8);
        for (int i = 0; i < 8; i++) {
            cin >> board[i];
        }

        int cnt = 0;

        // 오른쪽, 아래쪽만 검사해서 중복 방지
        int dr[2] = {0, 1};
        int dc[2] = {1, 0};

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                for (int d = 0; d < 2; d++) {
                    int endR = i + dr[d] * (N - 1);
                    int endC = j + dc[d] * (N - 1);

                    // 끝점이 범위 밖이면 다음 방향 검사
                    if (endR >= 8 || endC >= 8) continue;

                    int chk = 1;

                    // 양 끝에서 안쪽으로 마주 보는 글자 비교
                    for (int k = 0; k < N / 2; k++) {
                        int r1 = i + dr[d] * k;
                        int c1 = j + dc[d] * k;

                        int r2 = i + dr[d] * (N - 1 - k);
                        int c2 = j + dc[d] * (N - 1 - k);

                        if (board[r1][c1] != board[r2][c2]) {
                            chk = 0;
                            break;
                        }
                    }

                    if (chk == 1) cnt++;
                }
            }
        }

        cout << "#" << test_case << ' ' << cnt << '\n';
    }

    return 0;
}