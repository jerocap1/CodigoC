#include <stdio.h>

int main() {
    int id, stock = 0, cantidad = 0, opcion;
    float precio, total_ganancias = 0, descuento = 0;
    char nombre[30];

    do {
        printf("\nMenu de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar información del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                
                printf("Ingrese el nombre del producto: ");
                fflush(stdin);
                fgets(nombre, 30, stdin);
                
                printf("Ingrese la cantidad inicial en stock: ");
                do {
                    scanf("%d", &stock);
                    if (stock < 0) {
                        printf("La cantidad no puede ser negativa. Ingrese una cantidad válida: ");
                    }
                } while (stock < 0);
                
                printf("Ingrese el precio unitario del producto: ");
                do {
                    scanf("%f", &precio);
                    if (precio < 0) {
                        printf("El precio no puede ser negativo. Ingrese un precio válido: ");
                    }
                } while (precio < 0);
                
                break;

            case 2:
                printf("Ingrese la cantidad a vender: ");
                do {
                    scanf("%d", &cantidad);
                    if (cantidad < 1) {
                        printf("La cantidad a vender debe ser al menos 1. Vuelva a intentarlo: ");
                    }
                } while (cantidad < 1);

                if (stock >= cantidad) {
                    stock -= cantidad;
                    printf("Gracias por su compra!\n");

                    printf("Ingrese el descuento (porcentaje) para esta venta (0 si no aplica): ");
                    do {
                        scanf("%f", &descuento);
                        if (descuento < 0 || descuento > 100) {
                            printf("El descuento debe ser entre 0 y 100. Intente nuevamente: ");
                        }
                    } while (descuento < 0 || descuento > 100);

                    float precio_con_descuento = precio * (1 - descuento / 100);
                    total_ganancias += cantidad * precio_con_descuento;

                    printf("Stock disponible quedan: %d\n", stock);
                    printf("Ganancia de esta venta: $%.2f\n", cantidad * precio_con_descuento);
                } else {
                    printf("No hay suficiente stock. Solo hay %d unidades disponibles.\n", stock);
                }
                break;

            case 3:
                printf("Ingrese la cantidad a agregar al stock: ");
                do {
                    scanf("%d", &cantidad);
                    if (cantidad < 1) {
                        printf("La cantidad debe ser positiva. Vuelva a intentarlo: ");
                    }
                } while (cantidad < 1);

                stock += cantidad;
                printf("El stock se ha actualizado. Stock actual: %d\n", stock);
                break;

            case 4:
                printf("\nInformacion del producto:\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s", nombre);
                printf("Stock disponible: %d\n", stock);
                printf("Precio unitario: %.2f\n", precio);
                break;

            case 5:
                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
