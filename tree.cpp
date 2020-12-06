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
#define all(a)  (a).begin(),(a).end()
#define S second
using namespace std;
const ll l = 1e9+7;

ll dp[100001][2] = {};
 
ll sol(ll a[],ll b[],ll n,ll k)
{
    
   for(ll i = 1; i <= n; i++)
   {
      for(ll j = 1; j <= k; j++)
      {
        if(j >= a[i-1])
          dp[j][1] = max(dp[j][0] , b[i-1] + dp[j-a[i-1]][0]);
        else
          dp[j][1] = dp[j][0];
      }

      for(ll j = 1; j <= k; j++)
        dp[j][0] = dp[j][1];

   }

   return dp[k][1];
}

 
struct node 
{ 
    int data; 
    struct node *left, *right; 
}; 

node *newnode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 


void solvedw(node *root, int k) 
{ 
     
    if (root == NULL || k < 0)  return; 
   
    if (k==0) 
    { 
        cout << root->data << " "; 
        return; 
    } 
  
    
    solvedw(root->left, k-1); 
    solvedw(root->right, k-1); 
} 


 
int sol(node* root, node* target , int k) 
{ 
 
    if (root == NULL) return -1; 
  
     
    if (root == target) 
    { 
        solvedw(root, k); 
        return 0; 
    } 
  
     
    int dl = sol(root->left, target, k); 
  
     
    if (dl != -1) 
    { 
          
         if (dl + 1 == k) 
            cout << root->data <<" "; 
   
         else
            solvedw(root->right, k-dl-2); 
   
         return 1 + dl; 
    } 
  
     
    int dr = sol(root->right, target, k); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            cout << root->data << " "; 
         else
            solvedw(root->left, k-dr-2); 
         return 1 + dr; 
    } 
    
    return -1; 
} 




   

int main()
{
     #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     #endif
      
     
    node * root = newnode(20); 
    root->left = newnode(8); 
    root->right = newnode(22); 
    root->left->left = newnode(4); 
    root->left->right = newnode(12); 
    root->left->right->left = newnode(10); 
    root->left->right->right = newnode(14); 

    node* t = root -> left;//target = 8 && k = 2
    sol(root,t,2);
    cout<<endl;
    t = root->left->right->right;//target = 14 && k = 3
    sol(root,t,3);
    cout<<endl;
    t = root->left->right;//target = 12 && k = 2
    sol(root,t,2);
 
} 