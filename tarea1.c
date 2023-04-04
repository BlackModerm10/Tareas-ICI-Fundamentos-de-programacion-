/* *********************************|Tarea 1|*********************************
~ Matías Delgadillo Pietrantoni | 21.148.162-5
~ ICI1242-2
~ 04 de Abril del 2023
**************************************************************************** */
/* ****************************|Cobro de Peaje|****************************
~ ENTRADA ~
Unsigned long long - Cantidad de vehiculos
                   - Categoria
                   - Tarifas
Double  - Kms recorridos
        - Monto Total
Int - 4 Contadores para la categoria del vehículo
    - 3 Contadores para las tarifas del vehículo
    - 2 Contadores para vehículos con o sin descuentos
    
~ SALIDA ~
Se obtendran datos individuales de cada vehículo ingresado
Que categoría de vehículo corresponde
Tipo de tarifa
Distancia reccorrida en Kms
Monto del peaje a pagar
Si el vehículo le corresponde un descuento o no!
Si le corresponde entonces se dicta el porcentaje del descuento
Más el monto final con el descuento aplicado!
Se repite lo anterior hasta procesar todos los vehículos
Y se hace un reporte final que contiene:
La cantidad de vehículos procesados entre las 4 categorias
La cantidad de vehículos procesados en cada tipo de tarifa (1, 2 o 3).
La cantidad de vehículos que recibieron algún tipo de descuento.
La cantidad de vehículos que NO recibieron algún tipo de descuento.
La cantidad total de dinero recaudado por la autopista por concepto de peaje.
*/

/* ************| librerias |************ */
#include <stdio.h>
#include <math.h>
#define LINEAS "====================================\n"

int main() {
    // Declaración de variables
    unsigned long long cantVehiculos, categoria, tarifa;
    double km, montoTotal = 0;
    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0; // Contadores para categoria del vehiculo
    int contTarifa1 = 0, contTarifa2 = 0, contTarifa3 = 0; // Contador para Tarifas
    int contDescuento = 0, contNoDescuento = 0; // Contador descuento y noDescuento
    
    // Lectura de cantidad de vehículos!
    do {
        scanf("%llu", &cantVehiculos);
    } while (cantVehiculos < 1 || cantVehiculos > 100);
    
    // Procesamiento de vehículos!
    for (int i = 1; i <= cantVehiculos; i++) 
    {
        // Lectura de datos del vehículo!
        printf("Vehículo #%d\n", i);
        // Lectura de la categoría del vehículo
        do {
            scanf("%lld", &categoria);
        } while (categoria < 1 || categoria > 4);
            if (categoria == 1) {
                printf("Categoría Vehículo : %llu\n", categoria);
                cont1++;
            }
            else if (categoria == 2) {
                printf("Categoría Vehículo : %llu\n", categoria);
                cont2++;
            }
            else if (categoria == 3) {
                printf("Categoría Vehículo : %llu\n", categoria);
                cont3++;
            }
            else if (categoria == 4) {
                printf("Categoría Vehículo : %llu\n", categoria);
                cont4++;
            }
        do {
            scanf("%llu", &tarifa);
        } while (tarifa < 1 || tarifa > 3);
            if (tarifa == 1) {
                printf("Tipo Tarifa : BAJA\n");
                contTarifa1++;
            }
            else if (tarifa == 2) {
                printf("Tipo Tarifa : MEDIA\n");
                contTarifa2++;
            }
            else if (tarifa == 3) {
                printf("Tipo Tarifa : ALTA\n");
                contTarifa3++;
            }
        
        scanf("%lf", &km);
        printf("Largo Tramo %.2lf Kms.\n", km);
        // Determinar el precio según la categoria y tarifa del vehículo!
        unsigned long precio;
        if (categoria == 1) 
        {
            if (tarifa == 1) {
                precio = 100;
            } else if (tarifa == 2) {
                precio = 200;
            } else if (tarifa == 3) {
                precio = 300;
            }
        } else if (categoria == 2) {
            if (tarifa == 1) {
                precio = 175;
            } else if (tarifa == 2) {
                precio = 350;
            } else if (tarifa == 3) {
                precio = 525;
            }
        } else if (categoria == 3) {
            if (tarifa == 1) {
                precio = 273;
            } else if (tarifa == 2) {
                precio = 546;
            } else if (tarifa == 3) {
                precio = 819;
            }
        } else if (categoria == 4) {
            if (tarifa == 1) {
                precio = 125;
            } else if (tarifa == 2) {
                precio = 375;
            } else if (tarifa == 3){
                precio = 625;
            }
        }
        double monto = precio * km;
        //monto = round(monto);
        printf("Monto Peaje $%.lf\n",monto);
        
        // Aplicación del descuento, si corresponde o no!
        double descuento = 0;
        if (monto > 10000) {
            descuento = 0.2;
        } else if (monto >= 7000 && monto <= 10000) {
            descuento = 0.15;
        } else if (monto >= 3000 && monto < 7000) {
            descuento = 0.1;
        } else if (monto < 3000) {
            descuento = 0;
        }
        
        if (descuento > 0) {
            contDescuento++;
            double montoDesc = monto * (1 - descuento);
            //montoDesc = round(montoDesc);
            printf("Porcentaje de Descuento = %.1lf%%\n", (descuento * 100));
            printf("Monto Final Peaje = $%.lf\n", montoDesc);
            montoTotal += montoDesc;
        } else {
            contNoDescuento++;
            double montoNoDesc = monto * 1;
            printf("Vehículo NO tiene descuento!.\n");
            montoTotal += montoNoDesc;
            }
        
        
        printf(LINEAS);
    }
    printf("\nREPORTE FINAL\n");
    printf("-------------\n");
    printf("Total vehículos procesados CATEGORIA #1 = %d\n",cont1);
    printf("Total vehículos procesados CATEGORIA #2 = %d\n",cont2);
    printf("Total vehículos procesados CATEGORIA #3 = %d\n",cont3);
    printf("Total vehículos procesados CATEGORIA #4 = %d\n",cont4);
    printf("\n");
    printf("Total vehículos procesados TARIFA BAJA = %d\n",contTarifa1);
    printf("Total vehículos procesados TARIFA MEDIA = %d\n",contTarifa2);
    printf("Total vehículos procesados TARIFA ALTA = %d\n",contTarifa3);
    printf("\n");
    printf("Total vehículos procesados CON DESCUENTO = %d\n",contDescuento);
    printf("Total vehículos procesados SIN DESCUENTO = %d\n",contNoDescuento);
    printf("\n");
    printf("Total dinero recaudado = $%.lf", montoTotal);
    return 0;       
}
