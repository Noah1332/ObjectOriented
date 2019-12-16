//
//  main.cpp
//  Rock_Scissor_Paper
//
//  Created by Noah McGhghy on 9/8/19.
//  Copyright © 2019 Noah McGhghy. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <random>
using namespace std;


//borrowed from the raquetball program; used to generate a random number between 0 and 3.
int seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_real_distribution<double> distribution(0.0, 3.0);


int main()
{
    //Move is what the player or computer inputed; MoveN is the translated  form of their selection.
    char playerMove = 'a';
    int playerMoveN = 1;
    int computerMove = 0;
    //this allows the computer to generate a random choice.
    computerMove =  distribution (generator);
    int computerMoveN = 0;
    //sum is used to add the computer's and player's MoveNs together so the switch can output a winner.
    int sum = 0;
    
    
    cout << "Welcome to McGhghy's Rock Scissor Paper.\n";
    cout << "Please input your move. (R for rock, S for Scissor, P for Paper \n";
    cin >>  playerMove;
    
    //This section changes the playerMove into a number that can be used in later sum to calculate a winner;
    if ((playerMove == 'R') || (playerMove == 'r'))
        playerMoveN = 10;
    else if ((playerMove == 'S') || (playerMove == 's'))
        playerMoveN = 20;
    else if ((playerMove == 'P') || (playerMove == 'p'))
        playerMoveN = 30;
    
    //This section changed the computer's random generated move into the form needed for the later sum.
    if ((0 < computerMove) && (computerMove <= 1))
        computerMoveN = 1;
    else if ((1 < computerMove) && (computerMove <= 2))
        computerMoveN = 2;
    else
        computerMoveN = 3;
    
    //sum adds the choice of the user and the computer.
    sum = playerMoveN + computerMoveN;
    
    //the switch statement uses the sum to output the winner of the game.
    switch (sum)
    {
        case 11:
            cout << "You chose Rock and the computer chose Rock. Its a draw\n ";
            break;
            
        case 12:
            cout << "You chose Rock and the computer chose Scissor. You win\n ";
            break;
            
        case 13:
            cout << "You chose Rock and the computer chose Paper. You lose\n ";
            break;
            
        case 21:
            cout << "You chose Scissor and the computer chose Rock. You lose\n ";
            break;
            
        case 22:
            cout << "You chose Scissor and the computer chose Scissor. It's a Draw\n ";
            break;
            
        case 23:
            cout << "You chose Scissor and the computer chose Paper. You win\n ";
            break;
            
        case 31:
            cout << "You chose Paper and the computer chose Rock. You win\n ";
            break;
            
        case 32:
            cout << "You chose Paper and the computer chose Scissor. You lose\n ";
            break;
            
        case 33:
            cout << "You chose Paper and the computer chose Paper. It's a draw\n ";
            break;
            
            
    }
    
    return 0;
}
