// Escribe aquí la implementación de los ejercicios de búsqueda lineal.
//Ejercicio 1 —------------------------------------------------------------------------------------------
#include <stdio.h>

// Función para la búsqueda lineal
int busquedaLineal(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor) {
            return i; // devuelve la posición donde se encontró
        }
    }
    return -1; // si no se encuentra
}

// Función para imprimir el arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, valor, posicion;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];

    printf("Ingrese los %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    printf("\nEl arreglo ingresado es:\n");
    imprimirArreglo(arr, n);

    // Pedir el valor a buscar
    printf("\nIngrese el valor a buscar: ");
    scanf("%d", &valor);

    posicion = busquedaLineal(arr, n, valor);

    if (posicion != -1) {
        printf("El valor %d se encontro en la posicion %d (indice %d)\n", valor, posicion + 1, posicion);
    } else {
        printf("El valor %d no se encontro en el arreglo.\n", valor);
    }

    return 0;
}


/*Ejemplo de entrada y salida 

Ingrese la cantidad de elementos: 5
Ingrese los 5 numeros:
Numero 1: 5
Numero 2: 10
Numero 3: 20
Numero 4: 37
Numero 5: 50

El arreglo ingresado es:
5 10 20 37 50 

Ingrese el valor a buscar: 20
El valor 20 se encontró en la posicion 3 (indice 2)
*/

//Ejercicio 2 —---------------------------------------------------------------------------------------------------

#include <stdio.h>

// Función de búsqueda lineal mejorada
int busquedaLinealMejorada(int arr[], int n, int valor) {
    int i = 0;
    int encontrado = 0;  // bandera

    while (i < n && encontrado == 0) {
        if (arr[i] == valor) {
            encontrado = 1; // lo encontró
        } else {
            i++;
        }
    }

    if (encontrado == 1) {
        return i; // posición donde lo encontró
    } else {
        return -1; // no encontrado
    }
}

// Función para imprimir arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, valor, posicion;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];

    printf("Ingrese los %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEl arreglo ingresado es:\n");
    imprimirArreglo(arr, n);

    printf("\nIngrese el valor a buscar: ");
    scanf("%d", &valor);

    posicion = busquedaLinealMejorada(arr, n, valor);

    if (posicion != -1) {
        printf("El valor %d se encontro en la posicion %d (indice %d)\n", valor, posicion + 1, posicion);
    } else {
        printf("El valor %d no se encontro en el arreglo.\n", valor);
    }

    return 0;
}

/*Corrida 

Ingrese la cantidad de elementos: 6
Ingrese los 6 numeros:
Numero 1: 9
Numero 2: 0
Numero 3: 56
Numero 4: 8
Numero 5: 43
Numero 6: 5

El arreglo ingresado es:
9 0 56 8 43 5 

Ingrese el valor a buscar: 8
El valor 8 se encontro en la posicion 4 (indice 3)
*/


//Ejercicio 3—--------------------------------------------------------------------------------------------------------
#include <stdio.h>

// Función recursiva de búsqueda lineal
int busquedaLinealRecursiva(int arr[], int n, int valor, int i) {
    if (i >= n) {
        return -1; //  se acabó el arreglo
    }
    if (arr[i] == valor) {
        return i; // encontrado
    }
    // llamada recursiva con el siguiente índice
    return busquedaLinealRecursiva(arr, n, valor, i + 1);
}

// Función para imprimir arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, valor, posicion;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];

    printf("Ingrese los %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEl arreglo ingresado es:\n");
    imprimirArreglo(arr, n);

    printf("\nIngrese el valor a buscar: ");
    scanf("%d", &valor);

    posicion = busquedaLinealRecursiva(arr, n, valor, 0);

    if (posicion != -1) {
        printf("El valor %d se encontro en la posicion %d (indice %d)\n", valor, posicion + 1, posicion);
    } else {
        printf("El valor %d no se encontro en el arreglo.\n", valor);
    }

    return 0;
}

/*Corrida 

Ingrese la cantidad de elementos: 4
Ingrese los 4 numeros:
Numero 1: 1
Numero 2: 9
Numero 3: 34
Numero 4: 5


El arreglo ingresado es:
1 9 34 5 

Ingrese el valor a buscar: 9
El valor 9 se encontró en la posicion 2 (indice 1)
*/

//Ejercicio 4 ---------------------------------------------------------------------------------------------------------
#include <stdio.h>

// Función de búsqueda lineal con centinela
int busquedaLinealCentinela(int arr[], int n, int valor) {
    int ultimo = arr[n - 1];   // guardar el último valor
    arr[n - 1] = valor;        // colocar el centinela

    int i = 0;
    while (arr[i] != valor) {  // ya no se revisa i < n
        i++;
    }

    arr[n - 1] = ultimo; // restaurar el último valor original

    if (i < n - 1 || arr[n - 1] == valor) {
        return i; // encontrado dentro del arreglo original
    } else {
        return -1; // no encontrado
    }
}

// Función para imprimir arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, valor, posicion;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];

    printf("Ingrese los %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nEl arreglo ingresado es:\n");
    imprimirArreglo(arr, n);

    printf("\nIngrese el valor a buscar: ");
    scanf("%d", &valor);

    posicion = busquedaLinealCentinela(arr, n, valor);

    if (posicion != -1) {
        printf("El valor %d se encontro en la posicion %d (indice %d)\n", valor, posicion + 1, posicion);
    } else {
        printf("El valor %d no se encontro en el arreglo.\n", valor);
    }

    return 0;
}

/*Corrida 

Ingrese la cantidad de elementos: 6
Ingrese los 6 numeros:
Numero 1: 15
Numero 2: 7
Numero 3: 22
Numero 4: 5
Numero 5: 30
Numero 6: 10

El arreglo ingresado es:
15 7 22 5 30 10 

Ingrese el valor a buscar: 5
El valor 5 se encontro en la posicion 4 (indice 3)
*/





