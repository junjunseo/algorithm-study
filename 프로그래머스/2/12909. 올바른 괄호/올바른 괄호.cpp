#include<string>
#include <iostream>

using namespace std;

bool solution(string s){
    
    int cnt = 0;
    
    for(int i=0;i<s.size();i++){
        if(cnt<0) break;
        if(s[i]=='(') cnt += 1;
        if(s[i]==')') cnt -= 1;
    }
    
    if(cnt == 0) return true;
    else return false;
}