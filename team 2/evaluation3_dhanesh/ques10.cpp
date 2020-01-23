class Solution {
public:
    string s;
    vector<string> board;
    vector<vector<string>> v;
    bool isPossible(int n,int row,int col){
        for(int i=row-1;i>=0;i--){
            if(board[i][col]=='Q')
                return false;
        }
        int i=0;
         while(col-i>=0&&row-i>=0){
            if(board[row-i][col-i]=='Q')
                return false;
             i++;
        }
        i=0;
         while(col+i<n&&row-i>=0){
            if(board[row-i][col+i]=='Q')
                return false;
             i++;
        }
        return true;
    }
    
        void nQueenHelper(int n,int rowNo){ 
        if(n==rowNo){ 
            v.push_back(board);
            return;
        }       
        for(int i=0;i<n;i++){
            if(isPossible(n,rowNo,i)){
                board[rowNo][i]='Q';
                nQueenHelper(n,rowNo+1);
                board[rowNo][i]='.';
            }  
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        int y=n;s="";
        while(y--){
            s+='.';
        }
        for(int i=0;i<n;i++){
           board.push_back(s);
        } 
        nQueenHelper(n,0);
        return v;
    }
};