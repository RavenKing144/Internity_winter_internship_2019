#include <bits/stdc++.h>
using namespace std;

int minimax(char board[], char board_bool[], int mark);
int minimax2(char board[], char board_bool[], int mark);

void printBoard(char board[])
{
	int i=3,j=0;

	cout << "\nThis is how the board looks right now.\n\n";
	while(j<9)
	{
		cout << board[j] << " | ";
		i--;
		j++;

		if(i==1)
		{
			cout << board[j] << "\n";
			i=3;
			j++;
			if(j<9)
			{
				cout << "--  --  --\n";
			}
		}
	}
}

int isGameOver(char board[], char board_bool[], char Player_1, char Player_2)
{
	if (board[0] == board[1] && board[1] == board[2])
	{
		if(board[0] == Player_1)
		{
			return 1;
		} 
		else{
			return 2;
		}
	}
    else if (board[3] == board[4] && board[4] == board[5])
	{
		if(board[3] == Player_1)
		{
			return 1;
		} 
		else{
			return 2;
		}
	}
    else if (board[6] == board[7] && board[7] == board[8])
    {
		if(board[6] == Player_1)
		{
			return 1;
		} 
		else{
			return 2;
		}
	}
    else if (board[0] == board[3] && board[3] == board[6])
    {
		if(board[0] == Player_1)
		{
			return 1;
		} 
		else{
			return 2;
		}
	}
    else if (board[1] == board[4] && board[4] == board[7])
    {
		if(board[1] == Player_1)
		{
			return 1;
		} 
		else{
			return 2;
		}
	}
    else if (board[2] == board[5] && board[5] == board[8])
    {
		if(board[2] == Player_1)
		{
			return 1;
		} 
		else{
			return 2;
		}
	}
    else if (board[0] == board[4] && board[4] == board[8])
    {
		if(board[0] == Player_1)
		{
			return 1;
		} 
		else{
			return 2;
		}
	}
    else if (board[2] == board[4] && board[4] == board[6])
    {
		if(board[2] == Player_1)
		{
			return 1;
		} 
		else{
			return 2;
		}
	}
    else if (board_bool[0] != '0' && board_bool[1] != '0' && board_bool[2] != '0' 
                    && board_bool[3] != '0' && board_bool[4] != '0' && board_bool[5] != '0' 
                  && board_bool[6] != '0' && board_bool[7] != '0' && board_bool[8] != '0')

        return 0;
    else
        return -1;
}

int minimax(char board[], char board_bool[], int mark) 
{ 
    char o_mark;
    if(mark == '0')
    {
    	o_mark = 'X';
    }
    else{
    	o_mark = '0';
    }

    int score = isGameOver(board, board_bool, o_mark, mark); 
  
    // If Maximizer has won the game return his/her 
    // evaluated score 
    if (score == 1) 
        return 10; 
  
    // If Minimizer has won the game return his/her 
    // evaluated score 
    if (score == 2) 
        return -10; 
  
    // If there are no more moves and no winner then 
    // it is a tie 
    if (score == 0) 
        return 0;

    // return 0;
    char temp; 

    int best = -100000;

    for (int i = 0; i<9; i++) 
    { 
    	if(board_bool[i] == '0')
    	{
    		temp = board[i];
    		board[i] = o_mark;
    		board_bool[i] = '1';

    		best = max(best, minimax2(board, board_bool, mark));

    		board[i] = temp;
    		board_bool[i] = '0';
    	}
    } 

    return best;
} 

int minimax2(char board[], char board_bool[], int mark) 
{ 
    char o_mark;
    if(mark == '0')
    {
    	o_mark = 'X';
    }
    else{
    	o_mark = '0';
    }

    int score = isGameOver(board, board_bool, o_mark, mark); 
  
    // If Maximizer has won the game return his/her 
    // evaluated score 
    if (score == 1) 
        return 10; 
  
    // If Minimizer has won the game return his/her 
    // evaluated score 
    if (score == 2) 
        return -10; 
  
    // If there are no more moves and no winner then 
    // it is a tie 
    if (score == 0) 
        return 0;

    // return 0;
    char temp; 

    int best = 100000;

    for (int i = 0; i<9; i++) 
    { 
    	if(board_bool[i] == '0')
    	{
    		temp = board[i];
    		board[i] = mark;
    		board_bool[i] = '1';

    		best = min(best, minimax(board, board_bool, mark));

    		board[i] = temp;
    		board_bool[i] = '0';
    	}
    } 

    return best;
}

  
void computerMove(char board[], char board_bool[], int mark)
{
	int j=0;
	int bestVal = 100000;
	int pos;
	char temp;
	while(j<9)
	{
		if(board_bool[j] == '0')
		{
			temp = board[j];
			board[j] = mark;
			board_bool[j] = '1';

			int moveVal = minimax(board, board_bool, mark);

			if(moveVal < bestVal)
			{
				bestVal = moveVal;
				pos = j;
			}

			board[j] = temp;
			board_bool[j] = '0';

		}
		j++;
	}

	board[pos] = mark;
	board_bool[pos] = '1';
}

int main()
{
	cout << "Welcome to Tic-Tac-Toe!\nYou are Player 1 and Computer is Player 2.\n\nChoose one of these:\n1-0\n2-X\n\n";
	char Player_1;
	char Player_2;

	int x;
	do{
		cin >> x;
		if(x==1)
		{
			Player_1 = '0';
			Player_2 = 'X';
			break;
		}
		else if(x==2)
		{
			Player_1 = 'X';
			Player_2 = '0';
			break;
		}
		else{
			cout << "Invalid Choice!\n";
		}
	}while(x!=1 && x!=2);

	char board[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

	printBoard(board);

	char board_bool[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};

	int y;
	do
	{
		cout << "\nChoose a place to make your move.\n";
		cin >> x;

		if(board_bool[x] == '1')
		{
			cout << "Invalid Move.\n";
			continue;
		}

		board[x] = Player_1;
		board_bool[x] = '1';

		printBoard(board);

		y = isGameOver(board, board_bool, Player_1, Player_2);
		if(y!=-1)
		{
			break;
		}

		computerMove(board, board_bool, Player_2);

		printBoard(board);

		y = isGameOver(board, board_bool, Player_1, Player_2);
		if(y!=-1)
		{
			break;
		}

	}while(y==-1);


	// Result
	if(y == 0)
	{
		cout << "Draw!\n";
	}
	else if(y == 1)
	{
		cout << "Player 1 won the match.\n";
	}
	else if(y == 2)
	{
		cout << "Player 2 won the match.\n";
	}

	return 0;
}