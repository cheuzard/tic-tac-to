#include <stdio.h>
#include <stdlib.h>

//function to print a horizontal line of asterisks
void Line(){
    for(int i = 1; i<43;i++)printf("*");
    printf("\n");
}

// Function to print a single line of the 'O' symbol
// Takes an integer (1-5) representing which line of the symbol to print
//  ,gPPRg,
// dP'   `Yb 
// 8)     (8
// Yb     dP 
//  ,8ggg8,   
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


// Function to print a single line of the 'X' symbol
// Takes an integer (1-5) representing which line of the symbol to print
//   x       x 
//     x   x   
//       x     
//     x   x   
//   x       x  
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

//Function to print an empty cell
void empty(){
    printf("|             ");
}

//function that checks if there is a winner
//uses the "win" int variable to return 1 if there is a winner and 0 otherwise 
    int checkWin(int table[3][3]){
        int win = 0;

        //check the rows
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

        //check the columns
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

        //checks the main diagonal
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

        //checks the secondary diagonal
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
    //win int variable to state if the games has a winner
    int win = 0;
    
    //initializing the game board with empty spaces
    //the game board represented as a 2D array of integers, where 0 represents an empty space,
    // 1 represents player 1's move, and 2 represents player 2's move.
    int table[3][3]= {0}; 
    int x,y;

    //counting the turns to determine the current player
int round = 0;

    //the main game loop
while (!win)
{
    //asking the player for the coordinates the want to place there symbol in
        printf("it's player %d's turn", round%2 + 1);
        //using a do while loop to check that the cell is empty
        //player is determined by checking if the round is odd or even
        //the + 1 is to go from 0 or 1 to 1 or 2 
        do
        {
        printf(" select an empty space:");
        scanf("%d %d",&y,&x);
        } while (table[y - 1][x -1] != 0);

        //registering the move to the game board
        table[y - 1][x - 1] = round%2 + 1;
        
    
    //rendering the game board
    //looping three times, once for every row using the y coords
    for (int y = 0; y < 3; y++)
    {
        //printing a horizontal line for every row, to avoid doubling the asterisks lines only the upper line is printed
        //and the last asterisks line is printed last in the loop
            Line();

            //loop to render every line in a row, a row contains 5 lines
        for(int i= 1; i<=5;i++){

            //loop to move render the cells of a row
            for (int x = 0; x < 3; x++)
            {
                //printing the symbol for the cell, if the cell is empty, print an empty cell,
                //if the cell contains a 1, print an 'X', and if the cell contains a 2, print an 'O'
                if (table[y][x] == 0){
                    empty();
                }else if (table[y][x] == 1)
                {
                ex(i);
                }else{
                    circle(i);
                }
            }
            //print the final vertical wall (|) and break line 
            printf("|\n");
        }
    }
    //prints the final horizontal line after every cell is rendered 
    Line();

    //update the game win state for the next loop
    win = checkWin(table);

    //increment the turn counter after each turn
    round++;
}

    return 0;
}

