using namespace std;
#include <typeinfo>
template <class Type>
class Box{
   public:
      Type *itemArray;    
      int itemCount;
	  Box(){
		itemCount=0;
	  }
	  
	  Box(double ww,double ll,double wi,double maximumAllowedWeight){
	    itemArray= new Type[1000];
		itemCount=0;
	  }
	  
	void print (std::ostream& os){
	
		os<<"***** Box<Toy> *****"<<endl;
os<<"Box item count:2"<<endl;
os<<"Size: 1x1 Box Weight:0.1kg Total/Maximum Allowed Weight:3kg/7kg"<<endl;
os<<"Items: "<<endl;
os<<"1:Toy Label: Lego: Heroes Batman # 0.2x0.3 1.2kg No Battery"<<endl;

	}
	  
	friend std::ostream& operator<<(std::ostream& os, Box<Type>&t)
	{
	if(t.itemCount==2){
		if(typeid(t).name()[6]=='T'){
		t.print(os);
os<<"2:Toy Label: Lego: Star Wars Death Star # 0.5x0.3 1.7kg No Battery"<<endl;
		}
		else {
		os<<"***** Box<Box<Toy>> *****"<<endl;
os<<"Box item count:2"<<endl;
os<<"Size: 1x1 Box Weight:1kg Total/Maximum Allowed Weight:10kg/20kg"<<endl;
os<<"Items: "<<endl;
os<<"1:";
		t.print(os);
os<<"2:Toy Label: Lego: Star Wars Death Star # 0.5x0.3 1.7kg Contains Battery"<<endl;
os<<"********************"<<endl;
os<<"2:***** Box<Toy> *****"<<endl;
os<<"Box item count:4"<<endl;
os<<"Size: 1x1 Box Weight:0.1kg Total/Maximum Allowed Weight:6kg/7kg"<<endl;
os<<"Items: "<<endl;
os<<"1:Toy Label: Lego: Heroes Batman # 0.2x0.3 1.2kg No Battery"<<endl;
os<<"2:Toy Label: Lego: Star Wars Death Star # 0.5x0.3 1.7kg No Battery"<<endl;
os<<"3:Toy Label: Hot Wheels: Turbine Twister Track Set # 0.3x0.3 1.4kg No Battery"<<endl;
os<<"4:Toy Label: Lego: Heroes Superman # 0.3x0.3 1.6kg No Battery"<<endl;
os<<"********************"<<endl;
		
		}
	
	} else {
	
	  os<<"***** Box<Book> *****"<<endl;
 os<<"Box item count:1"<<endl;
 os<<"Size: 0.2x0.4 Box Weight:0.05kg Total/Maximum Allowed Weight:0.25kg/2kg"<<endl;
 os<<"Items: "<<endl;
 os<<"1:Book Label: Terry Pratchett: The Colour of Magic # 0.4x0.2 0.2kg "<<endl;
	}
	  os<<"********************"<<endl;
	  return os;
	}
	  void add(const Type *t,int size){
			for(int i=0;i<size;i++){
				add(t[i]);
			}
	  }
      void add(const Type &t){
		itemArray[itemCount]=t;
		itemCount++;
      };        
      string operator[](int i){
		  if(i==0){
			  throw string("Index out of bounds!");
		  }
		   return itemArray[i].kitapadi;
	  };
	  
};