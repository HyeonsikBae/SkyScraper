#include <stdio.h>
#include <stdlib.h>
int **answer;
int *top;
int *right;
int *bottom;
int *left;
int size;

int **initPuzzle(int len);
int **solve(char* clues, int len);
int backtrack(int **board);
int *findEmptyCell(int **board);
int noConflict(int **board, int row, int col, int guess);
int hasDuplicates(int **board, int row, int col, int guess);
int validMove(int **board, int row, int col);
int checkRow(int left, int right, int *buildings);
int viewCount(int forward, int *buildings);

/* 신규 추가 함수 */
void stringtoarr(char *clue);

int main()
{
    /*
    int clues[] = { 3, 2, 2, 1,
                    1, 2, 2, 2,
                    2, 2, 3, 1,
                    1, 3, 2, 4 };
    size = 4;
    char *arg = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    */
    size = 4;
    char *arg0 = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
    char *arg1 = "3 2 2 1 1 2 2 2 4 2 3 1 1 3 2 2";
    char *arg2 = "4 1 2 2 3 1 2 2 2 3 2 1 1 4 2 2";
    char *arg3 = "2 2 4 1 1 2 3 2 3 2 1 2 2 2 1 4";
    char *arg4 = "3 1 2 2 2 2 3 1 2 3 1 2 2 3 3 1";
    
    answer = solve(arg4, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int **initPuzzle(int len) {
    int **rtn;
    rtn = (int**) malloc ( sizeof(int*) * len );
    for(int i=0; i<len; i++){
        rtn[i] = (int*) malloc ( sizeof(int) * len );
    }

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++) {
            rtn[i][j] = 0;
        }
    }
    return rtn;
}


int **solve(char* clues, int len) {
    int **board = initPuzzle(len);
    answer = initPuzzle(len);
/*
    top = (int*) malloc ( sizeof(int) * len );
    right = (int*) malloc ( sizeof(int) * len );
    bottom = (int*) malloc ( sizeof(int) * len );
    left = (int*) malloc ( sizeof(int) * len );

    for (int i = 0; i < len; i++)
    {
        top[i] = clues[i];
        right[i] = clues[len + i];
        bottom[i] = clues[len*2 + i];
        left[i] = clues[len*3 + i];
    }
*/
    // 42 문제 문자열 포맷에 맞게 변환
    stringtoarr(clues);

    for (int i = 0; i < size; i++)
    backtrack(board);
    free(top);
    free(right);
    free(bottom);
    free(left);
    return answer;
}

int backtrack(int **board) {
    int *emptyCell = findEmptyCell(board);
    int row;
    int col;
    if(emptyCell[0] == -1) {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++) {
                answer[i][j] = board[i][j];
            }
        }
        free(emptyCell);
        return 1;
    }

    row = emptyCell[0];
    col = emptyCell[1];


    /* 행 또는 열 길이만큼 반복 */
    for (int guess = 1; guess <= size; guess++) {
        int safe;
        board[row][col] = guess;
        safe = noConflict(board, row, col, guess);
        if(safe == 1) {
            if (backtrack(board) == 1)
                return 1;
            else {
                board[row][col] = 0;
            }
        } else {
            board[row][col] = 0;
        }
    }

    return -1;
}

int *findEmptyCell(int **board) {
    int *rtn = (int*) malloc ( sizeof(int) * 2 );
    rtn[0] = -1;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (board[i][j] == 0) {
                rtn[0] = i;
                rtn[1] = j;
                return rtn;
            }
    return rtn;
}

int noConflict(int **board, int row, int col, int guess) {
    int a;
    int b;
    a = hasDuplicates(board, row, col, guess);
    b = validMove(board, row, col);
    if( (a == -1) && (b == 1) ) {
        return 1;
    } else {
        return -1;
    }
}

int hasDuplicates(int **board, int row, int col, int guess) {
    for (int i = 0; i < size; i++) {
        if (i == col)
            continue;
        if (board[row][i] == guess)
            return 1;
    }

    for (int j = 0; j < size; j++) {
        if (j == row)
            continue;
        if (board[j][col] == guess)
            return 1;
    }

    return -1;
}

int validMove(int **board, int row, int col) {
    int rowContainsZero;
    int colContainsZero;
    int a;
    int b;

    // Convert column into row in order to use checkRow()
    int *colToRow = (int*) malloc ( sizeof(int) * size );

    for (int i = 0; i < size; i++) {
        colToRow[i] = board[i][col];
    }

    // Check if they contain any zeros
    rowContainsZero = 0;
    for (int i = 0; i < size; i++)
    {
        if(board[row][i] == 0) {
            rowContainsZero = 1;
            break;
        }
    }
    colContainsZero = 0;
    for (int i = 0; i < size; i++)
    {
        if(colToRow[i] == 0) {
            colContainsZero = 1;
            break;
        }
    }

    if ( (rowContainsZero == 1) && (colContainsZero == 1) ) {
        return 1;
    }

    if (!(rowContainsZero == 1) && (colContainsZero == 1) ) {
        return checkRow(left[size - 1 - row], right[row], board[row]);
    }


    if ((rowContainsZero == 1) && !(colContainsZero == 1)) {
        return checkRow(top[col], bottom[size - 1 - col], colToRow);
    }

    // Compare (top && bottom) && (left && right)
    a = checkRow(top[col], bottom[size - 1 - col], colToRow);
    b = checkRow(left[size - 1 - row], right[row], board[row]);
    if((a == 1) && (b == 1)) {
        return 1;
    } else {
        return -1;
    }
}

int checkRow(int left, int right, int *buildings){

    if (left == 0 && right == 0)
        return 1;

    // Looking right to left
    if (left == 0 && right != 0) {
        if(right == viewCount(-1, buildings)) {
            return 1;
        } else {
            return -1;
        }
    }


    // Looking left to right
    if (left != 0 && right == 0) {
        if(left == viewCount(1, buildings)) {
            return 1;
        } else {
            return -1;
        }
    }


    // Looking both from the left and from the right
    if(left == viewCount(1, buildings) && right == viewCount(-1, buildings)) {
        return 1;
    } else {
        return -1;
    }
}


int viewCount(int forward, int *buildings){
    int count = 0;
    int max = 0;
    if (forward == 1) {
        if (buildings[0] != 0) {
            max = buildings[0];
            count++;
        }

        for (int i = 1; i < size; i++) {
            int building = buildings[i];
            if (building > buildings[i - 1] && building > max) {
                count++;
                max = building;
            }
        }
    } else {
        if (buildings[size - 1] != 0) {
            max = buildings[size - 1];
            count++;
        }

        for (int i = size - 2; i >= 0; i--) {
            int building = buildings[i];
            if (buildings[i] > buildings[i + 1] && building > max) {
                count++;
                max = building;
            }
        }
    }
    return count;
}

void stringtoarr(char *clue) {
    top = (int*) malloc ( sizeof(int) * size );
    right = (int*) malloc ( sizeof(int) * size );
    bottom = (int*) malloc ( sizeof(int) * size );
    left = (int*) malloc ( sizeof(int) * size );

    for (int i = 0; i < size; i++)
    {
        top[i] = (int) (clue[i * 2] - '0');
        right[i] = (int) (clue[i * 2 + 8] - '0');
        bottom[i] = (int) (clue[(3 - i) * 2 + 24] - '0');
        left[i] = (int) (clue[(3 - i) * 2 + 16] - '0');
    }

}