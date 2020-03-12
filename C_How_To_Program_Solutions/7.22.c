#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void findExit(int *direction,char maze[12][12],int *locationx,int *locationy);
void show(char maze[12][12]);
int main(){
    char maze[12][12] = {
            '#','#','#','#','#','#','#','#','#','#','#','#',

            '#','.','.','.','#','.','.','.','.','.','.','#',

            '.','.','#','.','#','.','#','#','#','#','.','#',

            '#','#','#','.','#','.','.','.','.','#','.','#',

            '#','.','.','.','.','#','#','#','.','#','.','.',

            '#','#','#','#','.','#','.','#','.','#','.','#',

            '#','.','.','#','.','#','.','#','.','#','.','#',

            '#','#','.','#','.','#','.','#','.','#','.','#',

            '#','.','.','.','.','.','.','.','.','#','.','#',

            '#','#','#','#','#','#','.','#','#','#','.','#',

            '#','.','.','.','.','.','.','#','.','.','.','#',

            '#','#','#','#','#','#','#','#','#','#','#','#'
    };
    int s,i;
    int direction = 0; // 0--> right,1 --> down, 2--->left , 3---> up
    int locationx = 0;
    int locationy = 2;
    while (maze[4][11] != 'X'){
        findExit(&direction,maze,&locationx,&locationy);
        show(maze);
        getch();

    }

    printf("\nProgram find the exit.\n");
    return 0;
}
void findExit(int *direction,char maze[12][12],int *locationx,int *locationy){
    int a= *direction;
    switch(a){
        case 0: // right
            if (maze[*locationy][*locationx+1] == '.' && maze[*locationy+1][*locationx] == '#'){
                maze[*locationy][*locationx] = 'X';
                *locationx += 1;
            }
            else if (maze[*locationy][*locationx+1] == '.' && maze[*locationy+1][*locationx] == 'X'){
                maze[*locationy][*locationx] = 'X';
                *locationx += 1;
            }
            else if (maze[*locationy][*locationx+1] == 'X'){
                maze[*locationy][*locationx] = 'X';
                *locationx += 1;
            }
            else if (maze[*locationy][*locationx+1] == '.'){
                maze[*locationy][*locationx] = 'X';
                *locationx += 1;
            }
            else if (maze[*locationy][*locationx+1] == '#' && maze[*locationy+1][*locationx] == '#'){
                maze[*locationy][*locationx] = 'X';

                *direction = 3;
            }
            else if (maze[*locationy][*locationx+1] == '#' && maze[*locationy-1][*locationx] == '#'){
                maze[*locationy][*locationx] = 'X';

                *direction = 1;
            }
            break;
        case 1: // down
            if (maze[*locationy][*locationx+1] == '#' && maze[*locationy+1][*locationx] == '.'){
                maze[*locationy][*locationx] = 'X';
                *locationy += 1;
            }
            else if (maze[*locationy][*locationx+1] == '.' && maze[*locationy+1][*locationx] == '.'){
                maze[*locationy][*locationx] = 'X';

                *direction = 0;
            }
            else if (maze[*locationy+1][*locationx] == 'X'){
                maze[*locationy][*locationx] = 'X';

                *locationy += 1;
            }
            else if (maze[*locationy+1][*locationx] == '#'){
                maze[*locationy][*locationx] = 'X';

                *direction = 2;
            }
            else if (maze[*locationy+1][*locationx] == '.'){
                maze[*locationy][*locationx] = 'X';

                *locationy += 1;
            }
            break;

        case 2: // left
            if (maze[*locationy-1][*locationx] == '#' && maze[*locationy][*locationx-1] == '.'){
                maze[*locationy][*locationx] = 'X';
                *locationx -= 1;
            }
            else if (maze[*locationy-1][*locationx] == 'X' && maze[*locationy][*locationx-1] == '.'){
                maze[*locationy][*locationx] = 'X';
                *locationx -= 1;
            }
            else if (maze[*locationy-1][*locationx] == '.'){
                maze[*locationy][*locationx] = 'X';

                *direction = 3;

            }
            else if (maze[*locationy][*locationx-1] == '#' && maze[*locationy-1][*locationx] == '#' && maze[*locationy+1][*locationx] == '#'){
                maze[*locationy][*locationx] = 'X';

                *direction = 0;
            }

            break;
        case 3: // up
            if (maze[*locationy-1][*locationx] == '.' && maze[*locationy][*locationx+1] == '#'){
                maze[*locationy][*locationx] = 'X';
                *locationy -= 1;
            }
            else if (maze[*locationy-1][*locationx] == '.' && maze[*locationy][*locationx+1] == 'X'){
                maze[*locationy][*locationx] = 'X';
                *locationy -= 1;
            }
            else if (maze[*locationy-1][*locationx] == '#' && maze[*locationy][*locationx-1] == '#' && maze[*locationy][*locationx+1] == '.'){
                maze[*locationy][*locationx] = 'X';

                *direction = 0;
            }
            else if (maze[*locationy-1][*locationx] == '#' && maze[*locationy][*locationx-1] == '.' && maze[*locationy][*locationx+1] == '#'){
                maze[*locationy][*locationx] = 'X';

                *direction = 2;
            }
            break;
    }
}
void show(char maze[12][12]){
    int i,s;
    for (i=0; i<12; i++){
        for (s=0; s<12; s++){
            printf("%c",maze[i][s]);
        }
        printf("\n");
    }
}