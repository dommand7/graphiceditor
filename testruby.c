#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int M, N;
char **matrix;
bool isPixelValid(int x, int y)
{
    if (x < 0 || x > N - 1 || y < 0 || y > M - 1)
        return false;
    return true;
}
char getPixelColor(int x, int y)
{
    if (isPixelValid(x, y))
        return matrix[x][y];
    return false;
}
char setPixelColor(int x, int y, char color)
{
    if (!isPixelValid(x, y))
    {
        return false;
    }
    return matrix[x][y] = color;
}
void fillRegion(int x, int y, char color, char remember)
{
    if (!isPixelValid(x, y))
        return;
    if (getPixelColor(x, y) == color)
        return;
    setPixelColor(x, y, color);
    if (getPixelColor(x - 1, y) == remember)
        fillRegion(x - 1, y, color, remember);
    if (getPixelColor(x + 1, y) == remember)
        fillRegion(x + 1, y, color, remember);
    if (getPixelColor(x, y - 1) == remember)
        fillRegion(x, y - 1, color, remember);
    if (getPixelColor(x, y + 1) == remember)
        fillRegion(x, y + 1, color, remember);
}
int main()
{
    int i, j, x, y, z;
    char c = '\0', color, remember;
    while (c != 'X')
    {
        scanf("%c", &c);
        switch (c)
        {
        case 'I':
        {
            scanf("%d %d", &M, &N);
            if (N > 250 || M > 250)
                printf("N and M are dimensions and have to be between 1 and 250");
            matrix = (char **)malloc(N * sizeof(char *));
            for (i = 0; i < N; i++)
            {
                matrix[i] = (char *)malloc(M * sizeof(char));
            }
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
            scanf("%d %d %c", &x, &y, &color);
            setPixelColor(y - 1, x - 1, color);
        }
        break;

        case 'V':
        {
            scanf("%d %d %d %c", &x, &y, &z, &color);
            for (i = y - 1; i <= z - 1; i++)
            {
                setPixelColor(i, x - 1, color);
            }
        }
        break;

        case 'H':
        {
            scanf("%d %d %d %c", &x, &y, &z, &color);
            for (i = x - 1; i <= y - 1; i++)
            {
                setPixelColor(z - 1, i, color);
            }
        }
        break;

        case 'F':
        {
            scanf("%d %d %c", &x, &y, &color);
            remember = getPixelColor(y - 1, x - 1);
            fillRegion(y - 1, x - 1, color, remember);
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
