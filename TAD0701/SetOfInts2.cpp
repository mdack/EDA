
#include <iostream>
using namespace std;

#include "Error.h"
#include "SetOfInts2.h"


// Constructors

SetOfInts2::SetOfInts2() {
	size = 0;
}


// Public methods

bool SetOfInts2::isEmpty() const{
	return (size == 0);
}

void SetOfInts2::add(int x) throw (Error) {
	if (!contains(x)){
		if (isFull())
			throw Error("Cannot add: The set is full");
		else {
			elems[size] = x;
			size++;
		}
	}
}

void SetOfInts2::remove(int x){
	bool found;
	int pos;

	linSearch(x,0,size,found,pos);
	if (found){
		size--;
		elems[pos] = elems[size];
	}
}

bool SetOfInts2::contains(int x) const {
	bool found;
	int pos;

	linSearch(x,0,size,found,pos);
	return found;
}

istream& operator>>(istream& sIn, SetOfInts2& set) {
	int n;
	int d;
	sIn >> n;
	set.size = 0;
	for (int i = 0; i < n; i++){
		sIn >> d;
		set.add(d);
	}
	return sIn;
}

ostream& operator<<(ostream& sOut, SetOfInts2& set) {
	sOut << "{";
	for (int i = 0; i < set.size-1; i++)
		sOut << set.elems[i] << ",";
	if (set.size > 0) sOut << set.elems[set.size-1];
	sOut << "}";
	return sOut;
}


// Private methods

bool SetOfInts2::isFull() const {
	return size == MAXSIZE;
}

void SetOfInts2::linSearch(int x, int left, int right, bool& found, int& pos) const {
// P: elems tiene al menos right elementos

	int i;

	if (left >= right) {
		found = false;
		pos = right;
	} else {
		found = false;
		i = left;
		while (!found && (i < right)) {
			found = elems[i] == x;
			if (!found)
				i++;
		}
		pos = i;
	}
	// Q :  found es true si existe un i en el intervalo left..right-1
	//        tal que elems[i] == x
	//      si found es true entonces pos = el minimo i en
	//        el intervalo left..right-1 tal que elems[i] == x
	//      si no found entonces pos == right
}

bool SetOfInts2::operator==(const SetOfInts2& set) {
	int i = 0;
	bool enc = true;
	int mitad, pos;

	//Reordenar los vectores
	//Y comprobar
	//El coste ser�a de O(n*log(n)) porque en realidad ser�a esto m�s
	//n ya que luego se hace una busqueda lineal, pero se coge el m�ximo
	//de esos dos costes

	if (set.size != size) enc = false;
	else {
		while (i < size && enc) {
			mitad = size / 2;
			linSearch(set.elems[i], 0, mitad, enc, pos);
			if (!enc) {
				linSearch(set.elems[i], mitad, size, enc, pos);
			}
			i++;
		}
	}
	return enc;
}