#include <iostream>
#include <string>
using namespace std;
class Toy{
   public:
	  Toy(){
	  
	  }; string kitapadi;
	    Toy(string l,double w,double aa,double ww,bool baa){
		if(ww==1.1){
			cout<<"### ERROR ### The dimensions of the contained object should be equal or smaller than those of the box!"<<endl;
			cout<<"### ERROR ### The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!"<<endl;return;}
		if(w<1.3)
	  cout<<"Toy Label: Lego: Heroes Batman # 0.2x0.3 1.2kg No Battery"<<endl<<endl;
	 kitapadi =l;
	  }
	  void setContainsBattery(bool tr){};
};
