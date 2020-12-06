#include<bits/stdc++.h>

#define ll long long int
#define f(i,n) for(ll i = 0; i < n ; i++)
#define F first 
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define nl cout<<endl
#define pb push_back
#define pb push_back
#define F first
#define S second
#define vi  vector<ll>
#define S second
using namespace std;
const ll l = 1e9+7;


 void fun(vector<vector<int>>& a) {


        queue<pair<int,int>> q;

        int fr = 0;
        int r = a.size();
        int c = a[0].size();
        int ans = 0;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(a[i][j]==2)
                    q.push({i,j});
                else if(a[i][j]==1)
                    fr++;
            }
        }

        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x>0 && a[x-1][y]==1)
                {
                    a[x-1][y] = 2;
                    fr--;
                    q.push({x-1,y});
                }
                if(y>0 && a[x][y-1]==1)
                {
                    a[x][y-1] = 2;
                    fr--;
                    q.push({x,y-1});
                }
                if(x<r-1 && a[x+1][y]==1)
                {
                    a[x+1][y] = 2;
                    fr--;
                    q.push({x+1,y});
                }
                if(y<c-1 && a[x][y+1]==1)
                {
                    a[x][y+1] = 2;
                    fr--;
                    q.push({x,y+1});
                }
            }
            if(!q.empty())
                ans++;
        }
        int ro = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(a[i][j] == 2)
                    ro++;
       
        cout<<"time frames :" <<ans<<endl;
        cout<<"fr oranges:" <<fr<<endl;
        cout<<"rotte oranges:" <<ro<<endl;
        return ;
    }
   

int main()
{
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif

    
     int n,m;
     cin>>n>>m;
     vector <vector<int>> v;
     vector<int> v1;

      for(int i = 0; i < n; i++)
      {
            for(int j = 0; j < m; j++)
              {
                int x; cin>>x;
                v1.pb(x);
              }  
              v.pb(v1); v1.clear();
      }
      
      fun(v);
    
 

} 