// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
//-----EJERCICIO 1-----
#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(const int a[], int izq, int der, int x) {
    if (izq > der) {
        return -1;//Vacio
    }
    int mitad = izq + (der - izq) / 2;
    if (a[mitad] == x) {
        return mitad;
    }
    if (x < a[mitad]) {
        return busqueda_binaria(a, izq, mitad - 1, x);//Buscar en lado izquierdo
    } else {
        return busqueda_binaria(a, mitad + 1, der, x);//Buscar en lado derecho
    }
}

//Comprobar que el arreglo este ordenado de menor a mayor
int arreglo_Ordenado(const int a[], int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            return 0; //No ordenado
        }
    }
    return 1; //Ordenado
}

int main(void) {
    int n; //Tamaño del arreglo
    int *arreglo = NULL; //Arreglo de enteros
    int x; //Numero a buscar
    int leidos; //Validar lecturas
    printf("Ingresa el tamano del arreglo: ");
    leidos = scanf("%d", &n);
    if (leidos != 1 || n <= 0) {
        printf("Entrada invalida para n\n");
        return 0;
    }
    arreglo = (int*)malloc(sizeof(int) * n);
    if (arreglo == NULL) {
        printf("No se pudo reservar memoria\n");
        return 0;
    }
    printf("Ingresa %d enteros ordenados de menor a mayor: ", n);
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arreglo[i]) != 1) {
            printf("Error, entrada invalida :(\n");
            free(arreglo);
            return 0;
        }
    }
    if (!arreglo_Ordenado(arreglo, n)) {
        printf("El arreglo no esta ordenado de menor a mayor :(\n");
        return 0;
    }

    printf("Ingresa el numero a buscar: ");
    if (scanf("%d", &x) != 1) {
        printf("Error , entrada invalida :(\n");
        free(arreglo);
        return 0;
    }
    int indice = busqueda_binaria(arreglo, 0, n - 1, x);
    if (indice >= 0) {
        printf("El numero %d si se encuentra en el arreglo :)\n", x);
        printf("Indice en el arreglo: %d\n", indice);
        printf("Es el elemento #%d del arreglo\n", indice + 1);
    } else {
        printf("El numero %d no se encuentra en el arreglo\n", x);
    }
    free(arreglo);
    return 0;
}

/*Ejemplo de entrada y salida
Ingresa el tamano del arreglo: 5
Ingresa 5 enteros ordenados de menor a mayor: 2 5 7 9 39
Ingresa el numero a buscar: 2
El numero 2 si se encuentra en el arreglo :)
Indice en el arreglo: 0
Es el elemento #1 del arreglo
*/

//-----EJERCICIO 2-----
#include <stdio.h>

//Busqueda binaria
void codigo_binario(double x, int k, double izq, double der) {
    if (k <= 0) return; //En caso de que se pidan 0 pasos
    double mitad = (izq + der) / 2.0;
    if (x < mitad) {
        putchar('0');//x esta en la izquierda
        codigo_binario(x, k - 1, izq, mitad);
    } else {
        putchar('1'); //x esta en la derecha
        codigo_binario(x, k - 1, mitad, der);
    }
}

int main(void) {
    double x; //Numero real
    int k; //Pasos a realizar

    printf("Ingresa x en [0,1) y el numero de pasos k: ");
    if (scanf("%lf %d", &x, &k) != 2) {
        printf("Entrada invalida.\n");
        return 0;
    }
    if (!(x >= 0.0 && x < 1.0) || k < 0) {
        printf("Error, X debe de estar entre 0 y 1 y k debe ser entera postiva :(\n");
        return 0;
    }
    printf("%lf en binario es aproximadamente: ", x);
    codigo_binario(x, k, 0.0, 1.0);
    putchar('\n');
    return 0;
}

/*Ejemplo de entrada y salida
Ingresa x en [0,1) y el numero de pasos k: 0.777 5
11000
*/
