/*******************************************************************************************
*								UNIVERSIDAD DE	COLIMA																		*
*			                     FACULTAD DE TELEMATICA																	*
*								PROYECTO INTEGRADOR																        *
*	SISTEMA DE INFORMACIÓN PARA EVALUAR EL SERVICIO QUE OFRECEN			* 
*						LAS BIBLIOTECAS DE LA UNIVERSIDAD DE COLIMA								*
********************************************************************************************/
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;
class Encuesta //Clase
{
	private:
		char comentario [256]; //Variable para ingresar comentario
		int tipo;	//Establece quien contesta la encuesta
		char carrera[256];	//Variable para ingresar carrera
		char biblioteca [256];	//Variable para ingresar biblioteca
		int semestre;	//Variable para ingresar semestre
		int calificacion [10]; //Vector para calificar preguntas
		int respuesta;	//Variable para comparar el rango de calificacion

	public:
		Encuesta();	//Constructor basio donde se iniciaisan las variables
		void hacerPreguntas();	//Metodo para hacer preguntas
		void guardarPreguntas();	//Metodo para guardar preguntas
		void leerRespuestas();	//Metodo para leer respuestas
		void gotoxy(int x, int y);	//Metodo para establecer coordenas
		void dibujarBarraLeer();	//Metodo para dibujar barra
		void dibujarBarraEscribir();	//Metodo para dibujar barra
		void pedirDatos();	//Metodo para pedir datos
		
};
Encuesta::Encuesta()	//Constructor vacio
{
	tipo=0;	//Se inicialisa en 0
	semestre=0;	//Se inicialisa en 0
	respuesta=0;	//Se inicialisa en 0
	calificacion[10]=0;	//Se inicialisa en 0
}
void Encuesta::pedirDatos()	//Pedir datos del visitante
{
	system("clear");	//borrar pantalla
	//Pide el tipo de usuario
	cout<<"Que tipo de usuario eres? \n";
	cout<<"Presiona 1 si eres ALUMNO\n";
	cout<<"Presiona 2 si eres DOCENTE\n";
	cout<<"Presiona 3 si eres INVESTIGADOR\n";
	cout<<"Presiona 4 si eres OTRO\n";
	cin>>tipo; //Guarda el tipo de usuario	
	if( tipo==1)	//Condicional si es Alumno
	{
		system("clear");	//borrar pantalla
		cout<<"Ingresa la carrera que estudias"<<endl;	//Pide la carrera que se cursa
		cout<<"Por favor usa - para contestar:"<<endl;
		cin>>carrera;	//Ingresa carrera
		cout<<"****************************"<<endl;
		cout<<"Ingresa el semestre en el que estudias actualmente: ";	//Pide el semestre que se cursa
		cin>>semestre;	//Ingresa el semestre
		cout<<"*****************************"<<endl;
		cout<<"Que biblioteca estas visitando?"<<endl;	//Pide el nombre de la Biblioteca
		cout<<"Por favor usa - para contestar:"<<endl;
		cin>>biblioteca;	//Ingresa Biblioteca
	}	
	else if( tipo==2)	//Condicional si es Docente
	{
		system("clear");	//borrar pantalla
		cout<<"Que biblioteca estas visitando?"<<endl;	//Pide el nombre de la Biblioteca
		cout<<"Por favor usa - para contestar:"<<endl;
		cin>>biblioteca;	//Ingresa Biblioteca
	}
	else if( tipo==3)	//Condicional si es Investigador
	{
		system("clear");	//borrar pantalla
		cout<<"Que biblioteca estas visitando?"<<endl; //Pide el nombre de la Biblioteca
		cout<<"Por favor usa - para contestar:"<<endl;
		cin>>biblioteca;	//Ingresa Biblioteca
	}
	else if( tipo==4)	//Condicional si es Otro
	{
		system("clear");	//borrar pantalla
		cout<<"Que biblioteca estas visitando?"<<endl;	//Pide el nombre de la Biblioteca
		cout<<"Por favor usa - para contestar:"<<endl;
		cin>>biblioteca;	//Ingresa Biblioteca
	}
	else
	{
		cout<<"Tipo no válido\n";	//Si tipo es mayor a 4
		return;	//Regresa al menu
	}
	guardarPreguntas();	//Manda a guardar las respuestas de las preguntas
	}
void Encuesta::dibujarBarraLeer()  //Mostrar barra de transferencia al abrir archivo 
{
	int i=0, w=0;  //Inicializadores para ciclos While
	int s=3,t=0 ; //Tiempo de transferencia
	int l=30;	//Longitud de la barra
	int x=1,y=1; //Coordenadas de posicionamiento para la barra
	int r=32; //Cordenada de posicionamiento para titulo
	t=s*1000/l;	//Convertir a segundos
	//Primera barra
	system("cls");
	cout<<"..::Leyendo Archivo::..\n";
	while(i <=l)	//Dibuja barra de tiempo faltante
	{
		gotoxy(x, y);	//Indica donde se imprime la barra
		cout<<"0%";	//Indica el valor inicial de la barra
		gotoxy(x+i+1, y);	//Establece en que posicion se mueve el caracter
		cout<<char( 176);	//Imprime caracter de barra
		i++;
	}
	//Segunda barra
	while(w<l)	//Dibujar barra de tiempo transcurrido
	{
		gotoxy(x, y-2);	//Indica donde se imprime la barra
		Sleep(t);		//Establece la velocidad
		gotoxy(x,y);	//Indica donde se imprime el valor inicial de la barra
		cout<<"0%";	//Indica el valor inicial de la barra
		gotoxy(x+w+1, y);	//Establece en 	que posiscion se mueve el caracter
		cout<<char(219);	//Imprime el otro caracter de barra
		gotoxy(r,y);	//Establece donde imprimira el valor de la barra segun el tiempo transcurrido
		cout<<" "<<w/s*11<<"%";	//Indica el valor de la barra segun el tiempo transcurrido
		w++;
	}
	system("cls");	//Borrar pantalla
}
void Encuesta::dibujarBarraEscribir()  //Mostrar barra de transferencia al guardar en archivo
{
	int i=0, w=0;  //Inicializadores para ciclos While
	int s=3,t=0 ; //Tiempo de transferencia
	int l=30;	//Longitud de la barra
	int x=1,y=1; //Coordenadas de posicionamiento para la barra
	int r=32; //Cordenada de posicionamiento para titulo
	t=s*1000/l;	//Convertir a segundos
	//Primera barra
	system("cls");	//Borra pantalla
	cout<<"..::Guardando Archivo::..\n";
	while(i <=l)	//Dibuja barra de tiempo faltante
	{
		gotoxy(x, y);	//Indica donde se imprime la barra
		cout<<"0%";	//Indica el valor inicial de la barra
		gotoxy(x+i+1, y);	//Establece en que posicion se mueve el caracter
		cout<<char( 176);	//Imprime caracter de barra
		i++;
	}
	//Segunda barra	
	while(w<l)	//Dibujar barra de tiempo transcurrido
	{
		gotoxy(x, y-2);	//Indica donde se imprime la barra
		Sleep(t);	//Establece la velocidad
		gotoxy(x,y);		//Indica donde se imprime el valor inicial de la barra
		cout<<"0%";	//Indica el valor inicial de la barra
		gotoxy(x+w+1, y);	//Establece en que posicion se mueve el caracter
		cout<<char(219);	//Imprime el otro caracter de barra
		gotoxy(r,y);	//Establece donde se imprimira el valor de la barra segun el tiempo transcurrido
		cout<<" "<<w/s*11<<"%";	//Indica el valor de la barra segun el tiempo transcurrido
		w++;
	}
	system("cls");	//Borrar pantalla
}
void Encuesta::gotoxy(int x, int y) //Coordenadas de barra de transferencia
{
	COORD coord;
    coord.X=x;	//Establece coordenada en x
	coord.Y	=y;	//Establece coordenada en y
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , coord);
}
void Encuesta::guardarPreguntas()  //Guarda respuestas en el archivo 
{
	hacerPreguntas();	//Manda a la funcion de Contestar preguntas
	string clave;	//Aqui se guarda lo que se encuentra dentro del archivo .txt
	ifstream in_file("C:\\contrasena\\contrasena.txt");	//Abre el archivo .txt de la ubicacion establecida
	getline(in_file,clave);	//Mueve lo del archivo al la variable antes establecida
	system("cls");	//Borrar pantalla
	//dibujarBarraEscribir();	//Muestra la barra para guardar preguntas
	if (clave=="E94ksnv.-")	//Si la contraseña coincide y la memoria esta conectada, el sistema continua
	{
		cout<<"AQUI estoy\n";
		ofstream archivoSalida("C:\\temp\\encuesta.bin", ios::app | ios::binary );	//Crea el archivo, o escribe en uno ya existente
		archivoSalida.write((char*)&tipo,sizeof(tipo));	//Guarda el tipo de quien la contesta
		if (tipo==1)	//Si el tipo es alumno
		{
		archivoSalida.write((char*)&carrera,sizeof(carrera));	//Guarda carrera
		archivoSalida.write((char*)&semestre,sizeof (semestre));	//Y guarda semestre
		}	//Si no lo es
		archivoSalida.write((char*)&biblioteca,sizeof (biblioteca));	//Guarda la biblioteca visitada
		archivoSalida.write((char*)&calificacion[1],sizeof (calificacion[1]));	//Guarda calificacion1
		archivoSalida.write((char*)&calificacion[2],sizeof (calificacion[2]));	//Guarda calificacion2
		archivoSalida.write((char*)&calificacion[3],sizeof (calificacion[3]));	//Guarda calificacion3
		archivoSalida.write((char*)&calificacion[4],sizeof (calificacion[4]));	//Guarda calificacion4
		archivoSalida.write((char*)&calificacion[5],sizeof (calificacion[5]));	//Guarda calificacion5
		archivoSalida.write((char*)&calificacion[6],sizeof (calificacion[6]));	//Guarda calificacion6
		archivoSalida.write((char*)&calificacion[7],sizeof (calificacion[7]));	//Guarda calificacion7
		archivoSalida.write((char*)&calificacion[8],sizeof (calificacion[8]));	//Guarda calificacion8
		archivoSalida.write((char*)&calificacion[9],sizeof (calificacion[9]));	//Guarda calificacion9
		archivoSalida.write((char*)&comentario,sizeof (comentario));	//Guarda comentario
	archivoSalida.close();	//Cierra el archivo
	cout<<"\n..::Preguntas guardadas::..";
	}
	else	//Si la calve no coincide o la memoria no se encuentra conectada
	{
		cout <<"Error: No se puede abrir, contrasena equivocada o archivo no encontrado"   << endl;		//Muestra mensaje de error
		exit (8);	//Cierra el programa
	}
}
void Encuesta::leerRespuestas() //Muestra las respuestas guardadas  
{		
	system("clear");	//Borra pantalla
	//dibujarBarraLeer();	//Imprime barra de lectura de archivo	
	ifstream archivoLectura("C:\\temp\\encuesta.bin", ios::in | ios::binary);	//Abre el archivo para impriir lo que tenga dentro
	cout<<"..::Datos::..\n";
	while (!archivoLectura.eof())	//Mientras el archivo no tenga final de cadena
	{
		archivoLectura.read((char*)&tipo,sizeof(tipo));	//Lee el tipo de quien contesto la encuesta
		if (tipo==1)	//Si tipo es igual a 1
		{
			cout<<"ALUMNO"<<endl;	//Imprime que es Alumno
			archivoLectura.read((char*)&carrera,sizeof (carrera));	//Lee la carrera que cursa
			cout<<"Carrera: "<<carrera<<endl;	//Imprime la carrera
			archivoLectura.read((char*)&semestre,sizeof (semestre));	//Lee el semestre en que se encuentra el alumno
			cout<<semestre<<" Semestre"<<endl;	//Imprime el semestre
		 }
		else if (tipo==2)	//Si tipo es igual a 2
		{
			cout<<"DOCENTE"<<endl;	//Imprime que es docente
		}
		else if (tipo==3)	//Si tipo es igual a 3
		{
			cout<<"INVESTIGADOR"<<endl;	//Imprime que es Investigador
		}
		else if (tipo==4)	//Si tipo es igual a 4
		{
			cout<<"OTRO"<<endl;	//Imprime que es Otro
		}
		//Para todos los usuario
		archivoLectura.read((char*)&biblioteca,sizeof (biblioteca));	//Lee la biblioteca
		cout<<"Biblioteca: "<<biblioteca<<endl;	//Imprime la biblioteca
		
		archivoLectura.read((char*)&calificacion[1],sizeof (calificacion[1]));	//Lee la calificacion 1
		cout<<calificacion[1]<<endl;	//Imprime califiacion 1
		archivoLectura.read((char*)&calificacion[2],sizeof (calificacion[2]));	//Lee la calificacion 2
		cout<<calificacion[2]<<endl;	//Imprime califiacion 2
		archivoLectura.read((char*)&calificacion[3],sizeof (calificacion[3]));	//Lee la calificacion 3
		cout<<calificacion[3]<<endl;	//Imprime califiacion 3
		archivoLectura.read((char*)&calificacion[4],sizeof (calificacion[4]));	//Lee la calificacion 4
		cout<<calificacion[4]<<endl;	//Imprime califiacion 4
		archivoLectura.read((char*)&calificacion[5],sizeof (calificacion[5]));	//Lee la calificacion 5
		cout<<calificacion[5]<<endl;	//Imprime califiacion 5
		archivoLectura.read((char*)&calificacion[6],sizeof (calificacion[6]));	//Lee la calificacion 6
		cout<<calificacion[6]<<endl;	//Imprime califiacion 6
		archivoLectura.read((char*)&calificacion[7],sizeof (calificacion[7]));	//Lee la calificacion 7
		cout<<calificacion[7]<<endl;	//Imprime califiacion 7
		archivoLectura.read((char*)&calificacion[8],sizeof (calificacion[8]));	//Lee la calificacion 8
		cout<<calificacion[8]<<endl;	//Imprime califiacion 8
		archivoLectura.read((char*)&calificacion[9],sizeof (calificacion[9]));	//Lee la calificacion 9
		cout<<calificacion[9]<<endl;	//Imprime califiacion 9
		archivoLectura.read((char*)&comentario,sizeof (comentario));	//Lee comentario
		cout<<comentario<<endl;	//Imprime comentario

		cout<<"***********"<<endl;
	}	
	
	archivoLectura.close();	//Cierra el archivo
	cout<<"..::ENTER para continuar::..\n"<<endl;	//Pide que el usuario presione un enter
	getchar();	//Al presionar enter regresa al menu
	getchar();
	
}
void Encuesta::hacerPreguntas() //Contestar preguntas
{
	//Pregunta 1	
	do
	{
		system("clear");
		cout<<"1.¿Con que frecuencia usted visita la biblioteca? \n";
		cout<<"Escriba 1 = Casi nunca o nunca\n";
		cout<<"Escriba 2 = Pocas veces\n";
		cout<<"Escriba 3 = Frecuentemente\n";
		cout<<"Escriba 4 = Muy frecuentemente\n";
		cin>>respuesta;	//Guarda respuesta
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[1]=respuesta;	//Guarda en la posicion 2 del vector de califiacion
	}
	//Pregunta 2
	do
	{
		system("clear");	//Borrar la pantalla
		cout<<"2.-¿Que le parecen nuestras instalaciones? \n";
		cout<<"Escriba 1 = Muy malas\n";
		cout<<"Escriba 2 = Tienen lo minimo\n";
		cout<<"Escriba 3 = Muy buenas\n";
		cout<<"Escriba 4 = Excelentes\n";
		cin>>respuesta;
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[2]=respuesta;	//Guarda en la posicion 1 del vector de califiacion
	}
	//Pregunta 3
	do
	{	
		system("clear");	//Borrar la pantalla
		cout<<"3.-¿Cuando usted viene a la biblioteca utiliza el material de computo? \n";
		cout<<"Escriba 1 = Casi nunca o nunca\n";
		cout<<"Escriba 2 = Pocas veces\n";
		cout<<"Escriba 3 = Frecuentemente\n";
		cout<<"Escriba 4 = Siempre\n";
		cin>>respuesta;
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[3]=respuesta;	//Guarda en la posicion 3 del vector de califiacion
	}
	//Pregunta 4
	do
	{
		system("clear");	//Borrar la pantalla
		cout<<"4.-¿Como califica este material? \n";
		cout<<"Escriba 1 = Malo o pobre\n";
		cout<<"Escriba 2 = Elemental\n";
		cout<<"Escriba 3 = Bueno\n";
		cout<<"Escriba 4 = Muy bueno\n";
		cin>>respuesta;
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[4]=respuesta;	//Guarda en la posicion 4 del vector de califiacion
	}
	//Pregunta 5
	do
	{
		system("clear");	//Borrar la pantalla
		cout<<"5.-¿Con que motivo viene en particular? \n";
		cout<<"Escriba 1 = No tengo opciones o el maestro quiere un titulo en especifico\n";
		cout<<"Escriba 2 = Como ultimo recurso\n";
		cout<<"Escriba 3 = Vengo cuando no encuentro recursos en la web\n";
		cout<<"Escriba 4 = Es una de mis primeras opciones\n";
		cin>>respuesta;
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[5]=respuesta;	//Guarda en la posicion 5 del vector de califiacion
	}
	//Pregunta 6
	do
	{	
		system("clear");	//Borrar la pantalla
		cout<<"6.-¿Con que frecuencia busca algun libro? \n";
		cout<<"Escriba 1 = Casi nunca o nunca\n";
		cout<<"Escriba 2 = Pocas veces\n";
		cout<<"Escriba 3 = Frecuentemente\n";
		cout<<"Escriba 4 = Muy frecuentemente\n";
		cin>>respuesta;
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[6]=respuesta;	//Guarda en la posicion 6 del vector de califiacion
	}
	//Pregunta 7
	do
	{
		system("clear");	//Borrar la pantalla
		cout<<"7.-¿Es bueno nuestro software de busqueda? \n";
		cout<<"Escriba 1 = No sirve para mi\n";
		cout<<"Escriba 2 = Es muy limitado\n";
		cout<<"Escriba 3 = Basicamente funciona\n";
		cout<<"Escriba 4 = Es muy bueno y eficaz\n";
		cin>>respuesta;
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[7]=respuesta;	//Guarda en la posicion 7 del vector de califiacion
	}
	//Pregunta 8
	do
	{	
		system("clear");	//Borrar la pantalla	
		cout<<"8.-¿Ha encontrado todos los libros necesarios? \n";
		cout<<"Escriba 1 = Casi nunca o nunca\n";
		cout<<"Escriba 2 = Pocas veces\n";
		cout<<"Escriba 3 = Frecuentemente\n";
		cout<<"Escriba 4 = Muy frecuentemente\n";
		cin>>respuesta;
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[8]=respuesta;	//Guarda en la posicion 8 del vector de califiacion
	}
	//Pregunta 9
	do
	{
		system("clear");	//Borrar la pantalla
		cout<<"9.-¿Como califica nuestrra viblioteca? \n";
		cout<<"Escriba 1 = Muy malas, material insuficiente\n";
		cout<<"Escriba 2 = Tienen lo minimo\n";
		cout<<"Escriba 3 = Muy buenas, muy buen acervo\n";
		cout<<"Escriba 4 = Excelentes, acervo muy completo\n";
		cin>>respuesta;
	}
	while(respuesta<1 || respuesta > 4);	//Si se encuntra dentro del rango
	{
		calificacion[9]=respuesta;	//Guarda en la posicion 9 del vector de califiacion
	}
	//Pregunta 10 - comentario
	system("clear");	//Borrar la pantalla
	cout << "10.- Nos podrias proporcionar una opinion sobre esta Biblioteca:"<<endl;	//Pide el comentario
	cout<<"Por favor usa - para contestar"<<endl;
	cin>>comentario;	//Ingresa comentario
}

int main() //Codigo principal
{
	//string clave;	//Aqui se guarda lo que se encuentra dentro del archivo .txt
	//ifstream in_file("C:\\contrasena\\contrasena.txt");	//Abre el archivo .txt de la ubicacion establecida
	//getline(in_file,clave);	//Mueve lo del archivo al la variable antes establecida
	//if (clave=="E94ksnv.-")	//Si la contraseña coincide y la memoria esta conectada, el sistema continua
	//{
		Encuesta r;	//Establece r como un objeto de la clase Encuesta
		int a;	//variabla para escojer la opcion deseada
		a=0;
		while(a!=3)//ciclo para si desea continuar
		{
			system ("clear");	//borra pantalla			//system ("clear");
			cout<<"|La Universidad De Colima, a traves de su Facultad de Telematica, ha puesto en"<<endl;
			cout<<"marcha un proyecto de Sistema de Evaluacion de Bibliotecas, que pretende"<<endl;
			cout<<"detectar las posibilidades de mejoramiento de este servicio. Para ello te"<<endl;
			cout<<"agradecemos que respondas esta encuesta, en la que solicitamos tu opinion"<<endl;
			cout<<"sobre las Bibliotecas, asi como de los recursos y servicios ofrecidos por las"<<endl;
			cout<<"mismas. Muchas gracias por tu colaboracion."<<endl<<endl;
			//Pide que ingrese una opcion para comensar con el sistema
			cout<<"Que quieres hacer: \n";
			cout<<"Presiona 1 para CONTESTAR ENCUESTA\n";
			cout<<"Presiona 2 para VER RESPUESTAS\n";
			cout<<"Presiona 3 para SALIR\n";
			cin>>a;	//Ingresa opcion
			if (a==1)	//Si la opcion ingresada es igual a 1
			{
				r.pedirDatos();	//Llama a la funcion para pedir los datos
			}
			else if(a==2)	//Si la opcion ingresada es igual a 2
			{
				string clave;	//Aqui se guarda lo que se encuentra dentro del archivo .txt
				ifstream in_file("C:\\contrasena\\contrasena.txt");	//Abre el archivo .txt de la ubicacion establecida
				getline(in_file,clave);	//Mueve lo del archivo al la variable antes establecida
				if (clave=="E94ksnv.-")	//Si la contraseña coincide y la memoria esta conectada, el sistema continua
				{
					r.leerRespuestas();	//Llama a la funcion para leer las respuestas
				}
				else	//Si la calve no coincide o la memoria no se encuentra conectada
				{
					cout <<"Error: No se puede abrir, contrasena equivocada o archivo no encontrado"   << endl;	//Muestra mensaje de error
					exit (8);	//Cierra programa
				}
			}	//Cierre del ciclo while, y si la opcion seleccionada es mayor a 3 se sale del sistema
		//}
	cout<<endl;	//Salto de linea
	system("clear");	//Borrar pantalla
	}
	//else	//Si la calve no coincide o la memoria no se encuentra conectada
	//{
      //cout <<"Error: No se puede abrir, contrasena equivocada o archivo no encontrado"   << endl;	//Muestra mensaje de error
      //exit (8);	//Cierra el programa
   // }
}

