#include <stdio.h>
#include <string.h>

#define NUM_BOXEADORES 6
#define NUM_COMBATES 3
#define MAX_NOMBRE 50

void limpiarSalto(char texto[]) {
    int len = strlen(texto);
    if (len > 0 && texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
    }
}

void ingresarNombres(char nombres[][MAX_NOMBRE]) {
    printf("\nIngrese los nombres de los %d boxeadores:\n", NUM_BOXEADORES);
    for (int i = 0; i < NUM_BOXEADORES; i++) {
        printf("Nombre del boxeador b%d: ", i + 1);
        fgets(nombres[i], MAX_NOMBRE, stdin);
        limpiarSalto(nombres[i]);
    }
}

int leerCombates(int ganadores[], int puntos[], char nombres[][MAX_NOMBRE]) {
    int ganador, punto;

    for (int i = 0; i < NUM_COMBATES; i++) {
        int b1 = i * 2;
        int b2 = i * 2 + 1;

        printf("\nCombate %d: %s (b%d) vs %s (b%d)\n", i + 1, nombres[b1], b1 + 1, nombres[b2], b2 + 1);

        do {
            printf("Ingrese el numero del boxeador ganador (1 para %s, 2 para %s): ", nombres[b1], nombres[b2]);
            if (scanf("%d", &ganador) != 1) {
                printf("Entrada invalida. Debe ingresar un numero.\n");
                while (getchar() != '\n');
                ganador = -1;
            } else if (ganador != 1 && ganador != 2) {
                printf("Solo puede ingresar 1 o 2.\n");
            }
        } while (ganador != 1 && ganador != 2);

        do {
            printf("Ingrese los puntos con los que gano: ");
            if (scanf("%d", &punto) != 1) {
                printf("Entrada invalida. Debe ingresar un numero.\n");
                while (getchar() != '\n');
                punto = -1;
            } else if (punto < 0) {
                printf("Los puntos no pueden ser negativos.\n");
            }
        } while (punto < 0);

        while (getchar() != '\n');

        ganadores[i] = (ganador == 1) ? b1 : b2;
        puntos[i] = punto;
    }

    return 1;
}

void ordenarPorPuntos(int ganadores[], int puntos[]) {
    int temp;
    for (int i = 0; i < NUM_COMBATES - 1; i++) {
        for (int j = 0; j < NUM_COMBATES - i - 1; j++) {
            if (puntos[j] < puntos[j + 1]) {
                temp = puntos[j];
                puntos[j] = puntos[j + 1];
                puntos[j + 1] = temp;
                temp = ganadores[j];
                ganadores[j] = ganadores[j + 1];
                ganadores[j + 1] = temp;
            }
        }
    }
}

void mostrarFinalistas(int ganadores[], int puntos[], char nombres[][MAX_NOMBRE]) {
    printf("\n=== Finalistas ===\n");
    for (int i = 0; i < 2; i++) {
        printf("%s (b%d) con %d puntos\n", nombres[ganadores[i]], ganadores[i] + 1, puntos[i]);
    }

    printf("\nEliminado: %s (b%d) con %d puntos\n", nombres[ganadores[2]], ganadores[2] + 1, puntos[2]);
}

int main() {
    char nombres[NUM_BOXEADORES][MAX_NOMBRE];
    int ganadores[NUM_COMBATES];
    int puntos[NUM_COMBATES];
    int nombresIngresados = 0;
    int combatesIngresados = 0;
    int opcion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Ingresar nombres de los boxeadores\n");
        printf("2. Ingresar ganadores y puntos\n");
        printf("3. Mostrar finalistas\n");
        printf("4. Salir\n");

        do {
            printf("Seleccione una opcion (1-4): ");
            if (scanf("%d", &opcion) != 1) {
                printf("Entrada invalida. Debe ingresar un numero entre 1 y 4.\n");
                while (getchar() != '\n');
                opcion = -1;
            } else if (opcion < 1 || opcion > 4) {
                printf("Opcion fuera de rango. Intente de nuevo.\n");
            }
        } while (opcion < 1 || opcion > 4);

        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                ingresarNombres(nombres);
                nombresIngresados = 1;
                break;
            case 2:
                if (!nombresIngresados) {
                    printf("Primero debe ingresar los nombres.\n");
                } else {
                    if (leerCombates(ganadores, puntos, nombres)) {
                        combatesIngresados = 1;
                    }
                }
                break;
            case 3:
                if (!nombresIngresados || !combatesIngresados) {
                    printf("Debe ingresar los nombres y los resultados primero.\n");
                } else {
                    ordenarPorPuntos(ganadores, puntos);
                    mostrarFinalistas(ganadores, puntos, nombres);
                }
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}
