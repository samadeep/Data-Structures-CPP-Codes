#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

//Implementation of a Stack
class Stack{
    public:
    int data[100];
    int top1;
    int capacity;
public:
    Stack()//constructor
    {
        top1=-1;
        capacity=100;
    }

    void pop()
    {
        top1--;

    }
    int top()
    {
        return data[top1];

    }
    void push(int val)
    {
        top1++;
        data[top1]=val;
    }

};

int operation(int v1,int v2,char ch)
{
    if(ch=='+')
    {
        return v1+v2;
    }

     if(ch=='-')
    {
        return v2-v1;
    }
    
     if(ch=='*')
    {
        // cout<< v2*v1 <<' ';
        return v2*v1;
    }
    
     if(ch=='/')
    {
        return v2/v1;
    }
     if(ch=='^')
    {
        return pow(v2,v1);
    }

    
    else return 1;
}
int main()
{
    stack<char> ops;
    stack<char> exp;

    Stack vs;
 


    string q;
    int v1,v2,val;
    
    int ans; int n;
    
    // cout<<'Enter Length of Expression'<<endl; 
    cin>>n;
    
    // cout << 'Enter the expression' << endl;
    int i=1; string s;
    
    while(i<=n)
    {
        cin>>s;
        
        if( s=="+"|| s=="-"|| s=="*"|| s=="/" || s=="^") 
        {
            char op=s[0]; 
            
            // cout<<op<<" ";
            
            int x=vs.top();vs.pop();
            int y=vs.top();vs.pop();
            
            int val=operation(x,y,op); 
            
            // cout<<val<<" ";
            
            vs.push(val);
        }
        
        else
        {
            int val_int=stoi(s); 
            
            // cout<<val_int+1<<" ";
            
            vs.push(val_int);
        }
        
        i++;
        
    }
    // vs.pop();
    cout<<vs.top()<<endl;
    
    //7
    
    //100 200 + 2 / 5 * 7 +
    
    
    //2 3 1 * + 9 -


    return 0;
}