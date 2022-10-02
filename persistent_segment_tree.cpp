#include<bits/stdc++.h>
using namespace std;
#define sz 200005
struct node{
 	node *left, *right;
  	int val,leftval,rightval;
  	node(int a = 0, int d=0,int e=0,node *b = NULL, node *c = NULL) :
    	val(a), left(b), right(c),leftval(d),rightval(e) {} // ** Constructor
    
    void build(int l, int r) { 
    	if(l == r) return; 
    	left = new node(); 
    	right = new node();
    	int mid = (l+r)/2;
    	left -> build(l, mid);
    	right -> build(mid+1, r);
  	}
  	node *update(int l, int r, int idx, int v) {  
    	if(r < idx || l > idx) return this; 
    	if(l == r) {  
    		node *ret = new node(val,leftval,rightval,left, right) ;     
      		ret -> val += v;
      		
      		return ret;
      	}
    	int mid = l + r >> 1;
    	node *ret = new node(val);
    	ret -> left = left -> update(l, mid, idx, v);
    	ret -> right = right -> update(mid+1, r, idx, v);
        ret -> val = ret -> left -> val + ret -> right -> val; 
        return ret;
  	}
  	
    int query(int l, int r, int i, int j) {
    	if(r < i || l > j) return 0;
    	if(i <= l && r <= j) { 
          return val; 
    	} 
    	int mid = (l+r)/2;
    	return left -> query(l, mid,i,j)+right -> query(mid+1, r,i,j);
  }

}*root[sz];
int arr[sz];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	root[0]=new node();
	root[0]->build(1,n);
	for(int i=1;i<=n;i++)
		root[0]=root[0]->update(1,n,i,arr[i]);
	int m;
	cin>>m;
	int cur=0;
	while(m--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a==1)
		{
			cur++;
			root[cur]=root[b]->update(1,n,c,d);
		}
		else
		{
			cout<<root[b]->query(1,n,c,d)<<"\n";
		}
	}
}