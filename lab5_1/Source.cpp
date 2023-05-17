#include <iostream>

class Pair {
private:
    int first;
    int second;

public:
    Pair(int firstValue, int secondValue) : first(firstValue), second(secondValue) {}

    void setPair(int firstValue, int secondValue) {
        first = firstValue;
        second = secondValue;
    }

    bool isGreater(const Pair& other) const {
        return (first > other.first) || (first == other.first && second > other.second);
    }

    int getFirst() const {
        return first;
    }

    int getSecond() const {
        return second;
    }
};

class Fraction : public Pair {
public:
    Fraction(int wholeValue, int smallValue) : Pair(wholeValue, smallValue) {}

    bool isGreater(const Fraction& other) const {
        if (getFirst() > other.getFirst())
            return true;
        else if (getFirst() < other.getFirst())
            return false;
        return getSecond() > other.getSecond();
    }

    bool isEqual(const Fraction& other) const {
        return getFirst() == other.getFirst() && getSecond() == other.getSecond();
    }

    bool isLess(const Fraction& other) const {
        return !isGreater(other) && !isEqual(other);
    }
};

int main() {
    Pair pair1(1, 5);
    Pair pair2(4, 0);

    if (pair1.isGreater(pair2))
        std::cout << "pair1 is greater than pair2" << std::endl;
    else
        std::cout << "pair1 is not greater than pair2" << std::endl;

    Fraction fraction1(2, 4);
    Fraction fraction2(8, 7);

    if (fraction1.isGreater(fraction2))
        std::cout << "fraction1 is greater than fraction2" << std::endl;
    else if (fraction1.isEqual(fraction2))
        std::cout << "fraction1 is equal to fraction2" << std::endl;
    else
        std::cout << "fraction1 is less than fraction2" << std::endl;

    return 0;
}
