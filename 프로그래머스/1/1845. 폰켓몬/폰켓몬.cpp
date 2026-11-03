#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    
    for(int n : nums) {
        s.insert(n);
    }
    
    if((nums.size())/2 < s.size()) return (nums.size())/2;
    else return s.size();
}