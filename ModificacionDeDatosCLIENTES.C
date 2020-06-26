# Tp-Final
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#define AR_CLIENTES "clientes.dat"
#define AR_CONSUMOS "consumos.dat"
#define ESC 27
#define DIM_CLI 100
typedef struct{
    int id;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[45];
    int movil;
    int baja; /// 1 si esta activo / 0 si esta dado de baja.
}stCliente;
typedef struct{
    int id;
    int idCliente;
    int anio;
    int mes; ///1 al 12.
    int dia; ///1 a... depende los meses.
    int datosConsumidos;
    int baja; /// 1 activo / 0 de baja.
}stConsumo;


void menuPrincipal();
void menuClientes();
void menuConsumos();
stCliente cargaUnCliente();
int validaEmail(char email[]);
int cargarListaClientes(stCliente c[], int v, int dim);
void guardarUnCliente(stCliente c);
void cargarArchListaClientes();
int buscoUltimoID();
void muestraUnCliente(stCliente c);
void mostrarArchClientes();
stCliente buscaClienteArchxNroCliente(int nroCliente);
void encontrarClienteArch();
void modificarClienteArch(stCliente c);
void menuModificacionDatos();
int buscaPosicion(int id);
void guardarClienteModificadoArch(stCliente c);
void modifRegistro(stCliente c);
void funcion05();
stCliente buscaPosicionDNI(int dni);
int validoDNI(int dni);
int validoNroCliente(int nro);

int archivoAArregloAltas(stCliente a[], int dim);
void intercambio(stCliente *i, stCliente *menor);
void muestraArreglo(int v, stCliente a[]);
int buscaMenorDNIArreglo(int v, stCliente a[], int pos);
void ordenacionSeleccionArchivoDNI();
void ordenamientoSeleccionAregloDNI(int v, stCliente a[]);
int buscaMenorApellidoArreglo(int v, stCliente a[], int pos);
void ordenamientoSeleccionAregloApellido(int v, stCliente a[]);
void ordenacionSeleccionArchivoApellido();
stCliente buscaClienteDNI(int dni);
void muestraBuscaCliente();

int archivoAArregloBajas(stCliente a[], int dim);
int buscaMenorEmailArreglo(int v, stCliente a[], int pos);
void ordenacionSeleccionArchivoEmail();

///UTILIDADES
int randomRango(int rangoMin ,int rangoMax);

///CONSUMOS
void guardarUnConsumo(stConsumo consumo);
stCliente clienteRandom ();
stConsumo cargaUnConsumo ();
int buscoUltimoIDConsumos();
void cargaArchListaConsumos();
void muestraUnConsumo(stConsumo c);
void mostrarArchConsumos();
void menuModificacionConsumo();
void modificacionConsumo();
stConsumo cambiarConsumo(stConsumo a);
void modifRegistroCONSUMOS(stConsumo c);
int buscaPosicionCONSUMO(int id);
stConsumo buscaxIDConsumo(int id, int anio, int mes, int dia);
void modificarConsumo(stConsumo a);
void modificoBajaConsumo();
void buscarConsumoFecha(int anio, int mes, int dia);
void preguntaFechaConsumo();
stConsumo ConsumoRandom();
stConsumo CargaUnConsmoRandom();


int main()
{
    stCliente Lista[DIM_CLI];
    int vLista = 0;
    stConsumo Consumos[30];
    char opcion;
    char opcionCli;
    char opcionCon;


    srand (time(NULL));

    //int random = randomRango(0,buscoUltimoID());
    //printf("%d", random);

    //muestraUnCliente(clienteRandom());

///fecha random

    int diaAzar;
    int mesAzar;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentAnio;
    int currentDia;
    int currentMes;

    currentAnio = tm.tm_year + 1900;
    currentMes = tm.tm_mon +1;
    currentDia = tm.tm_mday;

/*
    mesAzar = randomRango(1,currentMes);
    if(mesAzar == 6) {
        diaAzar = randomRango(1,currentDia);
    }
    else {
        diaAzar = randomRango()
    }
    //consumo.anio = currentAnio;
    printf("Anio %d \n", currentAnio);
    printf("Dia %d \n", diaAzar);
    printf("Mes %d \n", mesAzar);
*/

    system("pause");
    do{
        system("cls");
        menuPrincipal();
        opcion=getch();
        system("cls");
        switch(opcion){
        case '1':
            do{
            system("cls");
            menuClientes();
            opcionCli=getch();
            system("cls");
            switch(opcionCli){
            case '1':
                cargarArchListaClientes();
                break;
            case '2':
                mostrarArchClientes();
                system("pause");
                break;
            case '3':
                encontrarClienteArch();
                system("pause");
                break;
            case '4':
                funcion05();
                system("pause");
                break;
            case '5':
                ordenacionSeleccionArchivoDNI();
                system("pause");
                break;
            case '6':
                ordenacionSeleccionArchivoApellido();
                system("pause");
                break;
            case '7':
                muestraBuscaCliente();
                system("pause");
                break;
            case '8':
                ordenacionSeleccionArchivoEmail();
                system("pause");
                break;

            }
            }while(opcionCli!=ESC);
            break;
        case '2':
            do{
            system("cls");
            menuConsumos();
            opcionCon=getch();
            system("cls");
            srand (time(NULL));
            switch(opcionCon){

                case '1':
                    cargaArchListaConsumos();
                    system("cls");
                    break;

                case '2':
                    mostrarArchConsumos();
                    system("pause");
                    break;
                case '3':
                    modificacionConsumo();
                    break;
                case '4':
                    modificoBajaConsumo();
                    break;
                case '5':
                    preguntaFechaConsumo();
                    system("pause");
                    break;
                case '6':
                    CargaUnConsmoRandom();
                    system("pause");
                    break;

                            }

        }while(opcionCon!=ESC);

    }
    }while(opcion!=ESC);

    return 0;
}

///MENU PRINCIPAL.
void menuPrincipal(){
    printf("\t\t <<MENU PRINCIPAL>>");
    printf("\n\n");
    printf("1- Listado de clientes.\n");
    printf("\n2- Listado de consumos.\n");
    printf("\n\n");
    printf("ESC para salir...");
}
///MENU DE LA LISTA DE CLIENTES.
void menuClientes(){
      printf("\t\tListado de clientes.");
    printf("\n\n");
    printf("1- Cargar un cliente nuevo...\n\n");
    printf("2- Mostrar lista de clientes...\n\n");
    printf("3- Modificar un cliente...\n\n");
    printf("4- Dar de baja/alta un cliente...\n\n");
    printf("5- Mostrar clientes ordenados por DNI (activos)...\n\n");
    printf("6- Mostrar clientes ordenados por Apellido (activos)...\n\n");
    printf("7- Buscar un cliente por DNI (activos)...\n\n");
    printf("8- Mostrar clientes ordenados por mail (inactivos)...\n\n");
    printf("\n\n");
    printf("ESC para salir...");


}
///MENU DE LA LISTA DE CONSUMOS
void menuConsumos(){
    printf("\t\tConsumos.");
    printf("\n\n");
    printf("1- Carga un consumo. \n\n");
    printf("2- Muestra consumos. \n\n");
    printf("3- Modificar consumo. \n\n");
    printf("4- Dar de baja un consumo.\n\n");
    printf("5- Mostrar consumos por fecha.\n\n");
    printf("6- Cargar consumor random.");
    printf("\n\n");
    printf("ESC para salir...");
}

/**********************************************
FUNCION TIPO CLIENTE CARGA UNA ESTRUCTURA.
NO RECIBO NADA.
CREO ESTRUCTURA, LA CARGO.
RETORNO ESTRUCTURA CLIENTE.
**********************************************/
stCliente cargaUnCliente ()
{
    stCliente c;

    do {
        printf("\t Ingrese el numero de cliente: ");
        scanf("%d", &c.nroCliente);
    }while(c.nroCliente<0 && c.nroCliente < 99999 || validoNroCliente(c.nroCliente));

    printf("\t Ingrese el nombre del cliente: ");
    fflush(stdin);
    gets(c.nombre);
    printf("\t Ingrese el apellido del cliente: ");
    fflush(stdin);
    gets(c.apellido);

    do{
    printf("\t Ingrese el DNI del cliente: ");
    scanf("%d", &c.dni);
    }while(validoDNI(c.dni));

    do {
        printf("\t Ingrese el email del cliente: ");
        fflush(stdin);
        gets(c.email);
    }while(!validaEmail(c.email));

    printf("\t Ingrese el domicilio del cliente: ");
    fflush(stdin);
    gets(c.domicilio);
    printf("\t Ingrese el numero de celular: ");
    scanf(" %d", &c.movil);
    c.baja=0;

    return c;
}
/***************************************
VALIDO EMAIL.
RECIBO STRING EMAIL.
RECORRO EL STRING LETRA POR LETRA
COMPRUEBO SI HAY UN "@", si hay flag=1
si no hay flag=-1
RETORNO FLAG. (VERDADERO O FALSO)
***************************************/
int validaEmail(char email[]){
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag==0){
        if(email[i]==64){ ///64 ES "@" EN ASCII
            flag=1;
        }
        i++;
    }
    return flag;
}

/**********************************************
FUNCION CARGAR UN ARREGLO TIPO INT.
RECIBO EL ARREGLO, LOS VALIDOS, Y LA DIMENSION.
CARGO EL ARREGLO Y EL ID DE CADA POSICION.
RETORNO LOS VALIDOS.
**********************************************/
int cargarListaClientes(stCliente c[], int v, int dim){
    char opcion;
    while(v<dim && opcion!=ESC){
        system("cls");
        c[v]=cargaUnCliente();
        c[v].id=v;
        v++;
        opcion=getch();
        printf("\n\nESC para salir...");
    }
    return v;
}
/**********************************************
GUARDAR UN CLIENTE EN UN ARCHIVO.
RECIBO EL CLIENTE(ESTRUCTURA), ABRO ARCHIVO
LO GUARDO Y LO CIERRO.
**********************************************/
void guardarUnCliente(stCliente c){
    FILE *pArchClientes=fopen(AR_CLIENTES,"ab");
    if(pArchClientes){
    fwrite(&c,sizeof(stCliente),1,pArchClientes);
    fclose(pArchClientes);
    }
}
/**********************************************
CARGAR EN EL ARCHIVO UNA LISTA DE CLIENTES.
CREO UNA ESTRUCTURA Y LA METO EN UN BUCLE DE
CARGA.
**********************************************/
void cargarArchListaClientes(){
   stCliente c;
    char opcion;
    while(opcion !=ESC){
        c=cargaUnCliente();
        c.id=buscoUltimoID()+1;
        guardarUnCliente(c);
        printf("\n\nESC para salir...");
         fflush(stdin);
        opcion=getch();
    }
}
/**********************************************
FUNCION QUE BUSCA EL ULTIMO ID EN EL ARCHIVO.
TIPO INT.
RECORRO EL CURSOR PARA BUSCAR EL ULTIMO ID.
RETORNO LA ULTIMA POSICION.
**********************************************/
int buscoUltimoID(){
    stCliente c;
    int id=-1;
    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes){
        fseek(pArchClientes,sizeof(stCliente)*(-1),SEEK_END);
        if(fread(&c,sizeof(stCliente),1,pArchClientes)>0){
            id=c.id;
        }
        fclose(pArchClientes);
    }
    return id;
}
/**********************************************
MUESTRO UN CLIENTE.
**********************************************/
void muestraUnCliente(stCliente c){
    printf("------------------------------------\n");
    printf("Numero de Cliente: %d\n", c.nroCliente);
    printf("Nombre: %s\n", c.nombre);
    printf("Apellido: %s\n", c.apellido);
    printf("D.N.I: %d \n", c.dni);
    printf("Email: %s \n", c.email);
    printf("Telefono: %d \n", c.movil);
    printf("Domicilio: %s\n", c.domicilio);
    printf("\n  Baja s/n: %s \n", (c.baja)?"SI":"NO");
    //printf("\n  ID n %d", c.id);
}
/**********************************************
MOSTRAR ARCHIVO DE CLIENTES.
**********************************************/
void mostrarArchClientes(){
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes){
        while(fread(&c,sizeof(stCliente),1,pArchClientes)>0){
            muestraUnCliente(c);
        }
        fclose(pArchClientes);
    }
}

/**********************************************
FUNCION TIPO CLIENTE QUE BUSCA POR NRO DE CLIENTE
RECIBO EL NUMERO DE CLIENTE, ABRO EL ARCHIVO Y
COMPARO.
SI LO ENCUENTRO RETORNO EL CLIENTE.
**********************************************/
stCliente buscaClienteArchxNroCliente(int nroCliente){
    stCliente c;
    int flag=0;
    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes){
        while(flag==0 && fread(&c,sizeof(stCliente),1,pArchClientes)>0){
           if(nroCliente == c.nroCliente){
            flag=1;
           }
                }

        fclose(pArchClientes);
    }
    if(flag== 0){
        c.id=-1;
    }
    return c;
}
/**********************************************
FUNCION DONDE SE BUSCA AL CLIENTE Y LO MUESTRA.
**********************************************/
void encontrarClienteArch(){

    int nroCliente;
    stCliente c;
    printf("Ingrese el numero de cliente que desea modificar: ");
    scanf("%d", &nroCliente);
    system("cls");
    c=buscaClienteArchxNroCliente(nroCliente);
    if(c.id!=-1){
    muestraUnCliente(c);
    system("pause");
    modificarClienteArch(c);
    }else{
        printf("No se ha encontrado el apellido en la lista.\n\n");
    }
}
/**********************************************
MENU PARA MODIFICAR LOS DATOS DEL CLIENTE.
**********************************************/
void menuModificacionDatos(){
    printf("Que datos desea modificar?\n");
    printf("\n");
    printf("\n1- Numero de Cliente.\n");
    printf("\n2- Nombre.\n");
    printf("\n3- Apellido.\n");
    printf("\n4- D.N.I.\n");
    printf("\n5- Email.\n");
    printf("\n6- Telefono.\n");
    printf("\n7- Domicilio.\n");
    printf("\n\n\n9- GUARDAR CLIENTE.\n");
    printf("\n");
    printf("ESC para salir...");
}
/**********************************************
MODIFICAR UN CLIENTE DEL ARCHIVO.
RECIBO UN CLIENTE, LO MODIFICO.
**********************************************/
void modificarClienteArch(stCliente c){
    char opcion;
    do{
        system("cls");
    menuModificacionDatos();
    fflush(stdin);
    opcion=getch();
    system("cls");

    switch(opcion){
case '1':
    do{
        printf("\n Ingrese el nuevo numero de cliente: ");
        scanf("%d", &c.nroCliente);
    }while(c.nroCliente<0 || c.nroCliente>9999 || validoNroCliente(c.nroCliente));
    system("pause");
    break;
case '2':
     printf(" Ingrese el nuevo nombre de el cliente: ");
    fflush(stdin);
    gets(c.nombre);
    system("pause");
    break;
case '3':
    printf(" Ingrese el nuevo apellido de el cliente: ");
    fflush(stdin);
    gets(c.apellido);
    system("pause");
    break;
case '4':
   do{
    printf("\t Ingrese el nuevo DNI del cliente: ");
    scanf("%d", &c.dni);
    }while(validoDNI(c.dni));
    break;
case '5':
    do{
        printf(" Ingrese el nuevo EMail de el cliente: ");
        fflush(stdin);
        gets(c.email);
    }while(!validaEmail(c.email));
    system("pause");
    break;
case '7':
    printf(" Ingrese el nuevo Domicilio de el cliente: ");
    fflush(stdin);
    gets(c.domicilio);
    system("pause");
    break;
case '6':
     printf(" Ingrese el nuevo Numero de celular de el cliente: ");
    scanf(" %d", &c.movil);
    system("pause");
    break;

case '9':
        modifRegistro(c);
        printf("Cliente guardado...\n\n");
        system("pause");
    break;
    }
   }while(opcion!=ESC);
}


/**********************************************
BUSCO LA POSICION DE UN CLIENTE.
RECIBO LA ID ABRO ARCHIVO Y COMPARO.
RETORNO LA POSICION.
**********************************************/
int buscaPosicion(int id){
    int pos=-1;
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes){
        while(pos == -1 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0){
            if(c.id == id){
                pos = ftell(pArchClientes)/sizeof(stCliente)-1;
            }
        }
        fclose(pArchClientes);
    }

    return pos;
}
/**********************************************
MODIFICO EL REGSITRO DE UN CLIENTE EN ARCHIVO.
RECIBO UN CLIENTE MODIFICADO Y LO GUARDO POR SU
ID.
**********************************************/
void modifRegistro(stCliente c){
    int pos;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES, "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stCliente)*pos, SEEK_SET); /// depende de lo que retorne buscaPosicion()
        fwrite(&c, sizeof(stCliente), 1, pArchClientes);
        fclose(pArchClientes);
    }
}

void funcion05()
{
    int DNI = 0;
    int dato=0;
    stCliente c;
    printf("\t Dar de baja un cliente \n");
    printf("Ingrese el DNI del cliente\n");
    scanf("%d", &DNI);
    printf("\t Ingrese 1 para baja y 0 para alta \n");

    c = buscaPosicionDNI(DNI);
    scanf(" %d", &c.baja);
    if(c.id == -1){
        printf("El cliente no existe, ingrese un DNI valido \n");
    }else {
        modifRegistro(c);
    }

}
stCliente buscaPosicionDNI(int dni){

    stCliente c;
    int flag = 0;

    FILE *pArchClientes = fopen(AR_CLIENTES,"rb"); ///abrimos archivo
    if(pArchClientes)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0) ///recorremos archivo si flag esta en 0
        {
            if(c.dni == dni) ///si hay coincidencia del dni del parametro con dni de archivo flag pasa a valer 1 y se corta el ciclo
            {
                flag = 1;
            }
        }
        fclose(pArchClientes); ///cerramos archivo

    }
    if(flag == 0) ///si no se econtro el dni, retornamos el cliente con id -1
    {
        c.id=-1;
    }
    return c; ///retornamos el cliente
}
int validoDNI(int dni)
{
    int flag = 0;///declaro una bandera
    stCliente c;

    FILE *pArchCliente = fopen(AR_CLIENTES, "rb");///abro el arcchivo

    if(pArchCliente)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCliente) > 0)///recorro todo el archivo
        {
            if(dni == c.dni)///comparo el numero de dni recibido con los del resto del archivo
            {
                flag = 1;///si se encuentra uno igual el flag lo iguala a 0
            }
        }
    }

    return flag;///si retorna 0 es que es valido si retorna 1 no es valido
}
int validoNroCliente(int nro)
{
    int flag = 0;///decalro una bandera
    stCliente c;

    FILE *pArchCliente = fopen(AR_CLIENTES, "rb");///abro el archivo

    if(pArchCliente)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCliente) > 0)///recorro todo el archivo
        {
            if(nro == c.nroCliente)///comparo el dni recibido con cada uno de los que estan en el archivo
            {
                flag = 1;///si existe otro igual retorna 1
            }
        }
    }

    return flag;///si retorna 0 es que es valido si retorna 1 no es valido
}

///*********************************************************************************///
///FUNCIONES DE LISTADO DE ACTIVOS
///*********************************************************************************///


int archivoAArregloAltas(stCliente a[], int dim)
{
   int v = 0;///creo los validos del arreglo recibido
   stCliente c;

   FILE *pArchCliente = fopen(AR_CLIENTES, "rb");///abro el archivo en modo lectura

    if(pArchCliente)
    {
        while(fread(&c, sizeof(stCliente),1, pArchCliente) > 0)///recorro todo el archivo
        {
            if((c.baja == 0) && v<dim)///controlo que el archivo no tenga mas datos de los que soporta el arreglo
            {
                a[v] = c;///igualo el dato de ese archivo al arreglo en su posicion correspondiente
                v++;///incremento su posicion
            }

        }

        fclose(pArchCliente);///cierro el archivo
    }

    return v;///retorno los validos
}
/********************************************************
ORDENAMIENTOS POR DNI A LA LISTA DE CLIENTES (SELECCION)
********************************************************/

///funcion que intercambia  variables

void intercambio(stCliente *i, stCliente *menor)
{
    stCliente aux;

    aux = *menor;
    *menor = *i;
    *i = aux;
}

void muestraArreglo(int v, stCliente a[])
{
    int i;
    for(i = 0; i<v; i++)
    {
        muestraUnCliente(a[i]);
    }

}

int buscaMenorDNIArreglo(int v, stCliente a[], int pos)
{
    int posmenor = pos;///toma como posicion menor el valor de pos
    int i = pos + 1;///al arreglo se empieza a recorrer una posicion mas adelante que posmenos

    while(i<v)///se recorre todo el arreglo

    {
        if(a[i].dni < a[posmenor].dni)///compara el valor de i con el de posmenor
        {
            posmenor = i;///si es menor posmenor toma el valor de i
        }
        i++;
    }

    return posmenor;///retorna el valor de la posicion menor
}
///recibe los validos y el array de alumnos
void ordenamientoSeleccionAregloDNI(int v, stCliente a[])
{
    int posmenor = 0;///recibe lo que retorna la busqueda de la posicion menor
    int i = 0;

    while(i<v)///recorre todo el arreglo
    {
        posmenor = buscaMenorDNIArreglo(v, a, i);///posmenor almacena lo que retorna la funcion aneterior

        intercambio(&a[i], &a[posmenor]);

        i++;
    }

}

void ordenacionSeleccionArchivoDNI()
{
    stCliente ordenacion[DIM_CLI];///este arreglo almacena los clientes del archivo para luego ser ordenado
    int vOrdenacion = 0;

    vOrdenacion = archivoAArregloAltas(ordenacion, DIM_CLI);///paso el archivo al arreglo

    ordenamientoSeleccionAregloDNI(vOrdenacion, ordenacion);///ordeno el arreglo

    muestraArreglo(vOrdenacion, ordenacion);

}

///funcion que busca el menor apellido dentro de un arreglo de stcliente

int buscaMenorApellidoArreglo(int v, stCliente a[], int pos)
{
    int posmenor = pos;///toma como posicion menor el valor de pos
    int i = pos + 1;///al arreglo se empieza a recorrer una posicion mas adelante que posmenos


    while(i<v)///se recorre todo el arreglo
    {
        ///res = strcmpi(a[i], a[posmenor]);
        if(strcmpi(a[i].apellido, a[posmenor].apellido) < 0)///compara el valor de i con el de posmenor
        {
            posmenor = i;///si es menor posmenor toma el valor de i
        }
        i++;
    }

    return posmenor;///retorna el valor de la posicion menor
}

///ordenamiento por selleccion por apellido
///recibe los validos y el array de alumnos
void ordenamientoSeleccionAregloApellido(int v, stCliente a[])
{
    int posmenor = 0;///recibe lo que retorna la busqueda de la posicion menor
    int i = 0;

    while(i<v)///recorre todo el arreglo
    {
        posmenor = buscaMenorApellidoArreglo(v, a, i);///posmenor almacena lo que retorna la funcion aneterior

        intercambio(&a[i], &a[posmenor]);

        i++;
    }

}

///ordena el archivo por apellido
/// FUNCION DE LLAMADA DESDE EL MAIN
void ordenacionSeleccionArchivoApellido()
{
    stCliente ordenacion[DIM_CLI];///este arreglo almacena los clientes del archivo para luego ser ordenado
    int vOrdenacion = 0;

    vOrdenacion = archivoAArregloAltas(ordenacion, DIM_CLI);///paso el archivo al arreglo

    ordenamientoSeleccionAregloApellido(vOrdenacion, ordenacion);///ordeno el arreglo

    muestraArreglo(vOrdenacion, ordenacion);

}

///busco y retorno cliente por numero de documento

stCliente buscaClienteDNI(int dni)
{
    stCliente c;
    int flag = 0;///creo una bandera que me sirva de corte para el while
    FILE *pArchCliente = fopen(AR_CLIENTES, "rb");///abro el archivo

    if(pArchCliente)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCliente) > 0)///lo recorro
        {
            if(c.dni == dni)///compruebo si son iguales los numeros de dni
            {
                flag = 1;///pongo flag en uno para que no entre mas al while
            }
            else
            {
                c.id = -1;///si no existe un dni igual le asigno a nro de cliente -1
            }
        }
        fclose(pArchCliente);///cierro el archivo
    }


    return c;///retorno el cliente
}

///muestra el cliente que se deseo buscar

void muestraBuscaCliente()
{
    int dni;
    stCliente c;
    printf("Ingrese DNI para buscar: ");///le pido al usuario que ingrese el dni para buscarlo
    scanf("%d", &dni);

    c = buscaClienteDNI(dni);///igualo lo que retorna la funcion a c

    if(c.nroCliente == -1)///si el numero de cliente es -1 el cliente no existe
    {
        printf("\nEl cliente no existe...\n\n");
    }
    else
    {
        printf("\nEste es el cliente: \n\n");///si no se muestra los datos el cliente
        muestraUnCliente(c);
    }

}

/******************************************
ORDENAMIENTOS DE LOS CLIENTES DADOS DE
BAJA. ORDENADOS POR EMAIL (DRLRCCION)
******************************************/

///paso un archivo a un arreglo con filtro

int archivoAArregloBajas(stCliente a[], int dim)
{
   int v = 0;///creo los validos del arreglo recibido
   stCliente c;

   FILE *pArchCliente = fopen(AR_CLIENTES, "rb");///abro el archivo en modo lectura

    if(pArchCliente)
    {
        while(fread(&c, sizeof(stCliente),1, pArchCliente) > 0)///recorro todo el archivo
        {
            if((c.baja == 1) && v<dim)///controlo que el archivo no tenga mas datos de los que soporta el arreglo
            {
                a[v] = c;///igualo el dato de ese archivo al arreglo en su posicion correspondiente
                v++;///incremento su posicion
            }
        }

        fclose(pArchCliente);///cierro el archivo
    }

    return v;///retorno los validos
}

///funcion que busca el menor email dentro de un arreglo de stcliente (dados de baja)

int buscaMenorEmailArreglo(int v, stCliente a[], int pos)
{
    int posmenor = pos;///toma como posicion menor el valor de pos
    int i = pos + 1;///al arreglo se empieza a recorrer una posicion mas adelante que posmenos


    while(i<v)///se recorre todo el arreglo
    {
        ///res = strcmpi(a[i], a[posmenor]);
        if(strcmpi(a[i].email, a[posmenor].email) < 0)///compara el valor de i con el de posmenor
        {
            posmenor = i;///si es menor posmenor toma el valor de i
        }
        i++;
    }

    return posmenor;///retorna el valor de la posicion menor
}

///ordenamiento por selleccion por email dados de baja
///recibe los validos y el array de alumnos
void ordenamientoSeleccionAregloEmail(int v, stCliente a[])
{
    int posmenor = 0;///recibe lo que retorna la busqueda de la posicion menor
    int i = 0;

    while(i<v)///recorre todo el arreglo
    {
        posmenor = buscaMenorEmailArreglo(v, a, i);///posmenor almacena lo que retorna la funcion aneterior

        intercambio(&a[i], &a[posmenor]);

        i++;
    }

}

///ordena el archivo por email a los que estan dados de baja

void ordenacionSeleccionArchivoEmail()
{
    stCliente ordenacion[DIM_CLI];///este arreglo almacena los clientes del archivo para luego ser ordenado
    int vOrdenacion = 0;

    vOrdenacion = archivoAArregloBajas(ordenacion, DIM_CLI);///paso el archivo al arreglo

    ordenamientoSeleccionAregloEmail(vOrdenacion, ordenacion);///ordeno el arreglo

    muestraArreglo(vOrdenacion, ordenacion);///muestra el arrreglo ya ordenado

}

/********************************************************************************************/

///GUARDA UN CONSUMO EN ARCHIVO
void guardarUnConsumo(stConsumo consumo)
{
    FILE *pArchConsumos=fopen(AR_CONSUMOS,"ab");
    if(pArchConsumos){
    fwrite(&consumo,sizeof(stConsumo),1,pArchConsumos);
    fclose(pArchConsumos);
    }
}

/// CARGA UN CONSUMO, RETORNA EL CONSUMO
stConsumo cargaUnConsumo ()
{
    int dni =0;
    do{
    printf("Ingrese el DNI del cliente a cargar el consumo \n");
    scanf(" %d", &dni);
    }while(!validoDNI(dni));
    stCliente cliente = buscaClienteDNI(dni);
    stConsumo consumo;

    consumo.idCliente = cliente.id;

    printf("Ingrese al anio \n");
    scanf(" %d", &consumo.anio);
    do{
    printf("Ingrese el mes \n");
    scanf(" %d", &consumo.mes);
    }
    while(consumo.mes < 1 || consumo.mes > 12);

    printf("Ingrese el dia \n");
    scanf(" %d", &consumo.dia);
    do{
    printf("Ingrese el consumo 0/500 \n");
    scanf(" %d", &consumo.datosConsumidos);
    }while(consumo.datosConsumidos < 0 || consumo.datosConsumidos > 500);
    consumo.baja=0;
    return consumo;
}

/// BUSCA UN RANGO AL AZAR, RECIBE EL PARAMETRO INFERIOR Y EL PARAMETRO SUPERIOR
int randomRango(int rangoMin ,int rangoMax)
{
    int rango = rangoMin + rand() % (rangoMax +1 - rangoMin);
    return rango;
}

///BUSCA UN CLIENTE AL AZAR Y LO RETORNA
stCliente clienteRandom ()
{
    stCliente c;
    int id = randomRango(0,buscoUltimoID());
    int flag = 0;

    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes) {
        while(flag == 0 && fread(&c,sizeof(stCliente),1,pArchClientes) > 0) {
            if(id== c.id) {
                flag = 1;
            }
        }
        fclose(pArchClientes);
    }
    return c;
}

///BUSCA EL ULTIMO ID DE CONSUMOS
int buscoUltimoIDConsumos()
{
    stConsumo c;
    int id=-1;
    FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
    if(pArchConsumos){
        fseek(pArchConsumos,sizeof(stConsumo)*(-1),SEEK_END);
        if(fread(&c,sizeof(stConsumo),1,pArchConsumos)>0){
            id=c.id;
        }
        fclose(pArchConsumos);
    }
    return id;
}

///CARGA EL ARCHIVO CON UN CONSUMO
void cargaArchListaConsumos()
{
    stConsumo c;
    char opcion;
    while(opcion !=ESC) {

        c=cargaUnConsumo();
        c.id= buscoUltimoIDConsumos()+1;
        guardarUnConsumo(c);
        printf("ESC para salir \n");
        fflush(stdin);
        opcion = getch();
    }
}
///MUESTRA UN CONSUMO, RECIBE EL CONSUMO
void muestraUnConsumo(stConsumo c)
{
    printf("------------------------------------\n");
    printf("Numero de Cliente: %d\n", c.idCliente);
    printf("Anio: %d\n", c.anio);
    printf("Mes: %d\n", c.mes);
    printf("Dia: %d \n", c.dia);
    printf("Consumos en MB: %d \n", c.datosConsumidos);
    printf("\n  Baja s/n: %s \n", (c.baja)?"SI":"NO");
    ///printf("\n  ID n %d", c.id);
}

///MUESTRA TODOS LOS CONSUMOS
void mostrarArchConsumos()
{
    stConsumo c;
    FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
    if(pArchConsumos){
        while(fread(&c,sizeof(stConsumo),1,pArchConsumos)>0){
            muestraUnConsumo(c);
        }
        fclose(pArchConsumos);
    }
}

/* ///SIN TERMINAR
stConsumo CargaUnConsmo()
{
    stCliente cliente;
    stConsumo consumo;
    cliente = clienteRandom(); ///cliente al azar
    stConsumo.datosConsumidos = randomRango(0,500); ///megas al azar
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentAnio;
    int currentDia;
    int currentMes;
    currentAnio = tm.tm_year + 1900;
    currentMes = tm.tm_mon +1;
    currentDia = tm.tm_mday;
    //printf("anio: %d, mes %d, dia %d", currentAnio, currentMes, currentDia);
    printf("Ingrese ")
*/

/****************************************
MODIFICA LOS DATOS CONSUMIDOS DE CONSUMO.
BUSCO X DNI AL CLIENTE, BUSCO FECHA DE CONSUMO Y MODIFICO.
****************************************/
void modificacionConsumo(){
    stCliente c;
    stConsumo a;
    int dni;
    int anio;
    int mes;
    int dia;
    printf("Ingrese el anio: \n");
    scanf("%d",&anio);
    printf("Ingrese el el mes: \n");
    scanf("%d",&mes);
    printf("Ingrese el dia: \n");
    scanf("%d",&dia);
    system("cls");
    printf("Ingrese el DNI del cliente: ");
    scanf("%d",&dni);
    system("cls");
    c=buscaClienteDNI(dni);
    a=buscaxIDConsumo(c.id,anio,mes,dia);
    muestraUnConsumo(a);
    if(a.idCliente!=-1){
        printf("\n\nUsted busco el cliente: %s\n\n",c.apellido);
        system("pause");
        system("cls");
        modificarConsumo(a);
    }else{
        printf("No se ha encontrado ningun cliente con el DNI ingresado...\n\n");
    }
}
/****************************************
MENU DE LA MODIFICACION DE CONSUMO.
****************************************/
void menuModificacionConsumo(){
    printf("\t\t MODIFICACION CONSUMOS.");
    printf("\n\n");
    printf("1-Modificar consumo.\n\n");
    printf("2-GUARDAR MODIFICACION.");
    printf("\n\n");
    printf("ESC para salir...");
}

/****************************************
MODIFICO CONSUMO, RECIBO UN CONSUMO A.
OPCIONES 1: MODIFICO DATO CONSUMIDO.
OPCION 2: GUARDO MODIFICACION EN ARCHIVO.
****************************************/
void modificarConsumo(stConsumo a){

    char opcion;
    do{
        system("cls");
        menuModificacionConsumo();
        opcion=getch();
        system("cls");
        switch(opcion){
    case '1':
        ///a=cambiarConsumo(a);
        printf("Ingrese los MB nuevos: ");
        scanf("%d",&a.datosConsumidos);
        break;
    case '2':
       modifRegistroCONSUMOS(a);
        system("pause");
        break;
        }
    }while(opcion!=ESC);


}
/****************************************
CAMBIO CONSUMO, RECIBO CONSUMO A.
CAMBIO DATOS CONUMIDOS.
RETORNO EL CONSUMO.
****************************************/
stConsumo cambiarConsumo(stConsumo a){

    if(a.idCliente!= -1){
        printf("Ingrese el nuevo consumo: \n\n");
        scanf("%d", &a.datosConsumidos);
        system("pause");
    }else{
        printf("No se ha encontrado una fecha en los consumos.\n\n");
        system("pause");
    }

    return a;
}
/****************************************
MODIFICO CONSUMO, RECIBO EL CONSUMO MODIFICADO.
GUARDO EN EL ARCHIVO DE LA MISMA POSICION.
****************************************/
void modifRegistroCONSUMOS(stConsumo c){
    int pos;
    pos = buscaPosicionCONSUMO(c.id);
    FILE *pArchConsumo = fopen(AR_CONSUMOS, "r+b");
    if(pArchConsumo){
        fseek(pArchConsumo, sizeof(stConsumo)*pos, SEEK_SET); /// depende de lo que retorne buscaPosicion()
        fwrite(&c, sizeof(stConsumo), 1, pArchConsumo);
        fclose(pArchConsumo);
    }
}
/****************************************
BUSCO LA POSICION EN ARCHIVO CONSUMO.
RECIBO UNA ID.
LO BUSCO Y RETORNO POSICION.
SI NO EXISTE RETORNO -1.
****************************************/
int buscaPosicionCONSUMO(int id){
    int pos=-1;
    stConsumo c;
    FILE *pArchConsumo = fopen(AR_CONSUMOS,"rb");
    if(pArchConsumo){
        while(pos == -1 && fread(&c, sizeof(stConsumo), 1, pArchConsumo) > 0){
            if(c.id == id){
                pos = ftell(pArchConsumo)/sizeof(stConsumo)-1;
            }
        }
        fclose(pArchConsumo);
    }

    return pos;
}

/****************************************
BUSCO ID EN EL CONSUMO.
RECIBO EL ID, Y LA FECHA DEL CONSUMO.
RETORNO EL CONSUMO... LA POSICION SI EXISTE.
Y -1 SI NO EXISTE.
****************************************/
stConsumo buscaxIDConsumo(int id, int anio, int mes, int dia){
    stConsumo a;
    int flag=0;
    FILE *pArchConsumo = fopen(AR_CONSUMOS,"rb");
    if(pArchConsumo){
            while(flag ==0 && fread(&a,sizeof(stConsumo),1,pArchConsumo)>0){
                if(a.idCliente == id && a.anio==anio && a.mes==mes && a.dia==dia){
                    flag=1;
                }
            }
        fclose(pArchConsumo);
    }
    if(flag == 0){
        a.idCliente = -1;
    }
    return a;
}

void modificoBajaConsumo()
{
    stCliente cliente;
    stConsumo consumo;
    int dni = 0;
    int baja = 0;
    int anio, mes, dia;
    int flag = 0;

    ///le pide al usuario que ingrese la fecha en la cual se quiere dar de baja
    printf("Ingrese a%co: ", 164);
    scanf("%d", &anio);
    printf("Ingrese mes: ");
    scanf("%d", &mes);
    printf("Ingrese dia: ");
    scanf("%d", &dia);


    printf("Ingrese el DNI: ");///pide el DNI
    scanf("%d", &dni);

    cliente = buscaClienteDNI(dni);///busca el cliente por dni y lo retorna
    consumo = buscaxIDConsumo(cliente.id, anio, mes, dia);///busca el consumo relacionado al cliente que reotorna la funcion anterior

    if(cliente.nroCliente != -1)///si se retorna el cliente deseado se muestra el nombre y el apellido
    {
        printf("\nUsted busco a: %s %s \n\n",cliente.nombre, cliente.apellido);

    }
    else///si no existe se muestra este mensaje
    {
        printf("El cliente no existe\n\n");
    }

    if(consumo.idCliente != -1)///se corrobora que exista el consumo
    {
        do
        {
        printf("Ingrese 1 para dar de baja o 0 para dar de alta: ");///se pide si se quiere dar de alta o de baja
        scanf("%d", &baja);
        consumo.baja = baja;///se iguala la baja requerida a la baja del consumo
        } while(baja < 0 || baja > 1);
    }
    else
    {
        printf("\nLa fecha no existe...\n\n");
    }

    modifRegistroCONSUMOS(consumo);///se modifica el regsitro

}

void buscarConsumoFecha(int anio, int mes, int dia){
    stConsumo a;
    FILE *pArchConsumo= fopen(AR_CONSUMOS,"rb");
    if(pArchConsumo){
            while(fread(&a,sizeof(stConsumo),1,pArchConsumo)> 0){
                if(a.anio == anio && a.mes == mes && a.dia == dia){
                   muestraUnConsumo(a);
                }
            }
        fclose(pArchConsumo);
    }
}
void preguntaFechaConsumo(){
    int anio;
    int mes;
    int dia;
    printf("Ingrese el anio: \n");
    scanf("%d",&anio);
    printf("Ingrese el el mes: \n");
    scanf("%d",&mes);
    printf("Ingrese el dia: \n");
    scanf("%d",&dia);
    system("cls");
    buscarConsumoFecha(anio,mes,dia);
}
/**
* \brief Funcion que retorna la maxima cantidad de dias que tiene algun mes del anio (hasta mes 6)
* \param Recibe el mes
* \return Retorna la cantidad de dias de ese mes
**/
int diaMax (int mes)
{
    int dias; ///cantidad de dias que va a tener el mes
    if (mes == 1 || mes == 3 || mes == 5)
    {
        dias = 31;
    } else if (mes == 2)
    {
        dias = 28;
    }else if (mes == 4 || mes == 6)
    {
        dias= 30;
    }

    return dias;


}


stConsumo ConsumoRandom()
{
    stConsumo consumo;
    stCliente cliente;
    cliente = clienteRandom(); ///aca genero un cliente random
    consumo.idCliente = cliente.id; ///le asigno a nuestro consumo random nuestro id random

    ///FUNCIONES DE TIEMPO
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentAnio;
    int currentDia;
    int currentMes;

    ///FECHA ACTUAL
    currentAnio = tm.tm_year + 1900;
    currentMes = tm.tm_mon +1;
    currentDia = tm.tm_mday;

    ///FECHAS RANDOM (aca las cargo)
    consumo.mes = randomRango(1,currentMes);
    consumo.dia = randomRango(1, diaMax(consumo.mes));
    consumo.anio = currentAnio;
    consumo.datosConsumidos = randomRango(0,500);
    consumo.baja=0;

    return consumo; ///retorno un consumo con datos al azar
}

stConsumo CargaUnConsmoRandom()
{
    stConsumo c;
    for (int i=0; i<1000 ;i++){
        c = ConsumoRandom();
        c.id = buscoUltimoIDConsumos()+1;
        guardarUnConsumo(c);
    }

}
