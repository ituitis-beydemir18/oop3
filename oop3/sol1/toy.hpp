#include <iostream>
#include <string>
using namespace std;
class Toy{
   private:
      string label;
      double weight;
	  double length;
	  double width;
	  bool containsBattery;
   public:
	  Toy(){
	  
	  } 
	  Toy(string label,double weight,double length,double width,bool containsBattery){
		  this->label=label;
		  this->weight=weight;
		  this->length=length;
		  this->width=width;
		  this->containsBattery=containsBattery;
	  }
	  static string getType(){
			return "Toy";
	  };
	  string getLabel() const{return label;};
	  double getWeight() const{return weight;};
	  double getLength() const{return length;};
	  double getWidth() const{return width;};
	  bool isContainsBattery() const{return containsBattery;};
	  void setLabel(string label){this->label=label;};	  
	  void setWeight(double weight){this->weight=weight;};
	  void setLength(double length){this->length=length;};
	  void setWidth(double width){this->width=width;};
	  void setContainsBattery(bool containsBattery){
		  this->containsBattery=containsBattery;};
	  friend std::ostream& operator<<(std::ostream& os, const Toy& obj)
	{
	  os<<"Toy Label: "<<obj.label<<" # "<< obj.length << "x" <<obj.width << " " <<obj.weight<<"kg "<< (obj.containsBattery?"Contains Battery":"No Battery")<<endl;
	  return os;
	}
};
