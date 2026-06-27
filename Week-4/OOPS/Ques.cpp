//Design a Vehicle Rental System with Vehicle, Car, and Bike classes using inheritance, encapsulation, and virtual functions for calculating rental costs based on rental duration and specific vehicle rates.
#include <iostream>
#include <string>
#include <iomanip>
class Vehicle {
protected:
    std::string p;
    std::string q;
    double r;
public:
    Vehicle(std::string x,std::string y,double z) 
        : p(x),q(y),r(z){}
    virtual ~Vehicle(){}
    std::string getP() const { return p; }
    std::string getQ() const { return q; }
    double getR() const { return r; }
    virtual double calculateRentalCost(int d) const = 0;
    virtual void displayDetails() const {
        std::cout << "Vehicle ID: " << p 
                  << " | Model: " << q 
                  << " | Base Rate/Day: $" << r;
    }
};
class Car : public Vehicle {
private:
    std::string s; 
public:
    Car(std::string x,std::string y,double z,std::string w)
        : Vehicle(x,y,z),s(w){}
    double calculateRentalCost(int d) const override {
        double c=r*d;
        if(s=="Luxury"){
            c+=50.0*d; 
        }
        return c;
    }
    void displayDetails() const override {
        Vehicle::displayDetails();
        std::cout << " | Type: " << s << " Car" << std::endl;
    }
};
class Bike : public Vehicle {
private:
    int t;
public:
    Bike(std::string x,std::string y,double z,int u)
        : Vehicle(x,y,z),t(u){}
    double calculateRentalCost(int d) const override {
        double c=r*d;
        if(t>250){
            c+=15.0*d; 
        }
        return c;
    }
    void displayDetails() const override {
        Vehicle::displayDetails();
        std::cout << " | Engine: " << t << "cc Bike" << std::endl;
    }
};
int main() {
    std::cout << std::fixed << std::setprecision(2);
    Vehicle* m[2];
    m[0]=new Car("C101","Sedan Cruise",40.0,"Luxury");
    m[1]=new Bike("B202","Street Rider",20.0,300);
    int n=5;
    std::cout << "--- Rental Fleet Details & Cost for " << n << " Days ---" << std::endl;
    for(int i=0;i<2;++i){
        m[i]->displayDetails();
        std::cout << "Total Rental Cost: $" << m[i]->calculateRentalCost(n) << std::endl;
        std::cout << "--------------------------------------------------" << std::endl;
    }
    for(int i=0;i<2;++i){
        delete m[i];
    }
    return 0;
}