#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    Product(const string& name, double price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    const string& getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setQuantity(int newQuantity) { quantity = newQuantity; }

    virtual void purchase(int quantityToBuy) {
        if (quantityToBuy <= quantity) {
            quantity -= quantityToBuy;
            cout << "Purchased " << quantityToBuy << " " << name << "(s)." << endl;
        }
        else {
            cout << "Not enough quantity available for purchase." << endl;
        }
    }

private:
    string name;
    double price;
    int quantity;
};

class Electronics : public Product {
public:
    Electronics(const string& name, double price, int quantity, const string& brand)
        : Product(name, price, quantity), brand(brand) {}

private:
    string brand;
};

class Clothing : public Product {
public:
    Clothing(const string& name, double price, int quantity, const string& size)
        : Product(name, price, quantity), size(size) {}

private:
    string size;
};

class Food : public Product {
public:
    Food(const string& name, double price, int quantity, const string& expirationDate)
        : Product(name, price, quantity), expirationDate(expirationDate) {}

    void purchase(int quantityToBuy) override {
        if (quantityToBuy <= getQuantity()) {
            setQuantity(getQuantity() - quantityToBuy);
            cout << "Purchased " << quantityToBuy << " " << getName() << "(s) with expiration date " << expirationDate << "." << endl;
        }
        else {
            cout << "Not enough quantity available for purchase." << endl;
        }
    }

private:
    string expirationDate;
};

class ShoppingCart {
public:
    void addProduct(Product* product) {
        if (numProducts < MAX_PRODUCTS) {
            products[numProducts++] = product;
        }
    }

    void purchaseProducts() {
        for (int i = 0; i < numProducts; ++i) {
            products[i]->purchase(1);
        }
    }

private:
    static const int MAX_PRODUCTS = 10;
    Product* products[MAX_PRODUCTS];
    int numProducts = 0;
};

int main() {
    Electronics laptop("Laptop", 1000.0, 5, "Dell");
    Clothing shirt("Shirt", 25.0, 10, "M");
    Food apple("Apple", 1.0, 50, "2023-08-10");

    ShoppingCart cart;
    cart.addProduct(&laptop);
    cart.addProduct(&shirt);
    cart.addProduct(&apple);

    cart.purchaseProducts();

    return 0;
}