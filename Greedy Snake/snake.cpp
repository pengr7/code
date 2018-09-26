#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

char map[12][13] = {"************",
                    "*XXXXH     *",
                    "*          *",
                    "*          *",
                    "*          *",
                    "*          *",
                    "*          *",
                    "*          *",
                    "*          *",
                    "*          *",
                    "*          *",
                    "************"};
int snakeX[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int snakeY[SNAKE_MAX_LENGTH] = {1, 2, 3, 4, 5};
int snakelength = 5;

int judgefood(void) {
    for (int i = 1; i < 12; i++)
        for (int j = 1; j < 12; j++)
            if (map[i][j] == SNAKE_FOOD) return 1;
    return 0;
}

void snakemove(int x, int y) {
    map[snakeX[0]][snakeY[0]] = BLANK_CELL;
    for (int i = 0; i < snakelength - 1; i++) {
        snakeX[i] = snakeX[i + 1];
        snakeY[i] = snakeY[i + 1];
        map[snakeX[i]][snakeY[i]] = SNAKE_BODY;
    }
    snakeX[snakelength - 1] += x;
    snakeY[snakelength - 1] += y;
    map[snakeX[snakelength - 1]][snakeY[snakelength - 1]] = SNAKE_HEAD;
}

void put_money(void) {
    int i, x, y, food = 1;
    if (!judgefood()) {
        for (; food;) {
            food = 0;
            x = 1 + rand()%10;
            y = 1 + rand()%10;
            for (i = 0; i < snakelength; i++)
                if (snakeX[i] == x && snakeY[i] == y) food++;
        }
        map[x][y] = SNAKE_FOOD;
    }
}

void output(void) {
    if (!judgefood()) {
        snakelength++;
        for (int i = snakelength - 1; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }
    }
}

int gameover(void) {
    if (!snakeX[snakelength - 1] || snakeX[snakelength - 1] == 11 || !snakeY[snakelength - 1] || snakeY[snakelength - 1] == 11) return 1;
    for (int i = 0; i < snakelength - 1; i++)
        if (snakeX[i] == snakeX[snakelength - 1] && snakeY[i] == snakeY[snakelength - 1]) return 1;
    return 0;
}

int main() {
    while (!gameover()) {
        for (int i = 0; i < 12; i++) printf("%s\n", map[i]);
        printf("\nPRESS WASD TO MOVE\nPRODUCED BY CARL\nSCORE: %d\n", snakelength - 5);
        put_money();
        switch (getch()) {
            case 'w': snakemove(-1, 0); break;
            case 'a': snakemove(0, -1); break;
            case 's': snakemove(1, 0);  break;
            case 'd': snakemove(0, 1);  break;
            default: break;
        }
        output();
        system("cls");
        if (snakelength >= SNAKE_MAX_LENGTH) {
            printf("CONGRATULATIONS\nYOU WIN\n");
            return 0;
        }
    }
    printf("GAME OVER\nSCORE: %d\n", snakelength - 5);
    return 0;
}

