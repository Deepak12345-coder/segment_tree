#include <bits/stdc++.h>
using namespace std;
    int query(int ind,int low,int high,int l,int r,vector<int>&tree)
    {    
        // no overlap part
         if(r<low  || l>high) return INT_MAX;
         // complete overlap
         if(l<=low && high<=r) return tree[ind];
         int mid=(low+high)>>1;
      int left=   query(2*ind+1,low,mid,l,r,tree);
      int right=   query(2*ind+2,mid+1,high,l,r,tree);
      return min(left,right);
}
 
  void build(vector<int>&vs,int ind,int low,int high,vector<int>&tree)
  {
      if(low==high)
      {
          tree[ind]=vs[low];
          return ;
      }  
      int mid=(low+high)/2;
      build(vs,2*ind+1,low,mid,tree);
      build(vs,2*ind+2,mid+1,high,tree);
      tree[ind]=min(tree[2*ind+1],tree[2*ind+2]);
}

int main() {
    int n;
    cin>>n;
    vector<int>vs(n);
    vector<int>tree(4*n,0);
    for(int i=0;i<n;i++)
    {
        cin>>vs[i];
    } 
    build(vs,0,0,n-1,tree);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r,tree)<<endl;
    }
   return 0;
}
