#include "effective.hpp"

const double AspectRatio = 1.6432;
const int GamePlayer::NumTurns;
const double GamePlayer::FudgeFactor = 1.35;

const Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.data * rhs.data);
}

void TextBlock::printText() const {
    std::cout << "Text: " << text << std::endl;
}

std::size_t CTextBlock::length() const {
    if (!lengthIsValid) {
        textLength = std::strlen(pText);
        lengthIsValid = true;
    }

    return textLength;
}
