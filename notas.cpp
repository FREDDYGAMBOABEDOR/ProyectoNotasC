#include<iostream>
#include<string.h>
#include<windows.h> //color a las letras y al fondo.
#include<stdio.h>
#include<conio.h>



using namespace std;
					
void gotoxy(int x,int y);//inicializacion de la funcion goto

int main(){
int fila,opc,indiceNombre=0,notas[5][5],indiceMostrar,indiceEditar,item=1;
bool menuPrincipal=true,menuNombre=true,menuNota=true,menuEditarNombre=true; 


// INICIO calculo para la cantidad de espacios que tiene un arreglo.
string nombre[5],prueba;	
int tamano_del_tipo_de_dato; ///Ej. Tamaño de un Int (4 bytes), de un Char (1 byte)
int tamano_del_array; ///Aplica sizeof al array
int cantidadNombre;
///Obtenemos el tamano de un string y del array usando sizeof.
tamano_del_array = sizeof(nombre);
tamano_del_tipo_de_dato = sizeof(string);
cantidadNombre = tamano_del_array / tamano_del_tipo_de_dato;
//Fin de calculo de cantidad de elementos del arreglo nombre 

//bandera o marca identificar si desea volver al menu principal
do{
system("color F2");

do{
system("cls");


cout<<"*************************************"<<endl;
cout<<"********** Registro de notas*********"<<endl;
cout<<"*************************************"<<endl<<endl;
cout<<"1.- Ingresar Nombre de estudiante"<<endl;
cout<<"2.- Consultar Notas"<<endl;
cout<<"3.- Editar Notas"<<endl;
cout<<"4.- Salir"<<endl;
cout<<"Seleccione una opcion [1-3]:"<<endl;
cin>>opc;
if (opc<1 || opc>4){
cout<<"Ingrese la opcion correcta"<<endl;
system ("pause");

}
}while (opc<1 || opc>4);

switch (opc){
				case 1: 
					
						//getline(cin, nombre[indiceNombre]);
						do{
						
						if(nombre[indiceNombre].empty() && indiceNombre<cantidadNombre )
						{
						system("cls");
						
						cout<<nombre[indiceNombre];
						cout<<"********************************"<<endl;
						cout<<"*****Igreso de estudiantes******"<<endl;
						cout<<"********************************"<<endl<<endl;
						cout<<"Ingrese el nombre del estudiante: "<<endl;
						
						//getline(cin, nombre[indiceNombre]);
						cin>>nombre[indiceNombre];
						for(int i=0;i<=4;i++)//inicio;condicion;incremento
						{
						notas[indiceNombre][i]=0;
						}
						cout<<"Se desea ingresar otro nombre  si[1] no[0]: "<<endl;
						cin>>menuNombre;
						indiceNombre++;
						
						}
						else
						{
						cout<<"El curso a alcanzado el limite de estudiantes(5)"<<endl;
						for(int i=0;i<=4;i++)
						{
						cout<<nombre[i]<<endl;
						}
						/******El valor de menuNombre debe variar para que no se respita del bucle de
						el ciclo de mostrar los nombres ingresados de manera infinita**/		
						
						menuNombre=false;
						// esta es la linea a verificar.		
						system("pause");						
						}
					}while(menuNombre==true);
						
						break;	
			case 2:  	
						system("cls");
						indiceMostrar=0;
						item=1;
						cout<<"********************************"<<endl;
						cout<<"*****Mostrar estudiantes******"<<endl;
						cout<<"********************************"<<endl<<endl;
						if(nombre[indiceMostrar].empty())
						{
						system("color F4");
						cout<<endl<<"No existen estudiantes ingresados"<<endl;
						system("pause");
						}
			 			else
			 			{ fila=6;
			 				gotoxy(0,4);
			 				cout<<"Nombre del estudiante";
			 				gotoxy(30,4);
							cout<<"Foro";						 
							gotoxy(40,4);
							cout<<"PEP";
							gotoxy(50,4);
							cout<<"SEP";
							gotoxy(60,4);
							cout<<"PEC";
							gotoxy(70,4);
							cout<<"EXAMEN"<<endl;
							gotoxy(80,4);
							cout<<"PROMEDIO FINAL"<<endl;						 
						 	gotoxy(90,4);
							cout<<"ESTADO"<<endl;						 
						 
						 	while(!nombre[indiceMostrar].empty() && indiceMostrar<cantidadNombre)
						 	{
						 	gotoxy(0,fila);
							cout<<item<<".-"<<nombre[indiceMostrar];
							gotoxy(30,fila);
							cout<<notas[indiceMostrar][0];
							gotoxy(40,fila);
							cout<<notas[indiceMostrar][1];
							gotoxy(50,fila);
							cout<<notas[indiceMostrar][2];
							gotoxy(60,fila);
							cout<<notas[indiceMostrar][3];
							gotoxy(70,fila);
							cout<<notas[indiceMostrar][4];
							gotoxy(80,fila);
							cout<<((notas[indiceMostrar][0])*0.15)+((notas[indiceMostrar][1])*0.2)+((notas[indiceMostrar][2])*0.3)+((notas[indiceMostrar][3])*0.05)+((notas[indiceMostrar][4])*0.3);
							if(((notas[indiceMostrar][0])*0.15)+((notas[indiceMostrar][1])*0.2)+((notas[indiceMostrar][2])*0.3)+((notas[indiceMostrar][3])*0.05)+((notas[indiceMostrar][4])*0.3)<80)
							{
								gotoxy(90,fila);
								cout<<"REPROBADO";
							}
							else
							{	gotoxy(90,fila);
								cout<<"APROBADO";
							} 
							 
							 indiceMostrar++;
							 fila++;
							 item++;
							}
						 
						 cout<<endl;
						 system("pause");
						}
						break;
				case 3: do{
						menuEditarNombre=true;
						system("cls");
						indiceEditar=0;
						item=1;
						cout<<"********************************"<<endl;
						cout<<"*****Editar estudiantes******"<<endl;
						cout<<"********************************"<<endl<<endl;
						if(nombre[indiceEditar].empty())
						{
						system("color F4");
						cout<<"No existen estudiantes ingresados"<<endl;
						system("pause");
						menuEditarNombre=false;
						}
						else
						{
						
						cout<<"Listado de estudiantes a editar notas"<<endl;
						 	while(!nombre[indiceEditar].empty() && indiceEditar<cantidadNombre)
						 	{
							cout<<item<<".-"<<nombre[indiceEditar]<<endl;
							indiceEditar++;
							item++;
							}
							cout<<item<<".-"<<"Desea salir al menu anterior"<<endl;
	
							cout<<"Ingrese item del estudiante: ";
							cin>>indiceEditar;
							
							//para salir al menu principal
							if(indiceEditar==item)
							{
								menuEditarNombre=false;
								break;
							}
							indiceEditar--;
							//mostra nota del estudiante a editar
							do{
							
							do{
							
							system("cls");
							cout<<"********************************"<<endl;
							cout<<"*******Editar estudiantes******"<<endl;
							cout<<"********************************"<<endl<<endl;
							cout<<"El alumno (a) "<<nombre[indiceEditar]<<" tiene las siguientes notas"<<endl;
							cout<<"1.-FORO:  ";
							cout<<notas[indiceEditar][0]<<endl;
							cout<<"2.-PEP:  ";
							cout<<notas[indiceEditar][1]<<endl;
							cout<<"3.-SEP:  ";
							cout<<notas[indiceEditar][2]<<endl;
							cout<<"4.-PEC:  ";
							cout<<notas[indiceEditar][3]<<endl;
							cout<<"5.-EXAMEN:  ";
							cout<<notas[indiceEditar][4]<<endl;
							cout<<"6.-Salir al menu anterior."<<endl;
							cout<<"Ingrese la nota a editar:  ";
							cin>>opc;
							}while(opc<1 ||opc>6);
						
						
							switch (opc)
							{
							 case 1: 	cout<<"La nota del foro es: ";
							 			cout<<notas[indiceEditar][0]<<endl;
										cout<<"Ingrese la nueva nota: "; 
										cin>>notas[indiceEditar][0];
										cout<<"Nota editada exitosamente"<<endl;
										cout<<"Desea Editar otra nota Si[1]-No[0]:";
										cin>>menuNota;
																		
										break;
							case 2:
										cout<<"La nota de la PEP es: ";
							 			cout<<notas[indiceEditar][1]<<endl;
										cout<<"Ingrese la nueva nota: "; 
										cin>>notas[indiceEditar][1];
										cout<<"Nota editada exitosamente"<<endl;
										cout<<"Desea Editar otra nota Si[1]-No[0]:";
										cin>>menuNota;
	
										break;
							case 3:
										cout<<"La nota de la SEP es: ";
							 			cout<<notas[indiceEditar][2]<<endl;
										cout<<"Ingrese la nueva nota: "; 
										cin>>notas[indiceEditar][2];
										cout<<"Nota editada exitosamente"<<endl;
										cout<<"Desea Editar otra nota Si[1]-No[0]:";
										cin>>menuNota;
	
										break;
							case 4:
										cout<<"La nota de la PEC es: ";
							 			cout<<notas[indiceEditar][3]<<endl;
										cout<<"Ingrese la nueva nota: "; 
										cin>>notas[indiceEditar][3];
										cout<<"Nota editada exitosamente"<<endl;
										cout<<"Desea Editar otra nota Si[1]-No[0]:";
										cin>>menuNota;
	
										break;
							case 5:
										cout<<"La nota de la EXAMEN es: ";
							 			cout<<notas[indiceEditar][4]<<endl;
										cout<<"Ingrese la nueva nota: "; 
										cin>>notas[indiceEditar][4];
										cout<<"Nota editada exitosamente"<<endl;
										cout<<"Desea Editar otra nota Si[1]-No[0]:";
										cin>>menuNota;
	
										break;
							case 6:     menuNota=false;
										break;
	
							
							}
							}while(menuNota==true);
						
	//						system("pause");
						}//else
					}while(menuEditarNombre==true);//para mostrar el listado de estudiantes a editar
					break;
			case 4: menuPrincipal=false;
					break;
				
				
			} //llave del switch
//do while para controlar si desea volver al menu principal
}while(menuPrincipal==true);
//getch();


}

	void gotoxy(int x,int y){  
		      HANDLE hcon;  
		      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
		      COORD dwPos;  
		      dwPos.X = x;  
		      dwPos.Y= y;  
		      SetConsoleCursorPosition(hcon,dwPos);  
		 } 
		 
	
