//  Noah McGhghy
//  Z698V495
//
// Similatees multiple games of blackjack and estimates the probability the dealer will bust.
//
//  main.cpp
//  BlackJack_HW3
//
//  Created by Noah McGhghy on 9/16/19.
//  Copyright © 2019 Noah McGhghy. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <random>
using namespace std;

//Adapted from the RacquetBall Program.
int seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator(seed);
std::uniform_real_distribution<double> distribution(0.0, 13.0);

int gameSim(int gameTotal);
double bust(double dealerCount);
int dealCard();

int main()
{
    int gameTotal = 0;
    double probability = 0.0;
    //int dealerBust = 0;
    cout << " Welcome to McGhghy's BlackJack. Please Enter how many games you would like to stimulate\n";
    
    cin >> gameTotal;
    probability = gameSim(gameTotal);
    
    cout << " If you play " << gameTotal << " games the dealer's bust rate would be " << probability  << "%\n";
    cout << " the dealer would win " << int (gameTotal - (probability * gameTotal * .01)) << " of the games.\n";
    
    return 0;
}


//this function simulates game for n cases specified by the user.
int gameSim(int gameTotal)
{
    double bustProb = 0.0;
    double dealerWinRate = 0.0;
    double gameCount = 0.0;
    int cpuCount = 0;
    
    //the do loop continues simulating games until the game count is equal to the game total
    do{
        //dealCard() deals card to the cpu count
        cpuCount = dealCard();
        //after the cards are dealt the count is tested to see if it busted and then it is added to the dealerWinRate
        //if he busted a 1.0 is added. If he does not bust he gets 0.0 added.
        dealerWinRate += bust(cpuCount);
        gameCount++;
        
    } while (gameCount != gameTotal);
    
    //we calculate the probability of the entire simulation then return it to main.
    bustProb = dealerWinRate / gameTotal;
    bustProb *= 100;
    return bustProb;
}

//this function generates the gards that go into play for the cpu.
int dealCard()
{
    int cardCount = 0;
    int cardGen = 0;
    double card = 0.0;
    bool ace = false;
    while ((cardCount <= 21) && (cardCount < 17))
    {
        cardGen = distribution(generator);
        //this test whether the card is an ace or not
        if (cardGen == 1)
            ace = true;
        
        //this if loop-statement calculates the value of the card drawn.
        if ((cardGen < 11) && cardGen > 1 )
        {
            card = cardGen;
        }
        else if (cardGen > 10)
        {
            card = 10.0;
        }
        else if ((ace == true) && (cardCount < 11.0))
        {
            card = 11.0;
        }
        else if ((ace == true) && (cardCount > 11.0 ))
        {
            card = 1.0;
        }
        
        cardCount += card;
        ace = false;
    }
    //we return the card count so then it can be used in the bust function.
    return cardCount;
}

//this function test whether the dealer busted or won.
double bust (double dealerCount)
{
    double winner = 0.0;
    if (dealerCount <= 21)
        winner = 0.0;
    else if (dealerCount > 21)
        winner = 1.0;
  
    return winner;
}

