#include <iostream>
#include <vector>
using namespace std;

class MyClass {
private:
    int x;
    int y;
public:
    MyClass(){
        x = 0;
        y = 0;
        cout << "Default constructor" << endl;
    }

    MyClass(int x0, int y0){
        this->x = x0;
        this->y = y0;
        cout << "Parameterized constructor" << endl;
    }

    MyClass(double x0, double y0){
        this->x = static_cast<int>(x0);
        this->y = static_cast<int>(y0);
        cout << "Conversion constructor" << endl;
    }

    MyClass(const MyClass& obj){
        this->x = obj.x;
        this->y = obj.y;
        cout << "Copy constructor" << endl;
    }

    MyClass(MyClass&& obj) noexcept{
        this->x = obj.x;
        this->y = obj.y;
        cout << "Move constructor" << endl;
    }

    MyClass& operator=(const MyClass& obj){
        this->x = obj.x;
        this->y = obj.y;
        cout << "Operator overloading" << endl;
        return *this;
    }

    ~MyClass(){
        cout << "Destructor" << endl;
    }
};


int main() {
    vector<MyClass> v;

    MyClass a;                      //Default constructor
    MyClass b(1,2);         //Parameterized constructor
    MyClass c(1.5, 2.5);    //Conversion constructor
    MyClass d = b;                  //Copy constructor
    v.push_back(move(a));        //Move constructor
    a = b;                          //Operator overloading

    return 0;
}
