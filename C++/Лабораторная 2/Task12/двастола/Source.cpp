#include <iostream>
using namespace std;
int main() {
    long double x1, y1, x2, y2, w, h, W, H;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    long double w1 = fabs(x1 - x2);
    long double h1 = fabs(y1 - y2);
    long double minh, minw, maxh, maxw;

    minh = (y1 <= (H - y2)) ? y1 : (H - y2);
    minw = (x1 <= (W - x2)) ? x1 : (W - x2);
    maxh = (y1 >= (H - y2)) ? y1 : (H - y2);
    maxw = (x1 >= (W - x2)) ? x1 : (W - x2);

    if (h1 + h > H && w1 + w > W) {
        cout << "-1";
    }
    else if (h1 + h <= H && w1 + w <= W) {
        if (h <= maxh || w <= maxw) {
            cout << "0";
        }
        else {
            if ((h - maxh) <= (w - maxw)) {
                cout << h - maxh;
            }
            else {
                cout << w - maxw;
            }
        }
    }
    else if (w1 + w > W) {
        if (h <= maxh) {
            cout << "0";
        }
        else {
            cout << h - maxh;
        }
    }
    else if (h1 + h > H) {
        if (w <= maxw) {
            cout << "0";
        }
        else {
            cout << w - maxw;
        }
    }
	return 0;
}