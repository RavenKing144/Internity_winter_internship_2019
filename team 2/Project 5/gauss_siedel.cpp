#include <bits/stdc++.h>
using namespace std;
int n;

vector<double> siedel(vector<double> a[], vector<double> x, double b[])
{
    double d;
    int j, i;
    
    for(i=0;i<n;i++)
    {
        d = b[i];
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                d-=a[i][j]*x[j];
            }
        }
        x[i] = d/a[i][i];
    }
    return x; 
}

int main()
{
    // n is number of variables to be solved
    cin >> n;
    vector<double> x(n, 0);
    vector<double> a[n];
    double b[n];
    
    int i,j, k;
    
    /*
    
    Sample input:-

    3
    4 1 2 3 5 1 1 1 3
    4 7 3
    
    Sample output:-

    0.5008 0.99968 0.49984
    
    */
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> k;
            a[i].push_back(k);
        }
    }
    
    for(i=0;i<n;i++)
    {
        cin >> b[i];
    }
    
    for(i=0;i<5;i++)
    {
        x = siedel(a,x,b);
    }
    
    for(i=0;i<x.size();i++)
    {
        cout << x[i] << " ";
    }
    cout << "\n";
    return 0;
}