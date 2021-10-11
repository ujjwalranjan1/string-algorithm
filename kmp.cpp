
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define endl '\n'
const int N=1e5+5;
const int pr2=999999937;
const int pr3=999999929;


int pi[N];
void kmp(string s)
{
  int n=s.size();
  int i=0,j=-1;pi[0]=-1;
  while(i<n)
  {
    while(j!=-1 && s[i]!=s[j])j=pi[j];
    j++,i++;
    pi[i]=j;
  }
}

void print(int n)
{
  for(int i=1;i<=n;i++)
    cout<<pi[i]<<" ";
  cout<<endl;
}

void solve()
{

  string s;
  //abcabyabxabcabcaby
  cin>>s;
  int n=s.size();
  kmp(s);
  print(n);

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
