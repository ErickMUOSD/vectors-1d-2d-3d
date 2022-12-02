#include<stdio.h>
#include<locale.h>
#include<string.h>

int recu = 1;
int transistor, piezas, total, producto, mes, prod, posicion1, posicion2, val1, val2;
float sumprod = 0, prom;
int nuevCantidad = 0;
bool productoExiste = false, cantidadExcedida = false;
char nuevoNombre[300];
int encapsulado, cantrans, tipotrans, espt, esptcolum, continente, pc, mcanttransis[5][5];

float mespecificaciones[25][5], precioEncapsulado[5][5], ventas = 0,
        calcularVenta = 0, vcostenv[5];
char op, buskencapsulado[15], mencaptran[5][5][15], vnomtran[5][10], vcontinom[5][10];

bool productoExisteArreglo( bool existe, char* msg){

    if (!existe)
        printf("%d", msg);
}
void inicializarContinentes() {
    printf("\tAntes de iniciar el programa, captura los siguientes datos...\n\n");
    printf("Ingresa maximo 5 continentes y su costo de envio");
    //NOMBRE DE CONTINENTE Y DE TIPO DE TRANSISTOR
    for (continente = 0; continente < 5; continente++) {
        printf("\n\nNombre del Continente %d:", continente);
        scanf("%s", &vcontinom[continente - 1]);
        printf("\nPrecio de Envio C%d:", continente);
        scanf("%f", &vcostenv[continente - 1]);
    }
}

void inicializarTransistores() {
    for (tipotrans = 0; tipotrans < 5; tipotrans++) {
        printf("\n\n\nAbreviación del Tipo de Transistor %d:", tipotrans);
        for (encapsulado = 0; encapsulado < 5; encapsulado++) {
            printf("\n\nEncapsulado del Transitor tipo %d:", encapsulado);
            scanf("%s", &vnomtran[tipotrans]);
            printf("Piezas del Encapsulado %d:", encapsulado);
            scanf("%d", &mcanttransis[tipotrans][encapsulado]);

            printf("\\n\\Precio del encapsulado:");
            scanf("%f", &precioEncapsulado[tipotrans][tipotrans]);
        }
    }
}

void inicializarMatrizDeEspecificaciones() {
    printf("\n\n\n\n\n\nEn Base a la Siquiente Estructura Genera la Matriz de Especificaciones");
    printf("\nNPN es 0 y PNP es 1");
    printf("\n\n \t\tCosto\t\tTemp A.\t\tVoltaje\t\tCorriente\t\tNPN o PNP");
    printf("\nUTJ 1\nUTJ 2\nUTJ 3\nUTJ 4\nUTJ 5\nBJT 6\nBJT 7\nBJT 8\nBJT 9\nBJT 10\nJFET 11\nJFET 12\nJFET 13\nJFET 14\nJFET 15\nFET 16\nFET 17\nFET 18\nFET 19\nFET 20\nFOT 21\nFOT 22\nFOT 23\nFOT 24\nFOT 25");
    for (espt = 1; espt <= 25; espt++) {
        for (esptcolum = 1; esptcolum <= 5; esptcolum++) {
            printf("\n\n\nFila %d / Dato %d:", espt, esptcolum);
            scanf("%f", &mespecificaciones[espt - 1][esptcolum - 1]);
        }
    }
}

void imprimirEncapsulados() {
    printf("\n\n\n\t\t  Matriz de Encapsulados");
    printf("\n\n  \tTipo de transistor \t\t\tEncapsulados\n");
    for (tipotrans = 1; tipotrans <= 5; tipotrans++) {
        printf("\nTransistores de Tipo %s:  ", vnomtran[tipotrans - 1]);

        for (encapsulado = 1; encapsulado <= 5; encapsulado++) {
            printf("\t %s   ", mencaptran[tipotrans - 1][encapsulado - 1]);
        }
    }
}

void imprimirPiezasTotales() {
    printf("\n\n\n\n\t\t  Matriz de Piezas Totales de un Transistor");
    printf("\n\n  \tTipo de transistor \t\t\tCantidades\n");
    for (tipotrans = 1; tipotrans <= 5; tipotrans++) {
        printf("\nTransistores de Tipo %s:  ", vnomtran[tipotrans - 1]);

        for (encapsulado = 1; encapsulado <= 5; encapsulado++) {
            printf("\t %d   ", mcanttransis[tipotrans - 1][encapsulado - 1]);
        }
    }

}

void imprimirMatrizEspecificaciones() {
    printf("\n\n\n\t\t  Matriz de Especificaciones");
    printf("\n\nEncapsulado \t\t\tEspecificaciones\n");
    for (espt = 1; espt <= 25; espt++) {
        printf("\nE. %d:      ", espt);
        for (esptcolum = 1; esptcolum <= 5; esptcolum++) {
            printf("\t %.0f   ", mespecificaciones[espt - 1][esptcolum - 1]);
        }
    }
}

void imprimirListaDeOpciones(){
    printf("\n\n\n\t\t     Inventario de Transistores");
    printf("\n\n\nA. Examinar la cantidad total de piezas de un trasnsistor en especifico");
    printf("\nB. Cambiar los datos de un componente seleccionado (siempre y cuando sea el encapsulado o las piezas totales de un transistor) ");
    printf("\nC. Calcular promedio total de productos que se vende al año");
    printf("\nE. Obtener costo de envio a algun continente");
    printf("\nF. Consulta de datasheet");
    printf("\nG. Eliminar componentes ");
    printf("\nI. Realizar venta");
}
int main() {
    setlocale(LC_ALL, "");


    do {
        inicializarContinentes();

        //NOMBRE DE ENCAP Y CANTIDAD DE ENCAP
        inicializarTransistores();
        //DECLARAR ESPECIFICACIONES
        inicializarMatrizDeEspecificaciones();

        // DESPLIEGUE DE VECTORES

        // desplegar datos 1
        imprimirEncapsulados();

        // desplegar datos 2
        imprimirPiezasTotales();
        //DESPLIEGUE MATRIZ ESPECIFICACIONES
        imprimirMatrizEspecificaciones();


//CONSULTAR INCISOS
        imprimirListaDeOpciones();

        printf("\n\nIngresa la opción deseada :");
        scanf("%s", &op);
        switch (op) {
            case 'a':
            case 'A':
                printf("\n\n\t\tCantidad Total de un Transistor");
                printf("\n\nMatriticula del Transistor que quieres consultar : ");
                scanf("%s", &buskencapsulado);
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        if (strcmp(reinterpret_cast<const char *>(mencaptran[i][j]), buskencapsulado) == 0) {
                            int fila = i;
                            int columna = j;
                            printf(" Transistor: %s", mencaptran[i][j]);
                            printf(" piezas totales: %d ", mcanttransis[fila][columna]);
                            productoExiste = true;
                        }

                    }
                }
                if (!productoExiste)
                    printf("Producto no encontrado");
                break;
            case 'b':
            case 'B':

                printf("\n\nMatriticula del Transistor que quieres cambiar : ");
                scanf("%s", &buskencapsulado);

                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        if (strcmp(reinterpret_cast<const char *>(mencaptran[i][j]), buskencapsulado) == 0) {
                            printf("\n\n Nuevo nombre  : ");
                            scanf("%s", &nuevoNombre);
                            printf("\n\n Nueva cantidad  : ");
                            scanf("%d", &nuevCantidad);

                            int fila = i;
                            int columna = j;
                            for (int k = 0; k < strlen(nuevoNombre); ++k) {
                                mencaptran[fila][columna][k] = nuevoNombre[k];
                            }

                            mcanttransis[fila][columna] = nuevCantidad;

                            printf("\n\n x1: %s", mencaptran[fila][columna]);
                            productoExiste = true;

                        }
                    }
                }
                productoExisteArreglo(productoExiste, "producto no encontrado");

                break;
            case 'c':
            case 'C':
                sumprod = ventas / 12;
                printf("\n\n\t\tPromedio de Ventas Anuales");
                printf("\n\nEl promedio de ventas anuales es de: %f", sumprod);
                break;
            case 'e':
            case 'E':

                printf("\n\n Nombre del continente  : ");
                scanf("%s", nuevoNombre);

                for (int i = 0; i < 5; ++i) {
                    if (strcmp(reinterpret_cast<const char *>(vcontinom[i]), nuevoNombre) == 0) {

                        printf("\n\n Nombre del continente:: %s", vcontinom[i]);
                        printf("\n\n costo: %f", vcostenv[i]);
                        productoExiste = true;
                    }
                }
                productoExisteArreglo(productoExiste, "producto no existe");
                break;
            case 'f':
            case 'F':
                printf("\n\n\n\t\t  Matriz de Encapsulados");
                printf("\n\n  \tTipo de transistor \t\t\tEncapsulados\n");
                for (tipotrans = 1; tipotrans <= 5; tipotrans++) {
                    printf("\nTransistores de Tipo %s:  ", vnomtran[tipotrans - 1]);

                    for (encapsulado = 1; encapsulado <= 5; encapsulado++) {
                        printf("\t %s   ", mencaptran[tipotrans - 1][encapsulado - 1]);
                    }
                }
                break;
            case 'g':
            case 'G':
                printf("\n\nMatriticula del Transistor que quieres eliminar : ");
                scanf("%s", &buskencapsulado);
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        if (strcmp(reinterpret_cast<const char *>(mencaptran[i][j]), buskencapsulado) == 0) {
                            for (int m = 0; m < strlen(mencaptran[i][j]); ++m) {
                                memset(&mencaptran[i][j], 0, sizeof(mencaptran[i][j]));

                            }
                            productoExiste = true;
//                                mcanttransis[i][j] =  " ";
                            for (int k = j; k < 4; ++k) {
                                mcanttransis[i][k] = mcanttransis[i][k + 1];
                            }
                            mcanttransis[i][4] = 0;
                        }


                    }
                }
                productoExisteArreglo(productoExiste, "producto no existe");
                break;
            case 'i':
            case 'I':
                printf("\n\nMatriticula del Transistor que quieres vender : ");
                scanf("%s", &buskencapsulado);

                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        if (strcmp(reinterpret_cast<const char *>(mencaptran[i][j]), buskencapsulado) == 0) {

                            int cantidad;
                            printf("\\n\\n Cantidad del transistor que quieres vender : ");
                            scanf("%d", &cantidad);

                            if (cantidad <= mcanttransis[i][j]) {
                                printf("\n\n Nombre: %s", mencaptran[i][j]);
                                printf("\n\n Numero de piezas %d", cantidad);
                                printf("\n\n costo: %f", precioEncapsulado[i][j]);
                                calcularVenta = precioEncapsulado[i][j] * cantidad;
                                printf("\n\n Total: %f", calcularVenta);
                                mcanttransis[i][j] = mcanttransis[i][j] - cantidad;
                                ventas += calcularVenta;

                            } else
                                cantidadExcedida = true;

                            productoExiste = true;
                        }

                    }
                }
                if (cantidadExcedida)
                    printf("Cantidad excedida");
                productoExisteArreglo(productoExiste,  "producto no existe");
                break;

        }
//RECURSIVO
        printf("\n\n Ingresa [1]continuar  o  [0]salir");
        scanf("%d", &recu);
    } while (recu == 1);
}
