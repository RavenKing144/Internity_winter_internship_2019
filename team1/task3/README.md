## Implement dictionary and auto suggestion system as soon as a character is input by the user all the words stored starting with that letter or group of letters input by the user till	now shoud be displayed on the screen and the meaning of the word selected by the user from your code recommendation on the screen should be displayed


Take a character input and print all the possible words from the custom dictionary u have made as a text file, 
For example input is 'a'
Then output may be
- A
- Aa
- Aab
- Arab
- Abcd
Now take second character as input as 'c' now the first two character of the word I want to search in dictionary become 'ac'
So output may be 
- ac
- acb
- accd
Now the third character input be 't' so the prefix for the word user is searching in dictionary become 'act'
Output may come as
- act
- active
- action 
And take the input till a -1 is encountered as input
And search the final word in dictionary and return it's meaning and if the word is not present in dictionary print not found
And in between after writing first few letters of the word user might be searching in ur dictionary he found it in auto suggestions 
Like after user have input first three letters 'act' and autosuggestion output is 
- act
- action
- active
User is searching for 'active' he can enter 3 and directly get the meaning of the word
