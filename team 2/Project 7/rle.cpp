#include <bits/stdc++.h>

using namespace std;

int main() {

	ifstream fin;
	ofstream fout;
	fin.open("input_file.txt", ios::in);
	fout.open("compressed_file.txt", ios::out);

	char my_character, last_char;
	string result = "";
	int count=1;

	fin.get(my_character);
	// result+=my_character;
	last_char = my_character;

	while (!fin.eof()) 
	{
		fin.get(my_character);
		// cout << my_character;

		if(last_char == my_character)
		{
			count++;
		}
		else{
			result += to_string(count) + string(1, last_char);
			last_char = my_character;
			count=1;
		}
	}
	result += to_string(count-1) + string(1, last_char);

	fout << result;
	
	cout << "File Successfully Compressed.\n";

	return 0;
}