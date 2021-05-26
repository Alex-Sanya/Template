#include <iostream>
#include <tuple>
#include "utl.h"
#include "Figures.hpp"

using namespace std;

template<size_t> struct int_ {};

template <class Tuple, size_t Pos>
ostream& print_tuple(ostream& out, const Tuple& t, int_<Pos>) 
{
    out << get< tuple_size<Tuple>::value - Pos >(t) << ",\n";
    return print_tuple(out, t, int_<Pos - 1>());
}

template <class Tuple>
ostream& print_tuple(ostream& out, const Tuple& t, int_<1>)
{
    return out << get<tuple_size<Tuple>::value - 1>(t);
}

template <class... Args>
ostream& operator<<(ostream& out, const tuple<Args...>& t) 
{
    print_tuple(out, t, int_<sizeof...(Args)>());
    return out;
}

template <class... Args>
void print(const tuple<Args...>& t)
{
    cout << t << endl;
}

template<class T, size_t index = 0>
double square(T& t) 
{
    if constexpr (index < tuple_size<T>::value) 
    {
        return (double)SquareCalculation(get<index>(t)) + square<T, index + 1>(t);
    }
    else 
    {
        return 0;
    }
}

signed main() 
{
    Triangle<int> tri1(pair<int, int>(0, 0), 2, 3);
    Triangle<double> tri2(pair<double, double>(1.1, 2.2), 3.3, 4.4);
    Square<int> sq1(pair<int, int>(1, -2), 5);
    Square<double> sq2(pair<double, double>(8, 7.4), 5.5);
    Rectangle<int> rect1(pair<int, int>(1, -6), 4, 6);
    Rectangle<double> rect2(pair<double, double>(1.1, 2.2), 3.3, 4.4);
    auto _tuple = make_tuple(tri1, tri2, sq1, sq2, rect1, rect2);
    print(_tuple);
    cout << endl << "square: " << square(_tuple);
    return 0;
}