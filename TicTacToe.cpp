//  Noah McGhghy
//  Z698V495
//  Homework 2 Tic Tac Toe
//  Allows two users to play a normal game of tic tac toe and calculates the winner.
//  9/9/2019


#include <iostream>
using namespace std;
//declaring const row and column int variables for the multidimensional array.
const int ROW = 3;
const int COLUMN = 3;

//this function will draw the board.
void drawboard(char board[COLUMN][ROW]);
//this function will take in the user's input.
void userInput(char board[COLUMN][ROW], char piece);
//this function will check if the game is over.
int gameOver(char board[COLUMN][ROW], int count);
//this function determines who the winner is.
void winner(int player, int gameNotOver);

int main()
{
    int gameNotOver = 1;
    int player = 1;
    int count = 1;
    char board[COLUMN][ROW];
    char fill = '1';
    char piece = 'X';
    
    //this for-loop sets up the board initially for the beginning of the game.
    for (int i = 0; i < 3; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            board[i][j] = fill;
            fill++;
        }
    }
    
    //this do-loop will continue until there are no more moves or somebody has won. This is checked by the while statement.
    do
    {
        //this draw's the new board before the player has a chance to make their selection.
        drawboard(board);
        
        //this if-statement is used to determinee which playeer's turn it is.
        if ((player % 2) != 0)
        {
            cout << "Player 1 please choose where to play an X \n";
            piece = 'X';
        }
        else
        {
            cout << "Player 2 please choose where to play an O \n";
            piece = 'O';
        }
        //the function will take in the user's input.
        userInput(board, piece);
        //then gameNotOver will take in the result of the gameOver check. if 1 is returned it continues; 0 or 7 the program exits the do-loop
        gameNotOver = gameOver(board, count);
        //the player is increased so the other person can have a turn.
        player++;
        //count is used to see if there is still available moved to be made.
        count++;
        
        cout << endl;
    } while (gameNotOver == 1);
    
    //this will draw the board again showing the final position.
    drawboard(board);
    winner(player, gameNotOver);
    
    return 0;
}





//this function draws the board and shows what is in each position.
void drawboard(char board[COLUMN][ROW])
{
    cout << " " << endl;
    cout << " " <<  board[0][0] << "    |   " << board[0][1] << "   |   " << board [0][2] << endl;
    cout << " -------------------\n";
    cout << " " <<  board[1][0] << "    |   " << board[1][1] << "   |   " << board [1][2] << endl;
    cout << " -------------------\n";
    cout << " " << board[2][0] << "    |   " << board[2][1] << "   |   " << board [2][2] << endl;
    return;
}

//this function uses a switch to determine which piece will go in each spot depending on what the user choses.
void userInput(char board[COLUMN][ROW], char piece)
{
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
        case 1:
            board[0][0] = piece;
            break;
            
        case 2:
            board[0][1] = piece;
            break;
            
        case 3:
            board[0][2] = piece;
            break;
            
        case 4:
            board[1][0] = piece;
            break;
            
        case 5:
            board[1][1] = piece;
            break;
            
        case 6:
            board[1][2] = piece;
            break;
            
        case 7:
            board[2][0] = piece;
            break;
            
        case 8:
            board[2][1] = piece;
            break;
            
        case 9:
            board[2][2] = piece;
            break;
    }
    return;
}

//this function is made up of if-statements that compare all the possible ways win or draw.
int gameOver( char board[COLUMN][ROW], int count)
{
    if ((board[0][0] == board [0][1]) && (board[0][1] == board[0][2]))
    {
        return 0;
    }
    else if ((board[1][0] == board [1][1]) && (board[1][2] == board[1][0]))
    {
        return 0;
    }
    else if ((board[2][0] == board [2][1]) && (board[2][1] == board[2][2]))
    {
        return 0;
    }
    else if ((board[0][0] == board [1][0]) && (board[0][0] == board[2][0]))
    {
        return 0;
    }
    else if ((board[0][1] == board [1][1]) && (board[0][1] == board[2][1]))
    {
        return 0;
    }
    else if ((board[0][2] == board [1][2]) && (board[1][2] == board[2][2]))
    {
        return 0;
    }
    else if ((board[0][0] == board [1][1]) && (board[1][1] == board[2][2]))
    {
        return 0;
    }
    else if ((board[0][2] == board [1][1]) && (board[1][1] == board[2][0]))
    {
        return 0;
    }
    else if (count == 9)
    {
        return 7;
    }
    else
        return 1;
        
    
}

//this function declares the winner, or it declares a draw.
void winner(int player, int gameNotOver)
{
    if (gameNotOver == 7)
        cout << "It's a Draw\n";
    else if((player % 2) == 0)
        cout << "Player 1 Won\n";
    else
        cout << "Player 2 Won\n";
    return;
}
