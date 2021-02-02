#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void escribirArchivo(string Titulo);
void AppArchivo(string Titulo);
void leerArchivo(string Titulo);
void Registro(string Titulo);
void Menu(void);
void Menu2(void);
int main(void) 
{
  string Titulo;
  string Formato=".txt";
  cout<<"Introduzca el nombre del archivo (sin .txt): ";
  getline(cin,Titulo);
  Titulo.append(Formato);
  int Tipo, Reg=0;
  do
  {
    Menu();
    cout<<" \n\nIngrese el numero de su opcion: ";
    cin>>Tipo;
    getchar();
    switch (Tipo) 
	  {
      case 1:
         if(Reg==0)
         {
          escribirArchivo(Titulo);
          Reg=1; 
         }
         else Registro(Titulo); 
       break;          
	    case 2:
         leerArchivo(Titulo);
       break;          
	    case 3:       
       cout<<"\n-------MUCHAS GRACIAS ------\n";
       break;
	    default:cout<<"\nERROR, Al introducir la opcion\n";
       break;
     }
  }
  while(Tipo!=3);
  return 0;
} 
///Funcion Menu
void Menu(void)
{  
  cout<<"\t\t╔═════════════════════════════╗\n";
  cout<<"\t\t║           █ MENÚ █          ║\n";
  cout<<"\t\t║  1) Ingreso de datos        ║\n";
  cout<<"\t\t║  2) Mostrar Datos           ║\n";
  cout<<"\t\t║  3) Salir                   ║\n";
  cout<<"\t\t╚═════════════════════════════╝\n";		
}
//------Ingrseo de datos a registro----//
void escribirArchivo(string Titulo)
{ 
  string nombre, apellido, carrera;
  char r;
  int edad;
  ofstream Archivero;
  Archivero.open(Titulo.c_str(),ios::out);
  do
  {
    cout<<"Ingrese el nombre: ";
    getline(cin,nombre);
    cout<<"Ingrese el apellido: ";
    getline(cin,apellido);
    cout<<"Ingrese la carrera: ";
    getline(cin,carrera);
    cout<<"Ingrese la edad: ";
    cin>>edad;
    Archivero<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
    cout<<"Desea Ingresar otro contacto s/n: ";
    cin>>r;
    cin.ignore();
    cout<<endl;
  }
  while (r=='s');
  Archivero.close();
}
//------lectura e registro----//
void leerArchivo(string Titulo)
{
  string nombre, apellido, carrera;
  int edad;
  ifstream lectorArchivero;
  lectorArchivero.open(Titulo.c_str(),ios::in);
  if(lectorArchivero.fail())
  {
    cout<<"No se pudo leer o no existe el registro de: "<<Titulo<<endl;
  }
  else
    {
      while(!lectorArchivero.eof())
    {
        lectorArchivero>>nombre>>apellido>>carrera>>edad;
        if(!lectorArchivero.eof())
        {
          cout<<"-----------------"<<endl;
          cout<<"Nombre:"<<nombre<<endl;
          cout<<"Apellido:"<<apellido<<endl;
          cout<<"Carrera:"<<carrera<<endl;
          cout<<"Edad:"<<edad<<endl;
          cout<<"-----------------"<<endl;
        }
        cout<<endl;
      }
    } 
    lectorArchivero.close();
}
///Funcion Menu2
void Menu2(void)
{  
  cout<<"\t╔═══════════════════════════════════╗\n";
  cout<<"\t║     --Ingreso de datos MENÚ--     ║\n";
  cout<<"\t║  1) Sobrescribir Archivo          ║\n";
  cout<<"\t║  2) Ingresar datos en el Archivo  ║\n";
  cout<<"\t║  3) Salir al menu                 ║\n";
  cout<<"\t╚═══════════════════════════════════╝\n";		
} 
//Funcion de ingreso de mas datos
void Registro(string Titulo)
{
  int Tipo2;
cout<<"\nEl archivo '"<<Titulo<<"' contiene información, seleccione una opcion: "<<endl<<endl;
 do
  {
    Menu2();
    cout<<" \n\nIngrese el numero de su opcion: ";
    cin>>Tipo2;
    getchar();
    switch (Tipo2) 
	  {
      case 1:
        escribirArchivo(Titulo);
        Tipo2=3;
       break;          
	    case 2:
        AppArchivo(Titulo);
        Tipo2=3;
       break;          
	    case 3:       
       break;
	    default:cout<<"\nERROR, Al introducir la opcion\n";
       break;
    }
  }
  while(Tipo2!=3);
  cout<<endl;
}
//Funcion Añadir al archivo
void AppArchivo(string Titulo)
{ 
  string nombre, apellido, carrera;
  char r;
  int edad;
  ofstream Archivero;
  Archivero.open(Titulo.c_str(),ios::app);
  do
  {
    cout<<"Ingrese el nombre: ";
    getline(cin,nombre);
    cout<<"Ingrese el apellido: ";
    getline(cin,apellido);
    cout<<"Ingrese la carrera: ";
    getline(cin,carrera);
    cout<<"Ingrese la edad: ";
    cin>>edad;
    Archivero<<nombre<<" "<<apellido<<" "<<carrera<<" "<<edad<<endl;
    cout<<"Desea Ingresar otro contacto s/n: ";
    cin>>r;
    cin.ignore();
    cout<<endl;
  }
  while (r=='s');
  Archivero.close();
}
