// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
 class segment_tree{ 
     public :
        vector<int>tree;
        vector<int>A;
        int n;
        segment_tree(vector<int>&arr)
        {   n=arr.size();
            tree.resize(4*n,0);
            A=vector<int>(arr.begin(),arr.end());
              build(0,0,n-1);
        }
    int query(int ind,int low,int high,int l,int r)
    {    
        // no overlap part
         if(r<low  || l>high) return INT_MAX;
         // complete overlap
         if(l<=low && high<=r) return tree[ind];
         int mid=(low+high)>>1;
      int left=   query(2*ind+1,low,mid,l,r);
      int right=   query(2*ind+2,mid+1,high,l,r);
      return min(left,right);
}
 
  void build(int ind,int low,int high)
  {
      if(low==high)
      {
          tree[ind]=A[low];
          return ;
      }  
      int mid=(low+high)/2;
      build(2*ind+1,low,mid);
      build(2*ind+2,mid+1,high);
      tree[ind]=min(tree[2*ind+1],tree[2*ind+2]);
}     
  void update(int ind,int val,int low,int high,int i)
   {      
        if(low==high)
           {   
                tree[ind]=val;
               return ;
           } 
        int mid=(low+high)>>1;
        if(i<=mid)
        update(2*ind+1,val,low,mid,i);
        else
        update(2*ind+2,val,mid+1,high,i);
        tree[ind]=min(tree[2*ind+1],tree[2*ind+2]);
  }   
     void update1( int ind , int val)
     {
         update(0,val,0,n-1,ind);
     } 
     void query1(int l,int r)
     {
         cout<<query(0,0,n-1,l,r)<<endl;
     }
      
 };  

int main() {
    int n;
    cin>>n;
    vector<int>vs(n);
    for(int i=0;i<n;i++)
    {
        cin>>vs[i];
    } 
    segment_tree sg(vs);
  
    int q;
    cin>>q;
    while(q--)
    {
       int type;
       cin>>type;
       if(type==1)
       {   int l,r;
           cin>>l>>r;
           sg.query1(l,r);
       }
       else
       {   int ind,val;
           cin>>ind>>val;
           sg.update1(ind ,val);
       }
    }
   return 0;
}
