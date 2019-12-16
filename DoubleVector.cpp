//
//  main.cpp
//  DoubleVector
//
//  Created by Noah McGhghy on 10/30/19.
//  Copyright © 2019 Noah McGhghy. All rights reserved.
//
#include <iostream>
using namespace std;

class DoubleVector{
    
private:
    //declaring my private member functions
    double* ary;
    int maxCount;
    int count;
    
public:
    
    //constructors
    DoubleVector()
    {
        maxCount = 50;
        ary = new double [maxCount];
        for(int a = 0; a < maxCount; a++)
        {
            ary[a] = 0.0;}
        
    }
    DoubleVector(int num): maxCount(num), ary(new double [num]) {for(int a = 0; a < maxCount; a++){ary[a] = 0.0;}}
    DoubleVector(DoubleVector &ca)
    {
        maxCount = ca.maxCount;
        for(int a = 0; a < maxCount; a++)
        {
             ary[a] = ca.ary[a];
        }
    }
    ~DoubleVector();
    
    
    //overloaded member functions
    void operator=(const DoubleVector &obj)
    {
        ary = new double[obj.maxCount];
        maxCount = obj.maxCount;
        count = obj.count;
        for (int a = 0; a < maxCount; a++)
        {
            ary[a] = obj.ary[a];
        }
    }
    bool operator==(const DoubleVector &obj){if(obj.count == count){return true;}else{return false;}}

    //member functions
    void push_back(double a);
    int capacity();
    int size();
    void reserve(int a);
    void resize(int a);
    double valueAt(int a);
    void changeValue(double a, int b);
    void print() {for(int a = 0; a < count; a++){cout << double(ary[a]); cout << endl;}}
    void print1() {for(int a = 0; a < maxCount; a++){cout << double(ary[a]); cout << endl;}}
};

//adds another number to the dynamic array
void DoubleVector::push_back(double a)
{
    ary[count] = a;
    count++;
}

//returns the capacity of the dynamic array
int DoubleVector::capacity()
{
    return maxCount;
}

//returns the size of the array
int DoubleVector::size()
{
    return count;
}

//reserves memory for the new max count
void DoubleVector::reserve(int a)
{
    if (a > maxCount){
        double *temp = new double[a];
        for(int i = 0; i < maxCount; ++i)
            temp[i] = ary[i];
        delete ary;
        ary = temp;
    }
    
}


void DoubleVector::resize(int a)
{
    if (a > maxCount)
    {
        int temp = 0;
        maxCount = a;
        for(int b = count; b < a; b++)
        {
            ary[b] = 0.0;
            temp = b;
        }
        count = temp;
    }
    else
    {
        maxCount = a;
        count = a;
    }
}


double DoubleVector::valueAt(int a)
{
    return ary[a];
}


void DoubleVector::changeValue(double a, int b)
{
    ary[b] = a;
}

DoubleVector::~DoubleVector()
{
    maxCount = 0;
    delete[] ary;
}

int main()
{
    //calls defualt constructor
    DoubleVector test1;
    cout << " The Default constructor" << endl;
    test1.print1();
    cout<< endl;
    
    
    //calls parameterized constructor
    DoubleVector test2(100);
    
    //tests the pushback function to fill the "Double Vector;
    for(double a = 1.2; a < 50.0; a++)
        test2.push_back(a);
    cout << " Shows how the parameterized constructor works" << endl;
    test2.print();
    cout << endl;
    
    //tests the reserve and resize function
    test2.resize(30);
    test2.print();
    test2.reserve(51);
    test2.print();
    cout << endl;
    test2.print1();
    cout << endl;
    
    //tests size funtion
    cout << "the size of the dynamic array is " << test2.size() << endl;
    
    //test the capacity function
    cout << "the capacity of the dynamic array is " << test2.capacity() <<endl;
    
    DoubleVector test3;
    test3 = test2;
    if(test3 == test2)
        cout << " Test2 and Test3 are equal\n";
    
    test3.print1();
    cout << endl;
    
    test2.changeValue(66.7, 3);
    test2.print();
    cout << endl;
    cout << "The value at 5 is " << test3.valueAt(5) << endl;
    
    return 0;
}
