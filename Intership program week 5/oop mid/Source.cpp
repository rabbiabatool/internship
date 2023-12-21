#include<iostream>
#include<string>
using namespace std;
class ticTacToe
{
	char board[3][3];
public:
	int i = 0;
	int j = 0;
	ticTacToe()
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				board[i][j] = '-';
			}
		}
	}
	int check()
	{
		
			 if (board[0][0] == 'x'&&board[1][1]=='x'&& board[2][2] == 'x'|| board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o')
			 {
				cout << "game ends" << endl;
				return 2;
			 }
			 else  if (board[2][2] == 'x' && board[1][1] == 'x' && board[0][0] == 'x' || board[2][2] == 'o' && board[1][1] == 'o' && board[0][0] == 'o')
			 {
				 
				 cout << "game ends" << endl;
				 return 2;
			 }
			 else  if (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x' || board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o')
			 {

				 cout << "game ends" << endl;
				 return 2;
			 }
			 else  if (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x' || board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o')
			 {

				 cout << "game ends" << endl;
				 return 2;
			 }
			 else  if (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x' || board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o')
			 {

				 cout << "game ends" << endl;
				 return 2;
			 }
			 else  if (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x' || board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o')
			 {

				 cout << "game ends" << endl;
				 return 2;
			 }
			 else  if (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x' || board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o')
			 {

				 cout << "game ends" << endl;
				 return 2;
			 }
			 else  if (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x' || board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o')
			 {

				 cout << "game ends" << endl;
				 return 2;
			 }
			
			
		
	}
	int set_board(char a, int r, int c)
	{
		if (board[r][c] == 'o'|| board[r][c]=='x')
		{
			cout << "this move is full";
			return 1;
		}
		else
		{
			board[r][c] = a;
			return 2;
		}
		
		
	}
	void print()
	{
		for (int i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				cout << board[i][j];
				
			}
			cout << endl;
		}
		
	}
};
int main()
{
	char c1 = 'x';
	char c2 = 'o';
	char choice1 = 'a';
	string choice = "continue";
	ticTacToe player1;
	/*ticTacToe player2;*/
	int k = 0; // player number
	int row;
	int column;
	int play;
	cout << "enter 1 for playing  and zero for ending game" << endl;
	cin >> play;
	cout << "enter player 1 will take x or o" << endl;
	cin >> c1;
	cout << "enter player 2 will take x or o" << endl;
	cin >> c2;

	do
	{

		cout << "enter choice" << endl;
		cout << "enter continue for continueing game and exit for exit" << endl;
		cin >> choice;
		do
		{
			
			
				cout << "player" << k << endl;
				cout << "enter row number and coloumn number where you want to insert" <<c1<< endl;
				cout << "enter row number and column number not greater than 2" << endl;
				cin >> row;
				cin >> column;
				if (row < 0 || row>2 && column < 0 || column>2)
				{
					cout << "enter row number and coloumn number where you want to insert" << c1 << endl;
					cout << "enter row number and column number not greater than 2" << endl;
					cin >> row;
					cin >> column;
				}
				
					
					int set_return = player1.set_board(c1, row, column);
					if (set_return== 1)
					{
						cout << "enter row number and coloumn number where you want to insert"<<c1<< endl;
						cin >> row;
						cin >> column;
						
						set_return = player1.set_board(c1, row, column);
						
					}
					else
					{
						player1.print();
						int check_re2 = player1.check();
						if (check_re2 == 2)
						{
							cout << "player" << k << "is winner" << endl;
							break;
						}

					}
				 
				
				
				cout << "player" << k+1 << endl;
				cout << "enter row number and coloumn number where you want to insert"<<c2 << endl;
				cout << "enter row number and column number not greater than 2" << endl;
				cin >> row;
				cin >> column;
				if ((row < 0 || row>2) || (column < 0 || column>2))
				{
					cout << "enter row number and coloumn number where you want to insert" << c2 << endl;
					cout << "enter row number and column number not greater than 2" << endl;
					cin >> row;
					cin >> column;
				}
				

					int re = player1.set_board(c2, row, column);
					if (re == 1)
					{
						cout << "enter row number and coloumn number where you want to insert" <<c2<< endl;
						cin >> row;
						cin >> column;

						re = player1.set_board(c2, row, column);
						player1.print();
					}
					else
					{
						player1.print();
						int re2 = player1.check();
						if (re2 == 2)
						{
							cout << "player" << k+1 << "is winner" << endl;
							break;
						}

					}

				

			cout << "enter continue or exit" << endl;

			cin >> choice;

		} while (choice != "exit");
		cout << "enter 0 for ending and 1 for replaying" << endl;
		cin >> play;
	} while (play != 0);
	
		return 0;
}