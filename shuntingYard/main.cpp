#include <iostream>
#include "Node.h"
#include <cstring>
#include <cctype>

using namespace std;

struct Stack
{
  Node* top = NULL;

  //Function to add an item to the front of the stack
  void push(char* value)
  {
    Node* newNode = new Node();
    newNode->setValue(value);
    newNode->setNext(top);
    top = newNode;
  }

  //Function to remove and return an item from the top of the stack
  char* pop()
  {
    if(top == NULL)
      return NULL;
    char* value = top->getValue();
    Node* temp = top;
    top = top->getNext();
    delete temp;
    return value;
  }

  //Function to return the item from the top without removing it from the stack
  char* peek()
  {
    if (top == NULL)
      return NULL;
    return top->getValue();
  }

  //Function to check if the stack is empty
  bool isEmpty()
  {
    if(top == NULL)
      return true;
    return false;
  }
};

struct Queue
{
  Node* front = NULL;
  Node* back = NULL;

  //Function to add an item from the back of the queue
  void enqueue(char* value)
  {
    Node* newNode = new Node();
    newNode->setValue(value);
    if(back == NULL)
      {
	front = back = newNode;
	return;
      }
    back->setNext(newNode);
    back = newNode;
  }

  //Function to remove and return the item from the front of the queue
  char dequeue()
  {
    if(front == NULL)
      return NULL;
    char value = front->getValue();
    Node* temp = front;
    front = front->getNext();
    if(front == NULL)
      back = NULL;
    delete temp;
    return value;
  }

  //Funtion to check is the queue is empty
  bool isEmpty()
  {
    if(front == NULL)
      return true;
    return false;
  }
};

int operators(char op);
void shuntingYard(const char* infix, Queue & outputQueue);
Node* buildExpressionTree(Queue & postfixQueue);
void printInfix(Node* root);
void printPrefix(Node* root);
void printPostfix(Node* root);

int main()
{
  char infix [100];
  cout << "Enter an infix notation mathematical expression, using spaces between each token:" << endl;
  cin >> infix;
  cin.ignore();

  cout << "Postfix notation:" << endl;
  printPostfix();

  char command[80];
  cout << "Enter command(INFIX/PREFIX/POSTFIX):" << endl;
  cin.get(command, 80);
  cin.get();

  if(strcmp(command, "INFIX") == 0)
    {
      cout << "infix notation:" << endl;
      printInfix();
      cout << endl;
    }
  else if(strcmp(command, "PREFIX") == 0)
    {
      cout << "prefix notation:" << endl;
      printPrefix();
      cout << endl;
    }
  else if(strcmp(command, "POSTFIX") == 0)
    {
      cout << "postfix notation:" << endl;
      printPostfix();
      cout << endl;
    }
  
  return 0;
}

//
int operators(char op)
{
  if(op == '+' || op == '-')
    return 1;
  if(op == '*' || op == '/')
    return 2;
  return 3;
}

//Function to convert from infix to potfix
void shuntingYard(const char* infix, Queue & outputQueue)
{
  Stack opStack;
  while(*infix)
    {
      if(isdigit(*infix))
	outputQueue.enqueue(*infix);
      else if (*infix == '(')
	opStack.push(*infix);
      else if (*infix == ')')
	while(opStack.isEmpty() == false)
	  {
	    opStack.push(*infix);
	  }
    }
}

Node* buildExpressionTree(Queue & postfixQueue)
{
  Stack treeStack;
  while(postfixQueue.isEmpty() == false)
    {
      char token = prefixQueue.dequeue();
      Node* newNode = new Node();
      newNode->setValue(token);

      if(isdigit(token))
	treeStack.push(token);
      else
	{
	  newNode->setLeft(treeStack.pop);
	  newNode->setRight(treeStack.pop);
	  treeStack.push(token);
	}
    }
  return new Node(treeStack.pop);
}

void printInfix(Node* root)
{
  
}

void printPrefix(Node* root)
{

}

void printPostfix(Node* root)
{

}
