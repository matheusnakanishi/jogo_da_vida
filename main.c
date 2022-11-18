#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    arq = fopen("quadro.txt","r");

    char matriz[30][30];
    //char **bordas;

    // bordas = (char**)calloc(32, sizeof(char*));
    // for(int i = 0; i < 32; i++)
    //     bordas[i] = (char *)calloc(32, sizeof(char));

    // //criando uma matriz nula com borda para matriz principal
    // for (int i = 0; i < 32; i++)
    // {
    //     for (int j = 0; j < 32; j++)
    //     {
    //         bordas[i][j] = '0';
    //     }
        
    // }
    


    int vizinhos = 0;
    //lendo matriz principal pelo arquivo txt
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            fscanf(arq,"%c\n", &matriz[i][j]);
        }
        
    }
    //imprimindo matriz principal
    for(int i = 0; i < 30; i++)
    {    for (int j = 0; j < 30; j++)
        {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }    
    printf("\n\n");
    
    // //anexando matriz principal na matriz com bordas
    // for(int i = 1; i < 31; i++)
    // {    for (int j = 1; j < 31; j++)
    //     {
    //         bordas[i][j] = matriz[i-1][j-1];
    //     }
    // }  

    //imprimindo matriz apos anexar
    // for(int i = 0; i < 32; i++)
    // {    for (int j = 0; j < 32; j++)
    //     {
    //         printf("%c ", bordas[i][j]);
    //     }
    //     printf("\n");
    // }    
    
    //primeira geração
    // for (int i = 0; i < 30; i++)
    // {
    //     for (int j = 0; j < 30; j++)
    //     {
    //         printf("%c ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }
    
    while(1)
    {
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {   //contador de vizinhos
                    vizinhos = 0;
                    if (matriz[i-1][j-1] == '1')
                    {
                        vizinhos += 1;
                    }else
                    if (matriz[i-1][j] == '1')
                    {
                        vizinhos += 1;
                    }else
                    if (matriz[i-1][j+1] == '1')
                    {
                        vizinhos += 1;
                    }else
                    if (matriz[i][j-1] == '1')
                    {
                        vizinhos += 1;
                    }else
                    if (matriz[i+1][j-1] == '1')
                    {
                        vizinhos += 1;
                    }else
                    if (matriz[i+1][j] == '1')
                    {
                        vizinhos += 1;
                    }else
                    if (matriz[i+1][j+1] == '1')
                    {
                        vizinhos += 1;
                    }else
                    if (matriz[i][j+1] == '1')
                    {
                        vizinhos += 1;
                    }
                    
                    
                    if (matriz[i][j] == '1' && vizinhos < 2)
                    {
                        matriz[i][j] = '0';
                    }
                    else
                    {
                        if (matriz[i][j] == '1' && vizinhos > 3)
                        {
                            matriz[i][j] = '0';
                        }
                        else
                        {
                            if (matriz[i][j] == '1' && (vizinhos == 2 || vizinhos == 3))
                            {
                                matriz[i][j] = '1';
                            }
                            else
                            {
                                if (matriz[i][j] == '0' && vizinhos == 3)
                                {
                                    matriz[i][j] = '1';
                                }
                                
                            }
                            
                        }
                    }

                    
                
            }
        }
        system("cls");

                    for (int i = 0; i < 30; i++)
                    {
                        for (int j = 0; j < 30; j++)
                        {
                            printf("%c ", matriz[i][j]);
                        }
                        printf("\n");
                    }
    }    

    return 0;
}