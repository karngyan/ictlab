/*

Author: @karngyan
BE/10546/17

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<ll> vll;

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define cres(c,n) (c).clear(),(c).resize(n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ff first
#define ss second
#define mk make_pair
string s , t;
ll ns , nt ;
ll dp[3010][3010];

ll go(ll i , ll j)
{
	if(i >= ns or j >= nt)
		return 0;
	ll &ans = dp[i][j];
	if(ans != -1)
		return ans;
	if(s[i] == t[j])
		ans = 1 + go(i+1 , j+1);
	else
		ans = max(go(i , j+1) , go(i+1 , j));

	return ans;
}



signed main()
{
	fast;
	memset(dp , -1 , sizeof dp);
	
	cin >> s >> t;
	ns = s.length();
	nt = t.length();
	ll ans = go(0,0);
	// cout<<go(0,0)<<endl;

	ll i = 0, j = 0;
	while(i<ns and j<nt)
	{
		if(s[i] == t[j])
		{
			cout<<s[i];
			i++, j++;
		}
		else
		{
			if(dp[i+1][j] > dp[i][j+1])
				i++;
			else
				j++;
		}
	}


    cout << endl;

	
	return 0;
}

