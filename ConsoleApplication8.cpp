#include <iostream>
using namespace std;

class GeometricFigure {
public:
    virtual double calculateArea() const = 0;
};

class Rectangle : public GeometricFigure {
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double calculateArea() const override {
        return width * height;
    }

private:
    double width, height;
};

class Circle : public GeometricFigure {
public:
    Circle(double radius) : radius(radius) {}

    double calculateArea() const override {
        return 3.14159265358979323846 * radius * radius;
    }

private:
    double radius;
};

class Triangle : public GeometricFigure {
public:
    Triangle(double base, double height) : base(base), height(height) {}

    double calculateArea() const override {
        return 0.5 * base * height;
    }

private:
    double base, height;
};

class ComplexFigure {
public:
    ComplexFigure() : numFigures(0) {}

    void addFigure(GeometricFigure* figure) {
        if (numFigures < MAX_FIGURES) {
            figures[numFigures++] = figure;
        }
    }

    double calculateTotalArea() const {
        double totalArea = 0.0;
        for (int i = 0; i < numFigures; ++i) {
            totalArea += figures[i]->calculateArea();
        }
        return totalArea;
    }

private:
    static const int MAX_FIGURES = 10;
    GeometricFigure* figures[MAX_FIGURES];
    int numFigures;
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.0);
    Triangle triangle(4.0, 6.0);

    ComplexFigure complexFigure;
    complexFigure.addFigure(&rectangle);
    complexFigure.addFigure(&circle);
    complexFigure.addFigure(&triangle);

    double totalArea = complexFigure.calculateTotalArea();
    std::cout << "Total area of the complex figure: " << totalArea << std::endl;

    return 0;
}
