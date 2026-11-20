#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    
    unordered_set<string> nums(phone_book.begin(), phone_book.end());
    
    for(const string& num:phone_book) {
        string prefix;
        
        for(int i = 0; i<num.size()-1; i++) {
            prefix.push_back(num[i]);
            
            if(nums.find(prefix)!=nums.end()) {
                return false;
            }
        }
    }
    
    return true;
}