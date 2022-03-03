#include <iostream>
#include <cstdlib>
#include "lista.h"
#include <locale.h>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct punto {
    int porcentajePunto;
    int CodigoTema;
};

struct tipoYpor {
    string Tipoevaluacion;
    int porcentaje = 0;
    lista<punto> puntos;
};

struct corte {
    int numCorte;
    tipoYpor notas[10];
};

struct profesor {
    int cedula;
    string apellido;
    string nombre;
    int numClases;
    lista<corte> CortesDeNotas;
};

struct clases {
    int cedula;
    int cursos[];
};

struct tema {
    int codigo = 0;
    string nombre;
};

lista<profesor> profesores;
lista<tema> temas;

profesor prof;
tema temaA;

bool modified = false;
bool esquemaExiste = false;

void inicializarArreglo();
void generarArchivoProfesores();
void insertarInformacion();
void crearEsquema();
bool recuperarListaTemas();
void visualizarInformacion();
int tam_arreglo(corte);
void crearEsquema();
void insertarProfesor();
void visualizarInformacion();
bool recuperarInformacion();
bool recuperarListaProf();
bool estaModificado();
void borrarInformacion();
void borrarListaProf();
void menuInicio();
void salir();
void insertarTemas();
void consultarEsquema(int );

int main()
{
    setlocale(LC_CTYPE, "Spanish");

    menuInicio();

    return 0;
}

void salir()
{
    char opcion = '0';
    system("cls");

    if (modified == true) {
        while (opcion = '0') {
            cout << endl
                 << " ¡Toda información que no se haya guardado se perderá!" << endl;
            cout << " Si cargo la información de un archivo, esta dejará de estar disponible a menos que sea guardada" << endl;
            cout << " ¿Desea guardar la información antes de salir?" << endl;
            cout << " [1] Guardar y salir" << endl;
            cout << " [2] Solo salir" << endl;
            cout << " [3] Volver al menú anterior" << endl;
            opcion = getch();
            switch (opcion) {
            case '1':
                exit(0);
            case '2':
                borrarInformacion();
                exit(0);
            case '3':
                insertarProfesor();
            default:
                system("cls");
                cout << endl
                     << " Por favor ingrese una opción válida" << endl;
                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;
                opcion = '0';
                system("pause>nul");
                break;
            }
        }
    }
    exit(0);
}

bool estaModificado()
{
    ifstream inFile;
    inFile.open("Archivos/ListaDocentes.txt");
    if (inFile) {
        inFile.close();
        return true;
    }
    return false;
}

void borrarArchivoEsquemas(){
	int status;
	char fname;
	status = remove("Archivos/EsquemaCorte.txt");
}

bool recuperarListaProf(){
    string name, surname;
    int numClass, cc;
    ifstream inFile;

    inFile.open("Archivos/ListaDocentes.txt");

    if (!inFile) {
        return false;
    }
    else {
        while (inFile >> name >> surname >> numClass >> cc) {
            prof.nombre = name;
            prof.apellido = surname;
            prof.numClases = numClass;
            prof.cedula = cc;
            profesores.insertar(prof, cc);
        }
        inFile.close();
        modified = true;
        return true;
    }
}

void generarArchivoEsquemas(){
	int cedula, numPuntos, numProfes, numCortes;
	profesor aux;
	corte corteAux;
	punto puntoAux;
	int cantidadNotas;
	
    ofstream GuardarB;
    
    GuardarB.open("Archivos/EsquemaCorte.txt", ios::app);
	
	for(int i = 1; i <= profesores.get_tam();i++){
       	aux = profesores.buscarSinClave(i);
       	if(aux.CortesDeNotas.lista_vacia()){
       		
       		continue;
       			
		}
		
       	cedula = aux.cedula;
       	GuardarB << cedula << " ";
       	GuardarB << aux.CortesDeNotas.get_tam() << " ";
       	for (int j = 1; j <= aux.CortesDeNotas.get_tam(); j++) {
       		
	   		corteAux = aux.CortesDeNotas.buscar(j);
	   		cantidadNotas = tam_arreglo(corteAux);
	   		GuardarB << cantidadNotas << " ";
	   		for (int l = 0; l < 10; l++){
	   			
	   			
	   			
				GuardarB << corteAux.notas[l].Tipoevaluacion << " ";
	   			GuardarB << corteAux.notas[l].porcentaje << " ";
	   			numPuntos = corteAux.notas[l].puntos.get_tam() ;
	   			GuardarB << numPuntos << " "; 
	   			for (int k = 1; k <= numPuntos; k++) {
	   				
					
	        		puntoAux = corteAux.notas[l].puntos.buscarSinClave(k);
					GuardarB << puntoAux.porcentajePunto << " ";
	        		GuardarB << puntoAux.CodigoTema << " ";
	    		}
	    		
	    		if ( corteAux.notas[l+1].porcentaje == 0 ){
	   				l = 10;
				} 
	    		
				  			
			}
		}
		GuardarB << endl;
    }
	
}

bool recuperarEsquemaCortes()
{
    int cedula, numCortes, numNotas, porcentajeNota, numPuntos, porcentPunto, temaPunto = 0;
    string tipoNota = " ";
    profesor aux1;
    ifstream inFile;
    inFile.open("Archivos/EsquemaCorte.txt");
    if (!inFile) {
        return false;
    }
    else {
        while (inFile >> cedula >> numCortes) {
            aux1 = profesores.buscar(cedula); // Se crea un nodo auxiliar con la información de un profesor
            for (int x = 0; x < numCortes; x++) {
                corte corteA; // Se crea un corte
                inFile >> numNotas;
                for (int y = 0; y < numNotas; y++) {
                    inFile >> tipoNota >> porcentajeNota >> numPuntos;
                    //Se inserta la información de la nota
                    corteA.notas[y].Tipoevaluacion = tipoNota;
                    corteA.notas[y].porcentaje = porcentajeNota;
                    for (int z = 0; z < numPuntos; z++) {
                        inFile >> porcentPunto >> temaPunto;
                        punto puntoA; //Se crea un punto
                        puntoA.porcentajePunto = porcentPunto;
                        puntoA.CodigoTema = temaPunto;
                        corteA.notas[y].puntos.insertarSinClave(puntoA);
                    }
                }
                aux1.CortesDeNotas.insertar(corteA, x + 1); //Se inserta el corte con la información almacenada
                profesores.modificar(cedula, aux1); //Se asocia el corte insertado al profesor
            }
        }
        esquemaExiste = true;
        inFile.close();
        modified = true;
        return true;
    }
    return 0;
}

void borrarInformacion(){
	borrarListaProf();
	borrarArchivoEsquemas();
}

void borrarListaProf()
{
    int status;
    char fname;
    status = remove("Archivos/ListaDocentes.txt");
    if (status != 0) {
        cout << "No se pudo borrar la lista de profesores" << fname << "\n";
    }
}

void generarArchivoProfesores()
{
    ofstream Guardar;
    Guardar.open("Archivos/ListaDocentes.txt", ios::app);
    Guardar << prof.nombre << " " << prof.apellido << " " << prof.numClases << " " << prof.cedula << endl;
}


void insertarProfesor()
{
    int opcion = '0';
    while (opcion == '0') {
        system("cls");

        opcion = '0';

        cout << endl;
        cout << " [1] Agregar un nuevo profesor a la lista" << endl;
        cout << " [2] Visualizar lista de profesores" << endl;
        cout << " [3] Volver al menú anterior" << endl;

        opcion = getch();

        if (opcion == '2') {
            if (modified == false) {

                system("cls");

                cout << endl;
                cout << " Para poder mostrar la lista de docentes, debe haber por lo menos 1 docente inscrito" << endl;
                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;

                system("pause>nul");
            }
            else {
                system("cls");

                profesores.imprimirProfesor();

                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;

                system("pause>nul");
            }
            opcion = '0';
        }
        else if (opcion == '3') {
            insertarInformacion();
        }
        while (opcion == '1') {
            system("cls");

            cout << endl;
            cout << " Por favor ingrese los siguientes datos del docente en el orden mostrado y separados por un espacio" << endl;

            cout << " 1.Nombre \n 2.Apellido \n 3.Cantidad de grupos  \n 4.Cédula" << endl
                 << endl;
            cout << " ";
            cin >> prof.nombre;
            cin >> prof.apellido;
            cin >> prof.numClases;
            cin >> prof.cedula;

            profesores.insertar(prof, prof.cedula);

            modified = true;

            generarArchivoProfesores();

            system("cls");

            cout << endl;
            cout << " ¿Desea agregar otro docente?" << endl;
            cout << " [1] Si" << endl;
            cout << " [2] No" << endl;

            opcion = getch();

            if (opcion == 2) {
                insertarProfesor();
            }
        }
        opcion = '0';
    }
}

void insertarInformacion()
{
    char opcion = '0';

    while (opcion == '0') {
        system("cls");

        cout << endl;
        cout << " [1] Insertar un profesor" << endl;
        cout << " [2] Crear esquema de notas" << endl;
        cout << " [3] Insertar temas" << endl;
        cout << " [4] Borrar informacion" << endl;
        cout << " [5] Volver al menú principal " << endl;
        cout << " [0] Salir" << endl;

        opcion = getch();

        switch (opcion) {

        case '0':
            salir();
        case '1':
            opcion = '0';
            insertarProfesor();
        case '2':

            opcion = '0';
            system("cls");

            if (modified == false) {
                system("cls");

                cout << endl;
                cout << " Para poder crear el esquema de notas, debe haber por lo menos 1 docente inscrito." << endl;
                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;

                system(" pause>nul");

                opcion = '0';

                break;
            }

            cout << endl
                 << " [1] Acceder con la cédula del docente" << endl;
            cout << " [2] Volver al menú anterior " << endl;

            opcion = getch();

            if (opcion == '1') {
                crearEsquema();
            }
            insertarInformacion();

        case '3':

            opcion = '0';
            insertarTemas();

            break;
        case '5':
            menuInicio();
        case '4':
            opcion = '0';
            system("cls");

            if (modified == false) {
                opcion = '0';
                cout << endl
                     << " No existe información que se pueda eliminar" << endl;
                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;
                system("pause>nul");
                insertarInformacion();
            }

            cout << endl
                 << " Borrar información almacenada" << endl;
            cout << " ¡Atención! La información eliminada no se podrá recuperar" << endl;
            cout << " ¿Desea continuar?" << endl;
            cout << " [1] Si" << endl;
            cout << " [2] No" << endl;
            opcion = getch();
            if (opcion == '1') {
                modified = false;
                borrarInformacion();
                system("cls");
                cout << endl
                     << " La información se ha eliminado exitosamente" << endl;
                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;
                system("pause>nul");
            }
            opcion = '0';
            break;
        default:
            system("cls");
            cout << endl;
            cout << " Por favor ingrese una opción válida" << endl;
            cout << endl
                 << " Presione cualquier tecla para continuar..." << endl;

            opcion = '0';

            system("pause>nul");

            break;
        }
    }
}

void consultarEsquema(int a)
{

    system("cls");

    profesor aux;
    int cedula = a;
    char opcion = '1';
	
	
    aux = profesores.buscar(cedula);
	
	 
    opcion = '0';

    corte corteAux; // Se crea corte auxiliar

    int nCorte = 0;
    system("cls");
    cout << endl
         << " Profesor: " << aux.nombre << " " << aux.apellido << endl
         << endl;
    aux.CortesDeNotas.recorrerCorte();

    cout << endl
         << " Escriba el corte para ver su esquema completo: ";
    cin >> nCorte;

    while (!aux.CortesDeNotas.comprobar_clave(nCorte)) {
        cout << endl
             << " Escriba un corte que exista por favor: ";
        cin >> nCorte;
    }

    corteAux = aux.CortesDeNotas.buscar(nCorte);
    cout << endl
         << " Las notas para este corte son:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << endl
             << " Nota " << i + 1 << endl
             << endl;
        corteAux.notas[i].puntos.recorrerEvaluacion();

        if (corteAux.notas[i + 1].porcentaje == 0) {
            i = 10;
        }
    }
	cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;
    system("pause>nul");

    opcion = '0';
}

bool recuperarListaTemas()
{
    int codTema;
    string nombre;
    ifstream inFile;

    inFile.open("Archivos/ListaTemas.txt");

    if (!inFile) {
        return false;
    }
    else {
        while (inFile >> codTema >> nombre ) {
            temaA.codigo=codTema;
            temaA.nombre=nombre;
            temas.insertar(temaA,temaA.codigo);
        }
        inFile.close();
        modified = true;
        return true;
    }
}

void insertarTemas()
{
    int opcion = '0';
    while (opcion == '0') {
        system("cls");

        cout << endl <<"[1] Insertar tema" << endl;
        cout << "[2] Modificar tema" << endl;
        cout << "[3] Visualizar temas" << endl;
        cout << "[4] Volver al menu anterior" << endl;
        opcion = getch();

        switch (opcion) {

        case '1':

            while (opcion == '1') {
                system("cls");

                cout << endl << " Digite el codigo del tema con su nombre separados por un espacio  " << endl;
                cin >> temaA.codigo;
                cin >> temaA.nombre;

                temas.insertar(temaA, temaA.codigo);

                system("cls");

                cout << endl;
                cout << " ¿Desea agregar otro tema?" << endl;
                cout << " [1] Si" << endl;
                cout << " [2] No" << endl;

                opcion = getch();
            }
            opcion = '0';

            break;

        case '2':

            system("cls");
            int codigo;
            cout << "Digite el codigo del tema que desea modificar  " << endl;
            cin >> codigo;
            system("cls");

            cout << " Modificando tema con codigo: " << codigo << endl
                 << endl;
            cout << " Digite el codigo del tema con su nombre separados por un espacio  " << endl;
            cin >> temaA.codigo;
            cin >> temaA.nombre;

            temas.modificar(codigo, temaA);

            opcion = '0';
            break;

        case '3':

            system("cls");

            cout << " Visualizacion de temas " << endl;
            cout << "" << endl;
            temas.imprimirTema();
			 cout << endl
                 << " Presione cualquier tecla para continuar..." << endl;
            system("pause>nul");

            insertarTemas();

            opcion = '0';

            break;

        case '4':
            insertarInformacion();
            break;
        }
    }
}


int tam_arreglo(corte a){
    int tam=0;
    for(int i=0;i<10;i++ ){
        tam++;
		if(a.notas[i+1].porcentaje == 0){
            i = 10;
        }
    }
    return tam;
}

void crearEsquema()
{

    system("cls");

    profesor aux;

    int nota = 1;
    int nCorte = 1;
    int numPunto = 1;
    int cedula = 0;
    int numCorte = 0;
    char opcion = '1';
    int c = 1;
    bool opModificar = false;

    cout << endl
         << " Por favor ingrese la cédula del docente: ";

    cin >> cedula;

    if (profesores.comprobar_clave(cedula) == false) {
        cout << endl
             << " La cédula que ingresó no aparece en el registro, verifique la información" << endl;
        cout << endl
             << " Presione cualquier tecla para continuar..." << endl;

        system(" pause>nul");

        crearEsquema();
    }

    aux = profesores.buscar(cedula);

    opcion = '0';

    while (opcion == '0') {
        system("cls");
        cout << endl;
        cout << " [1] Ingresar cortes y notas " << endl;
        cout << " [2] Visualizar esquema " << endl;
        cout << " [3] Volver al menú anterior " << endl;

        opcion = getch();
        if (opcion == '1') {
            if (!aux.CortesDeNotas.lista_vacia()) {

                opcion == '0';
                system("cls");
                cout << endl
                     << " Este profesor ya cuenta con un esquema de cortes y notas " << endl;
                cout << " ¿Desea continuar?" << endl;
                cout << " [1] Si" << endl;
                cout << " [2] No" << endl;
                opcion = getch();
                if (opcion != '1') {
                    opcion = '0';
                }
            }
            if (opcion == '1') {
                system("cls");
                cout << endl
                     << " [1] Ingresar un corte " << endl;
                cout << endl
                     << " [2] Modificar un corte " << endl;
                cout << endl;
                cout << " [3] Volver al menú anterior" << endl;
                opcion = getch();

                if (opcion == '2') {
                    opModificar = true;
                    opcion = '1';
                }
                if (opcion != '1' && opcion != '2') {
                    opcion = '0';
                }
            }
        }
        else if (opcion == '3') {
            insertarInformacion();
        }
        else if (opcion == '2') {
            if (aux.CortesDeNotas.lista_vacia()) {
                system("cls");
                cout << endl
                     << " No existe esquema de notas y cortes para el profesor seleccionado " << endl;
                opcion = '0';
            }
            else {

                consultarEsquema(cedula);
            }
            cout << endl
                 << " Presione cualquier tecla para continuar..." << endl;
            system("pause>nul");
        }

        while (opcion == '1') { //aqui se agregaran lOS CORTES hasta que la persona no desee mas

            system("cls");
            int i = 0;
            int j = 1;
            numCorte = aux.CortesDeNotas.get_tam();

            c = aux.CortesDeNotas.get_tam();
            corte corteA; // Se un crea el corte el cual es una estructura que se guardara en la lista de cortes
            while (opcion == '1') { //aqui se agregaran LAS NOTAS para cadacorte, se agregaran hasta que la persona no quiera mas
                numPunto = 1;

                system("cls");
                if (opModificar) {
                    cout << endl
                         << " Para el corte que desea modificar escriba el tipo de notas y porcentaje separados por un espacio." << endl;
                    cout << " ";
                }
                else {
                    cout << endl
                         << " Para el corte " << c + 1 << " escriba el tipo de notas y porcentaje separados por un espacio." << endl;
                    cout << " ";
                }

                //ya que el corte solo tiene una clave y un arreglo de notas aca simplmente accedemos a ese arreglo y lo llenamos

                cin >> corteA.notas[i].Tipoevaluacion; //primer dato de una nota
                cin >> corteA.notas[i].porcentaje; //segundo  dato de una nota
                //ojo observese que este arreglo guarda estructuras de tipo "tipoYpor" que son como se compone una sola nota

                opcion = '1';

                while (opcion == '1') { //aqui se agregaran LOS PUNTOS para cada nota del corte, se agregaran hasta que la persona no quiera mas
                    punto puntoA; // Se un crea un punto el cual es una estructura que se guardara en la lista de puntos

                    system("cls");
                    opcion = '1';
                    cout << endl
                         << " Para la nota " << j << " de " << corteA.notas[i].Tipoevaluacion << " escriba el porcentaje del punto " << numPunto << " y el tema que se evalúa" << endl;
                    cout << " ";
                    cin >> puntoA.porcentajePunto; //se llena el primer dato de la estructura punto
                    cin >> puntoA.CodigoTema; //se llena el primer dato de la estructura punto

                    while (!temas.comprobar_clave(puntoA.CodigoTema)) {
						system("cls");
                        cout << endl
                             << " El tema con el codigo " << puntoA.CodigoTema << " no existe" << endl
                             << endl;
                        cout << " Por favor digite un codigo de un tema valido " << endl
                             << endl;
                        cin >> puntoA.CodigoTema;
                    }

                    //en este momento creamos el punto pero no se a agregado a la lista de puntos

                    corteA.notas[i].puntos.insertarSinClave(puntoA); //aqui al corte en su nota especifica se le agrega el tercer y ultimo dato que es el punto  que se agregara a su lista

                    system("cls");
                    cout << endl
                         << " El punto ha sido insertado " << endl;
                    cout << " ¿Desea agregar otro punto a la nota " << j << " de " << corteA.notas[i].Tipoevaluacion << "?" << endl;
                    cout << " [1] Si" << endl;
                    cout << " [2] No" << endl;
                    opcion = getch();

                    numPunto++;
                }

                esquemaExiste = true;
                i++;

                system("cls");
                cout << endl
                     << " Las notas han sido insertadas en el corte " << endl
                     << endl;
                cout << " ¿Desea agregar otro tipo de notas para este Corte?" << endl;
                cout << " [1] Si" << endl;
                cout << " [2] No" << endl;

                opcion = getch();
            }

            //OJO HASTA ESTE PUTNO SOLO HEMOS LLENADO LA ESTRUCTURA CORTE PERO NO LA HEMOS AGREGADO A LISTA DEL PROFESOR

            //modificar cortes
            system("cls");
            if (opModificar) {
                int corteMod = 0;
                opcion = '0';
                cout << " ¿ Cuál es el número del corte el cual desea modificar?" << endl;
                cin >> corteMod;
                aux.CortesDeNotas.modificar(corteMod, corteA); // MODIFICAMOS EL CORTE
                profesores.modificar(cedula, aux); // MODIFICAMOS LA LISTA DE PROFESORES
                esquemaExiste = true;
                cout << endl
                     << " El corte ha sido modificado" << endl
                     << endl;

                opModificar = false;
            }
            else {
                //insertar un corte

                opcion = '1';
                numCorte++;
                aux.CortesDeNotas.insertar(corteA, numCorte); // SE AGREGA EL CORTE CREADO A LA LISTA DE CORTES DEL PROFESOR
                profesores.modificar(cedula, aux); // MODIFICAMOS LA LISTA DE PROFESORES
                esquemaExiste = true;
                cout << endl
                     << " El corte ha sido insertado" << endl
                     << endl;
                cout << " ¿ Desea agregar otro corte junto a su esquema de notas para este profesor?" << endl;
                cout << " [1] Si" << endl;
                cout << " [2] No" << endl;
				opcion = getch();
				if(opcion == '2'){
					borrarArchivoEsquemas();
					generarArchivoEsquemas();
				}
            }
        }
        opcion = '0';
    }
}

void visualizarInformacion()
{
    char opcion = '0';
    int cedula = 0;
    system("cls");

    cout << endl;
    cout << " Menú de visualización" << endl;
    cout << " Por favor seleccione la información que desea consultar" << endl;
    cout << " [1] Consultar lista de docentes" << endl;
    cout << " [2] Consultar esquema de notas" << endl;
    cout << " [3] Consultar lista temas" << endl;
    cout << " [4] Volver al menú principal" << endl;
    cout << " [0] Salir" << endl;

    opcion = getch();

    switch (opcion) {
    case '0':
        exit(0);
    case '1':
        opcion = '0';
                system("cls");

                profesores.imprimirProfesor();

                cout << endl;
                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;

                system("pause>nul");

                visualizarInformacion();
            case '2':
				system("cls");
                cout << endl
                     << " Por favor ingrese la cédula del docente: ";

                cin >> cedula;

                if (profesores.comprobar_clave(cedula) == false) {
                    cout << endl
                         << " La cédula que ingresó no aparece en el registro, verifique la información" << endl;
                    cout << endl
                         << " Presione cualquier tecla para continuar..." << endl;

                    system(" pause>nul");

                    visualizarInformacion();
                }
                
               

                consultarEsquema(cedula);
                visualizarInformacion();
               
            case '3':
            	system("cls");

            cout << " Visualizacion de temas " << endl;
            cout << "" << endl;
            temas.imprimirTema();
			 cout << endl
                 << " Presione cualquier tecla para continuar..." << endl;
            system("pause>nul");

            visualizarInformacion();

            break;
            	
			case '4':
				menuInicio();
				
				default:
                cout << endl;
                cout << " Por favor ingrese una opción válida" << endl;
                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;

                system("pause>nul");

               visualizarInformacion();
			
			}
}

bool recuperarInformacion()
{
    bool profExist, esquemaExist , temaExist = false;
    profExist = recuperarListaProf();
    esquemaExist = recuperarEsquemaCortes();
    temaExist= recuperarListaTemas();
    if (profExist == true  || esquemaExist == true || temaExist == true) {
        return true;
    }
    return false;
}

void menuInicio()
{
    char opcion = '0';
    if (estaModificado()) {
        modified = true;
    }
    while (opcion == '0') {
        system("cls");

        cout << endl
             << "             Menú de inicio " << endl;
        cout << " Por favor seleccione la opción deseada: " << endl;
        cout << " [1] Insertar información" << endl;
        cout << " [2] Recuperar información" << endl;
        cout << " [0] Salir" << endl;

        opcion = getch();

        switch (opcion) {
        case '0':
            exit(0);
        case '1':
            system("cls");
            opcion = '0';
            if (modified == false) {
                insertarInformacion();
            }
            cout << endl
                 << " Existe un archivo con información almacenada" << endl;
            cout << " ¿Desea continuar? " << endl;
            cout << " [1] Borrar el archivo y continuar" << endl;
            cout << " [2] Cargar el archivo y continuar" << endl;
            cout << " [3] Volver al menú anterior" << endl;
            opcion = getch();
            if (opcion == '1') {
                modified = false;
                borrarInformacion();
                insertarInformacion();
            }
            else if (opcion == '2') {
                recuperarInformacion();
                insertarInformacion();
            }
            menuInicio();
        case '2':
            system("cls");
            if (modified == false) {
                cout << endl
                     << " No hay información para recuperar" << endl;
                cout << endl
                     << " Presione cualquier tecla para continuar..." << endl;
                system("pause>nul");
                menuInicio();
            }
            recuperarInformacion();
            visualizarInformacion();

        default:
            system("cls");

            cout << endl;
            cout << " Por favor ingrese una opción valida" << endl;
            cout << endl
                 << " Presione cualquier tecla para continuar..." << endl;

            system("pause>nul");

            opcion = 0;
            break;
        }
    }
}
