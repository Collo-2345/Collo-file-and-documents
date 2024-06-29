// A program to develop a software system for a car rental agency.
#include<iostream>
using namespace std;

// design an abstract base class call vehicle with a common attribute
class VEHICLE{
	 public:
	 	   string model,choice,type;
	 	   string make;
	 	   int year,period;
     virtual void calculateRentalCost() = 0; // virtual function
	
};
class CAR: public VEHICLE{
        public:
        	  int num_Doors = 4;
			  int Fuel = 22; // 20 liter per 40 km
        	  int Efficiency = 87;// percentage
        	  int mileage = 220 ;//220 Km/h
        	  double Rental_Cost,base_Cost,period_cost,Effiency_cost;
        	  
        void calculateRentalCost() {
        	
        	cout<<"\n\nENTER CAR DETAILS:\n\n";
        	cout<<"Enter the Type of the car:";
        	cin>>type;
        	cout<<"\n";
        	cout<<"Enter the Model of the car:";
        	cin>>model;
        	cout<<"\n";
        	cout<<"Enter the MADE IN of the car:";
        	cin>>make;
        	cout<<"\n";
        	cout<<"Enter the  Year of the car:";
        	cin>>year;
        	cout<<"\n";
        	cout<<"Enter the Hiring period for the car:";
        	cin>>period;
        	cout<<"\n";
        	base_Cost = 15000;// base cost of hiring
        	Effiency_cost = 0.1;// Fuel / mileage is  efficiency cost 
        	period_cost = 2000 * period; // period cost of hiring
        	Rental_Cost = (base_Cost * period) + (period_cost * Effiency_cost);
			cout<<"\n\n ...SUMMERY DESCRIPTION OF THE CAR...\n\n";
			cout<<"\n Car Type :"<<type<<endl;
			cout<<"\n Model :"<<model<<endl;
			cout<<"\n Made in :"<<make<<endl;
			cout<<"\n Year :"<<year<<endl;
			cout<<"\n Number of Door :"<<num_Doors<<endl;
			cout<<"\n Mileage:"<<mileage<<" Km/h"<<endl;
			cout<<"\n Efficiency:"<<Efficiency<<" %"<<endl;
			cout<<"\n Fuel consumption :"<<Fuel<<" liter per 100 Km"<<endl;
			cout<<"\n Total Rental Cost :"<<Rental_Cost<<" KES"<<endl;
		}
			
};

class SUV : public VEHICLE{
	      public:
	      	  int num_Doors = 6;
	      	  int cargo_Capacity =1000;//kg
			  int Fuel = 40; // 40 liter per 120 km
        	  int Efficiency = 89;// percentage
        	  int mileage = 320 ;//320 Km/h
        	  double Rental_Cost,base_Cost,period_cost,Effiency_cost;
        	  
        	void calculateRentalCost() {
        	cout<<"\n\nENTER SUV DETAILS:\n\n";
        	cout<<"Enter the Type of the Suv:";
        	cin>>type;
        	cout<<"\n";
        	cout<<"Enter the Model of the suv:";
        	cin>>model;
        	cout<<"\n";
        	cout<<"Enter the MADE IN of the car:";
        	cin>>make;
        	cout<<"\n";
        	cout<<"Enter the  Year of the suv:";
        	cin>>year;
        	cout<<"\n";
        	cout<<"Enter the Hiring period for the suv:";
        	cin>>period;
        	cout<<"\n";
        	base_Cost = 27000;// base cost of hiring
        	Effiency_cost = 0.1375;// Fuel / mileage is  efficiency cost 
        	period_cost = 3000 * period; // period cost of hiring
        	Rental_Cost = (base_Cost * period) + (period_cost * Effiency_cost);
			cout<<"\n\n ...SUMMERY DESCRIPTION OF THE SUV...\n\n";
			cout<<"\n Car Type :"<<type<<endl;
			cout<<"\n Model :"<<model<<endl;
			cout<<"\n Made in :"<<make<<endl;
			cout<<"\n Year :"<<year<<endl;
			cout<<"\n Number of Door :"<<num_Doors<<endl;
			cout<<"\n Cargo Capacity :"<<cargo_Capacity<<" Tonnes"<<endl;
			cout<<"\n Mileage:"<<mileage<<" Km/h"<<endl;
			cout<<"\n Efficiency:"<<Efficiency<<" %"<<endl;
			cout<<"\n Fuel consumption :"<<Fuel<<" liter per 120 Km"<<endl;
			cout<<"\n Total Rental Cost :"<<Rental_Cost<<" KES"<<endl;
		}
	      	
};
class TRUCK : public VEHICLE{
	        public:
	          int num_Doors = 2;
			  int Fuel = 60; // 60 liter per 240 km
        	  int Efficiency = 91;// percentage
        	  int mileage = 360 ;//360 Km/h
        	  int cargo_Capacity = 2000; //2000 kg equivalent to 2 tonnes
        	  double Rental_Cost,base_Cost,period_cost,Effiency_cost;
	        	
	         	void calculateRentalCost() {
        	cout<<"\n\nENTER TRUCK DETAILS:\n\n";
        	cout<<"Enter the Type of the Truck:";
        	cin>>type;
        	cout<<"\n";
        	cout<<"Enter the Model of the truck:";
        	cin>>model;
        	cout<<"\n";
        	cout<<"Enter the MADE IN of the car:";
        	cin>>make;
        	cout<<"\n";
        	cout<<"Enter the  Year of the truck:";
        	cin>>year;
        	cout<<"\n";
        	cout<<"Enter the Hiring period for the truck:";
        	cin>>period;
        	cout<<"\n";
        	base_Cost = 35000;// base cost of hiring
        	Effiency_cost = 0.1667;// Fuel / mileage is  efficiency cost 
        	period_cost = 5000 * period; // period cost of hiring
        	Rental_Cost = (base_Cost * period) + (period_cost * Effiency_cost);
			cout<<"\n\n ...SUMMERY DESCRIPTION OF THE TRUCK...\n\n";
			cout<<"\n Car Type :"<<type<<endl;
			cout<<"\n Model :"<<model<<endl;
			cout<<"\n Made in :"<<make<<endl;
			cout<<"\n Year :"<<year<<endl;
			cout<<"\n Number of Door :"<<num_Doors<<endl;
			cout<<"\n Cargo Capacity :"<<cargo_Capacity<<" Tonnes"<<endl;
			cout<<"\n Mileage:"<<mileage<<" Km/h"<<endl;
			cout<<"\n Efficiency:"<<Efficiency<<" %"<<endl;
			cout<<"\n Fuel consumption :"<<Fuel<<" liter per 120 Km"<<endl;
			cout<<"\n Total Rental Cost :"<<Rental_Cost<<" KES"<<endl;
		}
	      		
};
 void quit(); // quit function to terminate
// function to enable client to select the type of car
         void choose(){
	 	 string choice;
		 cout<<"\n\n RENTAL VEHICLES..\n\n";
		 cout<<"[1] CAR\n";
		 cout<<"[2] SUV\n";
		 cout<<"[3] TRUCK\n";
		 cout<<"[0] QUIT\n";
		 cout<<"\n";
		 cout<<" Enter Choice...\n";
		 cin>> choice;
	VEHICLE *Vptr;	 
   if(choice=="1")
   {CAR C;
    Vptr = & C;
	Vptr -> calculateRentalCost(); }
	
   else if(choice=="2")
   {SUV S;
    Vptr = & S;
	Vptr -> calculateRentalCost(); }
	
   else if(choice=="3")
   {TRUCK T;
    Vptr = & T;
	Vptr -> calculateRentalCost();}
   else if(choice=="0"){quit();}
   else{cout<<"Invalid";}
   
}
void quit(){
    	//quit function
    	_exit(1);
	}

main(){

	choose();
	
	return 0;
}
