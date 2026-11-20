#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void makeNumbers(const string& numbers,
                 vector<bool>& used,
                 int current,
                 unordered_set<int>& candidates) {
    for (int i = 0; i < numbers.size(); i++) {
        if (used[i]) continue;

        int next = current * 10 + (numbers[i] - '0');

        candidates.insert(next);

        used[i] = true;
        makeNumbers(numbers, used, next, candidates);
        used[i] = false;
    }
}

bool isPrime(int n) {
    
    if(n<2) return false;
    
    for(int i=2; i*i <= n; i++) {
        if(n%i==0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    
    vector<bool> used(numbers.size(), false);
    unordered_set<int> candidates;
    
    makeNumbers(numbers, used, 0, candidates);
    
    int answer = 0;
    
    for (int number : candidates) {
        if (isPrime(number)) {
            ++answer;
        }
    }
    
    return answer;
}