#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string stringsum(string a, string b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }

    int j = a.size() - 1;
    for (int i = b.size() - 1; i >= 0; i--, j--)
        a[j] += (b[i] - '0');

    for (int i = a.size() - 1; i > 0; i--)
    {
        if (a[i] > '9')
        {
            int d = a[i] - '0';
            a[i - 1] = ((a[i - 1] - '0') + d / 10) + '0';
            a[i] = (d % 10) + '0';
        }
    }
    if (a[0] > '9')
    {
        string ost;
        ost += a[0];
        a[0] = ((a[0] - '0') % 10) + '0';
        ost[0] = ((ost[0] - '0') / 10) + '0';
        a = ost + a;
    }
    return a;
}

string multiply(string a, string b) {
    int n = a.size();
    int m = b.size();
    string ans(n + m, '0');
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int p = (a[i] - '0') * (b[j] - '0') + (ans[i + j + 1] - '0');
            ans[i + j + 1] = p % 10 + '0';
            ans[i + j] += p / 10;
        }
    }
    for (int i = 0; i < m + n; i++) {
        if (ans[i] != '0')
        {
            return ans.substr(i);
        }
    }
}

string str_reverse(string a)
{
    string b;
    for (int i = a.length() - 1; i >= 0; i--)
        b += a[i];
    return  b;
}

string stringminus(string a, string b)
{
    int length = max(a.length(), b.length());
    a = str_reverse(a);
    b = str_reverse(b);
    if (a.length() != b.length())
        ((a.length() > b.length()) ? (b) : (a)).resize(length, '0');
    string c;
    c.resize(length);

    for (int i = 0; i < length; i++)
        c[i] = a[i] + '0' - b[i];

    for (int i = 0; i < length; i++)
        if (c[i] < '0')
        {
            c[i] += 10;
            c[i + 1]--;
        }
    return str_reverse(c);
}

string stringdivine2(string a) {
    string result(a.size(), 0);
    int n;

    for (int i = a.size() - 1; i >= 0; i--) {
        n = (a[i] - '0') * 5 + result[i + 1];
        result[i + 1] = n % 10;
        result[i] += n / 10;
    }

    for (int i = 0; i < result.size(); i++) {
        result[i] += '0';
    }
    if (result[0] == '0') {
        return result.substr(1);
    }

    return result;
}

int main() { //помогите,я хочу спать
    string a;
    getline(cin, a);
    int size = a.size();
    int* s = new int[size];
    for (int i = 0; i < 1; i++) {
        s[i] = (a[i] - '0');

        if (s[i] == 0 && size == 1) {
            cout << 1;
            return 0;
        }
        else if (s[i] == 1 && size == 1) {
            cout << 1;
            return 0;
        }

        string c;
        c = stringminus(a, "1");
        c = multiply(c, a);
        c = stringdivine2(c);
        c = stringsum(c, "1");
        cout << c;
    }
    delete[] s;
    return 0;
}