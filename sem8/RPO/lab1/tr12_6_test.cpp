#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace std;

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

class ShoppingCartRefactored
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
            double discount = getDiscount(getItemTotal(item));
            total -= discount;
            total += getItemTotal(item);
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

    double getItemTotal(const Item &item) const
    {
        return item.price * item.quantity;
    }

    double getDiscount(double itemTotal) const
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

TEST_CASE("Testing shoping cart class (replace temp with query method)")
{
    ShoppingCart cart = ShoppingCart();
    ShoppingCartRefactored cart_refactored = ShoppingCartRefactored();
    cart.addItem("Item1", 100, 3);
    cart.addItem("Item2", 20, 2);
    SUBCASE("Not refactored cart")
    {
        CHECK(cart.calculateTotal() == 310);
    }

    cart_refactored.addItem("Item1", 100, 3);
    cart_refactored.addItem("Item2", 20, 2);
    SUBCASE("Refactored cart")
    {
        CHECK(cart_refactored.calculateTotal() == 310);
    }
}