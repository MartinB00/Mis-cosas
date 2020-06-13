# Mis-cosas
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define LISTA_CLIENTES "Clientes.dat"
typedef struct{
    int id;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[50];
    char domicilio[50];
    int movil;
    int baja; /// 1 si esta activo / 0 si esta dado de baja.
}stClientes;
typedef struct{
    int id;
    int idCliente;
    int anio;
    int mes; ///1 al 12.
    int dia; ///1 a... depende los meses.
    int datosConsumidos;
    int baja; /// 1 activo / 0 de baja.
}stConsumos;

#define ESC 27

void menuPrincipal();
void menuClientes();
void menuConsumos();
stClientes cargaUnCliente();
int validaEmail(char email[]);
int cargarListaClientes(stClientes c[], int v, int dim);
void guardarUnCliente(stClientes c);
void cargarArchListaClientes();
int buscoUltimoID();
void muestraUnCliente(stClientes c);
void mostrarArchClientes();
stClientes buscaClienteArchxNroCliente(int nroCliente);
void encontrarClienteArch();
void modificarClienteArch(stClientes c);
void menuModificacionDatos();
int buscaPosicion(int id);
void guardarClienteModificadoArch(stClientes c);
void modifRegistro(stClientes c);


int main()
{
    stClientes Lista[30];
    stConsumos Consumos[30];
    char opcion;
    char opcionCli;
    char opcionCon;
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
            }
            }while(opcionCli!=ESC);
            break;
        case '2':
            do{
            system("cls");
            menuConsumos();
            opcionCon=getch();
            system("cls");
            switch(opcionCon){


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
    printf("\n\n");
    printf("ESC para salir...");


}
///MENU DE LA LISTA DE CONSUMOS
void menuConsumos(){
    printf("\t\tConsumos.");
    printf("\n\n");
    printf("Aca va todo consumos etc...");
    printf("\n\n");
    printf("ESC para salir...");
}

/**********************************************
FUNCION TIPO CLIENTE CARGA UNA ESTRUCTURA.
NO RECIBO NADA.
CREO ESTRUCTURA, LA CARGO.
RETORNO ESTRUCTURA CLIENTE.
**********************************************/
stClientes cargaUnCliente(){
    stClientes c;

    do{
        printf("\n Ingrese el nro de Cliente: ");
        scanf("%d", &c.nroCliente);
    }
    while(c.nroCliente<0 || c.nroCliente>9999999);
    printf(" Ingrese el Nombre: ");
    fflush(stdin);
    gets(c.nombre);
    printf(" Ingrese el Apellido: ");
    fflush(stdin);
    gets(c.apellido);
    printf(" Ingrese el DNI: ");
    scanf(" %d", &c.dni);
    do{
        printf(" Ingrese el EMail: ");
        fflush(stdin);
        gets(c.email);
    }while(!validaEmail(c.email));
    printf(" Ingrese la Domicilio: ");
    fflush(stdin);
    gets(c.domicilio);
    printf(" Ingrese el Numero de celular: ");
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
    int flag=-1;
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
int cargarListaClientes(stClientes c[], int v, int dim){
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
void guardarUnCliente(stClientes c){
    FILE *pArchClientes=fopen(LISTA_CLIENTES,"ab");
    if(pArchClientes){
    fwrite(&c,sizeof(stClientes),1,pArchClientes);
    fclose(pArchClientes);
    }
}
/**********************************************
CARGAR EN EL ARCHIVO UNA LISTA DE CLIENTES.
CREO UNA ESTRUCTURA Y LA METO EN UN BUCLE DE
CARGA.
**********************************************/
void cargarArchListaClientes(){
   stClientes c;
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
    stClientes c;
    int id=-1;
    FILE *pArchClientes = fopen(LISTA_CLIENTES,"rb");
    if(pArchClientes){
        fseek(pArchClientes,sizeof(stClientes)*(-1),SEEK_END);
        if(fread(&c,sizeof(stClientes),1,pArchClientes)>0){
            id=c.id;
        }
        fclose(pArchClientes);
    }
    return id;
}
/**********************************************
MUESTRO UN CLIENTE.
**********************************************/
void muestraUnCliente(stClientes c){
    printf("------------------------------------");
    printf("\nNumero de Cliente: %d\n", c.nroCliente);
    printf("\nNombre: %s\n", c.nombre);
    printf("\nApellido: %s\n", c.apellido);
    printf("\nD.N.I: %d \n", c.dni);
    printf("\nEmail: %s \n", c.email);
    printf("\nTelefono: %d \n", c.movil);
    printf("\nDomicilio: %s\n", c.domicilio);
    printf("\nActivo(0) o Baja(1): %d \n", c.baja);
}
/**********************************************
MOSTRAR ARCHIVO DE CLIENTES.
**********************************************/
void mostrarArchClientes(){
    stClientes c;
    FILE *pArchClientes = fopen(LISTA_CLIENTES,"rb");
    if(pArchClientes){
        while(fread(&c,sizeof(stClientes),1,pArchClientes)>0){
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
stClientes buscaClienteArchxNroCliente(int nroCliente){
    stClientes c;
    int flag=0;
    FILE *pArchClientes = fopen(LISTA_CLIENTES,"rb");
    if(pArchClientes){
        while(flag==0 && fread(&c,sizeof(stClientes),1,pArchClientes)>0){
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
    stClientes c;
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
    printf("\n8- Estado de actividad (Alta o baja).\n");
    printf("\n\n\n9- GUARDAR CLIENTE.\n");
    printf("\n");
    printf("ESC para salir...");
}
/**********************************************
MODIFICAR UN CLIENTE DEL ARCHIVO.
RECIBO UN CLIENTE, LO MODIFICO.
**********************************************/
void modificarClienteArch(stClientes c){
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
    }while(c.nroCliente<0 || c.nroCliente>9999999);
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
    printf(" Ingrese el nuevo DNI de el cliente: ");
    scanf(" %d", &c.dni);
    system("pause");
    break;
case '5':
    do{
        printf(" Ingrese el nuevo EMail de el cliente: ");
        fflush(stdin);
        gets(c.email);
    }while(!validaEmail(c.email));
    system("pause");
    break;
case '6':
    printf(" Ingrese el nuevo Domicilio de el cliente: ");
    fflush(stdin);
    gets(c.domicilio);
    system("pause");
    break;
case '7':
     printf(" Ingrese el nuevo Numero de celular de el cliente: ");
    scanf(" %d", &c.movil);
    system("pause");
    break;
case '8':
    c.baja=1;
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
    stClientes c;
    FILE *pArchClientes = fopen(LISTA_CLIENTES,"rb");
    if(pArchClientes){
        while(pos == -1 && fread(&c, sizeof(stClientes), 1, pArchClientes) > 0){
            if(c.id == id){
                pos = ftell(pArchClientes)/sizeof(stClientes)-1;
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
void modifRegistro(stClientes c){
    int pos;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(LISTA_CLIENTES, "r+b");
    if(pArchClientes){
        fseek(pArchClientes, sizeof(stClientes)*pos, SEEK_SET); /// depende de lo que retorne buscaPosicion()
        fwrite(&c, sizeof(stClientes), 1, pArchClientes);
        fclose(pArchClientes);
    }
}

