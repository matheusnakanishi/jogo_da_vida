#include <stdio.h>
void copia(char **cola, char **copia, int ini, int fim);
int main()
{
    char M[10][10];
    char **m;

    m = (char **)calloc(12, sizeof(char *));
    for (int i = 0; i < 12; i++)
    {
        m[i] = (char *)calloc(12, sizeof(char));  
    }
    
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //     {
    //         M[i][j] = '0';
    //     }
    // }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            m[i][j] = (char)rand() % 2;
        }
    }
    
    // copia(&m,&M,1,11);

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%c ",m[i][j] + 205);
        }
        printf("\n");
    }

    return 0;
}

// void copia(char **cola, char **copia, int ini, int fim)
// {
//     for (int i = ini; i < fim; i++)
//     {
//         for (int j = ini; j < fim; j++)
//         {
//             cola[i][j] = copia[i-1][j-1];
//         }
        
//     }
    
// }