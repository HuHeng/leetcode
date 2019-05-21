#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

class Solution {
    public:
        bool IsValid(vector<vector<char>>& board, int m, int n, int num){
            //row
            for(int i = 0; i < 9; ++i) {
                if(i == n)
                    continue;

                if(board[m][i] == num)
                    return false;
            }

            //column
            for(int i = 0; i < 9; ++i) {
                if(i == m)
                    continue;

                if(board[i][n] == num)
                    return false;
            }

            //rectangle
            int x = m/3 * 3;
            int y = n/3 * 3;
            for(int i = x; i<=x+2; ++i){
                for(int j = y; j <= y+2; ++j) {
                    if(i == m && n == j)
                        continue;

                    if(board[i][j] == num)
                        return false;
                }
            }
            return true;
        }

        bool DFS(vector<vector<char>>& board, int index) {
            if(index == 81)
                return true;
            int m = index / 9;
            int n = index % 9;
            if(board[m][n] == '.') {
                for(int i = 1; i <= 9; ++i){
                    if(IsValid(board, m, n, '0' + i)){
                        board[m][n] = '0' + i;
                        if(DFS(board, index + 1)){
                            return true;
                        }  
                        board[m][n] = '.';
                    }
                }
            }else {
                if(IsValid(board, m, n, board[m][n])){
                    return DFS(board, index+1);
                }
            }

            return false;

        }

        void solveSudoku(vector<vector<char>>& board) {
            bool ret = DFS(board, 0);
            std::cout << "solve: " << ret << std::endl;
        }
};

int main()
{
    Solution s;
    //vector<vector<char>> board = {
    //    {'5','3','.','.','7','.','.','.','.'},
    //    {'6','.','.','1','9','5','.','.','.'},
    //    {'.','9','8','.','.','.','.','6','.'},
    //    {'8','.','.','.','6','.','.','.','3'},
    //    {'4','.','.','8','.','3','.','.','1'},
    //    {'7','.','.','.','2','.','.','.','6'},
    //    {'.','6','.','.','.','.','2','8','.'},
    //    {'.','.','.','4','1','9','.','.','5'},
    //    {'.','.','.','.','8','.','.','7','9'}
    //};

    vector<vector<char>> board = {
        {'.','8','7','6','5','4','3','2','1'},
        {'2','.','.','.','.','.','.','.','.'},
        {'3','.','.','.','.','.','.','.','.'},
        {'4','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','.','.','.','.'},
        {'6','.','.','.','.','.','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'8','.','.','.','.','.','.','.','.'},
        {'9','.','.','.','.','.','.','.','.'}
    };
    s.solveSudoku(board);

    //std::cout << ret << std::endl;
    for(auto& x: board){
        for(auto& y: x){
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }

}
