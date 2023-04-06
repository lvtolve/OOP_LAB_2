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
        cout << "Default constructor called" << endl;
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
};

class Accident {
protected:
    Car* Model1, * Model2;
public:
    Accident() {
        Model1 = new Car;
        Model2 = new Car;
        cout << "Third default constructor called" << endl;
    }
    Accident(string a, int b, string c, int d) {
        Model1 = new Car(a, b);
        Model2 = new Car(c, d);
        cout << "Third constructor with parameters called" << endl;
    }
    Accident(Accident& obj) {
        Model1 = new Car(*(obj.Model1));
        Model2 = new Car(*(obj.Model2));
        cout << "Third copy constructor called" << endl;
    }
    ~Accident() {
        delete Model1;
        delete Model2;
        cout << "Third destructor called" << endl;
    }

};

int main() {
    Car* Model1 = new ElectroCar("Fervor", 125, 1.4);//помещение объкетов в перемннные раздичных типов 
    ElectroCar* Model2 = new ElectroCar("Beaster", 156, 1.9);
    delete Model1;
    delete Model2;
    cout << "-------------------------------------------------------------\n";
    //композиция объектов: атрибутом одного объекта класса A является другой объект класса B
    /*композиция объектов : атрибутом одного объекта класса A является указатель на другой объект класса B,
    создаваемый в конструкторе класса A и уничтожаемый в деструкторе класса A;
    композируемые классы должны определяться отдельно(не один в другом);
    при композиции показать, в чем разница,
    если объект класса А хранит прямо объект класса В или указатель на объект класса В.
    */
    Accident* Model3 = new Accident;
    Accident* Model4 = new Accident(*Model3);
    delete Model3;
    delete Model4;

}
