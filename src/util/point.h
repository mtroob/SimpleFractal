/*
 * point.h
 *
 *  Created on: Aug 19, 2017
 *      Author: michael
 */

#ifndef POINT_H_
#define POINT_H_

#include <type_traits>
#include <utility>

using std::move;
using std::common_type;

namespace fractal {

// Represents a point in 2d space
// Provides necessary mathematical operations, that can be used for several
// points with different template class types (if they are standard numeric types)
// The non-member mathematical functions, that return a Point class object,
// always return a point with a common template class type (a type that both
// coordinate types will be promoted to by the compiler)
template <class T>
struct Point {

    Point() : x(0), y(0) {}

	template <class U>
    Point(U x = 0, U y = 0) : x(x), y(y) {}

	template <class U>
    Point(const Point<U>& other) : x(other.x), y(other.y) {}

	template <class U>
    Point(Point<U>&& other) : x(move(other.x)), y(move(other.y)) {}

	template <class U>
	Point& operator=(const Point<U>& rhs) {
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	template <class U>
	Point& operator=(Point<U>&& rhs) {
		x = move(rhs.x);
		y = move(rhs.y);
		return *this;
	}

	template<class U>
	Point& operator+=(const Point<U>& rhs) {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	template<class U>
	Point& operator-=(const Point<U>& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	template<class U>
	Point& operator*=(const U& rhs) {
		x *= rhs;
		y *= rhs;
		return *this;
	}

	template<class U>
	Point& operator*=(const Point<U>& rhs) {
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	T x;
	T y;
};

template <class T, class U>
using common_type_t = typename common_type<T,U>::type;

template <class T, class U>
Point<common_type_t<T,U>> operator+(const Point<T>& lhs, const U& rhs) {
	return {lhs.x + rhs, lhs.y + rhs};
}

template <class T, class U>
Point<common_type_t<T,U>> operator+(const Point<T>& lhs, const Point<U>& rhs) {
	return {lhs.x + rhs.x, lhs.y + rhs.y};
}

template <class T, class U>
Point<common_type_t<T,U>> operator-(const Point<T>& lhs, const U& rhs) {
	return {lhs.x - rhs, lhs.y - rhs};
}

template <class T, class U>
Point<common_type_t<T,U>> operator-(const Point<T>& lhs, const Point<U>& rhs) {
	return {lhs.x - rhs.x, lhs.y - rhs.y};
}

template <class T, class U>
Point<common_type_t<T,U>> operator*(const Point<T>& lhs, const U& rhs) {
	return {lhs.x * rhs, lhs.y * rhs};
}

template <class T, class U>
Point<common_type_t<T,U>> operator*(const Point<T>& lhs, const Point<U>& rhs) {
	return {lhs.x * rhs.x, lhs.y * rhs.y};
}

template <class T, class U>
Point<common_type_t<T,U>> operator/(const Point<T>& lhs, const U& rhs) {
	return {lhs.x / rhs, lhs.y / rhs};
}

template <class T, class U>
Point<typename common_type<T,U>::type> operator/(const Point<T>& lhs, const Point<U>& rhs) {
	return {lhs.x / rhs.x, lhs.y / rhs.y};
}

} /* namespace fractal */

#endif /* POINT_H_ */
