#include<bits/stdc++.h>
using namespace std;
string s;
int sz , n , m;
char ch, ch2;
int operator_value( char op );
void Infix_To_Postfix();
stack < char > stk;
int main()
{
    cin>>s;
    Infix_To_Postfix();
    return 0;
}
void Infix_To_Postfix()
{
    string temp;
    sz = s.size();
    for ( int i = 0; i != sz; i++ )
    {
        if ( s [ i ] >= 'a' && s [ i ] <= 'z' )temp += s [ i ];
        else if ( s [ i ] == '(' )stk.push( s [ i ] );
        else if ( s [ i ] == ')' )
        {
            while ( !stk.empty() && stk.top() != '(' )
            {
                ch = stk.top();
                stk.pop();
                temp += ch;
            }
            stk.pop();
        }
        else
        {
            while ( !stk.empty() && operator_value( s [ i ] ) <= operator_value( stk.top() ) )
            {
                ch = stk.top();
                stk.pop();
                if ( ch != '(' && ch != ')' )temp += ch;
            }
            stk.push( s [ i ] );
        }
    }
    while ( !stk.empty() ){if(stk.top() != '(' && stk.top() != ')' )temp += stk.top();stk.pop();}
    cout<<temp<<endl;
}
int operator_value( char op )
{
    if ( op == '^' )return 3;
    if ( op == '*' || op == '/' )return 2;
    if ( op == '+' || op == '-' )return 1;
    return -1;
}
