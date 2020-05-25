#include "mat2.hpp"

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

Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
    return Mat2(m1) *= m2;
}