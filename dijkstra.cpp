#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
/**********************
DIJKSTRA CAMINO MINIMO
CON RECONSTRUCION DEL
CAMINO, GRAFO CONEXO
jorgegaraych@gmail.com
*********************/

int V,E;
vector < vector <pi> > listAdj;
vector <pi> dist;

void djistra(int start){
	int i,l,p,v,u;
	queue <int> q;
	q.push(start);
	dist[start]=make_pair(0,0);
	while(!q.empty()){
		v=q.front();                     // nodo v ----> u
		l=listAdj[v].size();		// cantidad de nodos adyacentes a v
		q.pop();
		for(i=0; i<l; i++){
			u=listAdj[v][i].first;  // nodo de llegada u
			p=listAdj[v][i].second;  // peso entre v y u

			if(dist[v].first + p < dist[u].first){
				dist[u].first=dist[v].first + p;  
				dist[u].second=v;
				q.push(u);
			}
		}
	}
}

int main(){
	int i;
	int u,v,p;

	scanf("%d %d",&V,&E);
	listAdj.resize(V+1);
	dist.resize(V+1);
	for(i=0;i<=V;i++)
		dist[i]=make_pair(1e9,0);  // inicializacion

	for(i=0; i<E; i++){
		scanf("%d %d %d",&u,&v,&p);
		listAdj[u].push_back(make_pair(v,p));
		listAdj[v].push_back(make_pair(u,p));
	}
	djistra(1);
	printf("Caminos minimos desde el nodo 1\n");
	for(i=1;i<=V;i++){
		printf("de 1 a %d: %d  desde: %d\n",i,dist[i].first,dist[i].second);
	}

	return 0;

}
