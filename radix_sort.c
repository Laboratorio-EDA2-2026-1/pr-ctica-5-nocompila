#include <stdio.h>

// obtener el número máximo de un arreglo
int obtenerMaximo(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting Sort 
void countingSort(int A[], int n, int exp) {
    // exp = 1 (unidades), 10 (decenas), 100 (centenas)
    int B[n];    // arreglo auxiliar para guardar el resultado             
    int C[10];     // para contar cuántos dígitos hay (0 al 9)           

   // Llenamos C con ceros
    for (int i = 0; i < 10; i++) {
        C[i] = 0;
    }

 // Contamos cuántos números tienen el mismo dígito en la posición actual
    for (int i = 0; i < n; i++) {
        int digito = (A[i] / exp) % 10;
        C[digito] = C[digito] + 1;
    }

// Acumulamos los conteos
    for (int i = 1; i < 10; i++) {
        C[i] = C[i] + C[i - 1];
    }
// Construimos el arreglo de salida B de derecha a izquierda
    for (int j = n - 1; j >= 0; j--) {
        int digito = (A[j] / exp) % 10;
        B[C[digito] - 1] = A[j];
        C[digito] = C[digito] - 1;
    }

// Copiamos lo que quedó en B a A
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

// Radix Sort 
void radixSort(int arr[], int n) {
    int max = obtenerMaximo(arr, n);

    // Ordenar por cada dígito 
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

// Imprimir arreglo
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingrese los %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArreglo original:\n");
    imprimirArreglo(arr, n);

    radixSort(arr, n);

    printf("\nArreglo ordenado:\n");
    imprimirArreglo(arr, n);

    return 0;
}
/*Corrida del codigo 
Entrada........
Ingrese la cantidad de elementos: 6
Ingrese los 6 numeros:
Numero 1: 170
Numero 2: 45
Numero 3: 75
Numero 4: 90
Numero 5: 802
Numero 6: 24
Salida....
Arreglo original:
170 45 75 90 802 24 

Arreglo ordenado:
24 45 75 90 170 802 

*/
