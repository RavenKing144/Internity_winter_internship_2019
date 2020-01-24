#include <bits/stdc++.h>
using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	fout.open("decompressed_file.txt", ios::out);
	fin.open("compressed_file.txt", ios::in);

	char my_character, last_char;
	string result = "";
	int count=0;

	while (!fin.eof())
	{
		fin.get(my_character);
		if(my_character<=57 && my_character>=48)
		{
			cout << count << "\n";
			count*=10;
			count+=stoi(string(1, my_character));
			cout << count << "\n";
		}
		else{
			// cout << my_character << "\n";
			while(count--)
			{
				// cout << count << "\n";
				result+=string(1, my_character);
			}
			count=0;
		}
	}

	fout << result;

	return 0;
}