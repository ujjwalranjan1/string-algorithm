
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define endl '\n'
const int N=1e5+5;
const int pr2=999999937;
const int pr3=999999929;

vector<int>zfun(string s)
{
  int n=s.size();
  vector<int>z(n,0);
  for(int i=1,l=0,r=0;i<n;i++)
  {
    if(i<=r)
      z[i]=min(r-i+1,z[i-l]);
    while(i+z[i]<n && s[z[i]]==s[i+z[i]])
      z[i]++;
    if(i+z[i]-1>r)
      l=i,r=i+z[i]-1;
  }
  return z;
}


void solve()
{
  string s;
  cin>>s;
  vector<int>v=zfun(s);
  for(auto it:v)
    cout<<it<<" ";
  cout<<endl;

}



int32_t main()
{
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("IN", "r", stdin);
  freopen("OUT", "w", stdout);
  #endif
  int t=1;
  //cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}
