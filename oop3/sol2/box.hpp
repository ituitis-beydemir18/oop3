using namespace std;
#include "base.hpp"
template <class Type>
class Box:public Base{
   private:
      Type *itemArray;    
      int itemCount;
      double maximumAllowedWeight;
	  
   public:
	  Box(){
		itemCount=0;
		itemArray = NULL;
	  }
	  
	  Box(double weight,double length,double width,double maximumAllowedWeight):Base("",weight,length,width){
		this->maximumAllowedWeight=maximumAllowedWeight;
		itemCount=0;
		itemArray = NULL;
	  }
	  
	  Box(const Box<Type> &b):Base(b){
		this->maximumAllowedWeight=b.maximumAllowedWeight;
		itemCount=b.itemCount;	
		itemArray = new Type[itemCount];	
		for(int i =0 ;i<itemCount;i++){
			itemArray[i]=b.itemArray[i];
		}
	  }
	  void operator=(const Box<Type> &b){
	    Base::operator=(b);
		this->maximumAllowedWeight=b.maximumAllowedWeight;
		if(itemCount!=b.itemCount){
			if(itemArray!=NULL)
				delete [] itemArray;
			itemArray = new Type[b.itemCount];	
		}
		itemCount=b.itemCount;	
		for(int i =0 ;i<itemCount;i++){
			itemArray[i]=b.itemArray[i];
		}
	  }
	  ~Box(){
	    if(itemArray!=NULL)
			delete [] itemArray;
	  }
	  
	  
	  static string getType(){
			return string("Box<")+Type::getType()+string(">");
	  };
	  
	  void add(const Type *t,int size){
			for(int i=0;i<size;i++){
				add(t[i]);
			}
	  }
	  double getWeight() const{
	    double weight=this->weight;
		for(int i =0 ;i<itemCount;i++){
			  weight+=itemArray[i].getWeight();
		 }
		 return weight;
	  }
	  
	  void setMaximumAllowedWeight(double maximumAllowedWeight){this->maximumAllowedWeight=maximumAllowedWeight;};
	  
	  double getMaximumAllowedWeight(){return maximumAllowedWeight;};
	  
	  
      void add(const Type &t){
	    if(t.getWeight() > maximumAllowedWeight - this->getWeight()){
			throw string("The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!"); 
		}
		if(!(t.getWidth()<=width && t.getLength()<= length) && !(t.getWidth()<=length && t.getLength()<= width) ){
			throw string("The dimensions of the contained object should be equal or smaller than those of the box!"); 
		}
		  
		Type *oldArray=itemArray;
		  
		itemArray = new Type[itemCount+1];
		
		for(int i =0 ;i<itemCount;i++){
			itemArray[i]=oldArray[i];
		}
		itemArray[itemCount]=t;
	    if(oldArray!=NULL)
			delete []oldArray;
		itemCount++;
      };      
	  
      Type& operator[](int i){
		  if(i>=itemCount|| i<0){
			  throw string("Index out of bounds!");
		  }
		   return itemArray[i];
	  };
	  
	  friend std::ostream& operator<<(std::ostream& os, const Box&t)
	{
	  os<<"***** "<<t.getType()<<" *****"<<endl;
	  os<<"Box item count:"<<t.itemCount<<endl;
	  os<<"Size: "<< t.length << "x" <<t.width << " Box Weight:" <<t.weight<<"kg Total/Maximum Allowed Weight:"<<t.getWeight()<<"kg/"<<t.maximumAllowedWeight<<"kg"<<endl;
	  os<<"Items: "<<endl;
	  for(int i =0 ;i<t.itemCount;i++){
		  os<<(i+1)<<":"<<t.itemArray[i];
	  }
	  os<<"********************"<<endl;
	  return os;
	}
	  
};