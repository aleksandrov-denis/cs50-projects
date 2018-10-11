/**
 * fifteen.c
 *
 * CS50 AP
 * Fifteen
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 *
 * Extra features including printing an actual grid to make it look more
 * tile-like, and using ANSI color sequences for some additional customizing
 */


/*board[x][y] = board[blank_col][blank_row];
                    board[blank_col][blank_row] = tile;*/


#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// ansi escape sequence to print grid color
// replace the number beteen [ and m with 31 for red, 32 for green, 33 for brown,
// 34 for blue, 35 for purple, 36 for cyan, 37 for gray
#define COLOR "\033[36m"

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// saved locations of the blank tile
int blank_row;
int blank_col;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void swapints(int *a, int *b, int tile);
void print_grid_row(int d);
void print_tile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
               DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(50000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    int x, y;
    int max = d * d;
    blank_row = d - 1;
    blank_col = d - 1;
    //if tile is even, do this
    if (d % 2 == 0)
    {
        for (x = 0; x < d; x++)
        {
            for (y = 0; y < d; y++)
            {
                //orders numbers in backwards order from top left to bottom right
                board[x][y] = max - 1;
                max--;
            }
        }
        //switches posittion of 1 and 2
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 3] = 1;
    }
    //if tile is odd, do this
    else
    {
        for (x = 0; x < d; x++)
        {
            for (y = 0; y < d; y++)
            {
                board[x][y] = max - 1;
                max--;
            }
        }
    }

}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int x, y;
    for (x = 0; x < d; x++)
    {
        for (y = 0; y < d; y++)
        {
            //prints zero as '_'
            if (board[x][y] == 0)
            {
                printf("  _");
            }
            else
            {
                //prints every int but with three spaces before it, style pts
                printf("%3i", board[x][y]);
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    int x, y, tile_row, tile_col;
    for (x = 0; x < d; x++)
    {
        for (y = 0; y < d; y++)
        {
            if (tile == board[x][y])
            {
                tile_col = x;
                tile_row = y;
                //if in same row, do this
                if (tile_row == blank_row)
                {
                    //if blank to left, swap
                    if (tile_col == blank_col + 1)
                    {
                        swapints(&board[tile_col][tile_row], &board[blank_col][blank_row], tile);
                        blank_col = x;
                        blank_row = y;
                        return true;
                    }
                    //if blank to right, swap
                    else if (tile_col == blank_col - 1)
                    {
                        swapints(&board[tile_col][tile_row], &board[blank_col][blank_row], tile);
                        blank_col = x;
                        blank_row = y;
                        return true;
                    }
                    //if none, then false
                    else
                    {
                        return false;
                    }
                }
                //if in same column, do this
                if (tile_col == blank_col)
                {
                    //if blank below, swap
                    if (tile_row == blank_row + 1)
                    {
                        swapints(&board[tile_col][tile_row], &board[blank_col][blank_row], tile);
                        blank_col = x;
                        blank_row = y;
                        return true;
                    }
                    //if blank above, swap
                    else if (tile_row == blank_row - 1)
                    {
                        swapints(&board[tile_col][tile_row], &board[blank_col][blank_row], tile);
                        blank_col = x;
                        blank_row = y;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    int val = 0;
    // checks each consequtive tile to make sure it's in order
    for (int x = 0; x < d; x++)
    {
        for (int y = 0; y < d; y++)
        {
            // if not last spot or correct value, then false
            if (++val != (d * d) && board[x][y] != val)
            {
                return false;
            }
        }
    }

    return true;
}

//basic swap function except int swap is assigned the value of the tile user wants to swap
void swapints(int *a, int *b, int tile)
{
    int swap = tile;
    swap = *a;
    *a = *b;
    *b = swap;
}
