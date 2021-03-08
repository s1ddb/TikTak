#include <iostream>




/* By Siddhartha Bobba
   Date 03/01/2021

   A 2 player Tic Tac Toe game to play between X and O, both operated by the user/s. Ask the players to replay or not and tells the user how many wins each player has at the end of each round. 

*/

  // Board layout

  // 11 12 13
  // 21 22 23
  // 31 32 33



  using namespace std;


char BoardMatrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'}; //makes a 3x3 matrix for the tic tac toe game and initializes all 9 elements of the matrix, placed outside the main function so it can be a universal varaible through all functions
char Player = 'X'; //variable to track the play of the user


void DrawBoard(); //Function to draw the board matrix
void PlayerInput(); //Function to get the player's game input
void SwitchPlayer(); //Function to switch the players when it's their turn
void CheckWin(); //Function to check who's the winner of the game
void ClearBoard(); 
void EndGame();

bool Gameplay = true; //to keep the game going or not
bool GameDraw = false;
bool WinX = false;
bool WinO = false;
int XCount = 0; //variable to keep track of wins for X
int OCount = 0; // variable to keep track of wins for Y


int FullBoard = 0; //to check if board is full or not
string PlayAgain; //to track answer for if the user wants to play again or not

int main()

{
  ClearBoard(); 
  DrawBoard();


  while(Gameplay) {

    
    PlayerInput(); //calls the PlayerInput variable inside main
    DrawBoard(); //calls the DrawBoard function inside the main after printing the player's input
    CheckWin(); // calls the CheckWin function in main to check if any player has won yet
    EndGame(); // end game functions, just a follow up function of CheckWin
    SwitchPlayer(); //calls the SwitchPlayer variable inside main to switch from X to O, or back.
    
  }


 
  
  return 0;
} //end of main



void ClearBoard() { //clears the board and replaces each slot with -
    for (int i = 0; i < 3; i++)
		for (int j=0; j < 3; j++)
			BoardMatrix[i][j] = '-';
}



void DrawBoard() {
  
  cout << "\t1 \t2 \t3 " << endl; // 1, 2, 3
   cout << "1\t" << BoardMatrix[0][0] << "  \t" << BoardMatrix[0][1] << "  \t" << BoardMatrix[0][2] << endl; //first row
   cout << "2\t" << BoardMatrix[1][0] << "  \t" << BoardMatrix[1][1] << "  \t" << BoardMatrix[1][2] << endl; //second row
   cout << "3\t" << BoardMatrix[2][0] << "  \t" << BoardMatrix[2][1] << "  \t" << BoardMatrix[2][2] << endl; //third row

  
   /* for (int i = 0; i < 3; i++) { //i = row
      
     for (int j = 0; j < 3; j++) { //j = column

       cout << BoardMatrix[i][j] << " "; //prints out every variable in the board
     }
     cout << endl; //displays the matrix in rows instead of in 1 line
   }
   */
   
 } //end of function


 void PlayerInput() {


   int ans; //variable to store player's answer
   cout << "Enter the number spot you would like to make your move on." << endl;
   cout << "Row number first, followed by Column Number." << endl; // directions for input
   cin >> ans; //takes player's input 


   if (ans == 11 && BoardMatrix[0][0] == '-') { //if ans is addressing the right slot and slot is empty, then place X or O
     BoardMatrix[0][0] = Player; //if input is 11, sets the first spot in the matrix to X or O (1 on the matrix layout)
     FullBoard++; //increments fullboard by 1 every time user plays
   }

   else if (ans == 12 && BoardMatrix[0][1] == '-') {
     BoardMatrix[0][1] = Player; //1 and 2 on the matrix layout (First row, second column)
	 FullBoard++;
   }

   else if (ans == 13 && BoardMatrix[0][2] == '-') {
     BoardMatrix[0][2] = Player; //1 and 3 on the matrix layout (First row, third column
	 FullBoard++;
   }

   else if (ans == 21 && BoardMatrix[1][0] == '-') {
     BoardMatrix[1][0] = Player; //2 and 1 on the matrix layout (Second row, first column)
	 FullBoard++;
   }

   else if (ans == 22 && BoardMatrix[1][1] == '-') {
     BoardMatrix[1][1] = Player; //2 and 2 on the matrix layout (Second row, second column)
	 FullBoard++;
   }


   else if (ans == 23 && BoardMatrix[1][2] == '-') {
     BoardMatrix[1][2] = Player; //1 and 2 on the matrix layout (Second row, third column)
	 FullBoard++;
   }

   else if (ans == 31 && BoardMatrix[2][0] == '-') {
     BoardMatrix[2][0] = Player; //3 and 1 on the matrix layout (Third row, first column)
	 FullBoard++;
   }
   else if (ans == 32 && BoardMatrix[2][1] == '-') {
     BoardMatrix[2][1] = Player; //3 and 2 on the matrix layout (Third row, second column)
	 FullBoard++;
   }

   else if (ans == 33 && BoardMatrix[2][2] == '-') {
     BoardMatrix[2][2] = Player; //3 and 3 on the matrix layout (Third row, third column)
	 FullBoard++;
   }


  
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
    GameDraw = true; //sets gamedraw boolean to true so we can call a draw later on along with fullboard being 9 to see if the board is full.

  }




}



void EndGame() {

   //End Game if X or O wins or ties

  if (WinX) {
    cout << "X Wins!" << endl;
    XCount++;
    cout << "X has " << XCount << " Win/s." << endl; //announce X wins
    cout << "O has " << OCount << " Win/s." << endl; //announce O wins
    cout << "Would you like to play again? Say 'Y' or 'N'" << endl;
    cin >> PlayAgain;
    if (PlayAgain == "Y") {
      //re initialize variables
      WinX = false;
      FullBoard = 0;
      GameDraw = false;
      ClearBoard();
      DrawBoard();
      SwitchPlayer();
    }
    else if (PlayAgain == "N") {
      Gameplay = false;
    }

  }
  if (WinO)  {
    cout << "O Wins!" << endl;
    OCount++;
    cout << "O has " << OCount << " Win/s." << endl; //announce O wins
    cout << "X has " << XCount << " Win/s." << endl; //announce X wins
    cout << "Would you like to play again? Say 'Y' or 'N'" << endl;
    cin >> PlayAgain;
    if (PlayAgain == "Y") {
      //re initialize variables

      WinO = false;
      FullBoard = 0;
      GameDraw = false;
      ClearBoard();
      DrawBoard();
      SwitchPlayer();
    }
    else if (PlayAgain == "N") {
      Gameplay = false;
    }

  }
  if (GameDraw == true && FullBoard == 9) {

    cout << "It's a Tie!" << endl;
    cout << "Would you like to play again? Say 'Y' or 'N'" << endl;
    cin >> PlayAgain;
    if (PlayAgain == "Y") {
      // re initialize variables

      GameDraw = false;
      WinO = false;
      WinX = false;
      ClearBoard();
      DrawBoard();
      SwitchPlayer();
    }
    else if (PlayAgain == "N") {
      Gameplay = false;
    }
  }


}

