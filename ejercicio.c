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
        }
    }

    return estudiantesCarreraSemestre;
}

// Función creada para imprimir la matriz
void imprimirMatriz(int **estudiantesCarreraSemestre)
{
    // Se imprimen las carreras, con el formato ya aplicado.
    printf("             ");
    for (int i = 0; i < 7; i++)
    {
        switch (i)
        {
        case 0:
            printf("IS");
            break;

        case 1:
            printf("Ad");
            break;

        case 2:
            printf("Ec");
            break;

        case 3:
            printf("RI");
            break;

        case 4:
            printf("Ma");
            break;

        case 5:
            printf("Co");
            break;

        case 6:
            printf("II");
            break;

        default:
            break;
        }
        printf("   ");
    }
    printf("\n");

    // Se imprime la matriz. Los condicionales le dan formato, para que se vea más estético. Al usar la terminal una fuente monoespaciada, se pueden colocar espacios para que los elementos queden separados en una forma similar a una cuadrícula
    for (int i = 0; i < 10; i++)
    {
        printf("Semestre %i: ", i + 1);
        if (i < 9)
        {
            printf(" ");
        }

        for (int j = 0; j < 7; j++)
        {

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
}

// Función que obtiene el año con mayor ingreso de todas las carreras
int anioMayorIngreso(int **matrizEstudiantes)
{
    int mayor = 0;
    int mayorIndice = 0;

    // La variable del primer ciclo se usa para definir la variable del segundo ciclo y asignar el mayorIndice. Representa los años.
    for (int k = 0; k < 5; k++)
    {
        int suma = 0;
        // La variable del segundo ciclo define los semestres por los que se va a iterar. Se define como 2 * el iterador k, y tiene que ser menor que 2 * (k + 1), de tal forma que itere por todos los semestres por separado, en función del año.
        for (int i = 2 * k; i < 2 * (k + 1); i++)
        {
            // La variable del tercer ciclo se usa para iterar por las carreras.
            for (int j = 0; j < 7; j++)
            {
                // Se suma la cantidad de estudiantes por año.
                suma += matrizEstudiantes[i][j];
            }
        }
        
        // Se evalúa si la suma de los semestres es mayor a la variable "mayor", si es así, se le asigna su valor a la variable, y el año actual a mayorIndice.
        if (suma > mayor)
        {
            mayor = suma;
            mayorIndice = k;
        }
    }

    return mayorIndice;
}

// Función que imprime el año con mayor ingreso de todas las carreras
void imprimirAnioMayorIngreso(int **matrizEstudiantes)
{
    int mayor = anioMayorIngreso(matrizEstudiantes);
    printf("\nAnio con mayor ingreso de estudiantes: %i\n\n", mayor + 1);
}

// Función que obtiene la carrera con la mayor cantidad de estudiantes ingresados en el último año
int mayorCantidadUltimoAnio(int **matrizEstudiantes)
{
    int mayor = 0;
    int mayorIndice = 0;

    for (int i = 0; i < 7; i++)
    {
        // Se define la variable suma, que tiene la suma de estudiantes de cada carrera en los últimos dos semestres, para obtener los estudiantes por año de la carrera.
        int suma = matrizEstudiantes[8][i] + matrizEstudiantes[9][i];

        if (suma > mayor)
        {
            mayor = suma;
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
    int suma = 0;

    // La variable del primer ciclo se usa para definir la variable del segundo ciclo, y para asignar el mayorIndice. Representa los años.
    for (int k = 0; k < 5; k++)
    {
        for (int i = 2 * k; i < 2 * (k + 1); i++)
        {
            suma += matrizEstudiantes[i][0];
        }

        // Se evalúa si la suma de los semestres es mayor a la variable "mayor", si es así, se le asigna su valor a la variable, y el año actual a mayorIndice.
        if (suma > mayor)
        {
            mayor = suma;
            mayorIndice = k;
        }
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

    // Se imprime la matriz
    imprimirMatriz(matrizEstudiantes);

    // Inciso a: El año en que ingresó la mayor cantidad de alumnos de la universidad.
    imprimirAnioMayorIngreso(matrizEstudiantes);

    // Inciso b: La carrera que recibió la mayor cantidad de alumnos en el último año.
    imprimirMayorCantidadUltimoAnio(matrizEstudiantes);

    // Inciso c: ¿En qué año la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos?
    imprimirAnioMayorCantidadSoftware(matrizEstudiantes);

    // Se libera la memoria ocupada por matrizEstudiantes
    free(matrizEstudiantes);
}
