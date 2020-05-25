#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>
#include <iostream>

Mat2& Mat2::operator*=(Mat2 const& m) {
    Mat2 a{*this};
    Mat2 b{
        a.e_00 * m.e_00 + a.e_10 * m.e_01,
        a.e_00 * m.e_10 + a.e_10 * m.e_11,
        a.e_01 * m.e_00 + a.e_11 * m.e_01,
        a.e_01 * m.e_10 + a.e_11 * m.e_11 };

    *this = b;
    return *this;
}

float Mat2::det() const {
    return e_00 * e_11 - e_10 * e_01;
}


Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
    return Mat2(m1) *= m2;
}
Vec2 operator*(Mat2 const& m, Vec2 const& v) {
    return {v.x * (m.e_00 + m.e_10), v.y * (m.e_01 + m.e_11)}; 
}

Mat2 inverse(Mat2 const& m) {
    float det = m.det();
    if (det == 0.0f) {
        std::cout << "The determinant of the Matrix is equal to 0 \n";
        return m;
    }
    return {m.e_11 / det, -m.e_10 / det, -m.e_01 / det, m.e_00 / det};
}

Mat2 transpose(Mat2 const& m) {
    return {m.e_00, m.e_01, m.e_10, m.e_11};
}

Mat2 make_rotation_mat2(float phi) {
    return {std::cos (phi), -std::sin (phi), std::sin (phi), std::cos (phi)};
}