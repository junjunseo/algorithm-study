#include <vector>
#include <iostream>
using namespace std;

int isPrime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}

int solution(vector<int> nums) {
    
    int count = 0;
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size();k++){
                int tmp = nums[i]+nums[j]+nums[k];
                if(isPrime(tmp))
                    count+=1;
            }
        }
    }
    return count;
}
    
