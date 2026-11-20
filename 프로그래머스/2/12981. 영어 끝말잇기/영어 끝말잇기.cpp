#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    for (int i = 1; i < words.size(); i++) {
        // 앞 단어의 마지막 글자와 현재 단어의 첫 글자 비교
        if (words[i].front() != words[i - 1].back()) {
            return {i % n + 1, i / n + 1};
        }

        // 현재 단어가 이전에 나온 적 있는지 확인
        for (int j = 0; j < i; j++) {
            if (words[i] == words[j]) {
                return {i % n + 1, i / n + 1};
            }
        }
    }

    return {0, 0};
}