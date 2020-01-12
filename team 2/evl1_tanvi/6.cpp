
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std; 

// A comparison function which is used by sort() in printLargest() 
int myCompare(string X, string Y) 	// first append Y at the end of X 
	string XY = X.append(Y); 

	// then append X at the end of Y 
	string YX = Y.append(X); 

	// Now see which of the two formed numbers is greater 
	return XY.compare(YX) > 0 ? 1: 0; 
} 

// The main function that prints the arrangement with the largest value. 
// The function accepts a vector of strings 
void printLargest(vector<string> arr) 
{ 
	// Sort the numbers using library sort function. The function uses 
	// our comparison function myCompare() to compare two strings. 
	// See http://www.cplusplus.com/reference/algorithm/sort/ for details 
	sort(arr.begin(), arr.end(), myCompare); 

	for (int i=0; i < arr.size() ; i++ ) 
		cout << arr[i]; } 

// Driver program to test above functions



int main()
{ 
    int t; 
    cin>>t;
    int c1,c2,c3,c4,n,m;

    int rick[1005],cab[1005];
    
    while(t--){
        cin>>c1>>c2>>c3>>c4;

        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>rick[i];
        }

        for(int i=0;i<m;i++){
            cin>>cab[i];
        }

        int rickcost = 0;
        for(int i=0;i<n;i++){
            rickcost += min(c1*rick[i],c2);
        }
        rickcost = min(rickcost,c3);

        int cabcost = 0;
        for(int i=0;i<m;i++){
            cabcost += min(c1*cab[i],c2);
        }
        cabcost = min(cabcost,c3);

        int finalAns = min(c4,rickcost+cabcost);
        cout<<finalAns<<endl;
    }
  vector<string> arr; 

	//output should be 6054854654 
	arr.push_back("54"); 
	arr.push_back("546"); 
	arr.push_back("548"); 
	arr.push_back("60"); 
	printLargest(arr); 

    return 0;
}

