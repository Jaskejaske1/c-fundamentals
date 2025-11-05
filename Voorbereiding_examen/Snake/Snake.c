#include <stdio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_LEN 200

int snakeX[MAX_LEN], snakeY[MAX_LEN];
int length = 4;
int dirX = 1, dirY = 0;
int fruitX, fruitY;
int score = 0;
int gameOver = 0;

void gotoXY(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void hideCursor() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(h, &info);
}

void drawBorder() {
    int x, y;
    gotoXY(0, 0);
    for (y = 0; y <= HEIGHT; y++) {
        for (x = 0; x <= WIDTH; x++) {
            if (y == 0 || y == HEIGHT || x == 0 || x == WIDTH)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void spawnFruit() {
    fruitX = rand() % (WIDTH - 2) + 1;
    fruitY = rand() % (HEIGHT - 2) + 1;
}

void drawSnakeAndFruit() {
    int i;

    // Draw fruit
    gotoXY(fruitX, fruitY);
    printf("*");

    // Draw snake
    for (i = 0; i < length; i++) {
        gotoXY(snakeX[i], snakeY[i]);
        printf(i == 0 ? "@" : "o");
    }

    // Print score
    gotoXY(0, HEIGHT + 1);
    printf("Score: %d", score);
}

void input() {
    if (GetAsyncKeyState(VK_UP) & 0x8000 && dirY != 1) {
        dirX = 0; dirY = -1;
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000 && dirY != -1) {
        dirX = 0; dirY = 1;
    }
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000 && dirX != 1) {
        dirX = -1; dirY = 0;
    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && dirX != -1) {
        dirX = 1; dirY = 0;
    }
    else if (GetAsyncKeyState('Q') & 0x8000) {
        gameOver = 1;
    }
}

void logic() {
    // Move tail
    for (int i = length - 1; i > 0; i--) {
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
    }

    // Move head
    snakeX[0] += dirX;
    snakeY[0] += dirY;

    // Collide wall
    if (snakeX[0] <= 0 || snakeX[0] >= WIDTH ||
        snakeY[0] <= 0 || snakeY[0] >= HEIGHT)
        gameOver = 1;

    // Collide body
    for (int i = 1; i < length; i++)
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
            gameOver = 1;

    // Eat fruit
    if (snakeX[0] == fruitX && snakeY[0] == fruitY) {
        length++;
        score++;
        spawnFruit();
    }
}

int main() {
    hideCursor();
    srand((unsigned)time(NULL));

    // Init snake
    for (int i = 0; i < length; i++) {
        snakeX[i] = 10 - i;
        snakeY[i] = 10;
    }

    spawnFruit();
    drawBorder();

    while (!gameOver) {
        input();
        logic();
        drawBorder();
        drawSnakeAndFruit();
        Sleep(120);
    }

    gotoXY(0, HEIGHT + 3);
    printf("GAME OVER! Final score: %d\nPress Enter to exit...", score);
    getchar();
    return 0;
}
