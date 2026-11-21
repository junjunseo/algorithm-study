#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	
	for(test_case = 1; test_case <= 10; ++test_case)
	{
        int N;
        cin>>N;
        vector<int> v(100);
        for(int i=0; i<100; i++) {
            cin>>v[i];
        }
        for(int i=0; i<N; i++) {
            sort(v.begin(), v.end());
            v[0] += 1;
            v[v.size()-1] -=1;
        }
        
        sort(v.begin(), v.end());
        int answer = v[v.size()-1] - v[0];
        
        cout<<"#"<<test_case<<' '<<answer<<"\n";
	}
	return 0;
}