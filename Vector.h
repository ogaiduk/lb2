#pragma once
#include <iostream>
#include <math.h>
#include <ostream>  

#define DllExport   __declspec( dllexport )

    DllExport friend Vector operator*(double a, Vector& v);
    DllExport friend std::ostream& operator<<(std::ostream& os, Vector& v);
    DllExport friend std::istream& operator>>(std::istream& os, Vector& v);

public:
    Vector();
    Vector(size_t i_size);
    Vector(size_t i_size, double value);
    Vector(const Vector& v);
    ~Vector();
    Vector& operator= (const Vector& v1);
    Vector& operator+= (const Vector& v1);
    Vector& operator-= (const Vector& v1);
    Vector& operator-- (int);
    Vector& operator++ (int);
    Vector operator- (const Vector& v1);
    Vector operator+ (const Vector& v1);
    Vector operator* (const double a);
    double operator* (const Vector& v1);
    operator double* () const;
    double& operator[] (int i);
    double lenght() const;
    size_t capacity() const;

private:
    double* ptr;
    size_t size;

};

