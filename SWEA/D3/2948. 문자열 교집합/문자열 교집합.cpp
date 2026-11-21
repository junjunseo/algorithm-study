#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // N, M 입력
		int N, M;
        cin>>N>>M;
        
        unordered_map<string, int> dictionary;
        
        for(int i = 0; i<N; i++) {
            string word;
            cin>>word;
            dictionary[word]++;
        }
        
        for(int j=0; j<M; j++) {
            string word;
            cin>>word;
            dictionary[word]++;
        }
        
        int answer=0;
        
		for(const auto& item:dictionary) {
            if(item.second>=2) answer++;
        }
        cout<<"#"<<test_case<<' '<<answer<<"\n";
	}
	return 0;
}