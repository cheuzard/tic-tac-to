#include <stdio.h>
#include <stdlib.h>

void Line(){
    for(int i = 1; i<43;i++)printf("*");
    printf("\n");
}
 

void circle(int Line){
    switch (Line)
    {
    case 1:
        printf("|   ,gPPRg,   ");
        break;
    case 2:
        printf("|  dP'   `Yb  ");
        break;
    case 3:
        printf("|  8)     (8  ");
        break;
    case 4:
        printf("|  Yb     dP  ");
        break;
    case 5:
        printf("|   ,8ggg8,   ");
        break;
    default:
    printf("error");
        break;
    }
}

void ex(int Line){
    switch (Line)
    {
    case 1:
        printf("|  x       x  ");
        break;
    case 2:
        printf("|    x   x    ");
        break;
    case 3:
        printf("|      x      ");
        break;
    case 4:
        printf("|    x   x    ");
        break;
    case 5:
        printf("|  x       x  ");
        break;
    default:
    printf("error");
        break;
    }
}

void empty(){
    printf("|             ");
}


    int checkWin(int table[3][3]){
        int win = 0;
        for (int i = 0; i < 3; i++)
        {
            if (table[i][0] == table[i][1] && table[i][1] == table[i][2]){
                switch (table[i][1])
                {
                case 1:
                    printf("player 1 wins !!\n");
                    win = 1;
                    break;
                case 2:
                    printf("player 2 wins !!\n");
                    win = 1;
                    break;
                default:
                    break;
                }
            }
            
        }
        for (int i = 0; i < 3; i++)
        {
            if (table[0][i] == table[1][i] && table[1][i] == table[2][i]){
                switch (table[1][i])
                {
                case 1:
                    printf("player 1 wins !!\n");
                    win = 1;
                    break;
                case 2:
                    printf("player 2 wins !!\n");
                    win = 1;
                    break;
                default:
                    break;
                }
            }
            
        }
        if (table[0][0] == table[1][1] && table[1][1] == table[2][2]){
            switch (table[1][1])
            {
            case 1:
                printf("player 1 wins !!\n");
                win = 1;
                break;
            case 2:
                printf("player 2 wins !!\n");
                win = 1;
                break;
            default:
                break;
            }
        }
        if (table[2][0] == table[1][1] && table[1][1] == table[0][2]){
            switch (table[1][1])
            {
            case 1:
                printf("player 1 wins !!\n");
                win = 1;
                break;
            case 2:
                printf("player 2 wins !!\n");
                win = 1;
                break;
            default:
                break;
            }
        }
        
            
     return win;   
    }
int main(int argc, char const *argv[])
{
    int win = 0;

    int table[3][3]= { 0,0,0,
                       0,0,0,     
                       0,0,0 }; 

    int x,y;
int round = 0;
while (!win)
{
    win = checkWin(table);
    
        printf("it's player %d's turn", round%2 + 1);
        do
        {
        printf(" select an empty space:");
        scanf("%d %d",&y,&x);
        } while (table[y - 1][x -1] != 0);
        table[y - 1][x - 1] = round%2 + 1;
        
    
    
    for (int y = 0; y < 3; y++)
    {
            Line();
        for(int i= 1; i<=5;i++){
            for (int x = 0; x < 3; x++)
            {
                if (table[y][x] == 0){
                    empty();
                }else if (table[y][x] == 1)
                {
                ex(i);
                }else{
                    circle(i);
                }
            }
            printf("|\n");
        }
    }
    Line();
    win = checkWin(table);
    round = round +1;
}

    
    return 0;
}

