#pragma once

#include <string>
#include <iostream>
#include <cstring>

#define ASPECT_RATIO 1.1413
#define FUNC_TAG() std::cout << "-------------------------- [ " << __FUNCTION__ << " ] -------------------------" << std::endl;
extern const double AspectRatio;

const char * const authorName = "Scott Meyers";
const std::string sauthorName = "Scott Meyers";

class GamePlayer {
private:
    static const int NumTurns = 5;  
    int score[NumTurns];
    static const double FudgeFactor;

public:
    GamePlayer()=default;
};

#define CALL_WITH_MAX(a, b) ((a) > (b) ? (a) : (b))

template <typename T> 
inline T callWithMax(T a, T b) {
    return (a > b) ? a : b;
}

enum class Color : uint8_t {
    Red,
    Green,
    Blue
};

enum OldColor {
    Red,
    Green,
    Blue
};

class Rational {
private:
    int data;
public:
    Rational() :data(0) {
        std::cout << "Rational: data = " << data << std::endl;
    }
     Rational(int a) : data(a) {
        std::cout << "Rational: data = " << data << std::endl;
    }
    void printRational() {
        std::cout << "Rational: data = " << data << std::endl;
    }
    Rational& operator=(const Rational& other) {
        if (this == &other) {
            return *this;
        }
        this->data = other.data;
        return *this;
    }
    friend const Rational operator*(const Rational& lhs, const Rational& rhs);
};

class TextBlock {
public:
    TextBlock() = default;
    TextBlock(std::string s) : text(s) { pText = &text[0]; }
    const char& operator[](std::size_t position) const { return text[position]; }
    char& operator[](std::size_t position) { return  text[position]; }
    void printText() const;
private:
    std::string text;
    char *pText;
};

class CTextBlock {
public:
    CTextBlock() :pText(nullptr) {}
    CTextBlock(std::string s) {
        pText = new char[s.length() + 1];
        strcpy(pText, s.c_str());
    }

    char& operator[](std::size_t position) const {
        return pText[position];
    }
    void printText() const { 
        std::cout << "TextBlock: " << pText << std::endl;
    }
    std::size_t length() const;
private:
    char *pText;
    std::size_t textLength;
    bool lengthIsValid;
};
