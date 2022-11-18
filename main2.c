#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Funções
void imprimir(char **matriz, int inicio, int fim);
int contar_vizinhos(char **matriz, int x, int y);

int main(int argc, char **argv)
{
    //Declaração devariáveis
    char matriz[30][30];
    char **borda;
    int i, j;
    int k = 0;
    int vizinhos = 0;
    int geracoes = atoi(argv[1]);

    //Arquivo txt
    FILE *arq;
    arq = fopen("quadro.txt","r");

    //Lendo Matriz do arquivo
    for (i = 0; i < 30; i++)
    {
        for (j = 0; j < 30; j++)
        {
            fscanf(arq,"%c\n", &matriz[i][j]);
        }  
    }

    //Alocando uma Matriz
    borda = (char**)calloc(32, sizeof(char *));
    for (i = 0; i < 32; i++)
    {
        borda[i] = (char *)calloc(32, sizeof(char ));
    }

    //Preenchendo uma Matriz Nula 32x32
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 32; j++)
        {
            borda[i][j] = '0';
        }
    }

    //Anexando a Matriz Principal com a Matriz Nula para adicionar uma borda
    for (i = 1; i < 31; i++)
    {    for (j = 1; j < 31; j++)
        {
            borda[i][j] = matriz[i-1][j-1];
        }
    }  

    //Imprimindo a Matriz
    imprimir(borda,1,31);

    while (k < geracoes)
    {
        for (i = 1; i < 31; i++)
        {
            for (j = 1; j < 31; j++)
            {
                vizinhos = contar_vizinhos(borda,i,j);

                //Criar outra matriz para aplicar as alteraçoes

                if (borda[i][j] == '1' && vizinhos < 2)
                {
                    matriz[i-1][j-1] = '0';
                }
                else
                {
                    if (borda[i][j] == '1' && vizinhos > 3)
                    {
                        matriz[i-1][j-1] = '0';
                    }
                    else
                    {
                        if (borda[i][j] == '1' && (vizinhos == 2 || vizinhos == 3))
                        {
                            matriz[i-1][j-1] = '1';
                        }
                        else
                        {
                            if (borda[i][j] == '0' && vizinhos == 3)
                            {
                                matriz[i-1][j-1] = '1';
                            }                    
                        }    
                    }
                }
            }
        }

        //criar funcao para copia de matriz;
        for (i = 1; i < 31; i++)
        {    
            for (j = 1; j < 31; j++)
            {
            borda[i][j] = matriz[i-1][j-1];
            }
        }  

        system("pause");
        system("cls");

        imprimir(borda,1,31);
        k++;
    }

    return 0;
}

void imprimir(char **matriz, int inicio, int fim)
{
    for (int i = inicio; i < fim; i++)
    {
        for (int j = inicio; j < fim; j++)
        {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int contar_vizinhos(char **matriz, int x, int y)
{
    int vizinhos = 0;

    if (matriz[x-1][y-1] == '1')
    {
        vizinhos += 1;
    }
    if (matriz[x-1][y] == '1')
    {
        vizinhos += 1;
    }
    if (matriz[x-1][y+1] == '1')
    {
        vizinhos += 1;
    }
    if (matriz[x][y-1] == '1')
    {
        vizinhos += 1;
    }
    if (matriz[x+1][y-1] == '1')
    {
        vizinhos += 1;
    }
    if (matriz[x+1][y] == '1')
    {
        vizinhos += 1;
    }
    if (matriz[x+1][y+1] == '1')
    {
        vizinhos += 1;
    }
    if (matriz[x][y+1] == '1')
    {
        vizinhos += 1;
    }

    return vizinhos;
}

