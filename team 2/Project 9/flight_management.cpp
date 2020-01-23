/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
#define MOD 1000000007
#define dd double
#define vi vector<int>
#define vll vector<ll>
#define forr(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define ms(s, n) memset(s, n, sizeof(s))
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define int ll
# define INF 0x3f3f3f3f
#include<unordered_map>
ll po(ll a, ll x,ll m){ if(x==0){return 1;}ll ans=1;ll k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; }
struct graphs
{
	map<int,vector<pair<int,int> > >graph;
	vector<pair<int,int> >p;
	int parent[100000];
	int rank[100000];
	int findRoot(int x,int *parent){
		if(parent[x]==-1)
			return x;
		return parent[x] = findRoot(parent[x],parent);
	}
	bool isCycle(){
		memset(parent,-1,sizeof(parent));
		memset(rank,1,sizeof(rank));
		int n = p.size();
        //cout<<n;
		for(int i=0;i<n;i++){
			int a = p[i].F;
			int b = p[i].S;
			int fir = findRoot(a,parent);
		 	int sec = findRoot(b,parent);
		 	if(fir==sec){
		 		cout<<"Cycle found!!!!\n";
		 		return true;
		 	}
			if(rank[fir]>rank[sec])
				swap(fir,sec);
			parent[fir] = sec;
			rank[sec]+=rank[fir];
		}
		 	cout<<"Cycle not found!!!!\n";
		 	return false;
	}
	void addEdge(int a,int b,int w){
		graph[a].pb(mp(b,w));
		graph[b].pb(mp(a,w));
		p.push_back(mp(a,b));
		if(isCycle())
		{
		    deleteEdge(a, b);
		}
	}
	void deleteEdge(int a, int b)
	{
	    vector<pair<int, int> >::iterator it;
	    for(it=graph[a].begin();it!=graph[a].end();it++)
	    {
	        if((*it).first == b)
	        {
	            break;
	        }
	    }
	    graph[a].erase(it);
	    for(it=graph[b].begin();it!=graph[b].end();it++)
	    {
	        if((*it).first == a)
	        {
	            break;
	        }
	    }
	    graph[b].erase(it);
	    for(it=p.begin();it!=p.end();it++)
	    {
	        if((*it).first==a && (*it).second==b)
	        {
	            break;
	        }
	    }
	    p.erase(it);
	    for(it=p.begin();it!=p.end();it++)
	    {
	        if((*it).first==b && (*it).second==a)
	        {
	            break;
	        }
	    }
	    p.erase(it);
	}
	void deleteNode(int a)
	{
		cout << "The graph looks like this:\n";
		map<int,vector<pair<int,int> > >::iterator it;
	    for(it=graph.begin();it!=graph.end();it++)
	    {
	    	cout << (*it).first << " -> ";
	    	p = (*it).second;
	    	vector<pair<int, int>>::iterator x;
	    	for(x = p.begin();x!=p.end();x++)
	    	{
	    		cout << "[" << (*x).first << "," << (*x).second <<"]";
	    	}
	    	cout << "\n";
	    }

	    graph.erase(a);
	    cout << "abc";
	    map<int,vector<pair<int,int> > >::iterator i;
	    for(i=graph.begin();i!=graph.end();i++)
	    {
	    	p = (*i).second;
	    	cout << (*i).first<< "\n";
	    	vector<pair<int, int>>::iterator x;
	    	for(x = p.begin();x!=p.end();x++)
	    	{
	    		if((*x).first == a)
	    		{
	    			p.erase(x);
	    		}
	    	}
	    	graph[(*i).first] = p;
	    }
	    cout <<"def\n";

	    cout << "The graph looks like this:\n";
		map<int,vector<pair<int,int> > >::iterator itx;
	    for(itx=graph.begin();itx!=graph.end();itx++)
	    {
	    	cout << (*it).first << " -> ";
	    	p = (*itx).second;
	    	vector<pair<int, int>>::iterator x;
	    	for(x = p.begin();x!=p.end();x++)
	    	{
	    		cout << "[" << (*x).first << "," << (*x).second <<"]";
	    	}
	    	cout << "\n";
	    }
	}
};
class Graph
{
	int V; // No. of vertices
	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list< pair<int, int> > *adj;
public:
	Graph(int V); // Constructor
	// function to add an edge to graph
	void addEdge1(int u, int v, int w);
	// prints shortest path from s
	void shortestPath(int s,int ds);
};
// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list< pair<int, int> >[V];
}
void Graph::addEdge1(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}
// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src,int d)
{
	// Create a set to store vertices that are being
	// prerocessed
	set< pair<int, int> > setds;
	// Create a vector for distances and initialize all
	// distances as infinite (INF)
	vector<int> dist(V, INF);
	// Insert source itself in Set and initialize its
	// distance as 0.
	setds.insert(make_pair(0, src));
	dist[src] = 0;
	/* Looping till all shortest distance are finalized
	then setds will become empty */
	while (!setds.empty())
	{
		// The first vertex in Set is the minimum distance
		// vertex, extract it from set.
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = tmp.second;
		// 'i' is used to get all adjacent vertices of a vertex
		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = (*i).first;
			int weight = (*i).second;
			// If there is shorter path to v through u.
			if (dist[v] > dist[u] + weight)
			{
				/* If distance of v is not INF then it must be in
					our set, so removing it and inserting again
					with updated less distance.
					Note : We extract only those vertices from Set
					for which distance is finalized. So for them,
					we would never reach here. */
				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));
				// Updating distance of v
				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}
	// Print shortest distances stored in dist[]
	//printf("Vertex Distance from Source\n");
	//for (int i = 0; i < V; ++i)
	//	printf("%d \t\t %d\n", i, dist[i]);
printf("%d  ",dist[d]);
}
// Driver program to test methods of graph class
int32_t main()
{
    cout <<"Enter 1 to find the cheapest distance"<<endl;
    cout <<"Enter 2 to find the shortest distance"<<endl;
    cout <<"Enter 3 to find the cycle if exists"<<endl;
    cout <<"Enter 4 to delete a node" << endl;
    int x;
    cin >>x;
    if(x==1)
    {
        int s,d;
        cout <<"enter the source"<<endl;
        cin >>s;
        cout <<"enter the destintion"<<endl;
        cin >>d;
        cout <<"The cheapest distance is"<<endl;
        // V = 9;
    	Graph g1(9);
	// making above shown graph
	g1.addEdge1(0, 1, 4);
	g1.addEdge1(0, 7, 8);
	g1.addEdge1(1, 2, 8);
	g1.addEdge1(1, 7, 11);
	g1.addEdge1(2, 3, 7);
	g1.addEdge1(2, 8, 2);
	g1.addEdge1(2, 5, 4);
	g1.addEdge1(3, 4, 9);
	g1.addEdge1(3, 5, 14);
	g1.addEdge1(4, 5, 10);
	g1.addEdge1(5, 6, 2);
	g1.addEdge1(6, 7, 1);
	g1.addEdge1(6, 8, 6);
	g1.addEdge1(7, 8, 7);
	g1.shortestPath(s,d);
	cout <<endl;
    }
    if(x==2)
    {
          int s1,d1;
        cout <<"enter the source"<<endl;
        cin >>s1;
        cout <<"enter the destintion"<<endl;
        cin >>d1;
	       cout <<"The closest path is"<<endl;
     	//int V = 9;
	       Graph g2(9);
	// making above shown graph
	    g2.addEdge1(0, 1, 25);
	    g2.addEdge1(0, 7, 80);
	    g2.addEdge1(1, 2, 28);
	    g2.addEdge1(1, 7, 91);
	    g2.addEdge1(2, 3, 72);
	    g2.addEdge1(2, 8, 25);
	    g2.addEdge1(2, 5, 46);
	    g2.addEdge1(3, 4, 95);
	    g2.addEdge1(3, 5, 14);
	    g2.addEdge1(4, 5, 10);
	    g2.addEdge1(5, 6, 82);
	    g2.addEdge1(6, 7, 61);
	    g2.addEdge1(6, 8, 56);
    	g2.addEdge1(7, 8, 37);
	    g2.shortestPath(s1,d1);
	    cout <<endl;
    }
    if(x==3)
    {
	    cout<<"To add the airports or remove them and detect cycle "<<endl;
	    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
 	    graphs g;
 	    cout <<"Adding A0 and A1 "<<endl;
 	    g.addEdge(0, 1, 4);
 	    cout <<"Adding A0 and A7 "<<endl;
	    g.addEdge(0, 7, 8);
	    cout <<"Adding A1 and A2 "<<endl;
	    g.addEdge(1, 2, 8);
	    cout <<"Adding A1 and A7 "<<endl;
	    g.addEdge(1, 7, 11);
	    cout <<"Adding A2 and A3 "<<endl;
	    g.addEdge(2, 3, 7);
	    cout <<"Adding A2 and A8 "<<endl;
	    g.addEdge(2, 8, 2);
	    cout <<"Adding A2 and A5 "<<endl;
    	g.addEdge(2, 5, 4);
    	cout <<"Adding A3 and A4 "<<endl;
	    g.addEdge(3, 4, 9);
	    cout <<"Adding A3 and A5 "<<endl;
	    g.addEdge(3, 5, 14);
	    cout <<"Adding A4 and A5 "<<endl;
	    g.addEdge(4, 5, 10);
	    cout <<"Adding A5 and A6 "<<endl;
	    g.addEdge(5, 6, 2);
	    cout <<"Adding A6 and A7 "<<endl;
	    g.addEdge(6, 7, 1);
	    cout <<"Adding A6 and A8 "<<endl;
    	g.addEdge(6, 8, 6);
    	cout <<"Adding A7 and A8 "<<endl;
    	g.addEdge(7, 8, 7);
    	//g.isCycle();
    }
    if(x==4)
    {
    	graphs g;
    	g.addEdge(0, 1, 4);
    	g.addEdge(0, 7, 8);
	    // cout <<"Adding A1 and A2 "<<endl;
	    g.addEdge(1, 2, 8);
	    // cout <<"Adding A1 and A7 "<<endl;
	    g.addEdge(1, 7, 11);
	    // cout <<"Adding A2 and A3 "<<endl;
	    g.addEdge(2, 3, 7);
	    // cout <<"Adding A2 and A8 "<<endl;
	    g.addEdge(2, 8, 2);
	    // cout <<"Adding A2 and A5 "<<endl;
    	g.addEdge(2, 5, 4);
    	// cout <<"Adding A3 and A4 "<<endl;
	    g.addEdge(3, 4, 9);
	    // cout <<"Adding A3 and A5 "<<endl;
	    g.addEdge(3, 5, 14);
	    // cout <<"Adding A4 and A5 "<<endl;
	    g.addEdge(4, 5, 10);
	    // cout <<"Adding A5 and A6 "<<endl;
	    g.addEdge(5, 6, 2);
	    // cout <<"Adding A6 and A7 "<<endl;
	    g.addEdge(6, 7, 1);
	    // cout <<"Adding A6 and A8 "<<endl;
    	g.addEdge(6, 8, 6);
    	// cout <<"Adding A7 and A8 "<<endl;
    	g.addEdge(7, 8, 7);
    	int x;
    	cout << "Enter the node you want to delete.\n";
    	cin >> x;	
    	g.deleteNode(x);
    }
	// create the graph given in above fugure
 	return 0;
}