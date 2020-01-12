#include<iostream>
using namespace std;
bool IsQuery(int p[], int n, int a,int k){
    int cnt=0;
    for(int i=0; i < n ; i++){
        if(a % p[i]==0){
            cnt++;
        }
    }
    if(cnt >= k){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    
    int n;
    cin >> n;
    int p[n];
    for(int i=0; i< n ; i++){
        cin >> p[i];
    }
    int q;
    cin >> q;
    
    while(q--){
        
        int a ,k;
        cin >> a >> k;
        
        if(IsQuery(p,n,a,k))
            cout << "Yes" << endl;
            
        else{
            cout << "No" << endl;
        }
    }
    
	return 0;
}