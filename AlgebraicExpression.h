//
//  AlgebraicExpression.h
//  
//
//  Created by Marisa Schmidt on 12/13/14.
//
//

#ifndef _AlgebraicExpression_h
#define _AlgebraicExpression_h

#include "Stack.h"
#include<iostream>
using namespace std;

class AlgebraicExpression {
    
public:
    AlgebraicExpression(); //default constructor
    //AlgebraicExpression(const &string); //copy constructor
    ~AlgebraicExpression();
    void getInfix(); //accessor functions
    void setInfix();
    void getPostfix();
    void doConversion();
    void infixToPostfix(); //convert infix to postfix
    void Evaluate(); //evaluate postfix
    int Calculate(int, int, char);
    int getFinalVal(); //return final value
    void Display();
    bool precedenceHigher(char, char); //determine precedence
    
    //convert algrebraic expression infix to postfix
    //evaluate expression
    
private:
    string infix;
    string postfix;
    int finalVal;

};


AlgebraicExpression::AlgebraicExpression() {
    //make some default values
    infix = " ";
    postfix = " ";
}

AlgebraicExpression::~AlgebraicExpression() {
    
}

/*
AlgebraicExpression::AlgebraicExpression (const &string e) {
 infix = e.infix;
}
 */


void AlgebraicExpression::setInfix() {
    cout << "Expression? " << endl;
    cin >> infix;
}

int AlgebraicExpression::getFinalVal() {
    return finalVal;
}

void AlgebraicExpression::getInfix() {
    cout << "Your Infix Equation: " << infix << endl;
    cout << endl;
}

void AlgebraicExpression::getPostfix() {
    cout << "Your Postfix Equation: " << postfix << endl;
    cout << endl;
}


void AlgebraicExpression::infixToPostfix () {
 
    Stack<char> s;
    char ch;
    
    
    for (int i=0; i < infix.length(); i++) {
        ch = infix[i];

        //if number, add to postfix expression
        if (isalnum(ch)) {
            postfix+=ch; //append integer to postfix immediately
        }
        else if (ch=='(') {
            s.push(ch); //push '(' immediately on to stack
        }
        else if (ch==')') { //pop that expression
            
            while(!s.isEmpty()) {
                ch = s.getTop(); //equal to top, where you will start to pop
                s.pop(); //pop your stack
                
                if (ch=='(') { //you don't need to add this to postfix expression, so break
                    break;
                    }
                
                postfix+=ch; //append operator that has been popped
                }//end while loop once stack is empty
        }
        else { //else, characters in expression not '(' or ')'
            
            while ( (!s.isEmpty()) && (!precedenceHigher(ch, s.getTop())) ) {
                //while precedence of top is higher than ch and stack is not empty
                postfix += s.getTop(); //append the top of the stack to postfix string
                s.pop(); //and pop it off the stack
            }
                   
            s.push(ch); //keep adding to stack

        }//end else
    } //end for loop
    

    //END OF STRING
    while (!s.isEmpty()) { //when reach end of string, make sure everything is popped

        
        if (ch==')') {
            s.pop(); //need not be added to postfix expression
            break;
        }
        else {
            
            postfix+=s.getTop(); //add it to postfix expression, then pop

            s.pop();

        }
        
    }//end while loop

} //end function


void AlgebraicExpression::doConversion() {
    
    infixToPostfix();

    Evaluate();
    
}

void AlgebraicExpression::Evaluate() {
    //will return integer... the final answer
    
    int operand1, operand2;
    int tempVal;
    //char ch;
    char ch;
    
    //scan left to right
    Stack<int> s;
    
    
    for (int i=1; i < postfix.length(); i++) {
        ch = postfix[i];

        
        //if number, add to postfix expression
        if (isalnum(ch)) {
            int num = (int)(ch - '0');
            Node<int> *ptrNode = new Node<int>(num);
            //add to stack
            s.push(num);
            
        }
        else { //character is an operator
            if (!s.isEmpty()) {
                operand1 = s.getTop(); //turn this into number
                s.pop();

                operand2 = s.getTop();
                s.pop();
            }
                //send it to calculate
                tempVal = Calculate(operand1, operand2, ch);
                s.push(tempVal);
            }
            
  
    }
    
    finalVal = s.getTop(); //this will be a number
    s.pop();
   
}


// returns the value when a specific operator
// operates on two operands
int AlgebraicExpression::Calculate(int op1, int op2, char operate) {

    int result;
    
    int z = 0; //default result value
    
    if (operate=='*')
        z = op2 * op1;
    else if (operate=='/')
        z = op2 / op1;
    else if (operate=='+')
        z = op2 + op1;
    else if (operate=='-')
        z = op2 - op1;
    else if (operate=='%')
        z = op2 % op1;
    else
        z = 0;
    
    
    result = z;
    
    return result;
}



            
bool AlgebraicExpression::precedenceHigher(char op1, char op2) {
    
    //how to tell if op2 is of higher presedence than op1
    
    int x, y;
    bool doesPrecede;
    
    if (op1=='(')
        x = 1;
    else if (op1=='*'||op1=='/'||op1=='%')
        x = 3;
    else if (op1=='+'||op1=='-')
        x = 2;
    
    
    
    if (op2=='(') {
        y = 1;
    }
    else if (op2=='*'||op2=='/'||op2=='%') {
        y = 3;
    }
    else if (op2=='+'||op2=='-') {
        y = 2;
    }

    
    if (x > y) {
        doesPrecede = true;
    }
    else { //if (x<=y)
        doesPrecede = false;
    }
    
    
    return doesPrecede;
    
}

void AlgebraicExpression::Display() {
    
    cout << finalVal << endl;
}


#endif
