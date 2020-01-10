#include <iostream>
#include<cstring>
using namespace std;
void compress(char str[]){

    char currChar=str[0];
    int count=1;
    int i=1,j=1;

    for(i=1;str[i] != '\0';i++){
        if(str[i]==currChar){
            count++;
        } else{
            if(count>0){
                str[j]=char(count+48);
                j++;

            }
            currChar=str[i];
            str[j]=str[i];
            j++;
            count=1;
        }

    }
  }
    if(count>0){
        str[j]=char(count+48);
        j++;
    }
    
 str[j]='\0';
    
}

int main() {
    char str[100];
    cin.getline(str, 100);
    compress(str);
    cout<<str;
}
