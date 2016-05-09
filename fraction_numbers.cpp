// Variant #21
#include <iostream>

using std::cout; using std::cin;
using std::endl;

class Fraction {
    int n, d;
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b); 
    }
public:
    Fraction(int n, int d = 1) {
        Fraction::n = n / gcd(n, d);
        Fraction::d = d / gcd(n, d);
    }
    int num() { return n; }
    int den() { return d; }
    friend std::istream& operator>> (std::istream& in, Fraction& object);
};

std::ostream& operator<< (std::ostream& out, Fraction fraction) {
    int n = fraction.num();
    int d = fraction.den();
    if (n == d && n/d == 1)
        return out << "1";
    else if (d == 1)
        return out << n;
    else if (n == 0)
        return out << "0";
    else 
        return out << n << '/' << d;
}

std::istream& operator>> (std::istream& in, Fraction& object){
    int n, d;
    in >> n >> d;
    object.n = n / object.gcd(n, d);
    object.d = d / object.gcd(n, d);
    return in;
}

bool operator== (Fraction left, Fraction right) {
    return left.num() == right.num() && left.den() == right.den();
}

bool operator!= (Fraction left, Fraction right) {
    return !(left == right);
}

Fraction operator+ (Fraction left, Fraction right) {
    Fraction result(left.num() * right.den() + left.den() * right.num(), 
                    left.den() * right.den());
    return result;
}

Fraction operator- (Fraction left, Fraction right) {
    Fraction result(left.num() * right.den() - left.den() * right.num(), 
                    left.den() * right.den());
    return result;
}

Fraction operator* (Fraction left, Fraction right) {
    Fraction result(left.num() * right.num(), left.den() * right.den());
    return result;
}

Fraction operator/ (Fraction left, Fraction right) {
    Fraction result(left.num() * right.den(), left.den() * right.num());
    return result;
}

int main(int argc, char const *argv[]) {
    Fraction first(1, 2), second(5, 2), third(2, 3);
    cout << first << " + " << second << " = "<< first + second << endl;
    cout << first << " - " << second << " = "<< first - second << endl;
    cout << first << " * " << third << " = "<< first * third << endl;
    cout << first << " / " << third << " = "<< first / third << endl;
    cout << "Enter a two fraction numbers splitted with space :\n";
    cin >> third >> second;
    cout << "Comparing: " << endl;
    cout << third << " == " << second << " => "<< (third == second) << endl;
    cout << third << " != " << second << " => "<< (third != second) << endl;
    return 0;
}