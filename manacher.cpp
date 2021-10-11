
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define endl '\n'
const int N=1e5+5;
const int pr2=999999937;
const int pr3=999999929;

void calc(string s)
{
  int n=s.size();
  vector<int>pl(n,0);
  int c=0,r=0;
  for(int i=1;i<n-1;i++)
  {
    int mirror=2*c-i;
    if(i<=r)
      pl[i]=min(r-i,pl[mirror]);
    while(s[i+(pl[i]+1)]==s[i-(pl[i]+1)])
      pl[i]++;

    if(r<i+pl[i])
    {
      c=i;
      r=i+pl[i];
    }
  }
  for(int i=1;i<n-1;i++)
    cout<<pl[i]<<" ";
  cout<<endl;
}

void manacher(string s)
{
  string t="$";
  for(auto c:s)
    t+='#',t+=c;
  t+="#@";
  calc(t);
}


void solve()
{
  string s;
  cin>>s;
  manacher(s);

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
