#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        long long answer = 0;
        int maxPrice = 0;

        for (int i = N - 1; i >= 0; i--) {
            if (v[i] > maxPrice) {
                maxPrice = v[i];
            } else {
                answer += maxPrice - v[i];
            }
        }

        cout << "#" << test_case << ' ' << answer << '\n';
    }

    return 0;
}