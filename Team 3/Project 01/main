#include"dictionary.h"
#include"autoSuggest.h"
  int main()
{
  Node *root = NULL;
  dictionary *d;
  fstream file;
  file.open("file.txt");
  struct TrieNode* root1 = getNode();
  while(!file.eof())
  {
    string word="",meaning="",temp="";
    getline(file,temp);
    int pos=temp.find(":");
    word=temp.substr(0,pos);
    meaning=temp.substr(pos+1);
    //cout<<word<<" "<<meaning<<endl;
    root=d->insert(root,word,meaning);
    insert(root1,word);
  }
  cout<<"Enter initials:->"<<endl;
  string init;
  cin>>init;
    int comp = printAutoSuggestions(root1, init);

    if (comp == -1)
        cout << "No other strings found with this prefix\n";

    else if (comp == 0)
        cout << "No string found with this prefix\n";
    cout<<"enter index"<<endl;
    int a;
    cin>>a;


  Node* s=d->search(root,c[a-1]);
  if(s)
    cout<<s->meaning<<endl;
  else
    cout<<"word not found"<<endl;
  return 0;
}
