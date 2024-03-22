#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    Product(const string &name, double price)
        : name_(name), price_(price) {}

    string getName() const
    {
        return name_;
    }

    double getPrice() const
    {
        return price_;
    }

private:
    string name_;
    double price_;
};

class ShoppingCart
{
public:
    void addProduct(const Product &product)
    {
        products_.push_back(product);
    }

    double getTotalPrice() const
    {
        double totalPrice = 0.0;

        for (const auto &product : products_)
        {
            totalPrice += applyDiscount(product);
        }

        return totalPrice;
    }

    void setDiscountRate(double discountRate)
    {
        discountRate_ = discountRate;
    }

    double applyDiscount(const Product &product) const
    {
        return product.getPrice() * (1.0 - discountRate_);
    }

private:
    vector<Product> products_;
    double discountRate_;
};

int main()
{
    ShoppingCart cart;

    Product apple("Apple", 25);
    Product banana("Banana", 35);
    Product orange("Orange", 55);

    cart.setDiscountRate(0.2);

    cart.addProduct(apple);
    cart.addProduct(banana);
    cart.addProduct(orange);

    cout << "Total price: " << cart.getTotalPrice() << "$";

    return 0;
}