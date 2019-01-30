#include <stdio.h>
#include <stdlib.h>

//1. *Количество маршрутов с препятствиями. Доска 5 x 5, координаты препятствий (1, 1), (3, 2), (1, 3).
int routes(int x, int y) {
    if ((x == 0 && y == 0) ||
        (x == 1 && y == 1) ||
        (x == 3 && y == 2) ||
        (x == 1 && y == 3))
        return 0;
    else if (x == 0 || y == 0)
        return 1;
    else
        return routes(x - 1, y) + routes(x, y - 1);
}

//3. ***Требуется обойти конём шахматную доску размером N × M, пройдя через все поля доски по одному разу.
#define sx 8
#define sy 8
int board[sx][sy];

void fillBoard() {
    int i;
    int j;
    for (i = 0; i < sx; i++)
        for (j = 0; j < sx; j++)
            board[i][j] = 0;
}

void printBoard() {
    int i;
    int j;
    for (i = 0; i < sy; i++) {
        for (j = 0; j < sy; j++)
            printf("%5d", board[i][j]);
        printf("\n");
    }
}

int knightMoves(int x, int y, int n) {
    int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int i = 0;
    int nx;
    int ny;
    
    n += 1;
    board[x][y] = n;
    
    if (n == sx * sy)
        return 1;
    
    while (i < (sx - 1)) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (((nx >= 0) && (nx < sx)) &&
            ((ny >= 0) && (ny < sy)) &&
            (board[nx][ny] == 0))
            if (knightMoves(nx, ny, n))
                return n;
        i++;
    }
    board[x][y] = 0;
    return 0;
}

int main(int argc, const char** argv) {
    int i;
    int j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++)
            printf("%3d", routes(j, i));
        printf("\n");
    }
    printf("\n");
    fillBoard();
    knightMoves(3, 0, 0);
    printBoard();
    
    return 0;
}
