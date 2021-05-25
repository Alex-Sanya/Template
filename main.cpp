#include <iostream>
#include <tuple>
#include "Figures.hpp"

template<std::size_t> struct int_ {};

template <class Tuple, size_t Pos>
std::ostream& print_tuple(std::ostream& out, const Tuple& t, int_<Pos>) {
    out << std::get< std::tuple_size<Tuple>::value - Pos >(t) << ",\n";
    return print_tuple(out, t, int_<Pos - 1>());
}

template <class Tuple>
std::ostream& print_tuple(std::ostream& out, const Tuple& t, int_<1>) {
    return out << std::get<std::tuple_size<Tuple>::value - 1>(t);
}

template <class... Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& t) {
    print_tuple(out, t, int_<sizeof...(Args)>());
    return out;
}

template <class... Args>
void print(const std::tuple<Args...>& t)
{
    std::cout << t << std::endl;
}

template<class T, size_t index = 0>
double square(T& t) {
    if constexpr (index < std::tuple_size<T>::value) {
        return (double)SquareCalculation(std::get<index>(t)) + square<T, index + 1>(t);
    }
    else {
        return 0;
    }
}

signed main() {
    Triangle<int> tri1(std::pair<int, int>(0, 0), 2, 3);
    Triangle<double> tri2(std::pair<double, double>(1.1, 2.2), 3.3, 4.4);
    Square<int> sq1(std::pair<int, int>(1, -2), 5);
    Square<double> sq2(std::pair<double, double>(8, 7.4), 5.5);
    Rectangle<int> rect1(std::pair<int, int>(1, -6), 4, 6);
    Rectangle<double> rect2(std::pair<double, double>(1.1, 2.2), 3.3, 4.4);
    auto _tuple = std::make_tuple(tri1, tri2, sq1, sq2, rect1, rect2);
    print(_tuple);
    std::cout << std::endl << "square: " << square(_tuple);
    return 0;
}