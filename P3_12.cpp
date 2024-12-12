#include <iostream>
#include <string>
#include <cmath>   // For mathematical operations like power
#include <cctype>
#include <algorithm>  // For checking if a character is a digit

using namespace std;

// Node structure for the stack
struct Node {
    char data;
    Node* next;

    Node(char value){
        data = value; 
        next = nullptr;
    }
};

// Stack class implemented using a singly linked list
class Stack {
private:
    Node* top;

public:
    Stack(){
         top = nullptr;
    }

    // Push an element onto the stack
    void push(char value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop an element from the stack
    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            exit(1); // Exit the program if stack underflows
        }
        char poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Peek the top element
    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            exit(1); // Exit if stack is empty when peeking
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Class for infix-to-prefix conversion and evaluation
class InfixToPrefix {
private:
    Stack stack;
    Stack evalStack;

    // Function to check operator precedence
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        if (op == '^') return 3;
        return 0;
    }

    // Function to check if a character is an operator
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }

    // Convert infix to prefix
   public: string convertInfixToPrefix(string infix) {
        string infixReversed = infix;
        reverse(infixReversed.begin(), infixReversed.end()); // Reverse the infix string directly
        string prefix;

        for (char ch : infixReversed) {  // Enhanced for loop for processing characters
            if (isalnum(ch)) {
                prefix += ch;
            } else if (ch == ')') {
                stack.push(ch);
            } else if (ch == '(') {
                while (!stack.isEmpty() && stack.peek() != ')') {
                    prefix += stack.pop();
                }
                stack.pop(); // Remove ')'
            } else if (isOperator(ch)) {
                while (!stack.isEmpty() && precedence(ch) <= precedence(stack.peek())) {
                    prefix += stack.pop();
                }
                stack.push(ch);
            }
        }

        while (!stack.isEmpty()) {
            prefix += stack.pop();
        }

        reverse(prefix.begin(), prefix.end()); // Reverse the final prefix expression
        return prefix;
    }

    // Function to evaluate a prefix expression
   public: int evaluatePrefix(string prefix) {
        Stack evalStack;
        reverse(prefix.begin(), prefix.end());
        for (char ch : prefix) {
            if (isdigit(ch)) {  // Corrected here
                evalStack.push(ch - '0');  // Convert char digit to integer
            } else if (isOperator(ch)) {
                // Pop two operands
                int op1 = evalStack.pop();
                int op2 = evalStack.pop();

                // Perform the operation
                int result;
                switch (ch) {
                    case '+': result = op1 + op2; break;
                    case '-': result = op1 - op2; break;
                    case '*': result = op1 * op2; break;
                    case '/': result = op1 / op2; break;
                    case '^': result = static_cast<int>(pow(op1, op2)); break;
                    default: cout << "Invalid operator" << endl; exit(1); // Exit on invalid operator
                }
                evalStack.push(result);
            }
        }
        return evalStack.pop();
}

};

// Main function to test the implementation
int main() {
    InfixToPrefix c;

    string infixExp;
    cout << "Enter an infix expression: ";
    cin >> infixExp;

    string prefixExp = c.convertInfixToPrefix(infixExp);
    cout << "Prefix Expression: " << prefixExp << endl;

    int result = c.evaluatePrefix(prefixExp);
    cout << "Result of Prefix Evaluation: " << result << endl;

    return 0;
}
