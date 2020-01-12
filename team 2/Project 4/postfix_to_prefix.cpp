#include <bits/stdc++.h>
using namespace std; 
  
// funtion to check if character is operator or not 
bool isOperator(char x) { 
  switch (x) { 
  case '+': 
  case '-': 
  case '/': 
  case '*': 
    return true; 
  } 
  return false; 
} 
  
// Convert postfix to Prefix expression 
string postToPre(string post_exp) { 
  
  stack<string> s; 
  
  // length of expression 
  int length = post_exp.size(); 
  
  // reading from right to left 
  for (int i = 0; i <length; i++) 
  { 
    if (isOperator(post_exp[i])) 
    {
        string o1 = s.top(); 
        s.pop(); 
        string o2 = s.top();
        s.pop();
        
        string temp = post_exp[i] + o2 + o1; 
      
        s.push(temp); 
    } 
    else
    {
        
        s.push(string(1, post_exp[i])); 
    } 
  } 
  
  // stack contains only the Prefix expression 
  return s.top(); 
} 
  
// Driver Code 
int main() { 
  string post_exp;
  cin >> post_exp;
  cout << "Prefix : " << postToPre(post_exp); 
  return 0; 
} 
