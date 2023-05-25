// Se incluyen las librerías a usar: stdio.h para imprimir datos, time.h para asignar la semilla a rand(), y stdlib.h para definir los arreglos como punteros.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **crearMatriz()
{
    // Se define una matriz que contenga 10 semestres y 7 carreras, todo inicializado en ceros.
    int **estudiantesCarreraSemestre = calloc(10, sizeof(int *));
    for (int i = 0; i < 10; i++)
    {
        estudiantesCarreraSemestre[i] = calloc(7, sizeof(int));
    }

    printf("\nCantidad de estudiantes por semestres y carreras (filas = semestres, columnas = carreras): \n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            // Se le asignan números aleatorios entre el 0 y el 100 a la matriz
            estudiantesCarreraSemestre[i][j] = rand() % 101;
            
            // Se imprime la matriz. Los condicionales le dan formato, para que se vea más estético. Al usar la terminal una fuente monoespaciada, se pueden colocar espacios para que los elementos queden separados en una forma similar a una cuadrícula
            printf("%i  ", estudiantesCarreraSemestre[i][j]);

            if (estudiantesCarreraSemestre[i][j] >= 10 && estudiantesCarreraSemestre[i][j] < 100)
            {
                printf(" ");
            }
            else if (estudiantesCarreraSemestre[i][j] < 10)
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    return estudiantesCarreraSemestre;
}

// Función que obtiene la cantidad de estudiantes ingresados por año
int *numeroDeEstudiantesPorAnio(int **matrizEstudiantes)
{
    // Se define un arreglo de 5 espacios, inicializado en ceros
    int *numeroDeEstudiantes = calloc(5, sizeof(int));

    // La variable del primer ciclo se usa para asignar valores a la matriz numeroDeEstudiantes. Representa los años.
    for (int k = 0; k < 5; k++)
    {
        // La variable del segundo ciclo define los semestres por los que se va a iterar. Se define como 2 * el iterador k, y tiene que ser menor 2 * (k + 1), de tal forma que itere por todos los semestres por separado, en función del año.
        for (int i = 2 * k; i < 2 * (k + 1); i++)
        {
            //La variable del tercer ciclo se usa para iterar por las carreras.
            for (int j = 0; j < 7; j++)
            {
                // Se le suma a numeroDeEstudiantes cada estudiante en los respectivos años.
                numeroDeEstudiantes[k] += matrizEstudiantes[i][j];
            }
        }
    }

    return numeroDeEstudiantes;
}

// Función que imprime la cantidad de estudiantes ingresados por año
void imprimirCantidadEstudiantesPorAnio(int **matrizEstudiantes)
{
    printf("\nNumero de estudiantes ingresados por anio: \n");

    int *numeroEstudiantesPorAnio = numeroDeEstudiantesPorAnio(matrizEstudiantes);

    for (int i = 0; i < 5; i++)
    {
        printf("Anio %i: %i\n", i + 1, numeroEstudiantesPorAnio[i]);
    }
    printf("\n");

    // Se libera la memoria ocupada por numeroEstudiantesPorAño
    free(numeroEstudiantesPorAnio);
}

// Función que obtiene la carrera con la mayor cantidad de estudiantes ingresados en el último año
int mayorCantidadUltimoAnio(int **matrizEstudiantes)
{
    int mayor = 0;
    int mayorIndice = 0;

    for (int i = 0; i < 7; i++)
    {
        // Se itera por todas las carreras en el último año, y se le asigna su índice a la variable mayorIndice, para obtener la carrera con mayor ingreso.
        if (matrizEstudiantes[9][i] > mayor)
        {
            mayor = matrizEstudiantes[9][i];
            mayorIndice = i;
        }
    }
    return mayorIndice;
}

// Función que imprime la carrera con la mayor cantidad de estudiantes ingresados en el último año
void imprimirMayorCantidadUltimoAnio(int **matrizEstudiantes)
{
    int mayorCantidadDeEstudiantes = mayorCantidadUltimoAnio(matrizEstudiantes);
    printf("La carrera con la mayor cantidad de estudiantes ingresados el ultimo anio es: ", mayorCantidadDeEstudiantes);

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

    printf("\n\n");
}

// Función que calcula en qué año ingresó la mayor cantidad de estudiantes a la carrera de Ingeniería de Software
int anioMayorCantidadSoftware(int **matrizEstudiantes)
{
    int mayor = 0;
    int mayorIndice = 0;

    for (int i = 0; i < 10; i++)
    {
        // Se itera por los semestres en la primera carrera (Ing. Software), y se asigna el índice del mayor para obtener el semestre de mayor ingreso.
        if (matrizEstudiantes[i][0] > mayor)
        {
            mayor = matrizEstudiantes[i][0];
            mayorIndice = i;
        }
    }

    // Se calcula el año respectivo al semestre y se retorna
    mayorIndice++;

    if (mayorIndice % 2 == 0)
    {
        mayorIndice /= 2;
    }
    else
    {
        mayorIndice = (mayorIndice / 2) + 1;
    }

    return mayorIndice;
}

// Función que imprime el año con la mayor cantidad de estudiantes ingresados en Ingeniería de Software
void imprimirAnioMayorCantidadSoftware(int **matrizEstudiantes)
{
    int mayor = anioMayorCantidadSoftware(matrizEstudiantes);

    printf("El anio con mayor cantidad de estudiantes en Ingenieria en Software es: %i\n", mayor);
}

int main()
{
    // Se asigna una semilla aleatoria
    srand(time(NULL));
    
    // Se crea la matriz con estudiantes por semestre y carrera
    int **matrizEstudiantes = crearMatriz();
    
    // Inciso a: El año en que ingresó la mayor cantidad de alumnos de la universidad.
    imprimirCantidadEstudiantesPorAnio(matrizEstudiantes);

    // Inciso b: La carrera que recibió la mayor cantidad de alumnos en el último año.
    imprimirMayorCantidadUltimoAnio(matrizEstudiantes);

    // Inciso c: ¿En qué año la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos?
    imprimirAnioMayorCantidadSoftware(matrizEstudiantes);

    // Se libera la memoria ocupada por matrizEstudiantes
    free(matrizEstudiantes);
}
