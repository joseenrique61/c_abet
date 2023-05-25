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

void imprimirCantidadEstudiantesPorAnio(int **matrizEstudiantes)
{
    printf("\nNumero de estudiantes ingresados por anio: \n");

    int *numeroEstudiantesPorAnio = numeroDeEstudiantesPorAnio(matrizEstudiantes);

    for (int i = 0; i < 5; i++)
    {
        printf("Anio %i: %i\n", i + 1, numeroEstudiantesPorAnio[i]);
    }
}

int mayorCantidadUltimoAnio(int **matrizEstudiantes)
{
    int mayor = 0;
    int mayorIndice = 0;

    for (int i = 0; i < 7; i++)
    {
        if (matrizEstudiantes[9][i] > mayor)
        {
            mayor = matrizEstudiantes[9][i];
            mayorIndice = i;
        }
    }
    return mayorIndice;
}

void imprimirMayorCantidadUltimoAnio(int **matrizEstudiantes)
{
    int mayorCantidadDeEstudiantes = mayorCantidadUltimoAnio(matrizEstudiantes);
    printf("\nLa carrera con la mayor cantidad de estudiantes ingresados el ultimo anio es: ", mayorCantidadDeEstudiantes);

    switch (mayorCantidadDeEstudiantes)
    {
    case 0:
        printf("Ingenieria de Software");
        break;

    case 1:
        printf("Administracion");
        break;

    case 2:
        printf("Economia");
        break;

    case 3:
        printf("Relaciones Internacionales");
        break;

    case 4:
        printf("Matematicas");
        break;

    case 5:
        printf("Contabilidad");
        break;

    case 6:
        printf("Ingenieria Industrial");
        break;

    default:
        break;
    }
}

int **crearMatriz() 
{
    // Se define una matriz que contenga 10 semestres y 7 carreras.
    int **estudiantesCarreraSemestre = calloc(10, sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        estudiantesCarreraSemestre[i] = calloc(7, sizeof(int));
    }

    // Se le asignan números aleatorios a la matriz
    printf("Cantidad de estudiantes por semestres y carreras (filas = semestres, columnas = carreras): \n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            estudiantesCarreraSemestre[i][j] = rand() % 101;
            printf("%i ", estudiantesCarreraSemestre[i][j]);
        }
        printf("\n");
    }

    return estudiantesCarreraSemestre;
}

int main()
{
    // Se asigna una semilla aleatoria
    srand(time(NULL));

    int **matrizEstudiantes = crearMatriz();

    imprimirCantidadEstudiantesPorAnio(matrizEstudiantes);

    imprimirMayorCantidadUltimoAnio(matrizEstudiantes);
}
