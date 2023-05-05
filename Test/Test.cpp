#include <iostream>
#include <string>
#include <windows.h>

class Data {
public:
	int dato;
	Data* nodoSiguiente = nullptr;
};

int stringTointeger(std::string str)
{
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		temp = temp * 10 + (str[i] - '0');
	}
	return temp;
}

Data* nuevoNodo(int dato) {
	Data* nuevoDato = new Data();

	nuevoDato->dato = dato;
	nuevoDato->nodoSiguiente = nullptr;

	return nuevoDato;
}

Data* nuevoNodo(int dato, Data* nodo) {
	Data* nuevoDato = new Data();

	nuevoDato->dato = dato;
	nuevoDato->nodoSiguiente = nodo;

	return nuevoDato;
}

Data* CrearLista() {
	Data* primero = nuevoNodo(1, nuevoNodo(2, nuevoNodo(3)));

	Data* head = primero;

	return head;
}

Data* AgregarNodo() {
	int value;
	std::string text;

	std::cout << "Ingresa el valor para el primer nodo: \n";
	std::cin >> value;

	Data* cabeza = nuevoNodo(value);
	Data* nodo = cabeza;

	system("CLS");

	std::cout << "Ingresa el valor para el nodo (escribe null para cancelar): \n";
	std::cin >> text;

	while (text != "null") {
		value = stringTointeger(text);
		nodo->nodoSiguiente = nuevoNodo(value);

		nodo = nodo->nodoSiguiente;

		system("CLS");

		std::cout << "Ingresa el valor para el nodo (escribe null para cancelar): \n";
		std::cin >> text;
	}

	return cabeza;
}

void RecorrerLista(Data* head) {
	std::cout<<"[" << head->dato << "]->";

	if (head->nodoSiguiente != nullptr)
	{
		RecorrerLista(head->nodoSiguiente);
	}
	else std::cout << "[NULL]";
}

void main() {

	Data dato1;
	Data dato2;
	Data dato3;

	dato1.dato = 1;
	dato2.dato = 2;
	dato1.nodoSiguiente = &dato2;

	dato3 = *nuevoNodo(3);
	dato2.nodoSiguiente = &dato3;

	//Data* head = CrearLista();
	//RecorrerLista(head);

	Data* head = AgregarNodo();

	system("CLS");

	RecorrerLista(head);
}