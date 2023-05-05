#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;



void discos_ejercicio1() {
	int disco1[8], disco2[8], discoXOR[8];
	int opcion;
	bool banderaDisco1 = false;
	bool banderaDisco2 = false;
	do
	{
		cout << "\n1 -> Guardar Datos en XOR" << endl
			<< "2 -> Obtener datos de disco 1" << endl
			<< "3 -> Obtener datos de disco 2" << endl
			<< "4 -> Salir" << endl
			<< "Ingrese la opcion que desea: ";
		cin >> opcion;
		switch (opcion) {
		case 1: {
			banderaDisco1 = true;
			banderaDisco2 = true;

			cout << "Ingrese datos del disco 1: " << endl;
			for (int i = 0; i < 8; i++)
			{
				cout << "Disco 1" << "[" << i << "]: ";
				cin >> disco1[i];
			}//Este for guarda los valores del disco 1 en posicion i

			cout << "Ingrese datos del disco 2: " << endl;
			for (int j = 0; j < 8; j++)
			{
				cout << "Disco 2" << "[" << j << "]: ";
				cin >> disco2[j];
			}//Este for guarda los valores del disco 2 en posicion j

			for (int k = 0; k < 8; k++)
			{
				if (disco1[k] == disco2[k])
				{
					discoXOR[k] = 0;
				}
				else if (disco1[k] != disco2[k]) {
					discoXOR[k] = 1;
				}
			} //Este for se encarga de guardar los datos en el disco xor con su metodología
			cout << "Disco XOR: " << "[";
			for (int l = 0; l < 8; l++)
			{
				cout << discoXOR[l] << " ";
			}
			cout << "]";
		}
			  break;
		case 2: {

			if (banderaDisco1 == true)
			{	
				cout << "Disco 1: [";
				for (int i = 0; i < 8; i++)
				{
					if (disco2[i] == discoXOR[i])
					{
						cout << "0" << " ";
					}
					else {
						cout << "1" << " ";
					}
				}
				cout << "]";
			}
			else {
				cout << "No se han calculado los valores del disco XOR";
			}
		}
			  break;
		case 3: {
			if (banderaDisco2 == true)
			{	
				cout << "Disco 2: [";
				for (int i = 0; i < 8; i++)
				{
					if (disco1[i] == discoXOR[i])
					{
						cout << "0" << " ";
					}
					else {
						cout << "1" << " ";
					}
				}
				cout << "]";
			}
			else {
				cout << "No se han calculado los valores del disco XOR";
			}
		}
			  break;
		}
	} while (opcion!=4);
}
char** Llenar_Matriz(int filas, int columnas) {
	char** M;
	M = new char*[filas];
	for (int i = 0; i < filas; i++)
	{
		M[i] = new char[columnas]; //Se guardan espacios en memoria
		for (int j = 0; j < columnas; j++)
		{
			M[i][j] = '-'; //Se llena la matriz de casillas normales
		}
	}
	return M;
}

int posicion_random(int tam) {
	int aleatorio = 1 + rand() % ((tam-1) - 1); //Rango de las casillas
	return aleatorio;
}
void agregar_obstaculos(char** mat, int obstaculos, int filas, int columnas) {
	int obstaculos_agregados = 0; //Contador para ir controlando el ciclo
	do {
		int fila = posicion_random(filas);
		int columna = posicion_random(columnas);
		if (mat[fila][columna] == '-') { //Comparo si los caracteres son iguales para no chocar obstaculos
			mat[fila][columna] = '#'; //Si se cumple se agrega en esa posicion el obstaculo
			obstaculos_agregados++; //Se incrementa el contador
		}
	} while (obstaculos_agregados < obstaculos);
}

void imprimir_matriz(char** mat, int filas, int columnas) { //Solo imprime la matriz con el formato deseado
	printf("\n");
	for (int i = 0; i < filas; i++)
	{
		cout << "|";
		for (int j = 0; j < columnas; j++)
		{
			cout << "'" << mat[i][j] << "'";
		}
		cout << "|";
		printf("\n");
	}
}

int menu() {
	cout << "\nMenu del Programa" << endl
		<< "1 -> Ejercicio 1 (Discos)" << endl
		<< "2 -> Ejercicio 2 (Matriz Obstaculos)" << endl
		<< "3 -> Salir" << endl
		<< "Ingrese la opcion que desea: " << endl;
	int numero;
	cin >> numero;
	return numero;
}

int main()
{
	int respuesta = menu();
	while (respuesta != 3) {
		switch (respuesta) {
		case 1: {
			discos_ejercicio1();
			break;
		}// Fin case 1
			 
		case 2: {
			printf("\n");
			cout << "Ingrese las filas de la matriz: ";
			int filas;
			cin >> filas;
			cout << "Ingrese las columnas de la matriz: ";
			int columnas;
			cin >> columnas;
			cout << "Ingrese los obstaculos de la matriz: ";
			int obstaculos;
			cin >> obstaculos;
			int casillas = filas * columnas;
			if (filas >= 5 && columnas >= 5 && (obstaculos >= 1 || obstaculos < casillas)) {
				char** mat = Llenar_Matriz(filas, columnas);
				agregar_obstaculos(mat, obstaculos, filas, columnas);
				imprimir_matriz(mat, filas, columnas);
				for (int i = 0; i < filas; i++)
				{
					delete[] mat[i];
				}
				delete[] mat;
			}
			else {
				cout << "Datos no validos";
			}
			break;
		}//Fin case 2
			  
		}//Fin del switch
		respuesta = menu();
	}//Fin del while
}