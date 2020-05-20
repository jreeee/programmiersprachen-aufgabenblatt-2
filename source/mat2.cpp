#include "mat2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m) {
    float tmp_00 = e_00;
    float tmp_01 = e_01;
    float tmp_10 = e_10;
    float tmp_11 = e_11;
    e_00 = tmp_00 * m.e_00 + tmp_10 * m.e_01;
    e_10 = tmp_00 * m.e_10 + tmp_10 * m.e_11;
    e_01 = tmp_01 * m.e_00 + tmp_11 * m.e_01;
    e_11 = tmp_01 * m.e_10 + tmp_11 * m.e_11;
    return *this;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
    return Mat2(m1) *= m2;
}