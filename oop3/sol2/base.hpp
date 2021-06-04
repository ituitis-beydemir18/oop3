#ifndef BASE_H
#define BASE_H

#include <string>
using namespace std;
class Base{
   protected:
      string label;
      double weight;
	  double length;
	  double width;
   public:
	  Base(){
		  
	  } 
	  Base(string label,double weight,double length,double width){
		  this->label=label;
		  this->weight=weight;
		  this->length=length;
		  this->width=width;
	  }
	  string getLabel() const{return label;};
	  double getWeight() const{return weight;};
	  double getLength() const{return length;};
	  double getWidth() const{return width;};
	  void setLabel(string label){this->label=label;};
	  void setWeight(double weight){this->weight=weight;};
	  void setLength(double length){this->length=length;};
	  void setWidth(double width){this->width=width;};
};

#endif