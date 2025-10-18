#ifndef TYPE_HPP
#define TYPE_HPP

enum Type { CHAR_T, INT_T, FLOAT_T, DOUBLE_T, UNKNOWN_T };

struct Parsed {
    double base;     // ハブ値：ここから各型へcast
    bool   is_nan;   // NaNか
    int    inf_sign; // +∞=+1, -∞=-1, 有限=0
    Type   src;      // もとの検出型（表示体裁の参考）
    bool   from_char;// 1文字入力だったか（表示判断に便利）
    Parsed(): base(0.0), is_nan(false), inf_sign(0), src(UNKNOWN_T), from_char(false){}
};

#endif