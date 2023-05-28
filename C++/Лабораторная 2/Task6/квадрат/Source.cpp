#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double k, x, y, d, a, b, c, r,min1,min2;
    cin >> k >> x >> y;
    a = fabs(k - x); b = fabs(k - y);
    c = fabs(x - 0); d = fabs(y - 0);

    if (k > 0) { //vne kvadrata//
        if (x >= k && y >= k) {
            r = sqrt(a * a + b * b);
            cout << setprecision(22) << r;
        }
        else if (x <= k && y >= k) {
            r = sqrtl(a * a + c * c);
            cout << setprecision(22) << r;
        }
        else if (y <= 0 && x <= 0) {
            r = sqrt(c * c + d * d);
            cout << setprecision(22) << r;
        }
        else if (x >= k && y <= 0) {
            r = sqrt(d * d + a * a);
            cout << setprecision(22) << r;
        }
        else if (x <= 0 && y >= k) {
            r = sqrt(c * c + b * b);
            cout << setprecision(22) << r;
        }
        else if (x >= 0 && x <= k && y >= k) {
            cout << setprecision(22) << b;
        }
        else if (y <= k && y >= 0 && x <= 0) {
            cout << setprecision(22) << c;
        }
        else if (x >= 0 && x <= k && y <= 0) {
            cout << setprecision(22) << d;
        }
        else if (x >= k && y >= 0 && y <= k) {
            cout << setprecision(22) << a;
        }
        else if (x > 0 && y > 0 && x < k && y < k) { //vnutri

            if (a > b) {
                min1 = b;
            }
            else { min1 = a; }

            if (x > y) {
                min2 = y;
            }
            else {
                min2 = x;
            }

            if (min2 > min1) {
                cout << setprecision(22) << min1;
            }
            else {
                cout << setprecision(22) << min2;
            }

        }
    }
    else if (k < 0) {

        if (x <= k && y <= k) {
            r = sqrt(a * a + b * b);
            cout << setprecision(22) << r;
        }
        else if (x >= k && y <= k) {
            r = sqrtl(a * a + c * c);
            cout << setprecision(22) << r;
        }
        else if (y >= 0 && x >= 0) {
            r = sqrt(c * c + d * d);
            cout << setprecision(22) << r;
        }
        else if (x <= k && y >= 0) {
            r = sqrt(d * d + a * a);
            cout << setprecision(22) << r;
        }
        else if (x >= 0 && y <= k) {
            r = sqrt(c * c + b * b);
            cout << setprecision(22) << r;
        }
        else if (x <= 0 && x >= k && y <= k) {
            cout << setprecision(22) << b;
        }
        else if (y >= k && y <= 0 && x >= 0) {
            cout << setprecision(22) << c;
        }
        else if (x <= 0 && x >= k && y >= 0) {
            cout << setprecision(22) << d;
        }
        else if (x <= k && y <= 0 && y >= k) {
            cout << setprecision(22) << a;
        }
        else if (x<0 && y<0 && x>k && y>k) { //vnutri

            if (a > b) {
                min1 = b;
            }
            else { min1 = a; }

            if (x > y) {
                min2 = y;
            }
            else {
                min2 = x;
            }

            if (min2 > min1) {
                cout << setprecision(22) << min1;
            }
            else {
                cout << setprecision(22) << min2;
            }
        }
    }

        return 0;
    }