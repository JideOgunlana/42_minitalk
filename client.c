#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_minitalk.h"

// Convert each character(s) in the message to their binary representation
// e.g the message is -> "abc" 
// a is converted to 01100001
// b is converted to 01100010
// c is converted to 01100011

// Each bit that make up these characters would represent a signal, this would allow the client send a messag to the server
// The 0 bit can be represented by the user defined signal USR1 and 1 bit represented by USR2 or vice-versa

// This means 8 bits have to be processed to send a character

// 5 to binary
// 5 / 2 r1
// 2 / 2 r0
// 1 / 2 r1
// 5 is 0b101 (00000101)

// unsigned char ft_tobinary(int num)
// {
//     int base;
//     int res = 1;

//     base = 2;
//     if (num < 0)
//         num = -num;
//     while (num > 0)
//     {
//         res *= num % 2;
//         num /= 2;
//     }
//     return (res);
// }

int main(int argc, char* argv[])
{
    pid_t server_pid;
    char *message;
    t_client message_length;
    t_client *my_mssg_len;
    // int bit = 0b00000000;
    char *res;

    if (argc != 3)
    {
        printf("Usage: ./client <server_pid> <message>\n");
    }
    else
    {
        server_pid = atoi(argv[1]);
        message = argv[2];
        int mssglen= (int) strlen(message);
        printf("%d - message length\n", mssglen);
        // bit += message[0];
        int i;
        int j;
        
        // printf("%d\n", 0 << 1);
        int mi = 0; // message_index
        while (mi < mssglen)
        {
            i = 0;
            j = 7;
            res = (char *) malloc(sizeof(char) * 8 + 1);
            res[8] = '\0';
            printf("%c\n", message[mi]);
            while (i < 8)
            {
                // printf("%d, %d\n", bit % 2, j);
                res[j] = message[mi] % 2 + '0';
                message[mi] = message[mi] >> 1;
                j--;
                i++;
            }
            i = 0;
            printf("%s\n", res);
            while (res[i] != '\0')
            {
                if (res[i] == '0')
                {
                    printf("SIGUSR1\n");
                    kill(server_pid, SIGUSR1);
                    // usleep(100);
                }
                else if (res[i] == '1')
                {
                    printf("SIGUSR2\n");
                    kill(server_pid, SIGUSR2);
                    // usleep(100);
                }
                else
                {
                    printf("Error!\n");
                }
                usleep(10);
                i++;
            }
            free(res);
            // sleep(1);
            mi++;
        }
        // printf("%s", res);
        
        // printf("%d\n", bit);
        // kill(server_pid, SIGUSR1);
         system("leaks client");
    }
    return (0);
}

// int main(int argc, char *argv[])
// {
//     (void)argc;
//     (void)argv;
    
//     t_client a = {1};
//     t_client *mssglen = {&a};
//     printf("%d", mssglen->ml);
//     return 0;
// }
