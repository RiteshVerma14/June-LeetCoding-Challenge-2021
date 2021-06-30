class Solution {
public:
    int temp[51][51][51];
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(temp,-1,sizeof(temp));
        return find(m,n,maxMove,startRow,startColumn);
    }
    int find(int m, int n, int maxMove, int startRow, int startColumn)
    {
        if(maxMove < 0)
            return 0;
        if(startRow == m || startColumn == n || startRow < 0 || startColumn < 0)
            return 1;
        if(temp[startRow][startColumn][maxMove] != -1)
            return temp[startRow][startColumn][maxMove]%1000000007;
        long total = 0;
        total = (total + find(m,n,maxMove-1,startRow,startColumn-1))%1000000007;
        total = (total + find(m,n,maxMove-1,startRow,startColumn+1))%1000000007;
        total = (total + find(m,n,maxMove-1,startRow-1,startColumn))%1000000007;
        total = (total + find(m,n,maxMove-1,startRow+1,startColumn))%1000000007;
        temp[startRow][startColumn][maxMove] = total%1000000007;
        return total%1000000007;
    }
};
