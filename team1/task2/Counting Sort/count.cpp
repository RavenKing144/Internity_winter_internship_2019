#include <iostream>
using namespace std;

 
template < class T > 
void
countSort (T array[], int size) 
{
  
T output[10];
  
T count[10];
  
T max = array[0];
  
for (int i = 1; i < size; i++)
    
    {
      
if (array[i] > max)
	
max = array[i];
    
}
  
for (int i = 0; i <= max; ++i)
    
    {
      
count[i] = 0;
  
} 
for (int i = 0; i < size; i++)
    
    {
      
count[array[i]]++;
  
} 
for (int i = 1; i <= max; i++)
    
    {
      
count[i] += count[i - 1];
  
} 
for (int i = size - 1; i >= 0; i--)
    
    {
      
output[count[array[i]] - 1] = array[i];
      
count[array[i]]--;
  
} 
for (int i = 0; i < size; i++)
    
    {
      
array[i] = output[i];

} 
} 
 
template < class T > 
void

printArray (T array[], int size) 
{
  
for (int i = 0; i < size; i++)
    
cout << array[i] << " ";
  
cout << endl;

} 
 
 
int

main () 
{
  
int array[] = { 4, 2, 2, 8, 3, 3, 1 };
  
int n = sizeof (array) / sizeof (array[0]);
  
countSort (array, n);
  
printArray (array, n);

}
