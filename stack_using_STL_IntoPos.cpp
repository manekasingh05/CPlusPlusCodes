#include<iostream>
#include<stack>
#include<iterator>
#include<algorithm>
using namespace std;

int Outpre(char x)
{
      if (x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 3;
    } else if (x == '^'){
        return 6;
    } else if (x == '('){
        return 7;
    } else if (x == ')'){
        return 0;
    }
    return -1;
}

int inPrecedence(char x){
    if (x == '+' || x == '-'){
        return 2;
    } else if (x == '*' || x == '/'){
        return 4;
    } else if (x == '^'){
        return 5;
    } else if (x == '('){
        return 0;
    }
    return -1;
}


int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')'){
        return 0;
    }
    return 1;
}

char *IntoPos(char *infix)
{
    int i=0,j=0;
    int len = strlen(infix);
    char *postfix = new char[len];

    stack<char> stack;

    while(infix[i]!= '\0')
    {
         if(isOperand(infix[i]))
         {
             postfix[j] = infix[i];
             i++;
             j++;

         }
         else{
             if(stack.empty() || Outpre(infix[i]) > inPrecedence(stack.top()))
             {
                 stack.push(infix[i]);
                 i++;
             }
             else if(Outpre(infix[i]) == inPrecedence(stack.top()))
             {
                 stack.pop();
             }
             else{

                 postfix[j] = stack.top();
                 j++;
                 stack.pop();
             }
             
         }

    }

     while (!stack.empty() && stack.top() != ')'){
        postfix[j++] = stack.top();
        stack.pop();
    }
 
    postfix[j] = '\0';
 
    return postfix;
}

int main()
{
     char infix[] = "((a+b)*c)-d^e^f";
 
    cout << IntoPos(infix) << endl;

    return 0;
}

