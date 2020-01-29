#include<iostream>
#include<climits>
using namespace std;


int findMinVertex(int* distance, bool* visited, int n){

	int minVertex = -1;
	for(int i = 0; i < n; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstraDist(pair<int,int>** edges, int n){
	int* distance = new int[n];
	bool* visited = new bool[n];

	for(int i = 0; i < n; i++){
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	char source,dest;
	cout<<"Enter source: ";
	cin>>source;
	cout<<"Enter destination: ";
	cin>>dest;
	int index = source - 'a';
	distance[index] = 0;

	for(int i = 0; i < n - 1; i++){
		int minVertex = findMinVertex(distance, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++){
			if(edges[minVertex][j].first != 0 && !visited[j]){
				int dist = distance[minVertex] + edges[minVertex][j].first;
				if(dist < distance[j]){
					distance[j] = dist;
				}
			}
		}
	}

	index = dest - 'a';
	if(distance[index]==0)
    {
        cout<<"Not possible"<<endl;
        return;
    }
	cout<<"Minimum distance from "<<source <<" to "<<dest <<" is "<<distance[index];
	delete [] visited;
	delete [] distance;

}

void dijkstraFare(pair<int,int>** edges, int n){
	int* fare = new int[n];
	bool* visited = new bool[n];

	for(int i = 0; i < n; i++){
		fare[i] = INT_MAX;
		visited[i] = false;
	}
	char source,dest;
	cout<<"Enter source: ";
	cin>>source;
	cout<<"Enter destination: ";
	cin>>dest;
	int index = source - 'a';
	fare[index] = 0;

	for(int i = 0; i < n - 1; i++){
		int minVertex = findMinVertex(fare, visited, n);
		visited[minVertex] = true;
		for(int j = 0; j < n; j++){
			if(edges[minVertex][j].second != 0 && !visited[j]){
				int cost = fare[minVertex] + edges[minVertex][j].second;
				if(cost < fare[j]){
					fare[j] = cost;
				}
			}
		}
	}

	index = dest - 'a';
	if(fare[index]==0)
    {
        cout<<"Not possible"<<endl;
        return;
    }
	cout<<"Minimum fare from "<<source <<" to "<<dest <<" is "<<fare[index];
	delete [] visited;
	delete [] fare;

}

void add(pair<int,int>**edges,int n)
{
    int i;
    i = n-1;
    char ch;
    do
    {
        char dest = 'a'+i;
        cout<<"Enter the id of airport connected with new airport : (from a to "<<dest<<" )";
        char s;
        cin>>s;
        cout<<"Enter fare from "<<s <<" to "<<dest;
        int fare,dist;
        cin>>fare;
        cout<<"Enter distance from "<<s <<" to "<<dest;
        cin>>dist;
        int j = (s - 'a');

        edges[i][j].first = dist;
        edges[i][j].second = fare;
        //cout<<"HEY"<<endl;
        edges[j][i] = edges[i][j];
        cout<<"Enter y to make more connections";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    cout<<"Added!"<<endl;
    return;
}

void deleteA(pair<int,int>**edges,int n)
{
    cout<<"Enter id of airport to be deleted : ";
    char c;
    cin>>c;
    int index = c - 'a';
    for(int i = 0;i<n;i++)
    {
        edges[i][index] = {0,0};
        edges[index][i] = {0,0};
    }
    cout<<"Airport deleted"<<endl;

}

int main() {
	int n = 10;
	int e;
	pair<int,int>** edges = new pair<int,int>*[1000];
	for (int i = 0; i < n; i++) {
		edges[i] = new pair<int,int>[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = {0,0};
		}
	}

	edges[0][2]  = {5, 100};
	edges[2][0]  = {5, 100};
	edges[0][3]  = {4, 200};
	edges[3][0]  = {4, 200};
	edges[1][2]  = {3, 200};
	edges[2][1]  = {3, 200};
	edges[2][3]  = {4,100};
	edges[3][2]  = {4,100};
	edges[5][1]  = {2, 300};
	edges[1][5]  = {2, 300};
	edges[2][4]  = {1, 350};
	edges[4][2]  = {1, 350};
	edges[4][5]  = {6,220};
	edges[5][4]  = {6,220};
	edges[3][6]  = {9, 140};
	edges[6][3]  = {9, 140};
	edges[6][5]  = {10, 550};
	edges[5][6]  = {10, 550};
	edges[6][7]  = {4, 170};
	edges[7][6]  = {4, 170};
	edges[7][9]  = {2, 240};
	edges[9][7]  = {2, 240};
	edges[8][9]  = {5, 360};
	edges[9][8]  = {5, 360};
	edges[9][0]  = {4, 320};
	edges[0][9]  = {4, 320};
	edges[9][4]  = {8, 170};
	edges[4][9]  = {8, 170};

	char c;
	cout << "Enter 1 for calculating cheapest route"<<endl<<"Enter 2 for calculating fastest route"<<endl;
	cout<<"Enter 3 to delete an airport "<<endl;
	cout<<"enter 4 to add an airport "<<endl;
	int ch;
	do
    {
       cin>>ch;
	switch(ch)
	{
    case 1:dijkstraFare(edges,n);break;
    case 2:dijkstraDist(edges, n);break;
    case 3:deleteA(edges,n);
    n--; break;
    case 4: n++;
        add(edges,n);
    default:cout<<"Wrong choice"<<endl;exit(0);
	}
	cout<<endl<<"Enter y to continue ";
	cin>>c;
	}while(c=='y'||c=='Y');



	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}
