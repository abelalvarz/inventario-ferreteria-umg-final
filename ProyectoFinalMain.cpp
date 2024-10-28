#include <iostream>
#include <string>
#include<fstream>
using namespace std;

string ERROR_OPEN_FILE_MESSAGE = "Error al abrir el archivo productos.txt";

void mostrarMenu(char option){
	cout<<"############### MENU ################# \n";
	cout<<"1. Agregar nuevo producto"<<endl;
	cout<<"2. Despachar producto"<<endl;
	cout<<"3. Ingreso de producto a inventario \n";
	cout<<"4. Obtener Productos \n";
	cout<<"0. Salir \n \n";		
}

void agregarProductoAFile(int id, string name, double price, int cantidadInventario){
	ofstream file;
	file.open("productos.txt",ios::app);
	if(file.fail()){
		cout<<ERROR_OPEN_FILE_MESSAGE;
		exit(1);
	}
	file << id <<" "<< name << " "<< price << " "<< cantidadInventario<<endl;
	file.close();
}

void obtenerProductos(){
	
	int id;
	string name;
	double price;
	int cantidadInventario;
	
	ifstream file;
	file.open("productos.txt",ios::out|ios::in);
	if(file.fail()){
		cout<<ERROR_OPEN_FILE_MESSAGE;
		cout<<"error";
	}
	if(file.is_open()){
		system("cls");
		cout<<"########## Lista de Productos #############"<<endl<<endl;
		while(!file.eof()){
			file>>id>>name>>price>>cantidadInventario;
			cout<<id<<" "<<name<< " "<< price<< " "<<cantidadInventario<<endl;
			
		}
	} else {
		cout<<ERROR_OPEN_FILE_MESSAGE<<endl;
		cout<<"error";
	}
}

void mostrarAgregarNuevoProducto(){
	
	int id = 1;
	string name;
	double price;
	int cantidadInventario;
	char agregarNuevo = 's';
	
	while(agregarNuevo == 's'){
		system("cls");
		cout<<"########## Agreguemos un nuevo producto ############"<<endl;
		cout<<"\nIngresa el nombre del producto: "<<endl;
		cin.ignore();
		getline(cin,name);
		
		cout<<"\nIngresa el precio del producto: "<<endl;
		cin>>price;
		
		cout<<"\nIngresa la cantidad de inventario del producto: "<<endl;
		cin>>cantidadInventario;
		
		agregarProductoAFile(id, name, price, cantidadInventario);
		cout<<"Producto guardado exitosamente!!"<<endl;
		
		cout<<"\nDesea agregar un nuevo producto? s/n"<<endl;
		cin>> agregarNuevo;
	}
}

void mostrarDespacharProducto(){
	
	int idProducto;
	system("cls");
	cout<<"########## Despachemos un producto ############"<<endl;
	
	for(int i=0; i < 10; i++){
		cout<<i<<". Producto"<<i<<endl;
	}
	
	cout<<"\nIngresa el id del producto a despachar: "<<endl;
	cin >> idProducto;
}

void mostrarIngresoNuevaMercaderia(){
	cout<<"Ingresa el producto con nuevo ingreso"<<endl;
}

int main(){
	
	char option;

	while(option != '0'){
		system("cls");
		cout<<"Bienvenido a la aplicacion de Inventario \n"<<endl;
		
		mostrarMenu(option);
		cout<<"Ingresa una opcion: "<<endl;
		cin >> option;
		
		
		switch(option){
			case '0':
				cout<<"Good bye!"<<endl;
				break;
			case '1':
				mostrarAgregarNuevoProducto();
				break;
			case '2':
				mostrarDespacharProducto();
				break;
			case '3':
				mostrarIngresoNuevaMercaderia();
			case '4':
				obtenerProductos();
				break;
			default:
				cout<< "WARNING: Opcion invalida."<<endl;
		}
		system("pause");
	}
	
	return 0;
}

