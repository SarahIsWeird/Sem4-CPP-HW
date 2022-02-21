#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
#include <string>

class Complex {
public:
    Complex(double left = 0, double right = 0, bool isPolar = false);
    Complex(const Complex &other);
    ~Complex();

    void SetReal(double real);
    void SetImaginary(double imaginary);
    void SetCartesian(double real, double imaginary);
    
    void SetMagnitude(double magnitude);
    void SetAngle(double angle);
    void SetPolar(double magnitude, double angle);

    double GetReal() const;
    double GetImaginary() const;

    double GetMagnitude() const;
    double GetAngle() const;

    std::string ToCartesianString() const;
    std::string ToPolarString() const;
    std::string ToString() const;

    static unsigned int GetInstanceCount() {
        return Complex::sm_instances;
    }

private:
    void CartesianToPolar();
    void PolarToCartesian();

    // Kartesisch
    double m_real = 0;
    double m_imaginary = 0;

    // Polar
    double m_magnitude = 0;
    double m_angle = 0;

    static unsigned int sm_instances;
};

#endif // COMPLEX_H