#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <time.h>
#define VK_UP 72
#define VK_DOWN 80
#define ENTER 13
#define BORRAR 8
int c=0,k=15;
int tecla;
bool flag=true,flag2=true,flag3=true,_flag3=true,flag4=true,_flag4=true;
char id[30],id2[30];

using namespace std;

void login_user();
void menu();
void gotoxy(int x,int y);
void password_ast(char password[]);
void validacion_log (char usuario[],char password[]);
void log_correcto (char usuario[]);
void log_incorrecto();
void log_warning();
void hora();
void flechas();
void elegir_opcion();
void pantalla_administrador();
void flechas2();
void elegir_opcion2();
void crear_usuario();
void eliminar_usuario ();
void ver_usuarios();
void pantalla_cliente();
void pantalla_log_cliente();
void flechas3();
void elegir_opcion3();
void login_cliente();
void crear_cliente();
void ver_cliente();
void eliminar_cliente ();
void _flechas3();
void _elegir_opcion3();
void venta_prod();
void listar_venta();
void pantalla_proveedor();
void elegir_opcion4();
void flechas4();
void crear_prov();
void ver_proveedor();
void eliminar_prov();
void login_proveedor();
void _elegir_opcion4();
void _flechas4();
void compra_producto();
void pantalla_log_prov();
void listar_prov();
void inventario();
void inventario2();
void inventario3();

/*-----------------------*/
/*		  PRODUCT		 */
/*-----------------------*/

class Producto{
	private:
		char nombre_prod[30];
		int cantidad_prod;
		float costo;
		float venta;
		float precio;
	public:
		Producto (char _nombre_prod[],int _cantidad_prod){
			strcpy(nombre_prod,_nombre_prod);
			cantidad_prod=_cantidad_prod;
		}
		Producto(){ };
		void archivo_vender_prod();
		void archivo_comprar_prod();
		void archivo_listar_prod();
		void archivo_listar_venta();
		void archivo_listar_prov();
};
void Producto::archivo_vender_prod(){
	char _nombre_prod[30];
	float _costo;
	float _venta;
	float _cantidad_prod;
	float _precio;
	char archivo_nombre[30];
	strcpy(archivo_nombre,id);
	strcat(archivo_nombre,".txt");
	
	ofstream guardar;
	ofstream guardar2;
	ifstream leer;
	leer.open("Inventario.txt");
	guardar.open("Temp.txt");
	guardar2.open(archivo_nombre,ios::app);
	leer>>_nombre_prod;
	while(!leer.eof()){
		leer>>_cantidad_prod>>_costo>>_venta>>_precio;
		if(strcmp(nombre_prod,_nombre_prod)==0){
			guardar<<_nombre_prod<<" "<<(_cantidad_prod-cantidad_prod)<<" "<<_costo<<" "<<_venta<<" "<<_costo*(_cantidad_prod-cantidad_prod)<<endl;
			
			guardar2<<_nombre_prod<<" "<<cantidad_prod<<" "<<_costo<<" "<<_venta<<" "<<(_venta)*cantidad_prod<<endl;
			
			cout<<"listo"<<" "<<id<<endl;
			system("pause>nul");
		}else{
			guardar<<_nombre_prod<<" "<<_cantidad_prod<<" "<<_costo<<" "<<_venta<<" "<<_precio<<endl;
		}
		leer>>_nombre_prod;
	}
	guardar2.close();
	leer.close();
	guardar.close();
	remove("Inventario.txt");
	rename("Temp.txt","Inventario.txt");
}
void Producto::archivo_comprar_prod(){
	char _nombre_prod[30];
	float _costo;
	float _venta;
	float _cantidad_prod;
	float _precio;
	char archivo_nombre2[30];
	strcpy(archivo_nombre2,id2);
	strcat(archivo_nombre2,".txt");
	
	ofstream guardar;
	ofstream guardar2;
	ifstream leer;
	ifstream leer2;
	leer.open("Inventario.txt");
	leer2.open(archivo_nombre2);
	guardar.open("Temp.txt");
	guardar2.open("Temp2.txt");
	leer>>_nombre_prod;
	while(!leer.eof()){
		leer>>_cantidad_prod>>_costo>>_venta>>_precio;
		
		if(strcmp(nombre_prod,_nombre_prod)==0){
			guardar<<_nombre_prod<<" "<<(_cantidad_prod+cantidad_prod)<<" "<<_costo<<" "<<_venta<<" "<<_costo*(_cantidad_prod+cantidad_prod)<<endl;

		}else{
			guardar<<_nombre_prod<<" "<<_cantidad_prod<<" "<<_costo<<" "<<_venta<<" "<<_precio<<endl;
		}
		
		leer>>_nombre_prod;
	}
	
	leer2>>_nombre_prod;
	while(!leer2.eof()){
		leer2>>_cantidad_prod>>_costo>>_venta>>_precio;
		if(strcmp(nombre_prod,_nombre_prod)==0){
				
			guardar2<<_nombre_prod<<" "<<(_cantidad_prod-cantidad_prod)<<" "<<_costo<<" "<<_venta<<" "<<_costo*(_cantidad_prod-cantidad_prod)<<endl;

		}else{
			guardar2<<_nombre_prod<<" "<<_cantidad_prod<<" "<<_costo<<" "<<_venta<<" "<<_precio<<endl;
		}
		leer2>>_nombre_prod;
	}
	guardar2.close();
	leer2.close();
	remove(archivo_nombre2);
	rename("Temp2.txt",archivo_nombre2);
	
	leer.close();
	guardar.close();
	remove("Inventario.txt");
	rename("Temp.txt","Inventario.txt");
}

void Producto::archivo_listar_prod(){
	int a=15,b=15;
	char _nombre_prod[30];
	float _costo;
	float _venta;
	float _cantidad_prod;
	float _precio;
	ifstream leer2;
	leer2.open("Inventario.txt");
	leer2>>_nombre_prod;
	while(!leer2.eof()){
		leer2>>_cantidad_prod>>_costo>>_venta>>_precio;
		gotoxy(10,a);
		cout<<_nombre_prod;
		gotoxy(20,b);
		cout<<"*";
		gotoxy(20,b+1);
		cout<<"*";
		gotoxy(25,a);
		cout<<_cantidad_prod;
		gotoxy(37,b);
		cout<<"*";
		gotoxy(37,b+1);
		cout<<"*";
		gotoxy(40,a);
		cout<<_costo;
		gotoxy(52,b);
		cout<<"*";
		gotoxy(52,b+1);
		cout<<"*";
		gotoxy(55,a);
		cout<<_venta;
		gotoxy(66,b);
		cout<<"*";
		gotoxy(66,b+1);
		cout<<"*";
		gotoxy(70,a);
		cout<<_precio<<endl;
		
		a=a+2;
		b=b+2;
		leer2>>_nombre_prod;
	}
	leer2.close();
}

void Producto::archivo_listar_venta(){
	int a=15,b=15;
	char _nombre_prod[30];
	float _costo;
	float _venta;
	float _cantidad_prod;
	float _precio;
	char archivo_nombre3[30];
	strcpy(archivo_nombre3,id);
	strcat(archivo_nombre3,".txt");
	
	ifstream leer2;
	leer2.open(archivo_nombre3);
	leer2>>_nombre_prod;
	while(!leer2.eof()){
		leer2>>_cantidad_prod>>_costo>>_venta>>_precio;
		gotoxy(10,a);
		cout<<_nombre_prod;
		gotoxy(20,b);
		cout<<"*";
		gotoxy(20,b+1);
		cout<<"*";
		gotoxy(25,a);
		cout<<_cantidad_prod;
		gotoxy(37,b);
		cout<<"*";
		gotoxy(37,b+1);
		cout<<"*";
		gotoxy(40,a);
		cout<<_costo;
		gotoxy(52,b);
		cout<<"*";
		gotoxy(52,b+1);
		cout<<"*";
		gotoxy(55,a);
		cout<<_venta;
		gotoxy(66,b);
		cout<<"*";
		gotoxy(66,b+1);
		cout<<"*";
		gotoxy(70,a);
		cout<<_precio<<endl;
		
		a=a+2;
		b=b+2;
		leer2>>_nombre_prod;
	}
	leer2.close();
}

void Producto::archivo_listar_prov(){
	int a=15,b=15;
	char _nombre_prod[30];
	float _costo;
	float _venta;
	float _cantidad_prod;
	float _precio;
	char archivo_nombre4[30];
	strcpy(archivo_nombre4,id2);
	strcat(archivo_nombre4,".txt");
	
	ifstream leer2;
	leer2.open(archivo_nombre4);
	leer2>>_nombre_prod;
	while(!leer2.eof()){
		leer2>>_cantidad_prod>>_costo>>_venta>>_precio;
		gotoxy(10,a);
		cout<<_nombre_prod;
		gotoxy(20,b);
		cout<<"*";
		gotoxy(20,b+1);
		cout<<"*";
		gotoxy(25,a);
		cout<<_cantidad_prod;
		gotoxy(37,b);
		cout<<"*";
		gotoxy(37,b+1);
		cout<<"*";
		gotoxy(40,a);
		cout<<_costo;
		gotoxy(52,b);
		cout<<"*";
		gotoxy(52,b+1);
		cout<<"*";
		gotoxy(55,a);
		cout<<_venta;
		gotoxy(66,b);
		cout<<"*";
		gotoxy(66,b+1);
		cout<<"*";
		gotoxy(70,a);
		cout<<_precio<<endl;
		
		a=a+2;
		b=b+2;
		leer2>>_nombre_prod;
	}
	leer2.close();
}

/*-----------------------*/
/*		PROVIDER		 */
/*-----------------------*/

class Proveedor{
	private:
		char nombre_prov[30];
		int numero;
		char codigo[30];
	public:
		Proveedor (char _nombre_prov[],int _numero,char _codigo[]){
			strcpy(nombre_prov,_nombre_prov);
			numero=_numero;
			strcpy(codigo,_codigo);
		}
		Proveedor(){ };
		Proveedor (char _codigo[]){
			strcpy(codigo,_codigo);
		}
		void archivo_crear_prov();
		void archivo_listar_prov();
		void archivo_eliminar_prov();
		bool archivo_buscar_prov();
};

void Proveedor::archivo_crear_prov(){
	char nombre_prov2[30];
	int numero2;
	char codigo2[30];
	ofstream guardar;
	guardar.open("Prov.txt",ios::app);
	guardar<<nombre_prov<<" "<<numero<<" "<<codigo<<endl;
}

void Proveedor::archivo_listar_prov(){
	int a=15,b=15;
	char nombre_prov2[30];
	int numero2;
	char codigo2[30];
	ifstream leer;
	leer.open("Prov.txt");
	leer>>nombre_prov2;
	while(!leer.eof()){
		leer>>numero2>>codigo2;
		
		gotoxy(20,a);
		cout<<"*";
		gotoxy(20,a+1);
		cout<<"*";
		gotoxy(25,b);
		cout<<nombre_prov2;
		gotoxy(37,a);
		cout<<"*";
		gotoxy(37,a+1);
		cout<<"*";
		gotoxy(40,b);
		cout<<numero2;
		gotoxy(52,a);
		cout<<"*";
		gotoxy(52,a+1);
		cout<<"*";
		gotoxy(55,b);
		cout<<codigo2;
		gotoxy(66,b);
		cout<<"*";
		gotoxy(66,b+1);
		cout<<"*"<<endl;
		
		a++;
		b=b+2;
		leer>>nombre_prov2;
	}
}

void Proveedor::archivo_eliminar_prov(){
	char _nombre_prov2[30];
	int _numero2;
	char _codigo2[30];
	ofstream guardar;
	ifstream leer;
	
	leer.open("Prov.txt");
	guardar.open("Temp.txt");
	
	leer>>_nombre_prov2;
	while(!leer.eof()){
		leer>>_numero2>>_codigo2;
		if(strcmp(codigo,_codigo2)==0){
			gotoxy(25,17);
				cout<<"E";
				Sleep(800);
				cout<<"L";
				Sleep(800);
				cout<<"I";
				Sleep(800);
				cout<<"M";
				Sleep(800);
				cout<<"I";
				Sleep(800);
				cout<<"N";
				Sleep(800);
				cout<<"A";
				Sleep(800);
				cout<<"D";
				Sleep(800);
				cout<<"O    ";
				
				Sleep(800);
				cout<<"C";
				Sleep(800);
				cout<<"O";
				Sleep(800);
				cout<<"R";
				Sleep(800);
				cout<<"R";
				Sleep(800);
				cout<<"E";
				Sleep(800);
				cout<<"C";
				Sleep(800);
				cout<<"T";
				Sleep(800);
				cout<<"A";
				Sleep(800);
				cout<<"M";
				Sleep(800);
				cout<<"E";
				Sleep(800);
				cout<<"N";
				Sleep(800);
				cout<<"T";
				Sleep(800);
				cout<<"E";
				
				Sleep(1000);
		}else{
			guardar<<_nombre_prov2<<" "<<_numero2<<" "<<_codigo2<<endl;
		}
		leer>>_nombre_prov2;
	}
	leer.close();
	guardar.close();
	remove("Prov.txt");
	rename("Temp.txt","Prov.txt");
}
bool Proveedor::archivo_buscar_prov(){
	char _nombre_prov2[30];
	int _numero2;
	char _codigo2[30];
	bool _flag=false;
	ifstream leer;
	leer.open("Prov.txt");
	leer>>_nombre_prov2;
	while(!leer.eof()){
		leer>>_numero2>>_codigo2;
		if(strcmp(codigo,_codigo2)==0){
			gotoxy(33,17);
			cout<<"B";
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"V";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"D";
			Sleep(800);
			cout<<"O";
			
			Sleep(1000);
			_flag=true;
			
			return true;
		}	

		leer>>_nombre_prov2;
	}
	if(_flag==false){
			gotoxy(33,17);
			cout<<"R";
			Sleep(800);
			cout<<"U";
			Sleep(800);
			cout<<"C";
			
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"C";
			Sleep(800);
			cout<<"O";
			Sleep(800);
			cout<<"R";
			Sleep(800);
			cout<<"R";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"C";
			Sleep(800);
			cout<<"T";
			Sleep(800);
			cout<<"O";
			
			Sleep(1000);
			
			return false;
	}
	leer.close();
}

/*-----------------------*/
/*		  CLIENT		 */
/*-----------------------*/

class Cliente{
	private:
		char nombres[30];
		char apellido_paterno[15];
		char apellido_materno[15];
		int numero;
		char dni[30];
	public:
		Cliente(char _nombres[],char _apellido_paterno[], char _apellido_materno[], int _numero, char _dni[]){
			strcpy(nombres,_nombres);
			strcpy(apellido_paterno,_apellido_paterno);
			strcpy(apellido_materno,_apellido_materno);
			numero=_numero;
			strcpy(dni,_dni);
		}
		Cliente(char _dni[]){
			strcpy(dni,_dni);
		}
		Cliente (){ };
		void archivo_crear_cliente();
		void archivo_listar_cliente();
		void archivo_eliminar_cliente();
		bool archivo_buscar_cliente();
};

void Cliente::archivo_crear_cliente(){
	ofstream guardar2;
	guardar2.open("Clientes.txt",ios::app);
	guardar2<<nombres<<" "<<apellido_paterno<<" "<<apellido_materno<<" "<<numero<<" "<<dni<<endl;
}

void Cliente::archivo_listar_cliente(){
	int a=15,b=15;
	char nombres2[30];
	char apellido_paterno2[15];
	char apellido_materno2[15];
	int numero2;
	char dni2[30];
	ifstream leer2;
	leer2.open("Clientes.txt");
	leer2>>nombres2;
	while(!leer2.eof()){
		leer2>>apellido_paterno2>>apellido_materno2>>numero2>>dni2;
		gotoxy(10,a);
		cout<<nombres2;
		gotoxy(20,b);
		cout<<"*";
		gotoxy(20,b+1);
		cout<<"*";
		gotoxy(25,a);
		cout<<apellido_paterno2;
		gotoxy(37,b);
		cout<<"*";
		gotoxy(37,b+1);
		cout<<"*";
		gotoxy(40,a);
		cout<<apellido_materno2;
		gotoxy(52,b);
		cout<<"*";
		gotoxy(52,b+1);
		cout<<"*";
		gotoxy(55,a);
		cout<<numero2;
		gotoxy(66,b);
		cout<<"*";
		gotoxy(66,b+1);
		cout<<"*";
		gotoxy(70,a);
		cout<<dni2<<endl;
		
		a=a+2;
		b=b+2;
		leer2>>nombres2;
	}
	leer2.close();
}
void Cliente::archivo_eliminar_cliente(){
	char _nombres2[30];
	char _apellido_paterno2[15];
	char _apellido_materno2[15];
	int _numero2;
	char _dni2[30];
	char archivo_nombre2[30];
	strcpy(archivo_nombre2,dni);
	strcat(archivo_nombre2,".txt");
	ofstream Temp;
	ifstream leer;
	leer.open("Clientes.txt");
	Temp.open("Temp.txt",ios::app);
	leer>>_nombres2;
	while(!leer.eof()){
		leer>>_apellido_paterno2>>_apellido_materno2>>_numero2>>_dni2;
		if(strcmp(dni,_dni2)==0){
			gotoxy(25,17);
			cout<<"E";
			Sleep(800);
			cout<<"L";
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"M";
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"A";
			Sleep(800);
			cout<<"D";
			Sleep(800);
			cout<<"O    ";
			
			Sleep(800);
			cout<<"C";
			Sleep(800);
			cout<<"O";
			Sleep(800);
			cout<<"R";
			Sleep(800);
			cout<<"R";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"C";
			Sleep(800);
			cout<<"T";
			Sleep(800);
			cout<<"A";
			Sleep(800);
			cout<<"M";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"T";
			Sleep(800);
			cout<<"E";
			
			remove(archivo_nombre2);
			Sleep(1000);
		}else{
			Temp<<_nombres2<<" "<<_apellido_paterno2<<" "<<_apellido_materno2<<" "<<_numero2<<" "<<_dni2<<endl;
		}
		leer>>_nombres2;
		
	}
	
	leer.close();
	Temp.close();
	remove("Clientes.txt");
	rename("Temp.txt","Clientes.txt");
}
bool Cliente::archivo_buscar_cliente(){
	char _nombres2[30];
	char _apellido_paterno2[15];
	char _apellido_materno2[15];
	int _numero2;
	char _dni2[30];
	bool _flag=false;
	ifstream leer;
	leer.open("Clientes.txt");
	leer>>_nombres2;
	while(!leer.eof()){
		leer>>_apellido_paterno2>>_apellido_materno2>>_numero2>>_dni2;
		if(strcmp(dni,_dni2)==0){
			gotoxy(33,17);
			cout<<"B";
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"V";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"D";
			Sleep(800);
			cout<<"O";
			
			Sleep(1000);
			_flag=true;
			
			return true;
		}	

		leer>>_nombres2;
	}
	if(_flag==false){
			gotoxy(33,17);
			cout<<"D";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"I";
			
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"C";
			Sleep(800);
			cout<<"O";
			Sleep(800);
			cout<<"R";
			Sleep(800);
			cout<<"R";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"C";
			Sleep(800);
			cout<<"T";
			Sleep(800);
			cout<<"O";
			
			Sleep(1000);
			
			return false;
	}
	leer.close();
}

/*-----------------------*/
/*		ADMINISTRATOR	 */
/*-----------------------*/

class Administrador{
	private:
		char usuario[30];
		char password[30];
	public:
		Administrador(char _usuario[], char _password[]){
			strcpy(usuario,_usuario);
			strcpy(password,_password);
		}
		Administrador(char _usuario[]){
			strcpy(usuario,_usuario);
		}
		Administrador(){ };
		void archivo_crear_user();
		void archivo_eliminar_user();
		void archivo_listar();
};

void Administrador :: archivo_crear_user(){
	ofstream guardar;
	guardar.open("users.txt",ios::app);
	guardar<<usuario<<" "<<password<<endl;
}

void Administrador :: archivo_eliminar_user(){
	char nombre[30],contra[30];
	ofstream Temp;
	ifstream leer;
	
	leer.open("users.txt");
	Temp.open("Temp.txt");
	
	leer>>nombre;
	while(!leer.eof()){
		leer>>contra;
		if(strcmp(usuario,nombre)==0){
			gotoxy(25,17);
			cout<<"E";
			Sleep(800);
			cout<<"L";
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"M";
			Sleep(800);
			cout<<"I";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"A";
			Sleep(800);
			cout<<"D";
			Sleep(800);
			cout<<"O    ";
			
			Sleep(800);
			cout<<"C";
			Sleep(800);
			cout<<"O";
			Sleep(800);
			cout<<"R";
			Sleep(800);
			cout<<"R";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"C";
			Sleep(800);
			cout<<"T";
			Sleep(800);
			cout<<"A";
			Sleep(800);
			cout<<"M";
			Sleep(800);
			cout<<"E";
			Sleep(800);
			cout<<"N";
			Sleep(800);
			cout<<"T";
			Sleep(800);
			cout<<"E";
			
			Sleep(1000);
		}else{
			Temp<<nombre<<" "<<contra<<endl;
		}
		leer>>nombre;
	}
	
	leer.close();
	Temp.close();
	
	remove("users.txt");
	rename("Temp.txt","users.txt");
}

void Administrador::archivo_listar(){
	ifstream leer;
	int a=0,b=0;
	char nombre2[30],contra2[30];
	leer.open("users.txt");
	leer>>nombre2;

	while(!leer.eof()){
		leer>>contra2;
		gotoxy(30,15+a);
		cout<<nombre2;
		gotoxy(40,15+b);
		cout<<"*";
		b++;
		gotoxy(40,15+b);
		cout<<"*";
		gotoxy(45,15+a);
		cout<<contra2<<endl;
		
		leer>>nombre2;
		a=a+2;
		b++;
	}
	leer.close();
}

/*-----------------------*/
/*		  MAIN			 */
/*-----------------------*/

int main () {
	
	system("color F9");
	login_user();
	menu();
	system("cls");
	system("pause>nul");	
	
}

/*-----------------------*/
/*	 FUNCTIONS OF MAIN	 */
/*-----------------------*/

void gotoxy(int x,int y){
	
	HANDLE hCon;
	COORD dwPos;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	dwPos.X=x;
	dwPos.Y=y;
	
	SetConsoleCursorPosition(hCon,dwPos);
	
}

/*-----------------------*/
/*	 CHART TO AST(PASS)	 */
/*-----------------------*/

void password_ast(char password[]){
	
	int i=0;

	do{

		password[i]=getch();
		if(password[i]!=BORRAR){
			if(password[i]!=ENTER){
				printf("*");
			}
			i++;
		}else{
				cout << (char)8 << (char)32 << (char)8;
				i--;

		}

	}while(password[i-1]!=ENTER);
	
	password[i-1] = NULL;
	cout<<endl;
	cout<<password<<endl;
	
}

/*-----------------------*/
/*	 	   LOGIN	     */
/*-----------------------*/

void login_user(){
	
	char usuario[30];
	char password[15];
	
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	//TITULO Y SUBTITULO
	gotoxy(25,8);
	printf("COLOCA TU USUARIO Y CONTRASEÑA");
	
	gotoxy(32,12);
	printf("<<< LOGIN >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"User:";
	gotoxy(20,17);
	cout<<"Password:";
	gotoxy(40,15);
	cin>>usuario;
	gotoxy(40,17);
	password_ast(password);
	
	validacion_log (usuario,password);
		
}

void validacion_log (char usuario[],char password[]){
	
	char contra[]="lolo";
	if(strcmp(password,contra)==0){
		system("cls");
		log_correcto (usuario);
	}else{
		system("cls");
		c++;
		if(c==3){
			log_warning();
		}else{
			log_incorrecto();
		}
	}
	
}

void log_correcto (char usuario[]) {
	
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(15,15);
	cout<<"Bienvenido "<<usuario<<endl;
	gotoxy(15,16);
	cout<<"Espera unos segundos hasta que cargue la interfaz..."<<endl;
	
	Sleep(5000);
	system("cls");
	
}

void log_incorrecto(){
	
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(25,15);
	printf("Usuario y/o contraseña incorrecto");
	system("pause>nul");
	system("cls");
	login_user();
	
}

void log_warning() {
	int seg=20;
	
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	while(seg!=-1){
	gotoxy(25,15);
	printf("Usuario y/o contraseña incorrecto");
	gotoxy(20,16);
	cout<<"Espere "<<seg<<" segundos hasta que se vuelva al login";
	seg--;
	Sleep(1000);
	}
	system("cls");
	c=0;
	login_user();
	
}

/*-----------------------*/
/*	 		TIME	 	 */
/*-----------------------*/

void hora(){
	
	time_t now=time(0);
	tm *time=localtime(&now);
	gotoxy(60,3);
	cout<<time->tm_hour<<":"<<time->tm_min<<":"<<time->tm_sec;
	
}

/*-----------------------*/
/*	 		MENU	 	 */
/*-----------------------*/

void elegir_opcion(){
	
	switch (k) {
		case 15:
			pantalla_administrador();
			break;
		case 17:
			pantalla_cliente();
			break;
		case 19:
			system("cls");
			inventario();
			break;
		case 21:
			pantalla_proveedor();
			break;
		case 23:
			flag=false;
			break;
	}
	
}

void flechas(){
	
	if(kbhit()){
		tecla=getch();
		if(tecla==VK_DOWN){
			if(k>=23){
				k=k+0;
			}else{
				k=k+2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k-2);
			cout<<" ";
		}
		if(tecla==VK_UP ){
			if(k<=15){
				k=k+0;
			}else{
				k=k-2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k+2);
			cout<<" ";
		}
		if(tecla==ENTER ){
			elegir_opcion();
		}
	}else{
		gotoxy(10,k);
		printf("%c",175);
	}

}

void menu() {
	
	flag=true;
	system("cls");
	while(flag!=false){
	
	//MARCOS DEL MENU
	for(int i=0;i<60;i++){
		gotoxy(10+i,5);
		printf("*");	
		
		gotoxy(10+i,10);
		printf("*");	
	}
	gotoxy(35,7);
	printf("SISTEMA DE FARMACIA");
	gotoxy(40,8);
	printf("YEI-LINUX | JESUS ALVAN");
	
	//OPCIONES
	
	gotoxy(12,15);
	cout<<"(1)Administrador de usuarios";
	gotoxy(12,17);
	cout<<"(2)Clientes";
	gotoxy(12,19);
	cout<<"(3)Inventario";
	gotoxy(12,21);
	cout<<"(4)Proveedor";
	gotoxy(12,23);
	cout<<"(5)Salir";
	
	hora();
	flechas();
	
	}
	system("exit");
	
}

/*-----------------------*/
/*	 MENU ADMINISTRATOR  */
/*-----------------------*/
void elegir_opcion2(){
	switch (k) {
		case 15:
			system("cls");
			crear_usuario();
			break;
		case 17:
			system("cls");
			eliminar_usuario();
			break;
		case 19:
			system("cls");
			ver_usuarios();
			break;
		case 21:
			system("cls");
			inventario();
			break;
		case 23:
			flag2=false;
			break;
	}
}

void flechas2(){
	
	if(kbhit()){
		tecla=getch();
		if(tecla==VK_DOWN){
			if(k>=23){
				k=k+0;
			}else{
				k=k+2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k-2);
			cout<<" ";
		}
		if(tecla==VK_UP ){
			if(k<=15){
				k=k+0;
			}else{
				k=k-2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k+2);
			cout<<" ";
		}
		if(tecla==ENTER ){
			elegir_opcion2();
		}
	}else{
		gotoxy(10,k);
		printf("%c",175);
	}

}

void pantalla_administrador(){
	flag2=true;
	system("cls");
	while(flag2!=false){
	
	//MARCOS DEL MENU
	for(int i=0;i<60;i++){
		gotoxy(10+i,5);
		printf("*");	
		
		gotoxy(10+i,10);
		printf("*");	
	}
	gotoxy(35,7);
	printf("ADMINISTRAR ");
	gotoxy(40,8);
	printf("USUARIO");
	
	//OPCIONES
	
	gotoxy(12,15);
	cout<<"(1)Crear nuevo usuario";
	gotoxy(12,17);
	cout<<"(2)Eliminar usuario";
	gotoxy(12,19);
	cout<<"(3)Ver usuarios";
	gotoxy(12,21);
	cout<<"(4)Inventario";
	gotoxy(12,23);
	cout<<"(5)Regresar";
	
	hora();
	flechas2();
	
	}
	system("cls");
	menu();
}

void crear_usuario(){

	char usuario[30];
	char password[15];
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< CREAR NUEVO USUARIO >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"User:";
	gotoxy(20,17);
	cout<<"Password:";
	gotoxy(40,15);
	cin>>usuario;
	gotoxy(40,17);
	cin>>password;
	
	Administrador admin(usuario,password);
	
	admin.archivo_crear_user();
	
	pantalla_administrador();
}

void eliminar_usuario (){
	
	char usuario[30];
	char password[15];
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< ELIMINAR NUEVO USUARIO >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"User:";
	gotoxy(40,15);
	cin>>usuario;
	
	Administrador admin2(usuario);
	
	admin2.archivo_eliminar_user();
	
	pantalla_administrador();
	
}

void ver_usuarios(){
	
	for(int i=0;i<29;i++){
		gotoxy(26+i,10);
		cout<<"*";
	}
	for(int j=0;j<7;j++){
		gotoxy(40,8+j);
		cout<<"*";
	}
	
	gotoxy(28,8);
	cout<<"USUARIOS";
	
	gotoxy(43,8);
	cout<<"PASSWORDS";
	
	Administrador admin3;
	
	admin3.archivo_listar();
	
	system("pause>nul");
	
	pantalla_administrador();

} 

/*-----------------------*/
/*	 	MENU CLIENT	 	 */
/*-----------------------*/
void elegir_opcion3(){
	
	switch (k) {
		case 15:
			system("cls");
			login_cliente();
			break;
		case 17:
			system("cls");
			crear_cliente();
			break;
		case 19:
			system("cls");
			eliminar_cliente ();
			break;
		case 21:
			system("cls");
			ver_cliente();
			break;
		case 23:
			flag3=false;
			break;
	}
	
}

void flechas3(){
	
	if(kbhit()){
		tecla=getch();
		if(tecla==VK_DOWN){
			if(k>=23){
				k=k+0;
			}else{
				k=k+2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k-2);
			cout<<" ";
		}
		if(tecla==VK_UP ){
			if(k<=15){
				k=k+0;
			}else{
				k=k-2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k+2);
			cout<<" ";
		}
		if(tecla==ENTER ){
			elegir_opcion3();
		}
	}else{
		gotoxy(10,k);
		printf("%c",175);
	}

}

void pantalla_cliente(){
	
	flag3=true;
	system("cls");
	while(flag3!=false){
	
	//MARCOS DEL MENU
	for(int i=0;i<60;i++){
		gotoxy(10+i,5);
		printf("*");	
		
		gotoxy(10+i,10);
		printf("*");	
	}
	gotoxy(35,7);
	printf("ADMINISTRAR ");
	gotoxy(40,8);
	printf("CLIENTE");
	
	//OPCIONES
	
	gotoxy(12,15);
	cout<<"(1)Login";
	gotoxy(12,17);
	cout<<"(2)Crear nuevo cliente";
	gotoxy(12,19);
	cout<<"(3)Eliminar cliente";
	gotoxy(12,21);
	cout<<"(4)Listar Clientes";
	gotoxy(12,23);
	cout<<"(5)Regresar";
	
	hora();
	flechas3();
	
	}
	system("cls");
	menu();
}

void login_cliente(){
	
	bool _flag;
	char  dni[30];
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< LOG IN CLIENTE >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"Dni:";
	gotoxy(40,15);
	cin>>dni;
	
	Cliente cliente4(dni);
	
	_flag=cliente4.archivo_buscar_cliente();
	
	if(_flag==true){
		strcpy(id,dni);
		pantalla_log_cliente();
	}else{
		pantalla_cliente();
	}
	
}

void crear_cliente(){

	char nombre[30];
	char apellido_paterno[15];
	char apellido_materno[15];
	int numero;
	char dni[30];
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,26);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< CREAR NUEVO USUARIO >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"Nombre:";
	gotoxy(20,17);
	cout<<"Apellido Paterno:";
	gotoxy(20,19);
	cout<<"Apellido Materno:";
	gotoxy(20,21);
	cout<<"Numero:";
	gotoxy(20,23);
	cout<<"Dni: ";
	
	gotoxy(40,15);
	cin>>nombre;
	gotoxy(40,17);
	cin>>apellido_paterno;
	gotoxy(40,19);
	cin>>apellido_materno;
	gotoxy(40,21);
	cin>>numero;
	gotoxy(40,23);
	cin>>dni;
	
	Cliente cliente(nombre,apellido_paterno,apellido_materno,numero,dni);
	
	cliente.archivo_crear_cliente();
	
	pantalla_cliente();
	
}

void ver_cliente(){
	
	for(int i=0;i<71;i++){
		gotoxy(8+i,10);
		cout<<"*";
	}
	for(int j=0;j<8;j++){
		gotoxy(20,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(37,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(52,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(66,7+j);
		cout<<"*";
	}
	
	gotoxy(10,8);
	cout<<"NOMBRE";
	
	gotoxy(25,8);
	cout<<"APELLIDO P.";

	gotoxy(40,8);
	cout<<"APELLIDO M.";
	
	gotoxy(55,8);
	cout<<"NUMERO";
	
	gotoxy(70,8);
	cout<<"DNI";
	
	Cliente cliente2;
	
	cliente2.archivo_listar_cliente();
	
	system("pause>nul");
	
	pantalla_cliente();

} 

void eliminar_cliente (){
	
	char dni[30];
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< ELIMINAR NUEVO CLIENTE >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"Dni:";
	gotoxy(40,15);
	cin>>dni;
	
	Cliente cliente3(dni);
	
	cliente3.archivo_eliminar_cliente();
	
	pantalla_cliente();
	
}

void pantalla_log_cliente(){
	_flag3=true;
	system("cls");
	while(_flag3!=false){
	
	//MARCOS DEL MENU
	for(int i=0;i<60;i++){
		gotoxy(10+i,5);
		printf("*");	
		
		gotoxy(10+i,10);
		printf("*");	
	}
	gotoxy(35,7);
	printf("PERFIL ");
	gotoxy(40,8);
	printf("CLIENTE");
	
	//OPCIONES
	
	gotoxy(12,15);
	cout<<"(1)Vender Productos";
	gotoxy(12,17);
	cout<<"(2)Lista de Compras";
	gotoxy(12,19);
	cout<<"(3)Inventario Actual";
	gotoxy(12,21);
	cout<<"(4)Salir";
	
	hora();
	gotoxy(60,4);
	cout<<id;
	_flechas3();
	
	}
	system("cls");
	pantalla_cliente();
}

void venta_producto(){
	char nombre_prod[30];
	int cantidad_prod;
	//MARCOS 
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< VENDER PRODUCTO >>>");
	
	//PANTALLA DE VENTA
	gotoxy(20,15);
	cout<<"Nombre Producto:";
	gotoxy(20,17);
	cout<<"Cantidad Producto:";
	
	gotoxy(40,15);
	cin>>nombre_prod;
	gotoxy(40,17);
	cin>>cantidad_prod;
	
	Producto prod(nombre_prod,cantidad_prod);
	
	prod.archivo_vender_prod();
	
 	pantalla_log_cliente();
}

void _elegir_opcion3(){
	switch (k) {
		case 15:
			system("cls");
			venta_producto();
			break;
		case 17:
			system("cls");
			listar_venta();
			break;
		case 19:
			system("cls");
			inventario2();
			break;
		case 21:
			_flag3=false;
			break;
	}
}

void _flechas3(){
	
	if(kbhit()){
		tecla=getch();
		if(tecla==VK_DOWN){
			if(k>=21){
				k=k+0;
			}else{
				k=k+2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k-2);
			cout<<" ";
		}
		if(tecla==VK_UP ){
			if(k<=15){
				k=k+0;
			}else{
				k=k-2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k+2);
			cout<<" ";
		}
		if(tecla==ENTER ){
			_elegir_opcion3();
		}
	}else{
		gotoxy(10,k);
		printf("%c",175);
	}

}

/*-----------------------*/
/*	 	MENU PROVIDER	 */
/*-----------------------*/

void pantalla_proveedor(){
	flag4=true;
	system("cls");
	while(flag4!=false){
	
	//MARCOS DEL MENU
	for(int i=0;i<60;i++){
		gotoxy(10+i,5);
		printf("*");	
		
		gotoxy(10+i,10);
		printf("*");	
	}
	gotoxy(35,7);
	printf("ADMINISTRAR ");
	gotoxy(40,8);
	printf("PROVEEDOR");
	
	//OPCIONES
	
	gotoxy(12,15);
	cout<<"(1)Login";
	gotoxy(12,17);
	cout<<"(2)Crear nuevo Proveedor";
	gotoxy(12,19);
	cout<<"(3)Eliminar Proveedor";
	gotoxy(12,21);
	cout<<"(4)Listar Proveedor";
	gotoxy(12,23);
	cout<<"(5)Regresar";
	
	hora();
	flechas4();
	
	}
	system("cls");
	menu();
}

void elegir_opcion4(){
	switch (k) {
		case 15:
			system("cls");
			login_proveedor();
			break;
		case 17:
			system("cls");
			crear_prov();
			break;
		case 19:
			system("cls");
			eliminar_prov();
			break;
		case 21:
			system("cls");
			ver_proveedor();
			break;
		case 23:
			flag4=false;
			break;
	}
}

void flechas4(){
	
	if(kbhit()){
		tecla=getch();
		if(tecla==VK_DOWN){
			if(k>=23){
				k=k+0;
			}else{
				k=k+2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k-2);
			cout<<" ";
		}
		if(tecla==VK_UP ){
			if(k<=15){
				k=k+0;
			}else{
				k=k-2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k+2);
			cout<<" ";
		}
		if(tecla==ENTER ){
			elegir_opcion4();
		}
	}else{
		gotoxy(10,k);
		printf("%c",175);
	}
}

void crear_prov(){

	char nombre_prov[30];
	int numero;
	char codigo[30];
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,21);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< CREAR NUEVO USUARIO >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"Nombre Proveedor:";
	gotoxy(20,17);
	cout<<"Numero Telefono:";
	gotoxy(20,19);
	cout<<"Ruc :";

	
	gotoxy(40,15);
	cin>>nombre_prov;
	gotoxy(40,17);
	cin>>numero;
	gotoxy(40,19);
	cin>>codigo;

	Proveedor prov(nombre_prov,numero,codigo);
	
	prov.archivo_crear_prov();
	
	pantalla_proveedor();
}

void ver_proveedor(){
	
	for(int i=0;i<46;i++){
		gotoxy(20+i,10);
		cout<<"*";
	}
	for(int j=0;j<8;j++){
		gotoxy(20,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(37,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(52,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(66,7+j);
		cout<<"*";
	}
	
	gotoxy(25,8);
	cout<<"PROVEEDOR";

	gotoxy(40,8);
	cout<<"TELEFONO";
	
	gotoxy(55,8);
	cout<<"RUC";
	
	Proveedor prov;
	
	prov.archivo_listar_prov();
	
	system("pause>nul");
	
	pantalla_proveedor();

} 
void eliminar_prov(){
	char ruc[30];
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< ELIMINAR NUEVO PROVEEDOR >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"Ruc:";
	gotoxy(40,15);
	cin>>ruc;
	
	Proveedor prov(ruc);
	
	prov.archivo_eliminar_prov();
	
	pantalla_proveedor();
}

void login_proveedor(){
	bool _flag2;
	char  ruc[30];
	//MARCOS DEL LOGIN
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< LOG IN PROVEEDOR >>>");
	
	//DATOS DEL LOGIN
	gotoxy(20,15);
	cout<<"Ruc:";
	gotoxy(40,15);
	cin>>ruc;
	
	Proveedor prov(ruc);
	
	_flag2=prov.archivo_buscar_prov();
	
	if(_flag2==true){
		strcpy(id2,ruc);
		pantalla_log_prov();
	}else{
		pantalla_proveedor();
	}
}

void pantalla_log_prov(){
	_flag4=true;
	system("cls");
	while(_flag4!=false){
	
	//MARCOS DEL MENU
	for(int i=0;i<60;i++){
		gotoxy(10+i,5);
		printf("*");	
		
		gotoxy(10+i,10);
		printf("*");	
	}
	gotoxy(35,7);
	printf("PERFIL ");
	gotoxy(40,8);
	printf("PROVEEDOR");
	
	//OPCIONES
	
	gotoxy(12,15);
	cout<<"(1)Comprar Productos al Proveedor";
	gotoxy(12,17);
	cout<<"(2)Inventario del Proveedor";
	gotoxy(12,19);
	cout<<"(3)Inventario Actual";
	gotoxy(12,21);
	cout<<"(4)Salir";
	
	hora();
	gotoxy(60,4);
	cout<<id2;
	_flechas4();
	
	}
	system("cls");
	pantalla_proveedor();
}
void _elegir_opcion4(){
	switch (k) {
		case 15:
			system("cls");
			compra_producto();
			break;
		case 17:
			system("cls");
			listar_prov();
			break;
		case 19:
			system("cls");
			inventario3();
			break;
		case 21:
			_flag4=false;
			break;
	}
}

void _flechas4(){
	
	if(kbhit()){
		tecla=getch();
		if(tecla==VK_DOWN){
			if(k>=21){
				k=k+0;
			}else{
				k=k+2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k-2);
			cout<<" ";
		}
		if(tecla==VK_UP ){
			if(k<=15){
				k=k+0;
			}else{
				k=k-2;
			}
			gotoxy(10,k);
			printf("%c",175);
			
			gotoxy(10,k+2);
			cout<<" ";
		}
		if(tecla==ENTER ){
			_elegir_opcion4();
		}
	}else{
		gotoxy(10,k);
		printf("%c",175);
	}

}
void compra_producto(){
	
	char nombre_prod[30];
	int cantidad_prod;
	//MARCOS 
	for(int i=0;i<60;i++){
		gotoxy(10+i,10);
		printf("*");	
		
		gotoxy(10+i,20);
		printf("*");	
	}
	
	gotoxy(28,12);
	printf("<<< VENDER PRODUCTO >>>");
	
	//PANTALLA DE VENTA
	gotoxy(20,15);
	cout<<"Nombre Producto:";
	gotoxy(20,17);
	cout<<"Cantidad Producto:";
	
	gotoxy(40,15);
	cin>>nombre_prod;
	gotoxy(40,17);
	cin>>cantidad_prod;
	
	Producto prod(nombre_prod,cantidad_prod);
	
	prod.archivo_comprar_prod();
	
 	pantalla_log_prov();
 	
}


/*-----------------------*/
/*	 	INVENTORY		 */
/*-----------------------*/

void inventario(){
	
	for(int i=0;i<71;i++){
		gotoxy(8+i,10);
		cout<<"*";
	}
	for(int j=0;j<8;j++){
		gotoxy(20,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(37,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(52,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(66,7+j);
		cout<<"*";
	}
	
	gotoxy(10,8);
	cout<<"PRODUCTO";
	
	gotoxy(25,8);
	cout<<"CANTIDAD";

	gotoxy(40,8);
	cout<<" COSTO";
	
	gotoxy(55,8);
	cout<<" VENTA";
	
	gotoxy(70,8);
	cout<<"PRECIO";
	
	Producto prod;
	
	prod.archivo_listar_prod();
	
	system("pause>nul");
	
	system("cls");
	
	menu();
}

void inventario2(){
	
	for(int i=0;i<71;i++){
		gotoxy(8+i,10);
		cout<<"*";
	}
	for(int j=0;j<8;j++){
		gotoxy(20,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(37,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(52,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(66,7+j);
		cout<<"*";
	}
	
	gotoxy(10,8);
	cout<<"PRODUCTO";
	
	gotoxy(25,8);
	cout<<"CANTIDAD";

	gotoxy(40,8);
	cout<<" COSTO";
	
	gotoxy(55,8);
	cout<<" VENTA";
	
	gotoxy(70,8);
	cout<<"PRECIO";
	
	Producto prod;
	
	prod.archivo_listar_prod();
	
	system("pause>nul");
	
	system("cls");
	
	pantalla_log_cliente();
}

void inventario3(){
	
	for(int i=0;i<71;i++){
		gotoxy(8+i,10);
		cout<<"*";
	}
	for(int j=0;j<8;j++){
		gotoxy(20,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(37,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(52,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(66,7+j);
		cout<<"*";
	}
	
	gotoxy(10,8);
	cout<<"PRODUCTO";
	
	gotoxy(25,8);
	cout<<"CANTIDAD";

	gotoxy(40,8);
	cout<<" COSTO";
	
	gotoxy(55,8);
	cout<<" VENTA";
	
	gotoxy(70,8);
	cout<<"PRECIO";
	
	Producto prod;
	
	prod.archivo_listar_prod();
	
	system("pause>nul");
	
	system("cls");
	
	pantalla_log_prov();
}

void listar_venta(){
	
	for(int i=0;i<71;i++){
		gotoxy(8+i,10);
		cout<<"*";
	}
	for(int j=0;j<8;j++){
		gotoxy(20,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(37,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(52,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(66,7+j);
		cout<<"*";
	}
	
	gotoxy(10,8);
	cout<<"PRODUCTO";
	
	gotoxy(25,8);
	cout<<"CANTIDAD";

	gotoxy(40,8);
	cout<<" COSTO";
	
	gotoxy(55,8);
	cout<<" VENTA";
	
	gotoxy(70,8);
	cout<<"PRECIO";
	
	Producto prod;
	
	prod.archivo_listar_venta();
	
	system("pause>nul");
	
	system("cls");
	
	pantalla_log_cliente();
}

void listar_prov(){
	
	for(int i=0;i<71;i++){
		gotoxy(8+i,10);
		cout<<"*";
	}
	for(int j=0;j<8;j++){
		gotoxy(20,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(37,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(52,7+j);
		cout<<"*";
	}
	
	for(int j=0;j<8;j++){
		gotoxy(66,7+j);
		cout<<"*";
	}
	
	gotoxy(10,8);
	cout<<"PRODUCTO";
	
	gotoxy(25,8);
	cout<<"CANTIDAD";

	gotoxy(40,8);
	cout<<" COSTO";
	
	gotoxy(55,8);
	cout<<" VENTA";
	
	gotoxy(70,8);
	cout<<"PRECIO";
	
	Producto prod;
	
	prod.archivo_listar_prov();
	
	system("pause>nul");
	
	system("cls");
	
	pantalla_log_prov();
	
}
