#include <iostream>
using namespace std;

class Product {
public:
    string name;
    double price;
    double discount;

    double finalPrice() {
        return (1 - discount) * price;
    }
};

int main() {
    Product p1;
    p1.name = "Notebook";
    p1.price = 1600.45;
    p1.discount = 0.15;

    cout << "Product name:         " << p1.name << endl;
    cout << "Product price:        " << p1.price << endl;
    cout << "Product discount:     " << p1.discount << endl;
    cout << "Product final price:  " << p1.finalPrice() << endl << endl;

    // Direct List Initialization
    Product p2 {"iPad", 899, 0.1};

    cout << "Product name:         " << p2.name << endl;
    cout << "Product price:        " << p2.price << endl;
    cout << "Product discount:     " << p2.discount << endl;
    cout << "Product final price:  " << p2.finalPrice() << endl << endl;

    return 0;
}