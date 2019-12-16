// Noah McGHghy
// Z608V495
// Homework 5
//
//  main.cpp
//  POSTNET
//
//  Created by Noah McGhghy on 9/29/19.
//  Copyright © 2019 Noah McGhghy. All rights reserved.
//
// 5 sets of 5 binary digits concatenate the values to get the full zipcode
// 7, 4, 2, 1, 0

#include <iostream>
#include <string>

class ZipCode{
    //zipBar is used for the conversion of ZipCode to Zip Bar
    //can be the  final Zip Bar if it starts as an integer zip Code.
    int zipBar[30];
    //zipCode is the actual ZipCode
    int zipCode;
    //used for the actual Zip Bar before conversion
    std::string zipsBar;
    
public:
    //function to convert string to int
    void unZip ();
    // function to convert int to string
    void reZip ();
    
    //constructors
    ZipCode();
    ZipCode(int zipCode): zipCode(zipCode) {}
    ZipCode(std::string zipsBar): zipsBar(zipsBar) {}
    
    //print functions depending on which direction the program is going.
    void printBar();
    void printCode();
};



int main (){
    //Example of Zipcode to Barcode
    std::cout << "Part 1: ZipCode to BarCode. " << std:: endl;
    ZipCode zip1(73533);
    zip1.reZip();
    zip1.printBar();
    
    //Example of Barcode to zipCode.
    std::cout << "Part 2: BarCode to Zipcode. " << std:: endl;
    ZipCode zip2{"1000100110010100011000110"};
    zip2.unZip();
    zip2.printCode();
    
    //example of an invalid entry
    std::cout << "Part 3: Invalid Entry. " << std:: endl;
    ZipCode zip3{"100010011001010001100011011000"};
    zip3.unZip();
    zip3.printCode();
    
    return 0;
}

void ZipCode::unZip(){
    //used to get string lenth to convert string to int
    int str_length = zipsBar.length();
    
      // create an array with size as string
      // length and initialize with 0
    int newZipBar[30];
    //initalized newzip bar to 0
    for (int i = 0; i < str_length; i++){
        newZipBar[i] = 0;
    }
    
    int j = 0;
      // for loop converts the string to ints
      for (int i = 0; zipsBar[i] != '\0'; i++) {
          if (zipsBar[i] == ',') {
          }
          else {
              newZipBar[j] = (zipsBar[i] - 48);
              j++;
          }
    }
    int zTemp = 0;
    //holds the actual integer in array form.
    int code[5] = {0};
    int a = 0;
    zipCode= 0;
    
    //converts the array into an integer using math and comparisons.
    if ((newZipBar[26] > 0) || (newZipBar[27] > 0) || (newZipBar[28] > 0)){
        zipCode = -1;
    }
    else{
        for (int i = 0; i < 25; i++)
        {
            if ((i== 0) || (i== 5) || (i== 10) || (i== 15) || (i== 20))
                zTemp += newZipBar[i] * 7;
            else if((i== 1) || (i== 6) || (i== 11) || (i== 16) || (i== 21))
                zTemp += newZipBar[i] * 4;
            else if((i== 2) || (i== 7) || (i== 12) || (i== 17) || (i== 22))
                zTemp += newZipBar[i] * 2;
            else if((i== 3) || (i== 8) || (i== 13) || (i== 18) || (i== 23))
                zTemp += newZipBar[i] * 1;
            else
                zTemp += newZipBar[i] * 0;
            if ((i== 4) || (i== 9) || (i== 14) || (i== 19) || (i== 24)){
                code[a] =zTemp;
                zTemp = 0;
                a++;
            }
        }
        //this for loop is where the new integer is actually put into the private member zipCode
        for (int i = 0; i < 5; i++){
            zipCode = (zipCode * 10) + code[i];
        }
    }
}


//this function takes the integer and converts it to an array barcode.
void ZipCode::reZip ()
{
    int newZipCode = zipCode;
    int tempBar[5];
    int k = 0;
    tempBar[0] = newZipCode / 10000;
    newZipCode = newZipCode % 10000;
    tempBar[1] = newZipCode /1000;
    newZipCode = newZipCode % 1000;
    tempBar[2] = newZipCode / 100;
    newZipCode = newZipCode % 100;
    tempBar[3] = newZipCode /10;
    newZipCode = newZipCode % 10;
    tempBar[4] = newZipCode;
    
    //sets zipBar to 0
    for(int i = 0; i < 25; i++){
        zipBar[i] = 0;
    }
    //converts the actual numbers into 1 and 0
    for(int i = 0; i < 5; i++){
        newZipCode = tempBar[i];
        if(newZipCode >= 7){
            zipBar[k] = 1;
            newZipCode -= 7;
            k++;
            if (newZipCode == 4){
                zipBar[k] = 1;
                k++;
                zipBar[k]=0;
                k++;
                zipBar[k] = 0;
                k++;
                zipBar[k] = 0;
                k++;
            }
            else if(newZipCode == 2){
                zipBar[k] = 0;
                k++;
                zipBar[k] = 1;
                k++;
                zipBar[k] = 0;
                k++;
                zipBar[k] = 0;
                k++;
            }
            else if(newZipCode == 1){
            zipBar[k] = 0;
            k++;
            zipBar[k] = 0;
            k++;
            zipBar[k] = 1;
            k++;
            zipBar[k] = 0;
            k++;
            }
            else if(newZipCode == 0){
            zipBar[k] = 0;
            k++;
            zipBar[k] = 0;
            k++;
            zipBar[k] = 0;
            k++;
            zipBar[k] = 1;
            k++;
            }
        }
        else if (newZipCode >= 4){
            zipBar[k] = 0;
            k++;
            zipBar[k] = 1;
            k++;
            newZipCode -=4;
        
            if(newZipCode == 2){
                zipBar[k] = 1;
                k++;
                zipBar[k] = 0;
                k++;
                zipBar[k] = 0;
                k++;
            }
            else if(newZipCode == 1){
            zipBar[k] = 0;
            k++;
            zipBar[k] = 1;
            k++;
            zipBar[k] = 0;
            k++;
            }
            else if(newZipCode == 0){
            zipBar[k] = 0;
            k++;
            zipBar[k] = 0;
            k++;
            zipBar[k] = 1;
            k++;
            }
        }
        else if (newZipCode >= 2){
            zipBar[k] = 0;
            k++;
            zipBar[k] = 0;
            k++;
            zipBar[k] = 1;
            k++;
            newZipCode -=2;
            if(newZipCode == 1){
                zipBar[k] = 1;
                k++;
                zipBar[k] = 0;
                k++;
                }
                else if(newZipCode == 0){
                    zipBar[k] = 0;
                    k++;
                    zipBar[k] = 1;
                    k++;
                }
        }
        else if(newZipCode == 1){
            zipBar[k] = 0;
            k++;
            zipBar[k] = 0;
            k++;
            zipBar[k] = 0;
            k++;
            zipBar[k] = 1;
            k++;
            zipBar[k] = 1;
            k++;
        }
    }
}
//prints the new bar zipcode
void ZipCode::printBar(){
    std::cout << "the Zip-Code Bar for " << zipCode << " is ";
    for (int i = 0; i < 25; i++){
        std::cout << zipBar[i];
    }
    std::cout << std::endl;
}

//prints the new zipcode from the zipbar.
void ZipCode::printCode(){
    if(zipCode == -1)
        std::cout << " Invalid Entry " << std::endl;
    else{
         std::cout << "The Zipcode for " << zipsBar;
        std::cout << " is " << zipCode << std::endl;
    }
}
