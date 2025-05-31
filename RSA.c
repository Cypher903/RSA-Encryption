#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "crypto.h"


int gcd(int x, int y);
int modInverse(int e, int m);
long long mod_exp(long long base, long long exp, long long mod);

int main()
{
    char data[100];
    int endata[100];
    char dedata[100];

    FILE *ptr = fopen("Public.txt", "r");
    if (!ptr)
    {
        printf("File not found.\n");
        return 1;
    }
    fgets(data, 100, ptr);
    fclose(ptr);

    int a, b;
    printf("Enter two large prime numbers: ");
    scanf("%d %d", &a, &b);

    int n = a * b;
    int o = (a - 1) * (b - 1); // phi(n)

    srand(time(0));
    int e;
    do
    {
        e = rand() % (o - 2) + 2; // ensure 2 <= e <= o-1
    } while (gcd(e, o) != 1);

    int d = modInverse(e, o);

    printf("Public Key (e,n): (%d)\n", e);
    printf("Private Key (d,n): (%d)\n", d);

    int x = 0;
    do
    {

        printf("Enter:\n1: Encryption\n2: Decryption\n> ");
        int nt;
        scanf("%d", &nt);
        if (nt == 1)
        {
            int pubkey;
            printf("Enter public key ");
            scanf("%d", &pubkey);
            if (pubkey == e)
            {
                int i = 0;
                while (data[i] != '\0')
                {
                    endata[i] = mod_exp(data[i], e, n);
                    i++;
                }

                ptr = fopen("Public.txt", "w");
                for (int j = 0; j < i; j++)
                {
                    fprintf(ptr, "%d ", endata[j]); // Write encrypted as space-separated integers
                }
                fclose(ptr);
                printf("Encryption complete.\n Enter 5 number to proceed\n");
                scanf("%d", &x);
            }
            else
            {
                printf("Enter Correct Key");
                x=5;
            }
        }
        else if (nt == 2)
        {
            int privkey;
            printf("Enter private key ");
            scanf("%d", &privkey);
            if (privkey == d)
            {
                ptr = fopen("Public.txt", "r");
                int num, i = 0;
                while (fscanf(ptr, "%d", &num) != EOF)
                {
                    dedata[i] = mod_exp(num, d, n); // Decrypt
                    i++;
                }
                dedata[i] = '\0';
                fclose(ptr);

                ptr = fopen("Public.txt", "w");
                fputs(dedata, ptr);
                fclose(ptr);
                printf("Decryption complete.\n");
            }
            else
            {
                printf("Enter Correct Key");
                x=5;
            }
            x = 0;
        }
        else
        {
            printf("Enter correct Value");
            x = 5;
        }
    } while (x == 5);

    return 0;
}


