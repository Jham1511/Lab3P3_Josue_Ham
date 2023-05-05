#include <iostream>
using namespace std;



void discos_ejercicio1() {
	int disco1[8], disco2[8], discoXOR[8];
	int opcion = 0;
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

void matriz_obstaculos() {

}
int menu() {
	cout << "\nMenu del Programa" << endl
		<< "1 -> Ejercicio 1" << endl
		<< "2 -> Ejercicio 2" << endl
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
		}
			  break;
		case 2: {

		}
			  break;
		}//Fin del switch
	}//Fin del while
	respuesta = menu();
}