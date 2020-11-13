#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int M, N;
char **matrix;
bool isPixelValid(int x, int y)
{
    if (x < 0 || x > N - 1 || y < 0 || y > M - 1)
        return false;
    else
        return true;
}
char getPixelColor(int x, int y)
{
    if (isPixelValid(x, y) == true)
        return matrix[x][y];
        else return '\0';
}
char setPixelColor(int x, int y, char color)
{
    if (isPixelValid(x, y) == true)
    {
        matrix[x][y] = color;
        return color;
    }
    else
        return '\0';
}
void region(int x, int y, char b, char remember)
{
    if (isPixelValid(x, y) == false)
        return;
    if (getPixelColor(x, y) == b)
        return;
    setPixelColor(x, y, b);
    if (getPixelColor(x - 1, y) == remember)
        region(x - 1, y, b, remember);
    if (getPixelColor(x + 1, y) == remember)
        region(x + 1, y, b, remember);
    if (getPixelColor(x, y - 1) == remember)
        region(x, y - 1, b, remember);
    if (getPixelColor(x, y + 1) == remember)
        region(x, y + 1, b, remember);
}
int main()
{
    int i, j, x, y, z;
    char c = 'A', b, remember;
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
            matrix = (char **)malloc(N * sizeof(char *));
            for (i = 0; i < N; i++)
            {
                matrix[i] = (char *)malloc(M * sizeof(char));
            }
            printf("uspilo\n");
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < M; j++)
                {
                    setPixelColor(i, j, 'O');
                }
            }
        }
        break;

        case 'C':
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < M; j++)
                    setPixelColor(i, j, 'O');
            }
        }
        break;

        case 'L':
        {
            scanf("%d %d %c", &x, &y, &b);
            printf("obojat ce piksel %d,%d bojom %c \n", x, y, b);
            setPixelColor(y - 1, x - 1, b);
        }
        break;

        case 'V':
        {
            scanf("%d %d %d %c", &x, &y, &z, &b);
            for (i = y - 1; i <= z - 1; i++)
            {
                setPixelColor(i, x - 1, b);
            }
        }
        break;

        case 'H':
        {
            scanf("%d %d %d %c", &x, &y, &z, &b);
            for (i = x - 1; i <= y - 1; i++)
            {
                setPixelColor(z - 1, i, b);
            }
        }
        break;

        case 'F':
        {
            scanf("%d %d %c", &x, &y, &b);
            remember = getPixelColor(y - 1, x - 1);
            region(y - 1, x - 1, b, remember);
        }
        break;
        case 'S':
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < M; j++)
                {
                    printf("%c", getPixelColor(i, j));
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
        free(matrix[i]);
    free(matrix);
}
