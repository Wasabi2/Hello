#include <stdio.h>  
#define ROW 10 
#define COLUMN 10

void produce(int[][COLUMN], int[][COLUMN]);
void print(int[][COLUMN]);
void copy(int[][COLUMN], int[][COLUMN]);
int neighbors(int[][COLUMN], int, int);
int isDifferent(int[][COLUMN], int[][COLUMN]);

int main() { 
    int current[ROW][COLUMN] = {
       {0, 1, 0, 1, 0, 0, 0, 0, 1, 1},
       {0, 1, 0, 1, 0, 0, 0, 0, 1, 1},
       {0, 1, 0, 1, 0, 0, 0, 0, 1, 1},
       {0, 1, 1, 1, 0, 0, 1, 0, 1, 1},
       {0, 1, 1, 1, 0, 1, 0, 0, 1, 1},
       {0, 1, 0, 1, 1, 0, 0, 1, 1, 1},
       {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
       {0, 1, 0, 1, 0, 0, 1, 0, 1, 1},
       {0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
       {0, 1, 0, 1, 1, 0, 0, 0, 1, 1}
    };
    int next[ROW][COLUMN] = {0};

    print(current);
    produce(current, next);
    while(isDifferent(current, next)) {
        copy(next, current);
        print(current);
        produce(current, next);
    }
   
    return 0; 
} 


void produce(int current[][COLUMN], int next[][COLUMN]) {
    int row; 
    for(row = 0; row < ROW; row++) {
        int column;
        for(column = 0; column < COLUMN; column++) {
            switch (neighbors(current, row, column)) {
               case 0: case 1: case 4:
                  next[row][column] = 0; break; 
               case 2: 
                  next[row][column] = current[row][column]; break; 
               case 3: 
                  next[row][column] = 1;
            } 
        }
    }
}

int neighbors(int current[][COLUMN], int row, int column) {
    int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
                      {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    int count, i;
    for(count = 0, i = 0; i < 8 && count < 4; i++) {
        int r = row + dirs[i][0];
        int c = column + dirs[i][1];
        if(r > -1 && r < ROW && c > -1 && c < COLUMN && current[r][c]) {
             count++;
        }
    }
    return count;
} 

void print(int current[][COLUMN]) {
    printf("Status...\n");
    int row;    
    for(row = 0; row < ROW; row++) { 
        int column;
        for(column = 0; column < COLUMN; column++) {
            putchar(current[row][column] ? '*' : '~');
        }
        puts("");
    } 
} 

void copy(int from[][COLUMN], int to[][COLUMN]) {
    int row;
    for(row = 0; row < ROW; row++) {
        int column;
        for(column = 0; column < COLUMN; column++) {
            to[row][column] = from[row][column];
            from[row][column] = 0;
        }
    }
}  

int isDifferent(int current[][COLUMN], int next[][COLUMN]) {
    int row;
    for(row = 0; row < ROW; row++) {
        int column;
        for(column = 0; column < COLUMN; column++) {
            if(current[row][column] != next[row][column]) {
                return 1;
            }
        }
    }
    return 0;
}  
