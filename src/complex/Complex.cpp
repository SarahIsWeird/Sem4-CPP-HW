#include "Complex.h"
#include <string>

unsigned int Complex::sm_instances = 0;

Complex::Complex(double left, double right, bool isPolar) : m_real(left), m_imaginary(right), m_magnitude(left), m_angle(right) {
    Complex::sm_instances++;
    
    if (!isPolar) {
        this->CartesianToPolar();
        return;
    }

    this->PolarToCartesian();
}

Complex::Complex(const Complex &other) : m_real(other.m_real), m_imaginary(other.m_imaginary), m_magnitude(other.m_magnitude), m_angle(other.m_angle) {
    Complex::sm_instances++;
}

Complex::~Complex() {
    Complex::sm_instances--;
}

void Complex::SetReal(double real) {
    this->m_real = real;

    this->CartesianToPolar();
}

void Complex::SetImaginary(double imaginary) {
    this->m_imaginary = imaginary;

    this->CartesianToPolar();
}

void Complex::SetCartesian(double real, double imaginary) {
    this->m_real = real;
    this->m_imaginary = imaginary;

    this->CartesianToPolar();
}

void Complex::SetMagnitude(double magnitude) {
    this->m_magnitude = magnitude;

    this->PolarToCartesian();
}

void Complex::SetAngle(double angle) {
    this->m_angle = angle;

    this->PolarToCartesian();
}

void Complex::SetPolar(double magnitude, double angle) {
    this->m_magnitude = magnitude;
    this->m_angle = angle;

    this->PolarToCartesian();
}

double Complex::GetReal() const {
    return this->m_real;
}

double Complex::GetImaginary() const {
    return this->m_imaginary;
}

double Complex::GetMagnitude() const {
    return this->m_magnitude;
}

double Complex::GetAngle() const {
    return this->m_angle;
}

std::string Complex::ToCartesianString() const {
    return "a = " + std::to_string(this->m_real) + "; b = " + std::to_string(this->m_imaginary);
}

std::string Complex::ToPolarString() const {
    return "r=" + std::to_string(this->m_magnitude) + "; theta=" + std::to_string(this->m_angle);
}

std::string Complex::ToString() const {
    return this->ToCartesianString() + " / " + this->ToPolarString();
}

void Complex::CartesianToPolar() {
    this->m_magnitude = std::sqrt(this->m_real * this->m_real + this->m_imaginary * this->m_imaginary);
    this->m_angle = std::atan2(this->m_imaginary, this->m_real);
}

void Complex::PolarToCartesian() {
    this->m_real = this->m_magnitude * std::cos(this->m_angle);
    this->m_imaginary = this->m_magnitude * std::sin(this->m_angle);
}