#include "ScalarConverter.hpp"
#include "LiteralDetector.hpp"
#include <cstdlib>   // strtod, strtol
#include <cerrno>    // errno, ERANGE
#include <cmath>     // std::isnan, std::isinf, std::fabs (C++98は <math.h> 相当)
#include <limits>    // numeric_limits
#include <climits>   // INT_MIN, INT_MAX

void ScalarConverter::convert(const std::string &l){
    Parsed out;
	Type type = detectType(l);
}

Type ScalarConverter::detectType(const std::string& l){
    if (l.empty())
		return (UNKNOWN_T);
	if (LiteralDetector::isPseudoFloat(l))
        return (FLOAT_T);
    if (LiteralDetector::isPseudoDouble(l))
        return (DOUBLE_T);
    if (LiteralDetector::isCharLit(l))
		return (CHAR_T);
	if (LiteralDetector::isIntLit(l))
		return (INT_T);
	if (LiteralDetector::isFloatLit(l))
		return (FLOAT_T);
	if (LiteralDetector::isDoubleLit(l))
		return (DOUBLE_T);
	return (UNKNOWN_T);
}

void ScalarConverter::setPseudoFloat(const std::string& l, Parsed& out){
	out.src = FLOAT_T;
	if (l == "nanf"){
		out.is_nan = true;
		out.base = std::numeric_limits<double>::quiet_NaN();
	}
	else if (l == "+inff"){
		out.inf_sign = 1;
		out.base = std::numeric_limits<double>::infinity();
	}
	else if (l == "-inff"){
		out.inf_sign = -1;
		out.base = -std::numeric_limits<double>::infinity();
	}
}

void ScalarConverter::setPseudoDouble(const std::string& l, Parsed& out){
	out.src = DOUBLE_T;
	if (l == "nan"){
		out.is_nan = true;
		out.base = std::numeric_limits<double>::quiet_NaN();
	}
	else if (l == "+inf"){
		out.inf_sign = 1;
		out.base = std::numeric_limits<double>::infinity();
	}
	else if (l == "-inf"){
		out.inf_sign = -1;
		out.base = -std::numeric_limits<double>::infinity();
	}
}

bool ScalarConverter::parseToBase(const std::string& l, Type type, Parsed& out){
	out = Parsed();
	out.src = type;

	if (type == FLOAT_T && LiteralDetector::isPseudoFloat(l)){
		setPseudoFloat(l, out);
		return (true);
	}
	if (type == FLOAT_T && LiteralDetector::isPseudoFloat(l)){
		setPseudoDouble(l, out);
		return (true);
	}

	if (type == CHAR_T){
		char c = l[0]; // clarify literal can be converted to detected type
		out.from_char = true;
		out.base = static_cast<double>(c);
	}
	if (type == INT_T){
		errno = 0;
		char *end = 0;
		long v = std::strtol(l.c_str(), &end, 10);
		if (*end != '\0' || errno == ERANGE)
			return (false);
		if (v < INT_MIN || v > INT_MAX)
			return (false);
		int i = static_cast<int>(v); // clarify literal can be converted to detected type
		out.base = static_cast<double>(i);
	}
	if (type == FLOAT_T){
		//ここからやる
		
		/*
		末尾の f を外す

		core = l.substr(0, l.size()-1);

		strtod で core をパース

		errno = 0; char* end = 0; double d = strtod(core.c_str(), &end);

		全消費チェック：*end == '\0' であること

		オーバーフローチェック：errno != ERANGE

		float に収まるか範囲確認（有限値のみ判定）

		fabs(d) <= numeric_limits<float>::max()

		（C++98 は lowest() がないので下限は -max() でよい）

		“実体として”いったん float に丸める

		float f = static_cast<float>(d);

		ハブ値に載せ替え

		out.base = static_cast<double>(f);

		成功で true を返す
		*/
	}
	if (type == DOUBLE_T){
		// ここからやる
		/*
		strtod でそのままパース

		errno = 0; char* end = 0; double d = strtod(l.c_str(), &end);

		全消費：*end == '\0'

		オーバーフロー：errno != ERANGE

		ハブ値に格納

		out.base = d;

		成功で true を返す
		*/
	}
}

