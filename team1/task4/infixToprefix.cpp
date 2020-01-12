#include<bits/stdc++.h>
using namespace std;
string s , temp;
stack < char > stk;
char ch;
int n , m , sz;
int operator_value( char op );
string Infix_To_Postfix();
int main()
{
    cin>>s;
    reverse( s.begin(), s.end() );
    s = Infix_To_Postfix();
    cout<<s<<endl;
    return 0;
}
string Infix_To_Postfix()
{
    sz = s.size();
    for ( int i = 0; i != sz; i++ )
    {
        if ( s [ i ] >= 'a' && s [ i ] <= 'z' )temp += s [ i ];
        else if ( s [ i ] == ')' )stk.push( s [ i ] );
        else if ( s [ i ] == '(' )
        {
            while ( !stk.empty() && stk.top() != ')' )
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
                if ( ch != ')' && ch != '(' )temp += ch;
            }
            stk.push( s [ i ] );
        }
    }
    while ( !stk.empty() )
    {
        if ( stk.top() != '(' && stk.top() != ')' )temp += stk.top();
        stk.pop();
    }
    reverse ( temp.begin() , temp.end() );
    return temp;
}
int operator_value( char op )
{
    if ( op == '^' )return 3;
    if ( op == '*' || op == '/' )return 2;
    if ( op == '+' || op == '-' )return 1;
    return -1;
}
 
