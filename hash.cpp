
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define endl '\n'
const int N=1e5+5;
const int pr1=1e9+7;
const int pr2=999999937;
const int pr3=999999929;
struct fhash{
  int n,m;
  int *fwd,*bwd,*pn;

  void init(string s,int p,int mod)
  {
    n=s.size();
    m=mod;
    fwd=new int[n];
    bwd=new int [n];
    pn=new int [n];

    fwd[0]=s[0]-'a'+1;
    pn[0]=1;
    bwd[0]=s[0]-'a'+1;

    for(int i=1;i<n;i++)
    {
      fwd[i]=((fwd[i-1]*p)%m+s[i]-'a'+1)%m;
      pn[i]=(pn[i-1]*p)%m;
      bwd[i]=(((s[i]-'a'+1)*pn[i])%m+bwd[i-1])%m;
    }
  }

  void print()
  {
    for(int i=0;i<n;i++)
      cout<<fwd[i]<<" ";
    cout<<endl;

    for(int i=0;i<n;i++)
      cout<<bwd[i]<<" ";
    cout<<endl;
  }

  int findfwdhash(int l,int r)
  {
    if(l==0)
      return fwd[r];
    return ((fwd[r]-(fwd[l-1]*pn[r-l+1])%m)%m+m)%m;
  }

  int binpow(int x,int p)
  {
    if(p==0)
      return 1LL;
    int ans=binpow(x,p/2);
    ans=(ans*ans)%m;
    if(p%2)
      ans=(ans*x)%m;
    return ans;
  }

  int modinverse(int x)
  {
    return binpow(x,m-2);
  }

  int findbwdhash(int l,int r)
  {
    if(l==0)
      return bwd[r];
    return ((((bwd[r]-bwd[l-1])%m+m)%m)*modinverse(pn[l]))%m;
  }

};


void solve()
{
  fhash fs1,fs2;
  string s;
  cin>>s;
  fs1.init(s,31LL,pr2);
  fs2.init(s,61LL,pr2);
  fs1.print();
  cout<<fs1.findfwdhash(2,3)<<endl;
  cout<<fs1.findbwdhash(2,3)<<endl;
  fs2.print();
  cout<<fs2.findfwdhash(2,3)<<endl;
  cout<<fs2.findbwdhash(2,3)<<endl;
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
