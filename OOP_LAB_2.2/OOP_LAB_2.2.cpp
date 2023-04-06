#include <iostream>
using namespace std;

class Car {
protected:
    string model;
    int max_speed;
public:
    Car() {
        model = "Forser";
        max_speed = 236;
        cout << endl << "Default constructor called" << endl;
    }
    Car(string a, int b) {
        model = a;
        max_speed = b;
        cout << "Constructor with parameters called" << endl;
    }
    Car(Car& obj) {
        model = obj.model;
        max_speed = obj.max_speed;
        cout << "Copy constructor called" << endl;
    }
    ~Car() {
        cout << model << " " << max_speed << "\n";
        cout << "Destructor called" << endl;
    }
    string getModel() {
        return model;
    }
    int getSpeed() {
        return max_speed;
    }
    void setModel(string a) {
        model = a;
    }
    void setSpeed(int b) {
        max_speed = b;
    }
};

class ElectroCar : public Car {
protected:
    double ai_model;
public:
    ElectroCar() : Car() {
        ai_model = 3.0;
        cout << "Second default constructor called" << endl;
    }
    ElectroCar(string a, int b, double c) : Car(a, b) {
        ai_model = c;
        cout << "Second constructor with parameters called" << endl;
    }
    ElectroCar(ElectroCar& obj) {
        model = obj.model;
        max_speed = obj.max_speed;
        ai_model = obj.ai_model;
        cout << "Second copy constructor called" << endl;
    }
    ~ElectroCar() {
        cout << model << " " << max_speed << " " << ai_model << "\n";
        cout << "Second destructor called" << endl;
    }
    double getAIModel() {
        return ai_model;
    }
    void setAImodel(double c) {
        ai_model = c;
    }
    void info() {
        cout << model << " " << max_speed << " " << ai_model << endl;
    }
};

int main() {
    Car* Model1 = new Car;
    Car* Model2 = new Car("Runner", 289);
    Car* Model3 = new Car(*Model2);
    delete Model1;
    delete Model2;
    delete Model3;
    ElectroCar* ElectroModel1 = new ElectroCar("Speeder", 312, 3.4);
    ElectroModel1->info();
    ElectroModel1->setAImodel(3.7);
    ElectroModel1->setSpeed(319);
    cout << "Change parametrs\n";
    delete ElectroModel1;
}
