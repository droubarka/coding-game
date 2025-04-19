#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
 void do_logic(char *a, char *b, char *c, char *gate)
 {
    int not_flag = 0;
    
    if (!strncmp(gate, "N", 1)) {
        not_flag = 1;
        gate++;
    }
    
    int idx = 0;
     
    while (a[idx])
    {
        int signal;
        int signal_1 = a[idx] == '-';
        int signal_2 = b[idx] == '-';

        if (!strcmp(gate, "AND")) {
            signal = signal_1 & signal_2;
        }
        else if (!strcmp(gate, "OR")) {
            signal = signal_1 | signal_2;
        }
        else if (!strcmp(gate, "XOR")) {
            signal = signal_1 ^ signal_2;
        }

        if (not_flag) {
            signal = !signal;
        }

        if (signal != 0) {
            c[idx] = '-';
        } else {
            c[idx] = '_';
        }

        idx++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);

    char names[4][9];
    char signals[4][65];

    for (int i = 0; i < n; i++) {
        scanf("%s%s", names[i], signals[i]);
    }

    for (int i = 0; i < m; i++) {
        char output_name[9];
        char type[9];
        char input_name_1[9];
        char input_name_2[9];
        scanf("%s%s%s%s", output_name, type, input_name_1, input_name_2);

        int idx_1;
        int idx_2;
        
        for (int i = 0; i < n; i++) {
            if (!strcmp(names[i], input_name_1))
            {
                idx_1 = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!strcmp(names[i], input_name_2))
            {
                idx_2 = i;
                break;
            }
        }
        
        char output_signal[65];

        do_logic(signals[idx_1], signals[idx_2], output_signal, type);

        output_signal[strlen(signals[idx_1])] = '\0';

        printf("%s %s\n", output_name, output_signal);
    }

    return 0;
}
