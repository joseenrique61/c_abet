#include <stdio.h>
#include <time.h>

int main()
{
    // Se asigna una semilla aleatoria
    srand(time(NULL));

    //Se define una matriz que contenga 10 semestres y 7 carreras.
    int estudiantesCarreraSemestre[10][7];

    //Se le asignan números aleatorios a la matriz
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            estudiantesCarreraSemestre[i][j] = rand() % 101;
            printf("%i ", estudiantesCarreraSemestre[i][j]);
        }
        printf("\n");
    }
}