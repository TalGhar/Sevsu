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
        return applyDiscount();
    }

    void setDiscountRate(double discountRate)
    {
        discountRate_ = discountRate;
    }

    double applyDiscount() const
    {
        return price_ * (1.0 - discountRate_);
    }

private:
    string name_;
    double price_;
    double discountRate_ = 0.0;
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
            totalPrice += product.getPrice();
        }

        return totalPrice;
    }

private:
    vector<Product> products_;
};

int main()
{
    ShoppingCart cart;

    Product apple("Apple", 25);
    Product banana("Banana", 35);
    Product orange("Orange", 55);

    apple.setDiscountRate(0.5);

    cart.addProduct(apple);
    cart.addProduct(banana);
    cart.addProduct(orange);

    cout << "Total price: " << cart.getTotalPrice() << "$";

    return 0;
}