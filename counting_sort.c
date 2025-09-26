//-----EJERCICIO 1-----

#include <stdio.h>
#define MAXN 10000  //Tamaño de la cadena

//counting_sort, 1 si se ordeno la cadena, 0 si fallo
int counting_sort(char s[]) {
    int conteo[26] = {0};

    //Iniciacion de los indices
    int i = 0;
    int j = 0;
    int idx = 0;

    //Recorrer la cadena y validacion de caracteres
    while (s[i] != '\0') {
        if (s[i] < 'a') {
            return 0;
        }
        if (s[i] > 'z') {
            return 0;
        }
        //Conteo
        conteo[(int)(s[i] - 'a')] = conteo[(int)(s[i] - 'a')] + 1;
        i = i + 1;
    }

    //Construccion de la cadena
    i = 0;
    while (i < 26) {
        j = 0;
        while (j < conteo[i]) {
            s[idx] = (char)('a' + i);
            idx = idx + 1;
            j = j + 1;
        }
        i = i + 1;
    }
    //Fin de la cadena
    s[idx] = '\0';
    return 1;
}

int main(void) {
    char s[MAXN]; //Cadena
    char *read_ptr;//Guarda el resultado de fgets para comprobar exito o fracaso
    int i;
    int funciona; //Guarda el valor de retorno de counting_sort (1 exito, 0 error)

    printf("Ingresa la cadena a ordenar: ");
    read_ptr = fgets(s, sizeof(s), stdin);
    if (read_ptr == NULL) {
        return 0;
    }
    i = 0; //Eliminar salto de linea
    while (s[i] != '\0') {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
        i = i + 1;
    }

    funciona  = counting_sort(s);
    if (funciona == 0) {
        //Validacion de la cadena
        fputs("Error, solo se permiten letras minusculas a-z :(\n", stderr);
        return 0;
    }
    //Resultado
    printf("Cadena ordenada: ");
    puts(s);

    return 0;
}

/* Ejemplo de entrada y salida 

Ingresa la cadena a ordenar: ajshdncbgetrs

Cadena ordenada: abcdeghjnrsst 
*/


//-----EJERCICIO 2-----
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Convertir la cadena a minusculas para facilitar su lectura
static void minusculas(char *s) {
    for ( ; *s; ++s) {
        *s = (char)tolower((unsigned char)*s);
    }
}

//Colores a enteros
static int color_Entero(char *txt) {
    minusculas(txt);
    if (strcmp(txt, "rojo") == 0)   return 0;
    if (strcmp(txt, "blanco") == 0) return 1;
    if (strcmp(txt, "azul") == 0)   return 2;
    return -1;//Texto invalido
}

//Enteros a numeros
static const char* entero_Color(int id) {
    if (id == 0) {
        return "rojo";
    }
    else if (id == 1) {
        return "blanco";
    }
    else {
        return "azul";
    }
}

void counting_sort(int A[], int n) {
    int C[3]; //Conteos
    int tamañoB = n; //Tamaño del arreglo B
    int i = 0;
    int j = 0;
    int k = 0;

    //Conteos
    for (i = 0; i < 3; ++i) {
        C[i] = 0;
    }
    for (i = 0; i < n; ++i) {
        k = A[i];
        C[k] = C[k] + 1;
    }
    for (i = 1; i < 3; ++i) {
        C[i] = C[i] + C[i - 1];
    }

    //Ordenar Arreglo usando arreglo B
    int B[tamañoB];
    for (j = n - 1; j >= 0; --j) {
        k = A[j];
        int posicion = C[k] - 1;
        B[posicion] = k;
        C[k] = C[k] - 1;
    }
    for (i = 0; i < n; ++i) {
        A[i] = B[i];
    }
}

int main(void) {
    int n; // Numero de elementos del arreglo
    int leidos; // Verificacion de lectura
    int i;

    printf("Ingresa el numero de elementos que deseas ordenar: ");
    leidos = scanf("%d", &n);
    if (leidos != 1) return 0;
    if (n <= 0)   return 0;

    printf("Escribe los %d colores (blanco, rojo, azul): ", n);
    int A[n];
    for (i = 0; i < n; ++i) {
        char buf[32];
        leidos = scanf("%s", buf);
        if (leidos != 1) return 0;
        int id = color_Entero(buf);
        if (id < 0) {
            return 0;
        }
        A[i] = id;
    }
    counting_sort(A, n);

    //Resultado
    printf("Arreglo ordenado: ");
    for (i = 0; i < n; ++i) {
        if (i) { putchar(' '); }
        fputs(entero_Color(A[i]), stdout);
    }
    putchar('\n');
    return 0;
}

/*Ejemplo de entrada y salida

Ingresa el numero de elementos que deseas ordenar: 4
Escribe los 4 colores (blanco, rojo, azul): rojo azul azul blanco
Arreglo ordenado: rojo blanco azul azul

*/

