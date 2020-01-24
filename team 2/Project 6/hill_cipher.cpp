#include <bits/stdc++.h>
using namespace std;

void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
  
    // Looping for each element of the matrix 
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
            //  Copying into temporary matrix only those element 
            //  which are not in given row and column 
            if (row != p && col != q) 
            { 
                temp[i][j++] = A[row][col]; 
  
                // Row is filled, so increase row index and 
                // reset col index 
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
  
/* Recursive function for finding determinant of matrix. 
   n is current dimension of A[][]. */
int determinant(int A[N][N], int n) 
{ 
    int D = 0; // Initialize result 
  
    //  Base case : if matrix contains single element 
    if (n == 1) 
        return A[0][0]; 
  
    int temp[N][N]; // To store cofactors 
  
    int sign = 1;  // To store sign multiplier 
  
     // Iterate for each element of first row 
    for (int f = 0; f < n; f++) 
    { 
        // Getting Cofactor of A[0][f] 
        getCofactor(A, temp, 0, f, n); 
        D += sign * A[0][f] * determinant(temp, n - 1); 
  
        // terms are to be added with alternate sign 
        sign = -sign; 
    } 
  
    return D; 
} 
  
// Function to get adjoint of A[N][N] in adj[N][N]. 
void adjoint(int A[N][N],int adj[N][N]) 
{ 
    if (N == 1) 
    { 
        adj[0][0] = 1; 
        return; 
    } 
  
    // temp is used to store cofactors of A[][] 
    int sign = 1, temp[N][N]; 
  
    for (int i=0; i<N; i++) 
    { 
        for (int j=0; j<N; j++) 
        { 
            // Get cofactor of A[i][j] 
            getCofactor(A, temp, i, j, N); 
  
            // sign of adj[j][i] positive if sum of row 
            // and column indexes is even. 
            sign = ((i+j)%2==0)? 1: -1; 
  
            // Interchanging rows and columns to get the 
            // transpose of the cofactor matrix 
            adj[j][i] = (sign)*(determinant(temp, N-1)); 
        } 
    } 
} 
  
// Function to calculate and store inverse, returns false if 
// matrix is singular 
bool inverse(int A[N][N], float inverse[N][N]) 
{ 
    // Find determinant of A[][] 
    int det = determinant(A, N); 
    if (det == 0) 
    { 
        cout << "Singular matrix, can't find its inverse"; 
        return false; 
    } 
  
    // Find adjoint 
    int adj[N][N]; 
    adjoint(A, adj); 
  
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
    for (int i=0; i<N; i++) 
        for (int j=0; j<N; j++) 
            inverse[i][j] = adj[i][j]/float(det); 
  
    return true; 
} 

void getKeyMatrix(string key, int keyMatrix[][3]) 
{ 
    int k = 0; 
    for (int i = 0; i < 3; i++)  
    { 
        for (int j = 0; j < 3; j++)  
        { 
            keyMatrix[i][j] = (key[k]) % 65; 
            k++; 
        } 
    } 
} 
  
void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) 
{ 
    int x, i, j; 
    for (i = 0; i < 3; i++)  
    { 
        for (j = 0; j < 1; j++) 
        { 
            cipherMatrix[i][j] = 0; 
           
            for (x = 0; x < 3; x++) 
            { 
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j]; 
            } 
          
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26; 
        } 
    } 
} 

void HillCipherEncrypt(string message, string key) 
{
    int keyMatrix[3][3]; 
    getKeyMatrix(key, keyMatrix); 
  
    int messageVector[3][1]; 
  
    for (int i = 0; i < 3; i++) 
        messageVector[i][0] = (message[i]) % 65; 
  
    int cipherMatrix[3][1]; 
  
    encrypt(cipherMatrix, keyMatrix, messageVector); 
  
    string CipherText; 
    
    for (int i = 0; i < 3; i++) 
        CipherText += cipherMatrix[i][0] + 65; 
  
    cout << " Ciphertext:" << CipherText; 
} 

void HillCipherDecrypt(string cmessage, string key) 
{
    int keyMatrix[3][3]; 
    getKeyMatrix(key, keyMatrix); 
  
    int cmessageVector[3][1]; 
  
    for (int i = 0; i < 3; i++) 
        cmessageVector[i][0] = (cmessage[i]) % 65; 
        
    // inverse of cmessageVector
    inverse(cmessageVector);
  
    int messageMatrix[3][1]; 
  
    decrypt(messageMatrix, keyMatrix, cmessageVector); 
  
    string MessageText; 
    
    for (int i = 0; i < 3; i++) 
        MessageText += messageMatrix[i][0] + 65; 
  
    cout << " Messagetext:" << MessageText; 
} 

int main()
{
    string message, cmessage;
    string key;
    
    cin >> message;// MESSAGE TO ENCRYPT
    cin >> key;
    HillCipherEncrypt(message, key);
    
    // cin >> cmessage; // MESSAGE TO DECRYPT
    // cin >> key;
    // HillCipherDecrypt(cmessage, key);
    
    return 0;
}