// 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <exception>
#include <iostream>

class Rectangle {

private:
    double length_, width_, area_;
public:
    void SetLength(double length) {
        if (length <= 0) throw std::invalid_argument("Length has to be positive");
        length_ = length;
        area_ = length_ * width_;
    }

    void SetWidth(double width) {
        if (width <= 0) throw std::invalid_argument("Width has to be positive");
        width_ = width;
        area_ = length_ * width_;

    }

    double GetLength() { return length_; }
    double GetWidth() { return width_; }
    double GetArea() { return area_; }
    Rectangle(double length, double width) : length_(length), width_(width), area_(length* width) {}
};

#include <iostream>

int main()
{
    double l, w;
    Rectangle r(1, 1);
    bool correct_input = false;
    do {
        std::cout << "Enter rectangle dimensions:";
        std::cin >> l >> w;
        try
        {
            r.SetLength(l);
            r.SetWidth(w);
            correct_input = true;
        }
        catch (const std::invalid_argument& a)
        {
            std::cout << a.what() << "\n";
        }
    } while (!correct_input);

    std::cout << "Rectangle area: " << r.GetArea();
}