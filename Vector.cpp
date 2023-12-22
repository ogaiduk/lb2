#pragma once
#include "Vector.h"
#include "OutOfRange.h"
#include "IncompatibleDimException.h"






Vector::Vector() : ptr(nullptr), size(0) {};


Vector::Vector(size_t i_size) : size(i_size) {
    ptr = new double[size];
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = 0;
    }
}

Vector::Vector(size_t i_size, double value) : size(i_size) {
    ptr = new double[size];
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = value;
    }
}

Vector::Vector(const Vector& v) : size(v.size) {
    ptr = new double[size];
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = v.ptr[i];
    }
}

Vector::~Vector() {
    delete[] ptr;
    size = 0;
}


Vector& Vector::operator= (const Vector& v1) {
    size = v1.capacity();
    delete[] ptr;
    ptr = new double[size];
    for (size_t i = 0; i < size; ++i) {
        ptr[i] = v1.ptr[i];
    }
    return *this;
}


Vector& Vector::operator+= (const Vector& v1) {
    if (size == v1.size) {
        for (size_t i = 0; i < size; ++i) {
            ptr[i] += v1.ptr[i];
        }
    }
    else {
        throw IncompatibleDimException("Dimensions are not equal");
    }
    return *this;
}

Vector& Vector::operator-= (const Vector& v1) {
    if (size == v1.size) {
        for (size_t i = 0; i < size; ++i) {
            ptr[i] -= v1.ptr[i];
        }
    }
    else {
        throw IncompatibleDimException("Dimensions are not equal");
    }
    return *this;
}

Vector& Vector::operator-- (int) {
    for (size_t i = 0; i < size; ++i) {
        ptr[i] -= 1;
    }
    return *this;
}

Vector& Vector::operator++ (int) {
    for (size_t i = 0; i < size; ++i) {
        ptr[i] += 1;
    }
    return *this;
}

Vector Vector::operator- (const Vector& v1) {
    if (size == v1.size) {
        for (size_t i = 0; i < size; ++i) {
            ptr[i] -= v1.ptr[i];
        }
    }
    else {
        throw IncompatibleDimException("Dimensions are not equal");
    }
    return *this;
}

Vector Vector::operator+ (const Vector& v1) {
    if (size == v1.size) {
        for (size_t i = 0; i < size; ++i) {
            ptr[i] += v1.ptr[i];
        }
    }
    else {
        throw IncompatibleDimException("Dimensions are not equal");
    }
    return *this;
}

Vector Vector::operator* (const double a) {
    for (size_t i = 0; i < size; ++i) {
        ptr[i] *= a;
    }

    return *this;
}

 double Vector::operator* (const Vector& v1) {
    double ans = 0;
    if (size == v1.size) {
        for (size_t i = 0; i < size; ++i) {
            ans += ptr[i] * v1.ptr[i];
        }
    }
    else {
        throw IncompatibleDimException("Dimensions are not equal");
    }
    return ans;
}

double& Vector::operator[] (int i) {
    if (i >= size or i < 0) {
        throw OutOfRange("element with this index doesnt exist\n");
    }
    return ptr[i];
}



Vector::operator double* () const {
    return ptr;
}

double Vector::lenght() const {
    double ans = 0;
    for (size_t i = 0; i < size; ++i) {
        ans += ptr[i] * ptr[i];
    }
    return sqrt(ans);
}

size_t Vector::capacity() const {
    return size;
}

Vector operator*(double a, Vector& v) {
    for (size_t i = 0; i < v.size; ++i) {
        v.ptr[i] *= a;
    }
    return v;
}


std::ostream& operator<<(std::ostream& os, Vector& v) {
    for (size_t i = 0; i < v.size; ++i) {
        os << v.ptr[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Vector& v) {
    for (size_t i = 0; i < v.size; ++i) {
        is >> v.ptr[i];
    }
    return is;
}
