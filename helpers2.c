#include "main.h"
/**
 * free_grid - free 2d array
 * @grid: pointer
 */
void free_grid(char **grid)
{
    int i;
    if (!grid)
        return;
    for (i = 0; grid[i]; i++)
    {
        free(grid[i]);
        grid[i] = NULL;
    }

    free(grid);
    grid = NULL;
}