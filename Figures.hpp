#ifndef MY_FIG
#define MY_FIG

#include <iostream>

template<class T1, class T2>
std::ostream& operator << (std::ostream& out, const std::pair<T1, T2>& p) {
	out << "(" << p.first << ", " << p.second << ")";
	return out;
}

template <typename T>
struct Triangle
{
	std::pair<T, T> Cord;
	T Base, Hight;
	Triangle(const std::pair<T, T>& cord, T base, T hight) : Cord(cord), Base(base), Hight(hight) {}
};

template<typename T>
T SquareCalculation(const Triangle<T>& tri) {
	return tri.Base * tri.Hight / 2.0;
}

template<typename T>
std::ostream& operator << (std::ostream& o, const Triangle<T>& tri) {
	o << "Triangle {" << tri.Cord << ", ";
	std::pair<T, T> next_cord(tri.Cord.first + tri.Base / 2.0, tri.Cord.second + tri.Hight);
	o << next_cord << ", ";
	next_cord = std::pair<T, T>(tri.Cord.first + tri.Base, tri.Cord.second);
	o << next_cord << "}";
	return o;
}

template <typename T>
struct Square
{
	std::pair<T, T> Cord;
	T Side;
	Square(const std::pair<T, T>& cord, T side) : Cord(cord), Side(side) {}
};

template<typename T>
T SquareCalculation(const Square<T>& sq) {
	return sq.Side * sq.Side;
}

template<typename T>
std::ostream& operator << (std::ostream& o, const Square<T>& sq) {
	o << "Square {" << sq.Cord << ", ";
	std::pair<T, T> next_cord(sq.Cord.first, sq.Cord.second + sq.Side);
	o << next_cord << ", ";
	next_cord = std::pair<T, T>(sq.Cord.first + sq.Side, sq.Cord.second + sq.Side);
	o << next_cord << ", ";
	next_cord = std::pair<T, T>(sq.Cord.first + sq.Side, sq.Cord.second);
	o << next_cord << "}";
	return o;
}

template <typename T>
struct Rectangle
{
	std::pair<T, T> Cord;
	T LargerSide, SmallerSide;
	Rectangle(const std::pair<T, T>& cord, T largerSide, T smallerSide) : Cord(cord), LargerSide(largerSide), SmallerSide(smallerSide) {}
};

template<typename T>
T SquareCalculation(const Rectangle<T>& re) {
	return re.SmallerSide * re.LargerSide;
}

template<typename T>
std::ostream& operator << (std::ostream& o, const Rectangle<T>& re) {
	o << "Rectangle {" << re.Cord << ", ";
	std::pair<T, T> next_cord(re.Cord.first, re.Cord.second + re.SmallerSide);
	o << next_cord << ", ";
	next_cord = std::pair<T, T>(re.Cord.first + re.LargerSide, re.Cord.second + re.SmallerSide);
	o << next_cord << ", ";
	next_cord = std::pair<T, T>(re.Cord.first + re.LargerSide, re.Cord.second);
	o << next_cord << "}";
	return o;
}

#endif MY_FIG