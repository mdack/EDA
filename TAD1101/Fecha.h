#ifndef FECHA_H
#define FECHA_H

class Fecha {

private:
	int _d;
	int _h;
	int _m;

public:

	/* Constructora por parámetros */
	Fecha(int d, int h, int m):_d(d), _h(h), _m(m){}

	/* Métodos de acceso a los datos de la fecha */
	int dia() const {
		return _d;
	}

	int hora() const {
		return _h;
	}

	int minuto() const {
		return _m;
	}

	/* Sobrecarga de operador "<", si la fecha es menor que la que se recibe devuelve true. */
	bool operator<(const Fecha fecha) const {
		bool esMenor = false;

		if (_d < fecha._d) {
			esMenor = true;
		}
		else if(_d == fecha._d){
			if (_h < fecha._h) {
				esMenor = true;
			}
			else if (_h == fecha._h) {
				if (_m < fecha._m) {
					esMenor = true;
				}
			}
		}
		return esMenor;
	}

	bool operator==(const Fecha f) const {
		return (_d == f._d && _h == f._h && _m == f._m);
	}
};

#endif
