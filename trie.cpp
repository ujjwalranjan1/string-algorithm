
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define endl '\n'
const int N=1e5+5;
const int pr2=999999937;
const int pr3=999999929;


struct node{
  node *a[26];
  int cnt;
  vector<string>send;

  node(){
  cnt=0;
  send.clear();
  for(int i=0;i<26;i++)
    a[i]=NULL;
  }

};

struct trie{
  node *root;
  trie(){
    root=new node;
  }

  void insertt(string s)
  {
    node *cur=root;
    for(auto it:s)
    {
      cur->cnt++;
      int k=it-'a';
      if(cur->a[k]==NULL)
        cur->a[k]=new node;
      cur=cur->a[k];
    }
    cur->cnt++;
    cur->send.push_back(s);
  }

  bool ispresent(string s)
  {
    node *cur=root;
    for(auto it:s)
    {
      if(cur==NULL)
        return 0;
      int k=it-'a';
      cur=cur->a[k];
    }
    if(cur->send.size())
      return 1;
    else
      return 0;
  }

  void erasee(string s)
  {
    node *cur=root;
    if(ispresent(s))
    {
      for(auto it:s)
      {
        cur->cnt--;
        int k=it-'a';
        cur=cur->a[k];
      }
      cur->cnt--;
      cur->send.clear();
    }
  }

  void dfs(node* cur)
  {
    if(cur->cnt==0)
      return;
    if(cur->send.size()!=0)
      cout<<cur->send[0]<<endl;
    for(int i=0;i<26;i++)
    {
      if(cur->a[i]!=NULL)
        dfs(cur->a[i]);
    }
  }

  void printt()
  {
    node *cur=root;
    dfs(root);
  }

};


void solve()
{
  int n;
  cin>>n;
  trie t;
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    t.insertt(s);
  }
  t.printt();
  cout<<endl;
  string d;
  cin>>d;
  t.erasee(d);
  t.printt();
  cout<<endl;
  cin>>d;
  t.erasee(d);
  t.printt();

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
