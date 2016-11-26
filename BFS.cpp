#include <bits/stdc++.h>
using namespace std;

/*************************
BFS 
lista de adyacencia
altura de los nodos
con respecto al nodo raiz
jorgegaraych@gmail.com
************************/

vector < vector <int> > listAdj;
vector <int> vis;

void BFS(int start){
  queue <int> Q;
  int i,v,l,u;
  vis[start]=0;
  Q.push(start);
  while(!Q.empty()){
    v=Q.front();
    Q.pop();
    l=listAdj[v].size();
    for(i=0;i<l;i++){
      u=listAdj[v][i];
      if(vis[u]==-1){   // chequea que no fue visitado
       vis[u]=vis[v]+1; // altura 
	     Q.push(u);
      }
    }
  }
}

int main(){
  int V,E,i,u,v;

  scanf("%d %d",&V,&E);
  listAdj.resize(V+1);
  vis.resize(V+1,-1);  
  for(i=0; i<E; i++){
    scanf("%d %d",&u,&v);
    listAdj[u].push_back(v);
    listAdj[v].push_back(u);
  }
  BFS(1);
  printf("altura con respecto al nodo raiz 1\n");
  for(i=1;i<=V;i++){
    printf("altura de %d: %d\n",i,vis[i]);
  }
  
  return 0;
}
