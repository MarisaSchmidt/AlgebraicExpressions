//  driverStack.cpp
//  
//
//  Created by Marisa Schmidt on 12/13/14.
//
//

#include "AlgebraicExpression.h"
#include<iostream>
using namespace std;

int main() {

    char answer;
    
    do {
       
        AlgebraicExpression a;
        
        a.setInfix();
        a.doConversion();
        a.Display();
    
        cout << "Enter another Equation? If yes, Type 'Y'. If not, type anything else." << endl;
        cin >> answer;

    } while (answer=='Y'||answer=='y');


    cout << "Exiting program..." << endl;
    return 0;
    
}
