#include <iostream>
#include <string>
#include "base.hpp"
using namespace std;
class Toy:public Base{
   private:
	  bool containsBattery;
   public:
	  Toy(){
	  
	  } 
	  Toy(string label,double weight,double length,double width,bool containsBattery):Base(label,weight,length,width){
		  this->containsBattery=containsBattery;
	  }
	  static string getType(){
			return "Toy";
	  };
	  bool isContainsBattery() const{return containsBattery;};
	  void setContainsBattery(bool containsBattery){
		  this->containsBattery=containsBattery;};
	  friend std::ostream& operator<<(std::ostream& os, const Toy& obj)
	{
	  os<<"Toy Label: "<<obj.label<<" # "<< obj.length << "x" <<obj.width << " " <<obj.weight<<"kg "<< (obj.containsBattery?"Contains Battery":"No Battery")<<endl;
	  return os;
	}
};
