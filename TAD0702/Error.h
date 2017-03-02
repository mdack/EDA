
#ifndef ERROR_H_
#define ERROR_H_

#include <string>
#include <iostream>
using namespace std;

class Error{
	private:
		string message;

	public:
		Error(string m) {message = m;}
		string getMessage() {return message;}
};

#endif /* ERROR_H_ */
