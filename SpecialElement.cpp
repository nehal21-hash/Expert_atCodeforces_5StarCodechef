
// Topic Name Brute Force,mapping 


// Time complexity is O(n^2)



#include <bits/stdc++.h>

using namespace std;

bool check(vector<long long>&v,long long val){
	int i =0,j = 1,n = v.size();
	long long sums = v[i]+v[j];
	bool ok = false;
	while(i<n && j<n){
		if(i == j){
			sums = 0;
			j++;
			if(i<n){
				sums+=v[i];
			}
			if(j<n){
				sums+=v[j];
			}else{
				break ;
			}
		}
		if(sums == val){
			return true;
		}
		if(sums<val){
			j++;
			sums+=v[j];
		}else{
			sums-=v[i];
			i++;
		}
	}
	return false;
}

void solve(){
	int n;
	cin>>n;
	vector<long long>v(n);
	for(auto &x:v){
		cin>>x;
	}	
	int result =0;
	
	for(int i=0;i<n;++i){
		bool ok = check(v,v[i]);
		result+=ok;
	}
	cout<<result<<endl;
	return ;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	solve();
    }
    return 0;
}
