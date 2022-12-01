#include<stdio.h>
#include<locale.h>
#include<string.h>

int main() {
    setlocale(LC_ALL, "");
    int recu;
    recu = 1;

    int transistor, piezas, total, producto, mes, prod, posicion1, posicion2, val1, val2;
    float sumprod = 0, prom;
    int nuevCantidad = 0;
    bool productoExiste = false;
    char nuevoNombre[300];
    int encapsulado, cantrans, tipotrans, espt, esptcolum, continente, pc, mcanttransis[5][5] = {
            {20, 10, 50, 6666, 660},
            {30, 30, 30, 30,   30,},
            {40, 40, 40, 40,   40,},
            {50, 50, 50, 50,   50,},
            {20, 20, 20, 20,   20},
    };
    float mespecificaciones[25][5] = {
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
            {100, 20, 3, 3, 'NPN'},
    },
            ventas[1000] = {},
    //cost de envio
    vcostenv[5] = {100.50,
                   200.50,
                   300.50,
                   400.50,
                   500.50};
    char op, buskencapsulado[15],
    //
    mencaptran[5][5][15] = {
            {{'t', 'o', '1'}, {'t', 'o', '2'}, {'t', 'o', '3'}, {'t', 'o', '4'}, {'t', 'o', '5'},},
            {{'a', 'o', '2'}, {'a', 'o', '3'}, {'a', 'o', '4'}, {'a', 'o', '5'}, {'a', 'o', '6'},},
            {{'b', 'o', '3'}, {'b', 'o', '4'}, {'t', 'o', '5'}, {'t', 'o', '6'}, {'t', 'o', '7'},},
            {{'c', 'o', '4'}, {'c', 'o', '5'}, {'t', 'o', '6'}, {'t', 'o', '7'}, {'t', 'o', '8'},},
            {{'d', 'o', '5'}, {'d', 'o', '6'}, {'t', 'o', '7'}, {'t', 'o', '8'}, {'t', 'o', '9'},},
    },
    //Abreviación del Tipo de Transistor
    vnomtran[5][10] = {
            {'a', 'a'},
            {'a', 'b'},
            {'a', 'c'},
            {'a', 'd'},
            {'a', 'e'},
    },
    //nombres de los contientes
    vcontinom[5][10] = {
            {'a', 's', 'i', 'a'},
            {'a', 'm', 'e', 'r', 'i', 'c', 'a'},
            {'a', 'f', 'r', 'i', 'c', 'a'},
            {'o', 'c', 'e', 'a', 'n', 'i', 'a'},
            {'e', 'u', 'r', 'o', 'p', 'a',},
    };;

    do {
        printf("\tAntes de iniciar el programa, captura los siguientes datos...\n\n");
        printf("Ingresa maximo 5 continentes y su costo de envio");
        //NOMBRE DE CONTINENTE Y DE TIPO DE TRANSISTOR
//        for (continente = 0; continente < 5; continente++) {
////            printf("\n\nNombre del Continente %d:", continente);
////            scanf("%s", &vcontinom[continente - 1]);
////            printf("\nPrecio de Envio C%d:", continente);
////            scanf("%f", &vcostenv[continente - 1]);
//        }
        //NOMBRE DE ENCAP Y CANTIDAD DE ENCAP
//        for (tipotrans = 0; tipotrans < 5; tipotrans++) {
////            printf("\n\n\nAbreviación del Tipo de Transistor %d:", tipotrans);
////            scanf("%s", &vnomtran[tipotrans - 1]);
//            for (encapsulado = 0; encapsulado < 5; encapsulado++) {
////                printf("\n\nEncapsulado del Transitor tipo %d:", encapsulado);
////                scanf("%s", &mencaptran[tipotrans - 1][encapsulado - 1]);
////                printf("Piezas del Encapsulado %d:", encapsulado);
////                scanf("%d", &mcanttransis[tipotrans - 1][encapsulado - 1]);
//
//            }
//        }
        //DECLARAR ESPECIFICACIONES

        printf("\n\n\n\n\n\nEn Base a la Siquiente Estructura Genera la Matriz de Especificaciones");
        printf("\nNPN es 0 y PNP es 1");
        printf("\n\n \t\tCosto\t\tTemp A.\t\tVoltaje\t\tCorriente\t\tNPN o PNP");
        printf("\nUTJ 1\nUTJ 2\nUTJ 3\nUTJ 4\nUTJ 5\nBJT 6\nBJT 7\nBJT 8\nBJT 9\nBJT 10\nJFET 11\nJFET 12\nJFET 13\nJFET 14\nJFET 15\nFET 16\nFET 17\nFET 18\nFET 19\nFET 20\nFOT 21\nFOT 22\nFOT 23\nFOT 24\nFOT 25");
//        for (espt = 1; espt <= 25; espt++) {
//            for (esptcolum = 1; esptcolum <= 5; esptcolum++) {
//                printf("\n\n\nFila %d / Dato %d:", espt, esptcolum);
//                scanf("%f", &mespecificaciones[espt - 1][esptcolum - 1]);
//            }
//        }

        // DESPLIEGUE DE VECTORES



        // desplegar datos 1
        printf("\n\n\n\t\t  Matriz de Encapsulados");
        printf("\n\n  \tTipo de transistor \t\t\tEncapsulados\n");
        for (tipotrans = 1; tipotrans <= 5; tipotrans++) {
            printf("\nTransistores de Tipo %s:  ", vnomtran[tipotrans - 1]);

            for (encapsulado = 1; encapsulado <= 5; encapsulado++) {
                printf("\t %s   ", mencaptran[tipotrans - 1][encapsulado - 1]);
            }
        }

        // desplegar datos 2
        printf("\n\n\n\n\t\t  Matriz de Piezas Totales de un Transistor");
        printf("\n\n  \tTipo de transistor \t\t\tCantidades\n");
        for (tipotrans = 1; tipotrans <= 5; tipotrans++) {
            printf("\nTransistores de Tipo %s:  ", vnomtran[tipotrans - 1]);

            for (encapsulado = 1; encapsulado <= 5; encapsulado++) {
                printf("\t %d   ", mcanttransis[tipotrans - 1][encapsulado - 1]);
            }
        }

        //DESPLIEGUE MATRIZ ESPECIFICACIONES

        printf("\n\n\n\t\t  Matriz de Especificaciones");
        printf("\n\nEncapsulado \t\t\tEspecificaciones\n");
        for (espt = 1; espt <= 25; espt++) {
            printf("\nE. %d:      ", espt);
            for (esptcolum = 1; esptcolum <= 5; esptcolum++) {
                printf("\t %.0f   ", mespecificaciones[espt - 1][esptcolum - 1]);
            }
        }

//CONSULTAR INCISOS
        printf("\n\n\n\t\t     Inventario de Transistores");
        printf("\n\n\nA. Examinar la cantidad total de piezas de un trasnsistor en especifico");
        printf("\nB. Cambiar los datos de un componente seleccionado (siempre y cuando sea el encapsulado o las piezas totales de un transistor) ");
        printf("\nC. Calcular promedio total de productos que se vende al año");
        printf("\nD. Verificar la temperatura adecuada para los transistores");
        printf("\nE. Obtener costo de envio a algun continente");
        printf("\nF. Consulta de datasheet");
        printf("\nG. Eliminar componentes ");
        printf("\nI. Realizar venta");
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
                if (!productoExiste)
                    printf("Producto no encontrado");
                break;
            case 'c':
            case 'C':
                for (producto = 1; producto <= 25; producto = producto + 1) {
                    printf("\n\n\n\t Los productos son: 1- T.UTJ  2- T.BJT  3- T.JFET  4- T.FET  5- T.FOT");
                    printf("\n\n Producto %d", producto);
                    sumprod = 0;
                    for (mes = 1; mes <= 12; mes = mes + 1) {
                        printf("\nProducción del mes %d :", mes);
                        scanf("%f", &prod);
                        sumprod = sumprod + prod;
                    }
                    prom = sumprod / 12;
                    printf("\nEl promedio anual de la producción %d es %.2f", producto, prom);
                }
                break;
            case 'i':
            case 'I':

                break;

        }
//RECURSIVO
        printf("\n\n Ingresa [1]continuar  o  [0]salir");
        scanf("%d", &recu);
    } while (recu == 1);
}
