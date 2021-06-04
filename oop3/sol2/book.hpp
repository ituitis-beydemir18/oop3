#include <iostream>
#include <string>
#include "base.hpp"
using namespace std;
class Book:public Base{
   public:
	  Book(){
		  
	  } 
	  Book(string label,double weight,double length,double width):Base(label,weight,length,width){
	  }
	  static string getType(){
			return "Book";
	  };
	  friend std::ostream& operator<<(std::ostream& os, const Book& obj)
	{
	  os<<"Book Label: "<<obj.label<<" # "<< obj.length << "x" <<obj.width << " " <<obj.weight<<"kg "<<endl;
	  return os;
	}
};
