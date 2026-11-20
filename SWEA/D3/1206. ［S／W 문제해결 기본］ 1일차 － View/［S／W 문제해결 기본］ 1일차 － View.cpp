#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T=10;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 누적 합 저장
    	int sum = 0;
        
        //건물 높이 배열 v
        vector<int> v;
        
        // 건물 수 N
        int N;
        cin>>N;
        
		for(int i=0; i<N; i++) {
            // 건물 높이 height
            int height;
            cin>>height;
            v.push_back(height);
        }
        
        for(int i=2; i<N-2; i++) {
            int neighbor = max(max(v[i-2], v[i-1]), 
                               			max(v[i+1], v[i+2]));
            if(v[i]>neighbor) {
                sum += v[i]-neighbor;
            }
        }
        
        cout<<"#"<< test_case << ' ' << sum<<"\n";       
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}