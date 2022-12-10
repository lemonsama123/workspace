#include<bits/stdc++.h>

using namespace std;

int tryToFill(vector<vector<char>>& board) {

    const int dy[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    const int dx[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

    int numsRemain = 81;
    int previousNumsRemain = 81;
    int possibleFillPos;
    bool rowFilled[9][9];
    bool columnFilled[9][9];
    bool ninePalaceFilled[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            rowFilled[i][j] = false;
            columnFilled[i][j] = false;
            ninePalaceFilled[i][j] = false;
        }
    }

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (board[y][x] != '.') {
                int charPos = board[y][x] - 49;
                int a = y / 3;
                int b = x / 3;

                rowFilled[y][charPos] = true;
                columnFilled[x][charPos] = true;
                ninePalaceFilled[a * 3 + b][charPos] = true;

                numsRemain--;
            }
        }
    }

    while (numsRemain > 0) {
        if (previousNumsRemain > numsRemain) {
            previousNumsRemain = numsRemain;
        } else {
            return 1;
        }
        for (int charPos = 0; charPos < 9; charPos++) {
            for (int y = 0; y < 9; y++) {
                if (rowFilled[y][charPos]) {
                    continue;
                }

                possibleFillPos = -1;

                for (int x = 0; x < 9; x++) {
                    int a = y / 3;
                    int b = x / 3;

                    if ((board[y][x] == '.') && (!columnFilled[x][charPos]) && (!ninePalaceFilled[a * 3 + b][charPos])) {
                        if (possibleFillPos == -1) {
                            possibleFillPos = x;
                        } else {
                            possibleFillPos = 10;
                            break;
                        }
                    }
                }

                if (possibleFillPos == 10) {
                    continue;
                }

                if (possibleFillPos == -1) {
                    return 0;
                }

                int a = y / 3;
                int b = possibleFillPos / 3;

                board[y][possibleFillPos] = charPos + 49;

                rowFilled[y][charPos] = true;
                columnFilled[possibleFillPos][charPos] = true;
                ninePalaceFilled[a * 3 + b][charPos] = true;

                numsRemain--;
            }

            for (int x = 0; x < 9; x++) {
                if (columnFilled[x][charPos]) {
                    continue;
                }
                possibleFillPos = -1;

                for (int y = 0; y < 9; y++) {
                    int a = y / 3;
                    int b = x / 3;

                    if ((board[y][x] == '.') && (!rowFilled[y][charPos]) && (!ninePalaceFilled[a * 3 + b][charPos])) {
                        if (possibleFillPos == -1) {
                            possibleFillPos = y;
                        } else {
                            possibleFillPos = 10;
                            break;
                        }
                    }
                }

                if (possibleFillPos == 10) {
                    continue;
                }
                if (possibleFillPos == -1) {
                    return 0;
                }
                int a = possibleFillPos / 3;
                int b = x / 3;

                board[possibleFillPos][x] = charPos + 49;

                rowFilled[possibleFillPos][charPos] = true;
                columnFilled[x][charPos] = true;
                ninePalaceFilled[a * 3 + b][charPos] = true;

                numsRemain--;
            }

            for (int i = 0; i < 9; i++) {
                if (ninePalaceFilled[i][charPos]) {
                    continue;
                }
                possibleFillPos = -1;

                for (int j = 0; j < 9; j++) {
                    int y = dy[i] * 3 + dy[j];
                    int x = dx[i] * 3 + dx[j];

                    if ((board[y][x] == '.') && (!rowFilled[y][charPos]) && (!columnFilled[x][charPos])) {
                        if (possibleFillPos == -1) {
                            possibleFillPos = j;
                        }
                        else {
                            possibleFillPos = 10;
                            break;
                        }
                    }
                }

                if (possibleFillPos == 10) {
                    continue;
                }
                if (possibleFillPos == -1) {
                    return 0;
                }
                int y = dy[i] * 3 + dy[possibleFillPos];
                int x = dx[i] * 3 + dx[possibleFillPos];

                board[y][x] = charPos + 49;

                rowFilled[y][charPos] = true;
                columnFilled[x][charPos] = true;
                ninePalaceFilled[i][charPos] = true;

                numsRemain--;
            }
        }
    }
    return 2;
}

void solveSudoku(vector<vector<char>>& board) {
    const int dy[9] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    const int dx[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    
    int numsRemain = 81;
    int previousNumsRemain = 81;
    int possibleFillPos;
    bool rowFilled[9][9];
    bool columnFilled[9][9];
    bool ninePalaceFilled[9][9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            rowFilled[i][j] = false;
            columnFilled[i][j] = false;
            ninePalaceFilled[i][j] = false;
        }
    }

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (board[y][x] != '.') {
                int charPos = board[y][x] - 49;
                int a = y / 3;
                int b = x / 3;

                rowFilled[y][charPos] = true;
                columnFilled[x][charPos] = true;
                ninePalaceFilled[a * 3 + b][charPos] = true;

                numsRemain--;
            }
        }
    }

    while (numsRemain > 0) {
        if (previousNumsRemain > numsRemain) {
            previousNumsRemain = numsRemain;
        } else {
            bool haveFilledNewValue = false;

            for (int y = 0; y < 9; y++) {
                for (int x = 0; x < 9; x++) {
                    if (board[y][x] == '.') {
                        int possibleFillPosTotal = 0; 
                        int possibleFillPosTry[2]; 

                        int a = y / 3;
                        int b = x / 3;

                        for (int charPos = 0; charPos < 9; charPos++) {
                            if ((!rowFilled[y][charPos]) && (!columnFilled[x][charPos]) && (!ninePalaceFilled[a * 3 + b][charPos])) {
                                possibleFillPosTotal++;
                                if (possibleFillPosTotal == 3) {
                                    break;
                                } else {
                                    possibleFillPosTry[possibleFillPosTotal - 1] = charPos;
                                }
                            }
                        }

                        if (possibleFillPosTotal == 3) {
                            continue;
                        }

                        vector<vector<char>> boardBackup = board; 
                        board[y][x] = possibleFillPosTry[0] + 49; 

                        int tryToFillResult = tryToFill(board); 

                        if (tryToFillResult == 2) {
                            return;
                        }
                        if (tryToFillResult == 0) {
                            haveFilledNewValue = true;

                            board = boardBackup;
                            board[y][x] = possibleFillPosTry[1] + 49;

                            rowFilled[y][possibleFillPosTry[1]] = true;
                            columnFilled[x][possibleFillPosTry[1]] = true;
                            ninePalaceFilled[a * 3 + b][possibleFillPosTry[1]] = true;

                            numsRemain--;
                        }
                        if (tryToFillResult == 1) {
                            board = boardBackup;
                            board[y][x] = possibleFillPosTry[1] + 49;

                            tryToFillResult = tryToFill(board);

                            if (tryToFillResult == 2) {
                                return;
                            }
                            if (tryToFillResult == 0) {
                                haveFilledNewValue = true;

                                board = boardBackup;
                                board[y][x] = possibleFillPosTry[0] + 49;

                                rowFilled[y][possibleFillPosTry[0]] = true;
                                columnFilled[x][possibleFillPosTry[0]] = true;
                                ninePalaceFilled[a * 3 + b][possibleFillPosTry[0]] = true;

                                numsRemain--;
                            }
                            if (tryToFillResult == 1) {
                                board = boardBackup;
                            }
                        }
                    }

                    if (haveFilledNewValue) {
                        break;
                    }
                }

                if (haveFilledNewValue) {
                    break;
                }
            }
        }

        for (int charPos = 0; charPos < 9; charPos++) {
            for (int y = 0; y < 9; y++) {
                if (rowFilled[y][charPos]) {
                    continue;
                }

                possibleFillPos = -1; 

                for (int x = 0; x < 9; x++) {
                    int a = y / 3;
                    int b = x / 3;

                    if ((board[y][x] == '.') && (!columnFilled[x][charPos]) && (!ninePalaceFilled[a * 3 + b][charPos])) {
                        if (possibleFillPos == -1) {
                            possibleFillPos = x;
                        } else {
                            possibleFillPos = 10;
                            break;
                        }
                    }
                }

                if (possibleFillPos == 10) {
                    continue;
                }
                
                int a = y / 3;
                int b = possibleFillPos / 3;

                board[y][possibleFillPos] = charPos + 49;

                rowFilled[y][charPos] = true;
                columnFilled[possibleFillPos][charPos] = true;
                ninePalaceFilled[a * 3 + b][charPos] = true;

                numsRemain--;
            }

            for (int x = 0; x < 9; x++) {
                if (columnFilled[x][charPos]) {
                    continue;
                }
                possibleFillPos = -1;

                for (int y = 0; y < 9; y++) {
                    int a = y / 3;
                    int b = x / 3;

                    if ((board[y][x] == '.') && (!rowFilled[y][charPos]) && (!ninePalaceFilled[a * 3 + b][charPos])) {
                        if (possibleFillPos == -1) {
                            possibleFillPos = y;
                        } else {
                            possibleFillPos = 10;
                            break;
                        }
                    }
                }

                if (possibleFillPos == 10) {
                    continue;
                }
                int a = possibleFillPos / 3;
                int b = x / 3;

                board[possibleFillPos][x] = charPos + 49;

                rowFilled[possibleFillPos][charPos] = true;
                columnFilled[x][charPos] = true;
                ninePalaceFilled[a * 3 + b][charPos] = true;

                numsRemain--;
            }

            for (int i = 0; i < 9; i++) {
                if (ninePalaceFilled[i][charPos]) {
                    continue;
                }
                possibleFillPos = -1;

                for (int j = 0; j < 9; j++) {
                    int y = dy[i] * 3 + dy[j];
                    int x = dx[i] * 3 + dx[j];

                    if ((board[y][x] == '.') && (!rowFilled[y][charPos]) && (!columnFilled[x][charPos])) {
                        if (possibleFillPos == -1) {
                            possibleFillPos = j;
                        } else {
                            possibleFillPos = 10;
                            break;
                        }
                    }
                }

                if (possibleFillPos == 10) {
                    continue;
                }
                int y = dy[i] * 3 + dy[possibleFillPos];
                int x = dx[i] * 3 + dx[possibleFillPos];

                board[y][x] = charPos + 49;

                rowFilled[y][charPos] = true;
                columnFilled[x][charPos] = true;
                ninePalaceFilled[i][charPos] = true;

                numsRemain--;
            }
        }
    }
}

int main () {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", board[i][j]);
        }
        puts("");
    }
    system("pause");
    return 0;
}