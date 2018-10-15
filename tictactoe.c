#include <stdio.h>
#include <stdbool.h>

void print_grid(char* grid)
{
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", grid[0], grid[1], grid[2]);
    printf("   |   |   \n");
    printf("-----------\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", grid[3], grid[4], grid[5]);
    printf("   |   |   \n");
    printf("-----------\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", grid[6], grid[7], grid[8]);
    printf("   |   |   \n");
}

bool has_won(char* grid, char marker)
{
    for(int i = 0; i < 3; i++)
    {
        if(marker == grid[3*i+0] && marker == grid[3*i+1] && marker == grid[3*i+2])
            return true;
        if(marker == grid[0 + i] && marker == grid[3 + i] && marker == grid[6 + i])
            return true;
    }

    if(marker == grid[0] && marker == grid[3] && marker == grid[8])
        return true;
    if(marker == grid[2] && marker == grid[3] && marker == grid[6])
        return true;

    return false;
}

int main()
{

    char grid[9];

    for(int i = 0; i < 9; ++i)
        grid[i] = '0' + i + 1;

    int currentPlayer = 1;

    while(1)
    {
        char marker = currentPlayer == 1 ? 'X' : 'O';
        printf("Tic Tac Toe\n\nPlayer 1 (X) - Player 2 (O)\n\n");
        print_grid(grid);

        printf("\nPlayer %d, enter a number: ", currentPlayer);

        int x;

        while(1){
            scanf("%d",&x);
            if(x < 1 || x > 9)
                printf("Invalid coordiante please enter a value from 1-9: ");
            else if(grid[x-1] != ('0'+x))
                printf("That spot is already taken up, please enter another value: ");
            else
                break; // valid input
        }

        grid[x-1] = marker;

        if(has_won(grid,marker))
        {
            printf("Player %d has won.\n");
            return 0;
        }

        bool flag = false;
        for(int i = 0; i < 9; ++i)
        {
            if(grid[i] == ('0' + i + 1))
                break;
        }

        if(flag)
        {
            printf("It's a tie!\n");
            return 0;
        }

        currentPlayer = 3-currentPlayer; // swaps 2 to 1 and 1 to 2

    }

}
