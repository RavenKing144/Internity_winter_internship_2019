#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>>fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector<vector <int>> res;
    vector<int>p;
    p.resize(4);
    for(int i=0;i<A.size()-3;i++){
        if(i>0 && A[i]==A[i-1]) continue;
        for(int j=i+1;j<A.size()-2;j++){
            if(j>i+1 && A[j]==A[j-1]) continue;
            int target=B-A[i]-A[j];
            p[0]=A[i];
            p[1]=A[j];

            int k=j+1;
            int q=A.size()-1;
            while(k<q){

                int sum=A[k]+A[q];
                if(sum==target){
                    p[2]=A[k];
                    p[3]=A[q];
                    res.push_back(p);
                    while(p[2]==A[k] && k<q) k++;
                }
                else if(sum<target) k++;
                else     q--;

            }
        }
    }
    return res;

}

template<class T>
void printVector(vector<vector<T>> const &mat) {
	for (vector<T> row: mat) {
            cout<<"[";
		for (T val: row) {
			cout << val << " ";
		}
		cout << "]\n";
	}
}

int main()
{
    vector<int>arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>>result = fourSum(arr,target);

    printVector(result);


}
