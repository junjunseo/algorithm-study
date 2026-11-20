#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, L;
int answer;
vector<pair<int, int>> ingredients;

void dfs(int idx, int scoreSum, int calSum) {
    // 제한 칼로리를 넘으면 이 조합은 더 탐색하지 않음
    if (calSum > L) {
        return;
    }

    // 모든 재료를 넣을지 말지 결정했다면 정답 갱신
    if (idx == N) {
        answer = max(answer, scoreSum);
        return;
    }

    // 현재 재료를 넣는 경우
    dfs(idx + 1,
        scoreSum + ingredients[idx].first,
        calSum + ingredients[idx].second);

    // 현재 재료를 넣지 않는 경우
    dfs(idx + 1, scoreSum, calSum);
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> L;

        ingredients.clear();
        answer = 0;

        for (int i = 0; i < N; i++) {
            int score, cal;
            cin >> score >> cal;
            ingredients.push_back({score, cal});
        }

        dfs(0, 0, 0);

        cout << "#" << tc << " " << answer << '\n';
    }

    return 0;
}