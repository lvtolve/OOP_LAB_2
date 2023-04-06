#include <iostream>
using namespace std;

class Car {
private:
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

int main() {
    Car Model1;
    Car Model2("Runner", 289);
    Car Model3(Model2);

}
