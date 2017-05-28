#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include <iostream>
#include <string>
using namespace std;

#include "HashMap.h"
#include "TreeMap.h"
#include "Fecha.h"
#include "List.h"


typedef string IdMedico;
typedef string Paciente;
typedef TreeMap<Fecha, Paciente> InfoMedico;


class Consultorio {

private:
	HashMap<IdMedico, InfoMedico> medicos;

public:
	//Parte pública


	//Constructor. Coste: O(1).
	Consultorio() : medicos() {

	}

	//Coste: O(1).
	void nuevoMedico(string nombMedico) {
		//Si ya lo contiene, no hace nada.
		if (!medicos.contains(nombMedico)) {	
			InfoMedico info;
			medicos.insert(nombMedico, info);
		}
	}

	//Coste: O(log(n)).
	void pideConsulta(string paciente, string medico, Fecha fecha) {
		//Si el médico no existe execpción
		if (!medicos.contains(medico))
			throw MedicoNoExiste();
		else {
			//Buscamos la fecha solicitada
			HashMap<IdMedico, InfoMedico>::Iterator it = medicos.find(medico);
			//Si la fecha está reservada excepción
			if (it.value().contains(fecha)) {
				throw FechaOcupada();
			}
			//Sino insertamos la cita en la información del médico
			else {
				it.value().insert(fecha, paciente);
			}
		}
	}

	//Coste: O(log(n))
	string siguientePaciente(string m) {
		string paciente = "";
		if (!medicos.contains(m))
			throw MedicoNoExiste();
		else {
			HashMap<IdMedico, InfoMedico>::Iterator it = medicos.find(m);
			
			if (it.value().empty())
				throw NoHayPacientes();
			else {
				TreeMap<Fecha, Paciente>::ConstIterator cit = it.value().cbegin();
				paciente = cit.value();
			}
		}
		return paciente;
	}

	//Coste: O(log(n))
	void atiendeConsulta(string m) {
		if (!medicos.contains(m))
			throw MedicoNoExiste();
		else {
			HashMap<IdMedico, InfoMedico>::Iterator it = medicos.find(m);

			if (it.value().empty())
				throw NoHayPacientes();
			else {
				TreeMap<Fecha, Paciente>::ConstIterator cit = it.value().cbegin();
				it.value().erase(cit.key());
			}
		}
	}
	
	//Coste: O(n), siendo n el numero de citas que tenga un médico
	InfoMedico listaPacientes(string m, Fecha f) {
		InfoMedico lista = InfoMedico();

		if (!medicos.contains(m))
			throw MedicoNoExiste();
		else {
			HashMap<IdMedico, InfoMedico>::Iterator it = medicos.find(m);
			if (!it.value().empty()) {

				TreeMap<Fecha, Paciente>::Iterator citInfo = it.value().begin();
				while(citInfo != it.value().end()) {
					if (citInfo.key().dia() == f.dia()) {
						lista.insert(citInfo.key(), citInfo.value());
					}
					citInfo.next();
				}				
			}
				
		}
		return lista;
	}
	
};

#endif 
