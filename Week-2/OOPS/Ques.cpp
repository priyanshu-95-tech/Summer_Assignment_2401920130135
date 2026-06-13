//Design an e-commerce inventory system that uses inheritance and polymorphism to manage and display details for different product types like Electronics and Clothing.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Product{
public:
    int a;
    string b;
    float c;
    Product(int a,string b,float c):a(a),b(b),c(c){}
    virtual void p(){
        cout<<"ID: "<<a<<" Name: "<<b<<" Price: $"<<c<<endl;
    }
};
class Electronics:public Product{
public:
    int d;
    Electronics(int a,string b,float c,int d):Product(a,b,c),d(d){}
    void p()override{
        cout<<"[Electronics] ";
        Product::p();
        cout<<" Warranty: "<<d<<" months"<<endl;
    }
};
class Clothing:public Product{
public:
    string e,f;
    Clothing(int a,string b,float c,string e,string f):Product(a,b,c),e(e),f(f){}
    void p()override{
        cout<<"[Clothing] ";
        Product::p();
        cout<<" Size: "<<e<<" Material: "<<f<<endl;
    }
};
class Inventory{
    vector<Product*>v;
public:
    void add(Product*x){
        v.push_back(x);
    }
    void show(){
        for(auto x:v){
            x->p();
        }
    }
};
int main(){
    Inventory inv;
    inv.add(new Electronics(101,"Laptop",999.99,24));
    inv.add(new Clothing(102,"T-Shirt",19.99,"M","Cotton"));
    inv.show();
    return 0;
}