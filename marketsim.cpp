#include<iostream>
#include<fstream>
using namespace std;

class bulding
{
private:
    int emp;
    int prod;
    int money;
    int salaries=1;
public:
    bulding(int init_emp){emp=init_emp;};
    int return_prod(){ prod=emp*2;return prod;};
    void money_acumulated(int gained)
    {money=(money+gained)-emp*salaries;}
    void new_salaries(int new_salaries)
    {salaries=new_salaries;}
    int employe_return(){return emp;}
    void employe_change(int price){
    if (2*price>salaries)
    {
        emp=emp+1;
    }else
    {
        emp=emp-1;
    }
    
    }
    int return_emp(){return emp;}
    ~bulding(){};
};
class pop
{
private:
    int size;
public:
    pop(int Size){size=Size;};
    int return_demand(){return size;}
    void size_change(int prod){if (prod>size)
    {
        size=size+4;
    }else if(prod<size)
    {
        size=size-1;
    }else
    {
        size=size+1;
    }
    }
    ~pop(){};
};
int main(){
    ofstream textFile;
    textFile.open("econsim.csv");
    textFile<<"demand"<<";"<<"price"<<";"<<"production"<<endl;
    int price=10;
    int salaries=11;
    int employes;
    int bought;
    pop farmer=2;
    int demand=farmer.return_demand();    
    bulding farm=1;
    int production=farm.return_prod();
    for (int i = 0; i < 150; i++)
    {
    employes=farm.employe_return();
    bought=employes*salaries/price;
    farmer.size_change(bought);
    production=farm.return_prod();
    demand=farmer.return_demand();
    if (demand>production)
    {
        price=price+1;
    }else if (demand<production)
    {
        price=price-1;
    }
    farm.employe_change(price);
    cout<<"demand: "<<demand<<endl;
    cout<<"price: "<<price<<endl;
    cout<<"production: "<<production<<endl;
    textFile<<demand<<";"<<price<<";"<<production<<endl;
    }
}