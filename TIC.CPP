#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

enum shape{O,X};
enum player{PLAYER1,PLAYER2};
int board[9]={-1};
int isGameOver=0;
int turn=PLAYER1;
int currentMode;
int userBlockChoice;

int MAXX,MAXY;
int gameCounter = 0;
void plotBoard();
void plotShape(shape s, int block);

int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..//BGI");
	cout << "\n\n\t\t\t" << "Player 1 wants X or O ? " << "\n\t\t\t"<<"Enter ";
	cin >> currentMode;

	cout << "\n\n\t\t\t" << "Player 1 has chosen" << ((currentMode == 0) ? "O":"\tX") || ((currentMode == 1) ? "X":"\tO");
	cout << "\n\n\t\t" << "Refer to your num pad to plot X and O according to region ";
	cout << "\n\n\t\t\t" << "7 | 8 | 9";
	cout << "\n\n\t\t\t" << "----|-----|---- ";
	cout << "\n\n\t\t\t" << "4 | 5 | 6";
	cout << "\n\n\t\t\t" << "----|-----|----";
	cout << "\n\n\t\t\t" << "1 | 2 | 3";
	cout << "\n\n\t\n\t\t" << "Press any key to begin the game! ";

	getch();
	clrscr();
	cleardevice();

	plotBoard();

	for(int k=0;k<9;k++)
	{
		board[k]=-1;
	}

	while(!isGameOver)
	{
		cout << "Player "<< (turn+1) << "Your turn" << endl;
		cin >> userBlockChoice;

		if(board[userBlockChoice-1]!=-1)
		{
			while(board[userBlockChoice-1]!=-1)
			{
				cin >> userBlockChoice;
			}
		}

		board[userBlockChoice-1] = currentMode;
		gameCounter++;

		if(
		(
		(board[0]==X && board[1]==X && board[2]==X) ||
		(board[3]==X && board[4]==X && board[5]==X) ||
		(board[6]==X && board[7]==X && board[8]==X) ||
		(board[0]==X && board[4]==X && board[8]==X) ||
		(board[6]==X && board[4]==X && board[2]==X) ||
		(board[8]==X && board[5]==X && board[2]==X) ||
		(board[7]==X && board[4]==X && board[1]==X) ||
		(board[6]==X && board[3]==X && board[0]==X)
		)
		
		||
		(
		(board[0]==O && board[1]==O && board[2]==O) ||
		(board[3]==O && board[4]==O && board[5]==O) ||
		(board[6]==O && board[7]==O && board[8]==O) ||
		(board[0]==O && board[4]==O && board[8]==O) ||
		(board[6]==O && board[4]==O && board[2]==O) ||
		(board[8]==O && board[5]==O && board[2]==O) ||
		(board[7]==O && board[4]==O && board[1]==O) ||
		(board[6]==O && board[3]==O && board[0]==O)
		)
		)
		
		{
			isGameOver = 1;
			cout<<"Player"<<(turn+1)<<"Wins!";
		}
		
		else if((gameCounter == 9) && (!isGameOver))
		{
			isGameOver = 1;
			cout<<"Its a tie";
		}
		
		plotShape((shape)currentMode,userBlockChoice);
		currentMode = 1-currentMode;
		turn = 1-turn;
		
	}
	getch();
return 0;
}

void plotBoard()
{
	MAXX=getmaxx();
	MAXY=getmaxy();
	line((MAXX/2)-50,(MAXY/2)-150,(MAXX/2)-50,(MAXY/2)+150);
	line((MAXX/2)+50,(MAXY/2)-150,(MAXX/2)+50,(MAXY/2)+150);
	line((MAXX/2)-150,(MAXY/2)-50,(MAXX/2)+150,(MAXY/2)-50);
	line((MAXX/2)-150,(MAXY/2)+50,(MAXX/2)+150,(MAXY/2)+50);
}

void plotShape(shape s, int block)
{
	setcolor(s == X ? RED:BLUE);
	
	switch(block)
	{
		case 1:
			if(s == X)
			{
				line((MAXX/2)-150,(MAXY/2)+50,(MAXX/2)-50,(MAXY/2)+150);
				line((MAXX/2)-50,(MAXY/2)+50,(MAXX/2)-150,(MAXY/2)+150);
			}
			else
			{
				circle((MAXX/2)-100,(MAXY/2)+100,40);
			}
			break;
			
			case 2:
			if(s == X)
			{
				line((MAXX/2)-50,(MAXY/2)+50,(MAXX/2)+50,(MAXY/2)+150);
				line((MAXX/2)-50,(MAXY/2)+50,(MAXX/2)-50,(MAXY/2)+150);
			}
			else
			{
				circle((MAXX/2),(MAXY/2)+100,40);
			}
			break;
			
			case 3:
			if(s == X)
			{
				line((MAXX/2)+50,(MAXY/2)+50,(MAXX/2)+150,(MAXY/2)+150);
				line((MAXX/2)+150,(MAXY/2)+50,(MAXX/2)+50,(MAXY/2)+150);
			}
			else
			{
				circle((MAXX/2)+100,(MAXY/2)+100,40);
			}
			break;
			
			
			case 4:
			if(s == X)
			{
				line((MAXX/2)-150,(MAXY/2)-50,(MAXX/2)-50,(MAXY/2)+50);
				line((MAXX/2)-50,(MAXY/2)-50,(MAXX/2)-150,(MAXY/2)+50);
			}
			else
			{
				circle((MAXX/2)-100,(MAXY/2),40);
			}
			break;
			
			case 5:
			if(s == X)
			{
				line((MAXX/2)-50,(MAXY/2)-50,(MAXX/2)+50,(MAXY/2)+50);
				line((MAXX/2)+50,(MAXY/2)-50,(MAXX/2)-50,(MAXY/2)+50);
			}
			else
			{
				circle((MAXX/2),(MAXY/2),40);
			}
			break;
			
			case 6:
			if(s == X)
			{
				line((MAXX/2)+50,(MAXY/2)-50,(MAXX/2)+150,(MAXY/2)+50);
				line((MAXX/2)+150,(MAXY/2)-50,(MAXX/2)+50,(MAXY/2)+50);
			}
			else
			{
				circle((MAXX/2)-100,(MAXY/2),40);
			}
			break;
			
			case 7:
			if(s == X)
			{
				line((MAXX/2)-150,(MAXY/2)-150,(MAXX/2)-50,(MAXY/2)-50);
				line((MAXX/2)-50,(MAXY/2)-150,(MAXX/2)-150,(MAXY/2)-50);
			}
			else
			{
				circle((MAXX/2)-100,(MAXY/2)-100,40);
			}
			break;
			
			case 8:
			if(s == X)
			{
				line((MAXX/2)-50,(MAXY/2)-150,(MAXX/2)+50,(MAXY/2)-50);
				line((MAXX/2)+50,(MAXY/2)-150,(MAXX/2)-50,(MAXY/2)-50);
			}
			else
			{
				circle((MAXX/2),(MAXY/2)-100,40);
			}
			break;
			
			case 9:
			if(s == X)
			{
				line((MAXX/2)+50,(MAXY/2)-150,(MAXX/2)+150,(MAXY/2)-50);
				line((MAXX/2)+150,(MAXY/2)-150,(MAXX/2)+50,(MAXY/2)-50);
			}
			else
			{
				circle((MAXX/2)+100,(MAXY/2)-100,40);
			}
			break;
	}
}
