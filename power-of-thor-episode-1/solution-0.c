#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{
    // the X position of the light of power
    int light_x;
    // the Y position of the light of power
    int light_y;
    // Thor's starting X position
    int initial_tx;
    // Thor's starting Y position
    int initial_ty;
    scanf("%d%d%d%d", &light_x, &light_y, &initial_tx, &initial_ty);

    // game loop
    while (1) {
        // The remaining amount of turns Thor can move. Do not remove this line.
        int remaining_turns;
        scanf("%d", &remaining_turns);

        fprintf(stderr, "Thor position = (%d, %d). Light position = (%d, %d). Energy = %d\n", initial_tx, initial_ty, light_x, light_y, remaining_turns);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        char buf[3];
        int  idx = 0;

        int  offset_x = 0;
        int  offset_y = 0;

        if (initial_ty < light_y && initial_ty <= 17)
        {
            buf[idx++] = 'S';
            offset_y = +1;
        }
        else if (initial_ty > light_y && initial_ty >= 0)
        {
            buf[idx++] = 'N';
            offset_y = -1;
        }
        if (initial_tx < light_x && initial_tx >= 0)
        {
            buf[idx++] = 'E';
            offset_x = +1;
        }
        else if (initial_tx > light_x && initial_tx <= 39)
        {
            buf[idx++] = 'W';
            offset_x = -1;
        }

        buf[idx++] = '\0';

        initial_tx += offset_x;
        initial_ty += offset_y;

        printf("%s\n", buf);
    }

    return 0;
}
