#include <iostream>
#include <string>

using namespace std;

class Personaje{
	private:
		string nombre;
		int puntosVida;
	public:
		Personaje(string nombre, int puntosVida);
		void recibirGolpe(int puntosPerdidos);
		string comer(int puntosGanados);
		string estaVivo();
		int getPuntosVida();
		string getNombre();
		
};

Personaje::Personaje(string nombre, int puntosVida){
	
	this->nombre = nombre;
	this->puntosVida = puntosVida;

}

string Personaje::getNombre(){
	return this->nombre;
}

int Personaje::getPuntosVida(){
	return this->puntosVida;
}

void Personaje::recibirGolpe(int puntosPerdidos){
	this->puntosVida -= puntosPerdidos;
}

string Personaje::comer(int puntosGanados){
	if(Personaje::estaVivo() == true){
		this->puntosVida += puntosGanados;
		return this->puntosVida;
	}else{
		mensaje = "no se puede revivir a un esta muerto";
		return mensaje;
	}
}

string Personaje::estaVivo(){
	if(this->puntosVida >0){
		return true
	}else{
		return false
	}
	
	
	
	
}
