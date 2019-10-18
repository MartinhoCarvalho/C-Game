#pragma once
# include <iostream>
# include <sstream>
# include <string>
# include <exception>
using namespace std;

class ERROR_Exception:public exception{
	public:
		 virtual const char *out() const throw(){
				return "error";
		}
		~ERROR_Exception(void){}
};

