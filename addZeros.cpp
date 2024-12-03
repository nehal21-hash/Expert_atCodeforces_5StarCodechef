
// Topic Name is :- Dynamic programming , Dfs , binarySearch used in this problem



#include <bits/stdc++.h>

using namespace std;


const int N = 3e5+10;
long long dp[N];

long long upper_limit(long long size,vector<pair<long long,long long>>&v){
	int l =0,h = v.size()-1;
	while(h-l>1){
		int mid = (l+h)/2;
		if(v[mid].first-size>0){
			h = mid-1;
		}else{
			l = mid;
		}
	}
	if(v[h].first-size != 0 && v[l].first-size != 0){
		return -1;
	}
	if(v[h].first-size == 0){
		return h;
	}
	return l;
}
long long lower_limit(long long size,vector<pair<long long,long long>>&v){
	int l = 0,h= v.size()-1;
	while(h-l>1){
		int mid = (l+h)/2;
		if(v[mid].first-size<0){
			l = mid+1;
		}else{
			h = mid;
		}
	}
	if(v[l].first-size != 0 && v[h].first-size !=0){
		return -1;
	}
	if(v[l].first-size == 0){
		return l;
	}
	return h;
}
long long addZeros(long long size,vector<pair<long long,long long>>&v){
	int h = upper_limit(size,v),l = lower_limit(size,v);
	if(h == -1 || l == -1){
		return 0;
	}
	long long result = 0;
	for(int i=l;i<=h;++i){
		if(v[i].second == 0){
			continue;
		}
		if(dp[v[i].second]!= -1){
			result = max(result,dp[v[i].second]);
			continue;
		}
		long long val = addZeros(size+v[i].second,v);
		dp[v[i].second] = val+v[i].second;
		result = max(result,val+v[i].second);
	}
	return result;
}

void solve(){
	long long n;
	cin>>n;
	vector<pair<long long,long long>>v(n);
	for(int i=0;i<n;++i){
		cin>>v[i].first;
		v[i].second = i;
		v[i].first = v[i].first+i;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<N;++i){
		dp[i] = -1;
	}
	long long result = n+addZeros(n,v);
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
