
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define endl '\n'
const int N=1e5+5;
const int pr2=999999937;
const int pr3=999999929;


#ifndef ONLINE_JUDGE
#define debarr(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#endif

void manacher(string s)
{
  int n=s.size();
  vector<int> d1(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
      while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
          k++;
      }
      d1[i] = k--;
      if (i + k > r) {
          l = i - k;
          r = i + k;
      }
  }

vector<int> d2(n);
for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
    }
    d2[i] = k--;
    if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
    }
}
for(int i=0;i<n;i++)
  cout<<d2[i]<<" "<<d1[i]<<endl;

}


void solve()
{
  string s;
  cin>>s;
  cout<<s<<endl;
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
