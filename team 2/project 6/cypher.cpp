#include <bits/stdc++.h> 
using namespace std; 
string encryptRailFence(string text, int key) 
{ 
	char rail[key][(text.length())]; 

	// filling the rail matrix to distinguish filled 
	// spaces from blank ones 
	for (int i=0; i < key; i++) 
		for (int j = 0; j < text.length(); j++) 
			rail[i][j] = '\n'; 

	// to find the direction 
	bool dir_down = false; 
	int row = 0, col = 0; 

	for (int i=0; i < text.length(); i++) 
	{
		if (row == 0 || row == key-1) 
			dir_down = !dir_down; 

		rail[row][col++] = text[i]; 

		// find the next row using direction flag 
		dir_down?row++ : row--; 
	} 
	string result; 
	for (int i=0; i < key; i++) 
		for (int j=0; j < text.length(); j++) 
			if (rail[i][j]!='\n') 
				result.push_back(rail[i][j]); 

	return result; 
}

class hill
{
       public:
              string msg,k;
              int *enc;
              int key[3][3],inv[3][3];
              hill(string a, string b)
              {
                     msg = a;
                     k = b;
                     int i,j,l=0;
                     for(i=0;i<3;i++)
                     {
                           for(j=0;j<3;j++)
                           {
                                  if(l>=k.size())
                                  {
                                         key[i][j] = 'x' - 'a' + 1;
                                  }
                                  else
                                  {
                                         key[i][j] = k[l]-'a' + 1; 
                                  }
                                  //cout<<key[i][j]<<" ";
                                  l++;
                           }

                     }
                     
                     while(msg.size()%3!=0)
                     {
                           msg = msg + 'x';
                     }
                     cout<<"Extended Message : ";
                     cout<<msg<<endl;
                    
                     enc = new int[msg.size()];
                    
              }
              void encrypt()
              {
                     int i,j,l,m;
                     for(l=0;l<msg.size();)
                     {
                           m = l;
                           for(i=0;i<3;i++)
                           {
                                  enc[l] = (key[i][0]*(msg[m]-'a' + 1) + key[i][1]*(msg[m+1]-'a' + 1) +key[i][2]*(msg[m+2]-'a' + 1))%26 + 'a'-1;
                                  cout<<(char)enc[l];
                                  l++;
                           }     
                     }
              }
};

int main() 
{ 
	string text;
    int key;
    cin>>text;
    cin>>key;
    string a=encryptRailFence(text,key);
    cout<<a<<endl; 
    string key2;
    cin>>key2;
    hill h(a,key2);
    h.encrypt();
	return 0; 
} 
