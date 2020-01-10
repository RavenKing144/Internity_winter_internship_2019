#include<stdio.h>
#include<stdlib.h>
#include"Trie.h"
using namespace std;
Dictionary::Dictionary()
{
	root=new TrieNode();
}
TrieNode::TrieNode():meaning("")
{
				for(int i=0;i<ALPHABETS;i++)
				children[i]=NULL;

}
void Dictionary::insert(string word, string meaning)
{
	int i,index;
	TrieNode *temp=root;
	for(i=0;i<word.length();i++)
	{
		index=word[i]-'a';
		if(temp->children[index]==NULL)
			temp->children[index]=new TrieNode();
		temp=temp->children[index];
	}
	temp->meaning=meaning;

}
void Dictionary::autoComplete(TrieNode *root, string word,vector< string> &similarWords)
{
	TrieNode *temp=root;
	if(root->meaning!="")
		{
			similarWords.push_back(word);
		}
	for(int i=0;i<ALPHABETS;i++)
	{
			if(temp->children[i])
				autoComplete(temp->children[i],word+(char)(i+'a'),similarWords);
	}
}
void Dictionary::search(string word)
{
	int i,index;
	TrieNode* temp=root;
	vector <string> similarWords;
	for(i=0;i<word.length();i++)
	{
		index=word[i]-'a';
		if(temp->children[index]==NULL)
			{
				autoComplete(temp,word.substr(0,i),similarWords);
				break;
			}
		temp=temp->children[index];
	}
	if(temp->meaning=="")
		autoComplete(temp,word,similarWords);

	if(temp->meaning!="")
	cout<<"\n\tThe word \""<<word<<"\" was found with meaning \""<<temp->meaning<<"\"";
	else
	{
		cout<<"\n\tThe word \""<<word<<"\" was not found";
		if(similarWords.size()==0)
			return;
		cout<<"\n\tDid you mean? "<<endl;;
		for(i=0;i<similarWords.size() && i<10;i++)
			{
				cout<<i+1<<" " <<similarWords[i]<<" " <<endl;
				if(i==similarWords.size()-2 || i==9)
                {
                    cout<<" or ";
                }
			}
			int ch;
			cout<<"Enter index :";
			cin>>ch;
			if(ch>=0&&ch<=similarWords.size())
            {
                search(similarWords[ch-1]);
            }
            else
            {
                cout<<"Wrong input"<<endl;
            }
	}

}
bool Dictionary:: isEmpty(TrieNode* temp)
{
	int i;
	for(i=0;i<ALPHABETS;i++)
		if(temp->children[i])
			return 0;
	return 1;
}
TrieNode* Dictionary::removeUtil(TrieNode*temp,string word,int depth=0)
{
	if(depth==word.size())
	{
		temp->meaning="";
		if(isEmpty(temp))
			{
				delete(temp);
				temp=NULL;
			}
		return temp;

	}
	int index=word[depth]-'a';
	temp->children[index]=removeUtil(temp->children[index],word, depth+1);
	if(isEmpty(temp) && temp->meaning=="")
	{
		delete temp;
		temp=NULL;
	}
	return temp;
}

void Dictionary::remove(string word)
{
	removeUtil(root,word);
	cout<<"\n\tThe word \""<<word<<" has been successfully removed. ";

}

TrieNode* Dictionary::clearDictionary(TrieNode *temp)
{
	for(int i=0;i<ALPHABETS;i++)
	{
		if(temp->children[i])
			temp->children[i]=clearDictionary(temp->children[i]);
	}
	delete temp;
	temp=NULL;
	return temp;
}
Dictionary ::~Dictionary()
{
	clearDictionary(root);
}

int main()
{

	Dictionary obj;
	string word,meaning;
	ifstream fin;
	int n,ch;
	char c;
	cout<<"\n\tDICTIONARY";
	fin.open("Dictionary.txt");
        while(!fin.eof())
			{
				fin>>word;
				fin>>meaning;
				obj.insert(word,meaning);
			}
			fin.close();

	do
	{
		system("cls");
		cout<<"\n\t1.Search Word";
		cout<<"\n\t2.Remove Word";
		cout<<"\n\t3.Exit";
		cout<<"\n\tEnter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
			    cout<<"\n\tENTER WORD: ";
			    cin>>word;
                obj.search(word);
					break;
			case 2:
			    cout<<"\n\tENTER WORD: ";
			    cin>>word;
			    obj.remove(word);
					break;
            default: exit(0);

		}
		cout<<"\n\n\t Do u want to continue (enter 'y' or 'Y') ";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;

}
