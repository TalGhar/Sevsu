#include <iostream>

class DrawingAPI
{
public:
    void drawCircle(int x, int y, int radius)
    {
        std::cout << "API.circle at " << x << "," << y << " with radius " << radius << "\n";
    };
    virtual void drawSquare(int x, int y, int side)
    {
        std::cout << "API.square at " << x << "," << y << " with side " << side << "\n";
    };
    virtual void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        std::cout << "API.triangle with points (" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), (" << x3 << "," << y3 << ")\n";
    };
};

class Circle
{
private:
    DrawingAPI *drawingAPI;
    int x, y, radius;

public:
    Circle(DrawingAPI *drawingAPI, int x, int y, int radius) : drawingAPI(drawingAPI), x(x), y(y), radius(radius) {}

    void draw()
    {
        drawingAPI->drawCircle(x, y, radius);
    }
};

class Square
{
private:
    DrawingAPI *drawingAPI;
    int x, y, side;

public:
    Square(DrawingAPI *drawingAPI, int x, int y, int side) : drawingAPI(drawingAPI), x(x), y(y), side(side) {}

    void draw()
    {
        drawingAPI->drawSquare(x, y, side);
    }
};

class Triangle
{
private:
    DrawingAPI *drawingAPI;
    int x1, y1, x2, y2, x3, y3;

public:
    Triangle(DrawingAPI *drawingAPI, int x1, int y1, int x2, int y2, int x3, int y3) : drawingAPI(drawingAPI), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    void draw()
    {
        drawingAPI->drawTriangle(x1, y1, x2, y2, x3, y3);
    }
};


int main() {
    DrawingAPI* drawingAPI = new DrawingAPI();

    Circle* circle = new Circle(drawingAPI, 10, 20, 15);
    Square* square = new Square(drawingAPI, 50, 60, 20);
    Triangle* triangle = new Triangle(drawingAPI, 100, 110, 120, 130, 140, 150);

    circle->draw();
    square->draw();
    triangle->draw();

    delete circle;
    delete square;
    delete triangle;
    delete drawingAPI;

    return 0;
}