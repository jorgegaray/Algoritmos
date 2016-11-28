#include <bits/stdc++.h>
using namespace std;

/**********************
Segment Tree -> RMQ  Range Min/Max Query
jorgegaraych@gmail.com wrote this file
Jorge Garay Chandia
*********************/
// no testeado

struct Node {   
	int start, end, n, value;
	Node(int nn,int i, int f,int v){
		n=nn;
		start=i;
		end=f;
		value=v;
	}
};
vector <int> vec;  // vector initial
vector < vector <struct Node> > listA;  // list of adyacencia

int RMQ(struct Node node,int i, int j){        //  RMQ range [ i , j ]
	if(node.end < i || node.start > j ) return INT_MAX;  // out of range   (return INT_MIN for RMaxQ)
	else if(node.start >= i && node.end <= j) return node.value; //in range
	else{
		int l=listA[node.n].size();  // 0 <= l <= 2
		int m=INT_MAX;    			//	( INT_MIN for RMaxQ)
		for(int w=0; w<l; w++){
			int x=RMQ(listA[node.n][w],i,j);
			m=min(m,x);    					 // max(m,x);
		}
		return m;
	}
}

int update(struct Node &node, int position, int value){   // update (node, position, value)   
	if(node.end < position || node.start > position ) { // out of range
		return node.value;  
	}
	else if(node.start==node.end && node.end==position){   // update in position
		node.value=value;
		return value;
	}
	else { //in range	
		int l=listA[node.n].size();
		node.value=INT_MAX;				//  update value in the range  (INT_MIN for RMaxQ)
		for(int i=0;i<l;i++){ 			// 0 <= l <= 2
			node.value=min(node.value, update(listA[node.n][i],position,value));  
		}
		return node.value;
	} 
}


int buildSegmentTree(int node, int start, int end){
	if(start==end) {
		struct Node n1(-1, start, start, vec[start]);
		listA[node].push_back(n1);
		return vec[start];   // node leaf
	}
	else if(end-start==1){
		int a=vec[start];
		int b= vec[end];
		struct Node n1(-1, start, start, a);    // node leaf
		struct Node n2(-1, end, end, b);		  // node leaf
		listA[node].push_back(n1);
		listA[node].push_back(n2);
		return min(a,b);		 // return max(a,b) for RMaxQ
	}
	else{
		int mid=(start+end)/2;
		int a=buildSegmentTree(node*2,start,mid);
		int b= buildSegmentTree(node*2+1,mid+1,end);
		struct Node n1(node*2, start, mid, a);
		struct Node n2(node*2+1, mid+1, end, b);
		listA[node].push_back(n1);
		listA[node].push_back(n2);
		return min(a,b);		// return max(a,b) for RMaxQ
	}
}

int main(){
	int N,C;
	int u,v,p_min_root,i,a;

	scanf("%d %d",&N, &C);
	vec.resize(N+1);
	listA.resize(4*N);

	for(i=0;i<N;i++)
		scanf("%d",&vec[i]);	

	// build Segment Tree
	p_min_root=buildSegmentTree(1,0,N-1);
	struct Node root= Node(1,0,N-1,p_min_root); // node root name=1 range [0, N-1] , value=p_min_root

	// RMQ (root , i, j)  range [i,j]    0 <= i <= j < N
	//update (root, position, value) update in position by this value
	for(i=0;i<C;i++){			// numbers of consults
		scanf("%d %d %d",&a,&u,&v);     // type of consults a=0 RMQ a=1 update
		if(a==0)
			printf("RMQ(%d,%d)= %d\n",u,v,RMQ(root,u,v));
		else
			update(root, u,v); 
	}
	return 0;
}

/******************
EXAMPLE
INPUT
5 8
1 2 3 0 1
0 0 3
1 1 -1
0 1 4
1 3 -3
0 1 4
0 2 2
0 3 4
0 1 1

OUTPUT
RMQ(0,3)= 0
RMQ(1,4)= -1
RMQ(1,4)= -3
RMQ(2,2)= 3
RMQ(3,4)= -3
RMQ(1,1)= -1

***************/
