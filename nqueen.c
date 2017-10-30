#include<stdio.h>
#include <stdlib.h>
int board[8][8];
int n=8;
int  issafe(int row,int col)
{
        int i,j;
        for(i=0;i<row;i++)
        if(board[i][col]==1)
        return 0;
        
        for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(board[i][j]==1)
        return 0;
        
        for(i=row,j=col;i>=0&&j<n;i--,j++)
        if(board[i][j]==1)
        return 0;
        
        return 1;  
        
}
int solve(int row)
{
        int j;
        if(row>=n)
        return 1;
        int i;
        for(i=0;i<n;i++)
        {
                if(issafe(row,i)==1)
                {
                        board[row][i]=1;
                        if(solve(row+1)==1)
                        return 1;
                        board[row][i]=0;
                 }
        }
        return 0;
        
}
int main()
{
        int i,j;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        board[i][j]=0;
        if(solve(0)==0)
        printf("there is no solution\n");
        else
        {
                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        printf("%d    ",board[i][j]);
                        printf("\n");
                }
        }
        return 0;
}
