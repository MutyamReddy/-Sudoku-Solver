class Solution {
public:
    
    bool checkrow(vector<vector<char>>&sd,int row,char num){
        for(int i=0;i<sd.size();i++){
            if(sd[row][i]==num){
                return false;
            }
        }
        return true;
    }
   bool checkcol(vector<vector<char>>&sd,int col,char num){
        for(int i=0;i<sd.size();i++){
            if(sd[i][col]==num){
                return false;
            }
        }
        return true;
    }
    bool checkbox(vector<vector<char>>&sd,int startrow,int startcol,char num){
        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                if(sd[startrow+row][startcol+col]==num){
                    return false;
                }
            }
        }
        return true;
    }
    bool issafe(vector<vector<char>>&sd,int row,int col,char num){
        bool validrow=checkrow(sd,row,num);
        bool validcol=checkcol(sd,col,num);
        bool validbox=checkbox(sd,row-row%3,col-col%3,num);
        return validrow&&validcol&&validbox&&(sd[row][col]=='.');
    }
    bool solver(vector<vector<char>>&sd,int row,int col){
        if(row==9){
            return true;
        }if(col==9){
            return solver(sd,row+1,0);
        }
        if(sd[row][col]!='.'){
            return solver(sd,row,col+1);
        }
        for(int i='1';i<='9';i++){
            if(issafe(sd,row,col,i)){
                sd[row][col]=i;
            if(solver(sd,row,col+1)){
                return true;
            }
                sd[row][col]='.';
            }
            
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& sd) {
        solver(sd,0,0);
    }
};
