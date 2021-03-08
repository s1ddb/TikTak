#include <iostream>




/* By Siddhartha Bobba
   Date 03/01/2021

   A 2 player Tic Tac Toe game

*/

  // Board layout

  // 1 2 3
  // 4 5 6
  // 7 8 9



  using namespace std;


char BoardMatrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //makes a 3x3 matrix for the tic tac toe game and initializes all 9 elements of the matrix, placed outside the main function so it can be a universal varaible through all functions
char Player = 'X'; //variable to track the play of the user


void DrawBoard(); //Function to draw the board matrix
void PlayerInput(); //Function to get the player's game input
void SwitchPlayer(); //Function to switch the players when it's their turn
void CheckWin(); //Function to check who's the winner of the game
void ClearBoard(); 

bool Gameplay = true; //to keep the game going or not
bool GameDraw = false;
int FullBoard = 0; //to check if board is full or not

int main()

{
  ClearBoard(); 
  DrawBoard();

  while(Gameplay = true) {
    
    PlayerInput(); //calls the PlayerInput variable inside main
    DrawBoard(); //calls the DrawBoard variable inside the main after printing the player's input
    CheckWin(); // calls the CheckWin variable in main to check if any player has won yet
    SwitchPlayer(); //calls the SwitchPlayer variable inside main to switch from X to O, or back.
    
  }
 
  
  return 0;
} //end of main



void ClearBoard() {
    for (int i = 0; i < 3; i++)
		for (int j=0; j < 3; j++)
			BoardMatrix[i][j] = '-';
}



void DrawBoard() {
  
   cout << "Use numbers 1 to 9 to pick where to place your play" << endl;

  
     for (int i = 0; i < 3; i++) { //i = row
      
     for (int j = 0; j < 3; j++) { //j = column

       cout << BoardMatrix[i][j] << " "; //prints out every variable in the board
     }
     cout << endl; //displays the matrix in rows instead of in 1 line
   }

 } //end of function


 void PlayerInput() {


   int ans; //variable to store player's answer
   cout << "Enter the number spot you would like to make your move on: " << endl;
   cin >> ans; //takes player's input 


   if (ans == 1) {
     BoardMatrix[0][0] = Player; //if input is 1, sets the first spot in the matrix to X (1 on the matrix layout)
     FullBoard++;
   }

   else if (ans == 2) {
     BoardMatrix[0][1] = Player; //2 on the matrix layout (First row, second column)
	 FullBoard++;
   }

   else if (ans == 3) {
     BoardMatrix[0][2] = Player; //3 on the matrix layout (First row, third column
	 FullBoard++;
   }

   else if (ans == 4) {
     BoardMatrix[1][0] = Player; //4 on the matrix layout (Second row, first column)
	 FullBoard++;
   }

   else if (ans == 5) {
     BoardMatrix[1][1] = Player; //5 on the matrix layout (Second row, second column)
	 FullBoard++;
   }

   else if (ans == 6) {
     BoardMatrix[1][2] = Player; //6 on the matrix layout (Second row, third column)
	 FullBoard++;
   }

   else if (ans == 7) {
     BoardMatrix[2][0] = Player; //7 on the matrix layout (Third row, first column)
	 FullBoard++;
   }
   else if (ans == 8) {
     BoardMatrix[2][1] = Player; //8 on the matrix layout (Third row, second column)
	 FullBoard++;
   }

   else if (ans == 9) {
     BoardMatrix[2][2] = Player; //9 on the matrix layout (Third row, third column)
	 FullBoard++;
   }


   /* if (ans != '1', '2', '3', '4', '5', '6', '7', '8', '9') {

     cout << "Invalid input, please select a spot on the game board from 1 to 9" << endl;

   } // throws an error if anything other than numbers from 1 to 9 are entered.
   */
  
 }


 void SwitchPlayer() {

   if (Player == 'X') {

     Player = 'O'; //switch player to O if it's Y whenever the function is called
    
   }

   else {

     Player = 'X'; //if the player is not X, then switch to X
    
   }


 }


  void CheckWin() {


   bool WinX = false;
   bool WinO = false;

   // all the if statements for the possible ways X could win
  
  if (BoardMatrix[0][0] == 'X' && BoardMatrix[0][1] == 'X' && BoardMatrix[0][2] == 'X')	{
    WinX = true;
  }
  if (BoardMatrix[1][0] == 'X' && BoardMatrix[1][1] == 'X' && BoardMatrix[1][2] == 'X')	{
    WinX = true;
  }
  if (BoardMatrix[2][0] == 'X' && BoardMatrix[2][1] == 'X' && BoardMatrix[2][2] == 'X')	{
    WinX = true;
  }
  if (BoardMatrix[0][0] == 'X' && BoardMatrix[1][0] == 'X' && BoardMatrix[2][0] == 'X')	{
    WinX = true;
  }		
  if (BoardMatrix[0][1] == 'X' && BoardMatrix[1][1] == 'X' && BoardMatrix[2][1] == 'X') {
    WinX = true;
  }		
  if (BoardMatrix[0][2] == 'X' && BoardMatrix[1][2] == 'X' && BoardMatrix[2][2] == 'X')	{
    WinX = true;
  }
  if (BoardMatrix[0][0] == 'X' && BoardMatrix[1][1] == 'X' && BoardMatrix[2][2] == 'X') {
    WinX = true;
  }		
  if (BoardMatrix[2][0] == 'X' && BoardMatrix[1][1] == 'X' && BoardMatrix[0][2] == 'X')	{
    WinX = true;
  }


  // all the if statements for the possible ways O could win
  
  if (BoardMatrix[0][0] == 'O' && BoardMatrix[0][1] == 'O' && BoardMatrix[0][2] == 'O') {
    WinO = true;
  }
  if (BoardMatrix[1][0] == 'O' && BoardMatrix[1][1] == 'O' && BoardMatrix[1][2] == 'O') {
    WinO = true;
  }
  if (BoardMatrix[2][0] == 'O' && BoardMatrix[2][1] == 'O' && BoardMatrix[2][2] == 'O') {
    WinO = true;
  }
  if (BoardMatrix[0][0] == 'O' && BoardMatrix[1][0] == 'O' && BoardMatrix[2][0] == 'O') {
    WinO = true;
  }
  if (BoardMatrix[0][1] == 'O' && BoardMatrix[1][1] == 'O' && BoardMatrix[2][1] == 'O') {
    WinO = true;
  }
  if (BoardMatrix[0][2] == 'O' && BoardMatrix[1][2] == 'O' && BoardMatrix[2][2] == 'O') {
    WinO = true;
  }
  if (BoardMatrix[0][0] == 'O' && BoardMatrix[1][1] == 'O' && BoardMatrix[2][2] == 'O') {
    WinO = true;
  }
  if (BoardMatrix[2][0] == 'O' && BoardMatrix[1][1] == 'O' && BoardMatrix[0][2] == 'O') {
    WinO = true;
  }

  else {
    GameDraw = true;

  }

   //End Game if Won

  if (WinX) {
    cout << "X Wins!";
    Gameplay = false;
  }
  if (WinO)  {
    cout << "O Wins!";
    Gameplay = false;
  }
  if (GameDraw == true && FullBoard == 9) {

    cout << "It's a Tie!" << endl;
    Gameplay = false;
  }

    
}

