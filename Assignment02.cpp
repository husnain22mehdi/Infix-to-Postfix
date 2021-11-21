#include <iostream>
#include <string>
using namespace std;

template <typename datatype>

class Stack
{
  private:

    const int static size = 300;
    datatype arr[size];
    int top = -1;
    
   
  public:

     bool isEmpty(){
        return top==-1;
    }

    bool isFull(){
        return top==size-1;
    }
    
    bool push(datatype element){
        if (!isFull()){
            arr[++top] = element;
            return true;
        }
        else{
            return false;
        }
    }

    bool pop(){
        if (!isEmpty()){
            top--;
            return true;
        }
        else{
            return false;
        }
    }
    void clear(){
        top = -1;
    }
    
    datatype* peek(){
        if (!isEmpty()){
            return &arr[top];
        }
        else{
            return NULL;
        }
    }
};

class InfixtoPostfix
{
    string postfix = "";
    Stack<char> charStack;
    
public:
    
    string conversion(string infix){
        
        for (char i : infix){

            if (i == '('){
                charStack.push(i);
            }

            else if (i == ')'){

                postfix += " ";
                while (*charStack.peek() != '('){
                    
                    postfix += *charStack.peek();
                    
                    charStack.pop();
                }
                charStack.pop();
            }

            else if (i == '+' || i == '-' || i == '*' || i == '/'){
                
                postfix += " ";
                if (charStack.isEmpty() || *charStack.peek() == '('){
                    charStack.push(i);

                }else if ((i == '*' || i == '/') && (*charStack.peek() == '+' || *charStack.peek() == '-')){
                    charStack.push(i);

                }else{

                    while (!charStack.isEmpty()){
            
                        if (*charStack.peek() != '(')
                        {
                            postfix += *charStack.peek();
                            charStack.pop();
                        }
                    }
                    charStack.push(i);
                    postfix += ' ';
                }

            }

            else if (i != ' '){

                postfix += i;
            }
        
        }
         
        postfix += " ";   
        while (charStack.peek() != NULL){
            postfix += *charStack.peek();
            charStack.pop();
        }
        
    
        // 2*(31+6)*5/2
        return postfix;
    }
    
    double evaluate(string input){
        
        Stack<double> doubleStack;
        double operand1;
        double operand2;
        double result = 0;
        string numstr = "";
        
        for (char i : input){
            
            if (i == '+' && !doubleStack.isEmpty()){
                operand2 = *doubleStack.peek();
                doubleStack.pop();
                operand1 = *doubleStack.peek();
                doubleStack.pop();
                result = operand1 + operand2;
                doubleStack.push(result);                
                }
                
            else if (i == '-' && !doubleStack.isEmpty()){
                operand2 = *doubleStack.peek();
                doubleStack.pop();
                operand1 = *doubleStack.peek();
                doubleStack.pop();
                result = operand1 - operand2;
                doubleStack.push(result);
                }
                
            else if (i == '*' && !doubleStack.isEmpty()){
                operand2 = *doubleStack.peek();
                doubleStack.pop();
                operand1 = *doubleStack.peek();
                doubleStack.pop();
                result = operand1 * operand2;
                doubleStack.push(result);
                }
                
            else if (i == '/' && !doubleStack.isEmpty()){
                operand2 = *doubleStack.peek();
                doubleStack.pop();
                operand1 = *doubleStack.peek();
                doubleStack.pop();
                result = operand1 / operand2;
                doubleStack.push(result);
                }
                
            else{
                
                if (i != ' '){
                    numstr += i;
                    continue;
                    }
                else if (numstr != "")
                    doubleStack.push(stod(numstr));
                numstr = "";
                
                }
                
        } 
        return *doubleStack.peek();
    }
};

int main() {
    // Write C++ code here
    string infix = "9+9+88*(99*34)+(99-100)*199";
    string converted_postfix;
    double evaluated_postfix;
    InfixtoPostfix obj;

    cout << "Infix = " << infix << endl;
    cout << endl;

    converted_postfix = obj.conversion(infix);
    
    cout << "Postfix = " << converted_postfix << endl;
    cout << endl;

    evaluated_postfix = obj.evaluate(converted_postfix);

    cout << "Evaluated Answer = " << evaluated_postfix << endl;
    

    return 0;
}
