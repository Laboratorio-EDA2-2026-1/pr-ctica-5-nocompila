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
    int B[n];                 
    int C[10];                

   
    for (int i = 0; i < 10; i++) {
        C[i] = 0;
    }

 
    for (int i = 0; i < n; i++) {
        int digito = (A[i] / exp) % 10;
        C[digito] = C[digito] + 1;
    }


    for (int i = 1; i < 10; i++) {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        int digito = (A[j] / exp) % 10;
        B[C[digito] - 1] = A[j];
        C[digito] = C[digito] - 1;
    }


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

