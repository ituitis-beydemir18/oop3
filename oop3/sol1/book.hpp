#include <iostream>
#include <string>
using namespace std;
class Book{
   private:
      string label;
      double weight;
	  double length;
	  double width;
   public:
	  Book(){
		  
	  } 
	  Book(string label,double weight,double length,double width){
		  this->label=label;
		  this->weight=weight;
		  this->length=length;
		  this->width=width;
	  }
	  static string getType(){
			return "Book";
	  };
	  string getLabel() const{return label;};
	  double getWeight() const{return weight;};
	  double getLength() const{return length;};
	  double getWidth() const{return width;};
	  void setLabel(string label){this->label=label;};
	  void setWeight(double weight){this->weight=weight;};
	  void setLength(double length){this->length=length;};
	  void setWidth(double width){this->width=width;};
	  friend std::ostream& operator<<(std::ostream& os, const Book& obj)
	{
	  os<<"Book Label: "<<obj.label<<" # "<< obj.length << "x" <<obj.width << " " <<obj.weight<<"kg "<<endl;
	  return os;
	}
};
