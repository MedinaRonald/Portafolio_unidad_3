#include <iostream>
#include <string>
#include <cctype>
#include <algorithm> 
#include "pila.hpp"
#include "cola.hpp"

using namespace std;

bool revisarPalindromo(string palabraEva);
bool revisarTexto(string mensaje);

int main(){

	string texto;
	string textoviado;
	
	
	cout << "Escriba la palabra a revisar: ";
	getline(cin, texto);
	
	textoviado = texto;

	textoviado.erase(std::remove(textoviado.begin(), textoviado.end(), ' '), textoviado.end());
	
	
	textoviado.erase(std::remove_if(textoviado.begin(), textoviado.end(), [](unsigned char c) { return std::ispunct(c); }), textoviado.end()); 
	
	
	textoviado.erase(std::remove_if(textoviado.begin(), textoviado.end(), [](unsigned char c) { return std::isdigit(c); }), textoviado.end()); 

	transform(textoviado.begin(), textoviado.end(), textoviado.begin(), [](unsigned char c){ return toupper(c); });

 for (int i = 0; i < textoviado.length(); i++) {
    textoviado[i] = toupper(textoviado[i]);
  }

	cout << endl;
	
	if(revisarPalindromo(textoviado)){
		cout << "La palabra ingresada: '" << texto << "'es un Palindromo" << endl;
	}else{
		cout << "La palabra ingresada: '" << texto << "' NO es un Palindromo" << endl;
	}
	cout << endl;	
	return 0;
}


//funcion para revisar el palindromo
bool revisarPalindromo(string palabraEva){
	
	char letra;
	string palabraPila;
	string palabraLetra;
	
	Pila<char> pilaLetra;
	Cola<char> colaLetra;
	

	for(int i = 0; i < palabraEva.length(); i++){
		letra = palabraEva[i];
		pilaLetra.push(letra);
		colaLetra.enqueue(letra);
	}
	
	
	for(int i = 0; i < palabraEva.length(); i++){		
		palabraPila += pilaLetra.pop();
		palabraLetra += colaLetra.dequeue();
	}
		if(palabraPila == palabraLetra){
			cout << "Palabra escrita al reves: " << palabraPila << endl;
			cout << "Palabra escrita normal: " << palabraLetra << endl;
		return true;
	}else{
			cout << "Palabra escrita al reves: " << palabraPila << endl;
			cout << "Palabra escrita normal: " << palabraLetra << endl;
		return false;
	}
}
