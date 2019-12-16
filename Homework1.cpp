//
//  Homework 1
//  Noah McGhghy
//  Z698V495
//  A program that can find the factorial of any large number (up to 10,000 digits)
//
//  Created by Noah McGhghy on 9/2/19.
//  Copyright © 2019 Noah McGhghy. All rights reserved.
//

#include <iostream>
using namespace std;

//this is the function protype for my factorial program.
void factorialMath (int origNum);


//This function calculates the factorial of any number.
void factorialMath (int origNum)
{
    //this declares and initiates the array to 10,000 digits and they are all intialized to 0.
    int factAry[10000] = {0};
    //the array's first index is set to 1
    factAry[0] = 1;
    //carryOver is used in the mathematical calculation of the factorial.
    int carryOver = 0;
    //the array size is initially set to 1. Since the array is set to 10,000, this will be used in the output later.
    int arySize = 1;
    
    //the first for loop is used to start the index at 2 until it reaches the size of the original factorial number.
    for (int index = 2; index <= origNum; index++)
    {
        /*the second for loop is used for the actual math calculations either putting the solution into the array or
         carrying it over. This leads to a increase in arySize. The nested for-loop is based off of the class notes. */
        for (int indexTwo = 0; indexTwo < arySize; indexTwo++)
        {
            int sum = factAry[indexTwo] * index + carryOver;
            carryOver = sum / 10;
            factAry[indexTwo] = sum % 10;
        }
        
        //This section deals with the carries that are larger than 9. Stops when the carry is not greater than 0.
        while (carryOver > 0)
        {
            factAry[arySize] = carryOver % 10;
            carryOver = carryOver / 10;
            arySize++;
        }
    }
    
    /*After the math is completed this next section outputs that array to the screen.
     It subracts one from the arySize because the math ends by increasing arySize.*/
    cout << "The factorial of " << origNum << " is ";
    for (int a = arySize - 1; a >=0; --a)
    {
        cout << factAry[a];
    }
}

int main()
{
    char stop = 'y';
    cout << "Welcome to the Factorial Calculator.\n";
    do
    {
        int factorialNumb;
        cout << "Please input a number you would like to find the factorial of. \n";
        cin >> factorialNumb;
        //inputs the desired number into the function to determine/calculate the factorial.
        factorialMath(factorialNumb);
        cout << endl <<"Would you like to find another factorial? (y/n) \n";
        cin >> stop;
    } while (stop != 'n');
    
    return 0;
}
