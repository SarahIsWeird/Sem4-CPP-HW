#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <string>

class Complex {
public:
    Complex(double real, double imaginary);

    void SetReal(double real);
    void SetImaginary(double imaginary);
    void SetCartesian(double real, double imaginary);
    
    void SetMagnitude(double magnitude);
    void SetAngle(double angle);
    void SetPolar(double magnitude, double angle);

    double GetReal();
    double GetImaginary();

    double GetMagnitude();
    double GetAngle();

    std::string ToCartesianString();
    std::string ToPolarString();
    std::string ToString();

private:
    void CartesianToPolar();
    void PolarToCartesian();

    double m_real = 0;
    double m_imaginary = 0;

    double m_magnitude = 0;
    double m_angle = 0;
};

#endif // COMPLEX_H