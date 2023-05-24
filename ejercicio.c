#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *numeroDeEstudiantesPorAnio(int **matrizEstudiantes)
{
    int *numeroDeEstudiantes = calloc(5, sizeof(int));
    for (int k = 0; k < 5; k++)
    {
        for (int i = 2 * k; i < 2 * (k + 1); i++)
        {
            for (int j = 0; j < 7; j++)
            {
                numeroDeEstudiantes[k] += matrizEstudiantes[i][j];
            }
        }
    }
    
    return numeroDeEstudiantes;
}

int main()
{
    // Se asigna una semilla aleatoria
    srand(time(NULL));

    // Se define una matriz que contenga 10 semestres y 7 carreras.
    int **estudiantesCarreraSemestre = calloc(10, sizeof(int*));
    for (int i = 0; i < 10; i++) {
        estudiantesCarreraSemestre[i] = calloc(7, sizeof(int));
    }

        // Se le asignan números aleatorios a la matriz
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                estudiantesCarreraSemestre[i][j] = rand() % 101;
                printf("%i ", estudiantesCarreraSemestre[i][j]);
            }
            printf("\n");
        }

    printf("\nNumero de estudiantes ingresados por anio: \n");

    int *numeroEstudiantesPorAnio = numeroDeEstudiantesPorAnio(estudiantesCarreraSemestre);

    for (int i = 0; i < 5; i++){
        printf("Anio %i: %i\n", i + 1, numeroEstudiantesPorAnio[i]);
    }
}
