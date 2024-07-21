#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

void ProgramGreeting();
void menu();
void gameInstructions();
void gameExplain();
void gamePlay();
void gameQuit();
void display( char[]);
char board[9] = {'0','1','2','3','4','5','6','7','8'};
int winGame(char []);


int main()
{

ProgramGreeting();

// Variable Declaration
int menuOption,
    humVsComp = 1,
    move,
    points,
    number = rand()%9;
char position,
     rerun;

// Specification B1 - Start Menu
  menu();
  cin >> menuOption;

  switch(menuOption){
    case 1:
    gameExplain();
    cout << "If you're ready to play the game, enter 2 : ";
    cin >> menuOption;
    cout << endl;
    break;
    case 2: 
    gamePlay();
    break;
    case 3:
    gameQuit();
    break;
  } 
// Display the Game Instructions
      if (menuOption == 2){
  gameInstructions();

// Specification B2 - Valid Menu Choices
  while (!(menuOption == 1 || menuOption == 2 || menuOption == 3)){
    cout << "Please enter a valid menu option : ";
    cin >> menuOption;
  }

// Specification C1 - Random Start
// Determine who goes first
  cout << endl;
  cout << "Player X : human will be playing first." << endl;
  cout << "Player O : Computer will be playing second." << endl;
  cout << endl;

// Specification A1 - Main Game Loop 
do
{
// Specification C2 - Simple Display
// Display the board
display(board);

if(humVsComp %2 == 1)
humVsComp = 1;
else
humVsComp = 2;


// Specification C3 - AI
// Calculate the computer’s move
if(humVsComp == 2)
{
cout << "\n";
cout << "Player " << humVsComp << " (O) : Computer " << endl;
number = rand()%9;
position = 'O';
move = 0;

  
while(move == 0)
{
// Update the board with the computer’s move
if (number == 0 && board[0] == '0'){
board[0] = position;
move = 1;
}
else if (number == 1 && board[1] == '1'){

board[1] = position;
move = 1;
}
else if (number == 2 && board[2] == '2'){

board[2] = position;
move = 1;
}
else if (number == 3 && board[3] == '3'){
board[3] = position;
move = 1;
}
else if (number == 4 && board[4] == '4'){

board[4] = position;
move = 1;
}
else if (number == 5 && board[5] == '5'){

board[5] = position;
move = 1;
}
else if (number == 6 && board[6] == '6'){

board[6] = position;
move = 1;
}
else if (number == 7 && board[7] == '7'){

board[7] = position;
move = 1;
}
else if (number == 8 && board[8] == '8'){

board[8] = position;
move = 1;
}

else
{
number = rand()%9;
}
}
points = winGame(board);
humVsComp++;
}

// Get the human’s move
else if(humVsComp == 1)
{
cout << endl;
cout << "Player " << humVsComp << " (X) please enter a number from board :  ";
cin >> number;
position = 'X';
// Update the board with the human’s move 
if (number == 0 && board[0] == '0')
board[1] = position;
  
else if (number == 1 && board[1] == '1')
board[1] = position;
  
else if (number == 2 && board[2] == '2')
board[2] = position;
  
else if (number == 3 && board[3] == '3')
board[3] = position;
  
else if (number == 4 && board[4] == '4')
board[4] = position;
  
else if (number == 5 && board[5] == '5')
board[5] = position;
  
else if (number == 6 && board[6] == '6')
board[6] = position;
  
else if (number == 7 && board[7] == '7')
board[7] = position;
  
else if (number == 8 && board[8] == '8')

board[8] = position;

// Specification B3 - Valid Move
else
{
 cout << "Sorry, the position is already occupied." << endl; 

humVsComp--;
}
points = winGame(board);

humVsComp++;
}
  }while(points == 1);

// Specification A2 - Simple Prompt
  cout << endl;
  cout << "Would you like to play again? ";
  cin >> rerun;
  if (rerun == 'N' || rerun == 'n'){
    cout << endl;
    cout << "You have quit the program. Thank you for playing.\n";
  }
if(points == -1){
cout << endl;

// Congratulate the winner or declare a tie
cout << "Congratulations Player " << humVsComp << " is the winner!\n";}
  
else{
cout << "" << endl;
cout << "The game is a tie!\n";
  }

  }
// Source File Header
void ProgramGreeting(){
  cout << "Shreya Sareen\n";
  cout << "Tic Tac Toe, CISP 360\n";
  cout << "December 4th, 2022\n";
  cout << endl;
  cout << "Hello! This program is a game of Tic-Tac-Toe." << endl;
}

void menu(){
  cout << "----" << endl;
  cout << "MENU" << endl;
  cout << "----" << endl;
  cout << "1) Explain Game\n";
  cout << "2) Play Game\n";
  cout << "3) Quit Game\n"; 
  cout << endl;
  cout << "Please enter an option from the Menu : ";
}
void gameInstructions(){
  cout << "GAME INSTRUCTIONS" << endl;
  cout << "-----------------" << endl;
  cout << endl;
  cout << "1. You will be playing the game against the computer\n";
  cout << endl;
  cout << "2. You will take alternate turns filling in the tic tac board\n";
    cout << endl;
  cout << "3. Enter a number from tic tac toe board when its your turn, board will update number with an X\n";
  cout << endl;
  cout << "Good Luck!" << endl;
  cout << endl;
  
}
void gameExplain(){
  cout << endl;
  cout << "> Tic Tac Toe is a two-player board game where each player takes turns filling a space with either an X or an O\n";
  cout << "> If one of the players gets 3 X's or 3 O's in a vertical, horizontal, or diagonal line, then that player wins the game\n";
  cout << "> If both players don't get 3 X's or O's and all spaces are filled out, then both players get a tie\n";
  cout << endl;
}
void gamePlay(){
  cout << endl;
}
void gameQuit(){
  cout << endl;
  cout << "You have quit the game. Thank you for playing." << endl;
  return 0;
}

// Specification A3 - Array Data Type
void display(char board[])
{
cout << endl;


cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;
cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;
cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;

}

int winGame(char board[])
{
if (board[0] == board[1] && board[1] == board[2])
return 1;
  
else if (board[3] == board[4] && board[4] == board[5])
return 1;
  
else if (board[6] == board[7] && board[7] == board[8])
return 1;
  
else if (board[0] == board[3] && board[3] == board[6])
return 1;
  
else if (board[1] == board[4] && board[4] == board[7])
return 1;
  
else if (board[2] == board[5] && board[5] == board[8])
return 1;
  
else if (board[0] == board[4] && board[4] == board[8])
return 1;
  
else if (board[2] == board[4] && board[4] == board[6])

return 1;
else if (board[0] != '0' && board[1] != '1' && board[2] != '2'
&& board[3] != '3' && board[4] != '4' && board[5] != '5' 
&& board[6] != '6' && board[7] != '7' && board[8] != '8')

return 0;
  
else
return -1;
}
// Program Output 