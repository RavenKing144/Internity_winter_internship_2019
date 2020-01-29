#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define MOD 1000000007
#define dd double
#define vis vector<int>
#define vll vector<ll>
#define forr(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define ms(s, n) memset(s, n, sizeof(s))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define int long long
# define INF 0x3f3f3f3f
#include<unordered_map>

long long po(long long a, long long x,long long m){ if(x==0){return 1;}long long ans=1;long long k=1;  while(k<=x) {if(x&k){ans=((ans*a)%m);} k<<=1; a*=a; a%=m; }return ans; }
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
			int a = p[i].first;
			int b = p[i].second;
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
		graph[a].push_back(make_pair(b,w));
		graph[b].push_back(make_pair(a,w));
		p.push_back(make_pair(a,b));
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
		cout << "The airport network is as follows \n \n";
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

	    cout << "The airport network is as follows  \n \n";
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
	int V;
	list< pair<int, int> > *adj;
public:
	Graph(int V);
	void addEdge1(int u, int v, int w);
	void shortestPath(int s,int ds);
};
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
void Graph::shortestPath(int src,int d)
{
	set< pair<int, int> > setds;

	vector<int> dist(V, INF);

	setds.insert(make_pair(0, src));
	dist[src] = 0;

	while (!setds.empty())
	{

		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		int u = tmp.second;

		list< pair<int, int> >::iterator i;
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{

			int v = (*i).first;
			int weight = (*i).second;

			if (dist[v] > dist[u] + weight)
			{

				if (dist[v] != INF)
					setds.erase(setds.find(make_pair(dist[v], v)));

				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}

printf("%d  ",dist[d]);
}

int32_t main()
{  cout<<"This is the flight management system \n\n";
  cout<<"You have the following options \n";
    cout <<"Press 1 to find the cheapest flight \n";
    cout <<"Press 2 to find the Fastest route\n";
    cout <<"Press 3 to find if cycle exists in the airport network \n";
    cout <<"Press 4 to crash an Airport \n";
    int x;
    cin >>x;
    if(x==1)
    {
        int s,d;
        cout <<"Enter the source airport"<<endl;
        cin >>s;
        cout <<"Enter your destination"<<endl;
        cin >>d;
        cout <<"The cheapest flight is"<<endl;

    	Graph g1(9);

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
        cout <<"Enter the source airport"<<endl;
        cin >>s1;
        cout <<"Enter your destination"<<endl;
        cin >>d1;
	       cout <<"The closest path is"<<endl;

	       Graph g2(9);
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
 	    cout <<"Adding 0 and 1 "<<endl;
 	    g.addEdge(0, 1, 4);
 	    cout <<"Adding 0 and 7 "<<endl;
	    g.addEdge(0, 7, 8);
	    cout <<"Adding 1 and 2 "<<endl;
	    g.addEdge(1, 2, 8);
	    cout <<"Adding 1 and 7 "<<endl;
	    g.addEdge(1, 7, 11);
	    cout <<"Adding 2 and 3 "<<endl;
	    g.addEdge(2, 3, 7);
	    cout <<"Adding 2 and 8 "<<endl;
	    g.addEdge(2, 8, 2);
	    cout <<"Adding 2 and 5 "<<endl;
    	g.addEdge(2, 5, 4);
    	cout <<"Adding 3 and 4 "<<endl;
	    g.addEdge(3, 4, 9);
	    cout <<"Adding 3 and 5 "<<endl;
	    g.addEdge(3, 5, 14);
	    cout <<"Adding 4 and 5 "<<endl;
	    g.addEdge(4, 5, 10);
	    cout <<"Adding 5 and 6 "<<endl;
	    g.addEdge(5, 6, 2);
	    cout <<"Adding 6 and 7 "<<endl;
	    g.addEdge(6, 7, 1);
	    cout <<"Adding 6 and 8 "<<endl;
    	g.addEdge(6, 8, 6);
    	cout <<"Adding 7 and 8 "<<endl;
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
