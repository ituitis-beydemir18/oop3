#include <iostream>
#include <string>
using namespace std;
class Book{
   public:
	  Book(){
		  
	  } 
	  string kitapadi;
	  Book(string l,double w,double uzunluk,double ww){
	  kitapadi=l;
	  }
	  friend std::ostream& operator<<(std::ostream& os, const Book& obj)
	{
	  return os;
	}
};
