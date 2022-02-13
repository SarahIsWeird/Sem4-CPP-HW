#include "Complex.h"
#include <string>

Complex::Complex(double real, double imaginary) : m_real(real), m_imaginary(imaginary) {
    this->CartesianToPolar();
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

double Complex::GetReal() {
    return this->m_real;
}

double Complex::GetImaginary() {
    return this->m_imaginary;
}

double Complex::GetMagnitude() {
    return this->m_magnitude;
}

double Complex::GetAngle() {
    return this->m_angle;
}

std::string Complex::ToCartesianString() {
    return "a = " + std::to_string(this->m_real) + "; b = " + std::to_string(this->m_imaginary);
}

std::string Complex::ToPolarString() {
    return "r=" + std::to_string(this->m_magnitude) + "; theta=" + std::to_string(this->m_angle);
}

std::string Complex::ToString() {
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