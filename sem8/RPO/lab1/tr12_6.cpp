#include <iostream>
#include <vector>

class ShoppingCart
{
public:
    void addItem(std::string name, double price, int quantity)
    {
        items.push_back({name, price, quantity});
    }

    double calculateTotal()
    {
        double total = 0.0;

        for (const auto &item : items)
        {
            double itemTotal = item.price * item.quantity;
            double discount = getDiscount(itemTotal);
            itemTotal -= discount;
            total += itemTotal;
        }

        return total;
    }

private:
    struct Item
    {
        std::string name;
        double price;
        int quantity;
    };

    std::vector<Item> items;

    double getDiscount(double itemTotal)
    {
        if (itemTotal > 100)
        {
            return itemTotal * 0.1;
        }
        else
        {
            return 0.0;
        }
    }
};

int main()
{
    ShoppingCart cart;
    cart.addItem("Item 1", 50.0, 2);
    cart.addItem("Item 2", 25.0, 3);

    double total = cart.calculateTotal();
    std::cout << "Total: " << total << std::endl;

    return 0;
}