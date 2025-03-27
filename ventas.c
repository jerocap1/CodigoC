#include <stdio.h>

int main() {
    int id, stock=0, cantidad=0, opcion;
    float precio, total_ganancias = 0;
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
                    // Registro del producto
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                
                printf("Ingrese el nombre del producto: ");
                fflush(stdin);
                fgets(nombre, 30, stdin);
                
                printf("Ingrese la cantidad inicial en stock: ");
                scanf("%d", &stock);
                
                printf("Ingrese el precio unitario del producto: ");
                scanf("%f", &precio);
             break;

            case 2:
            printf("Ingrese la cantidad a vender: ");  
            scanf("%d", &cantidad);
            if (cantidad<0){
                do{

                        printf("El numero ingresado no es correcto, vuelva a ingresar: \n");
                        scanf("%d", &cantidad);
                }while(cantidad<1);
            }
            
                if (stock>=cantidad){
                    stock=stock-cantidad;
                    printf("Gracias por su compra!");
                    printf("\nStock disponible quedan: %d",stock);
                }
                else{
                    printf("No hay suficiente stock\n");
                }
                
                
                
                break;

            case 3:
                printf("Ingrese la cantidad a agregar al stock: ");
                scanf("%d", &cantidad);
                if (cantidad<1){
                    printf("El numero ingresado no es correcto, vuelva a ingresar: \n");
                }
                
                
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