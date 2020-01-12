#include<iostream>
#include"autocomplete.h"
#include"dictionary.h"
using namespace std;

  int main()
{
  Node *root = NULL;
  dictionary *d;
  fstream file;
  file.open("my_words.txt");
  struct trie_node* root1 = getNode();
  while(!file.eof())
  {
    string word="",meaning="",temp="";
    getline(file,temp);
    int pos=temp.find(":");
    word=temp.substr(0,pos);
    meaning=temp.substr(pos+1);
    root=d->insert(root,word,meaning);
    insert(root1,word);
  }
  cout<<"Enter the query-"<<endl;
  string init;
  cin>>init;
    int comp = print_suggestions(root1, init);

    if (comp == -1)
        cout << "Not found\n";

    else if (comp == 0)
        cout << "Not found\n";
    cout<<"enter index"<<endl;
    int a;
    cin>>a;


  Node* s=d->search(root,c[a-1]);
  if(s)
    cout<<s->meaning<<endl;
  else
    cout<<"Not found"<<endl;
  return 0;
}
