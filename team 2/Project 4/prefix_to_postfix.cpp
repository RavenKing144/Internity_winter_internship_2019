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
  
// Convert prefix to Postfix expression 
string preToPost(string pre_exp) { 
  
  stack<string> s; 
  
  // length of expression 
  int length = pre_exp.size(); 
  
  // reading from right to left 
  for (int i = length - 1; i >= 0; i--) 
  { 
    if (isOperator(pre_exp[i])) 
    {
        string o1 = s.top(); 
        s.pop(); 
        string o2 = s.top();
        s.pop();
        
        string temp = o1 + o2 + pre_exp[i]; 
      
        s.push(temp); 
    } 
    else
    {
        s.push(string(1, pre_exp[i])); 
    } 
  } 
  
  // stack contains only the Postfix expression 
  return s.top(); 
} 
  
// Driver Code 
int main() { 
  string pre_exp;
  cin >> pre_exp;
  cout << "Postfix : " << preToPost(pre_exp); 
  return 0; 
} 
