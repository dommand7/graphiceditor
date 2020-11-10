#include <stdio.h>
#include <stdlib.h>
int i, M, N, x, y, j, z, var, red, st1, st2, st, red1, red2, l, d;
char c = 'A', b, pamti, boja;
char **tablica;
void regija(int x, int y, char boja, char pamti)
{
    if (tablica[x][y] == boja)
        return;
    tablica[x][y] = boja;
    if ((x - 1) >= 0 && (x - 1) < N && y >= 0 && y < M && (tablica[x - 1][y] == pamti))
        regija(x - 1, y, boja, pamti);
    if ((x + 1) >= 0 && (x + 1) < N && y >= 0 && y < M && (tablica[x + 1][y] == pamti))
        regija(x + 1, y, boja, pamti);
    if (x >= 0 && x < N && (y - 1) >= 0 && (y - 1) < M && (tablica[x][y - 1] == pamti))
        regija(x, y - 1, boja, pamti);
    if (x >= 0 && x < N && (y + 1) >= 0 && (y + 1) < M && (tablica[x][y + 1] == pamti))
        regija(x, y + 1, boja, pamti);
}
int main()
{
    while (c != 'X')
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'I':
        {
            scanf("%d %d", &M, &N);
            if (N > 250 || M > 250)
                printf("N i M moraju biti manji ili jednaki 250");
            tablica = (char **)malloc(N * sizeof(char *));
            for (i = 0; i < N; i++)
            {
                tablica[i] = (char *)malloc(M * sizeof(char));
            }
            printf("uspilo\n");
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < M; j++)
                {
                    tablica[i][j] = 'O';
                }
            }
        }
        break;

        case 'C':
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < M; j++)
                    tablica[i][j] = 'O';
            }
        }
        break;

        case 'L':
        {
            scanf("%d %d %c", &x, &y, &b);
            printf("obojat ce piksel %d,%d bojom %c \n", x, y, b);
            tablica[y - 1][x - 1] = b;
        }
        break;

        case 'V':
        {
            scanf("%d %d %d %c", &red, &st1, &st2, &b);
            for (i = st1 - 1; i <= st2 - 1; i++)
            {
                tablica[i][red - 1] = b;
            }
        }
        break;

        case 'H':
        {
            scanf("%d %d %d %c", &red1, &red2, &st, &b);
            for (i = red1 - 1; i <= red2 - 1; i++)
            {
                tablica[st - 1][i] = b;
            }
        }
        break;

        case 'F':
        {
            scanf("%d %d %c", &l, &d, &boja);
            pamti = tablica[d - 1][l - 1];
            regija(d - 1, l - 1, boja, pamti);
        }
        break;
        case 'S':
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < M; j++)
                {
                    printf("%c", tablica[i][j]);
                }
                printf("\n");
            }
        }
        break;

        case 'X':
            break;
        }
    }
    for (i = 0; i < N; i++)
        free(tablica[i]);
    free(tablica);
}
