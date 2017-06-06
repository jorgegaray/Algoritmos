#include <bits/stdc++.h>
using namespace std;
/**********************
Kruskal  
jorgegaraych@gmail.com wrote this file
Jorge Garay Chandia
*********************/



vector <pair< int, pair <int,int> > > Kruskal( vector <vector < pair<int,int> > > lst_adj ){
	int u,v,w,i,j;
	vector <pair <int, pair<int,int> > >  result;
	vector <pair <int, pair<int,int> > >  EDGES;
	set < int > isAdd;

	// add edges to vector
	for(int i=0; i< lst_adj.size(); i++){
		for(int j=0; j< lst_adj[i].size(); j++){
			u=i;
			v=lst_adj[i][j].first;
			w=lst_adj[i][j].second;
			EDGES.push_back(make_pair(w,make_pair(u,v)));  // 	< weight , <node u, node v> >
		}
	}
	sort(EDGES.begin(),EDGES.end());  //

	for( i=0; i<EDGES.size(); i++){
		if(isAdd.insert(EDGES[i].second.first).second){   // insert node u its ok
			isAdd.insert(EDGES[i].second.second);         // insert node v 
			result.push_back(EDGES[i]);					  //  add edges to vector result
		}
		else if(isAdd.insert(EDGES[i].second.second).second){  // insert node v its ok
			isAdd.insert(EDGES[i].second.first);			   // insert node u
			result.push_back(EDGES[i]);						   //  add edges to vector result
		}

	}
	return result;
}

int main(){
	int V,E,N,C;
	int x,y,w,v,p_min_root,i,a;
	vector <vector < pair<int,int> > > lst_adj;
	scanf("%d %d",&V, &E);
	lst_adj.resize(V+1);
	for(i=0; i<E; i++){
		scanf("%d %d %d",&x,&y,&w);
		lst_adj[x].push_back(make_pair(y,w));
	}
	vector <pair <int, pair<int,int> > > result = Kruskal(lst_adj);
		for(int i=0;i<result.size();i++){
		printf("%d<-->%d, %d\n",result[i].second.first,result[i].second.second,result[i].first);
	}
	return 0;
}

/******************
EXAMPLE
INPUT
5 7         // V vertices E edges
1 5 1	    // node u  node v  weight
1 3 5
5 3 1
5 2 3
2 4 5
4 1 1
4 3 10

OUTPUT
1<-->5, 1
4<-->1, 1
5<-->3, 1
5<-->2, 3


***************/
