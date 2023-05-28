#include <iostream>
#include <algorithm>
#include "vector.h"
using namespace std;
int main()
{
   Vector <double> a;
   Vector <double> b;

   int num = 0;
   for(int i =0;i<13;i++)
       a.push_back(rand()%23);
       //cin >> num;
//       while (num != -1)
//       {
//           a.push_back(num);
//           num=-1;
//           //cin >> num;
//       }

       int amount = a.size() / 3;
       for (int i = 0; i < amount * 3; i += 3)
       {
           a.sort(i,i+3);
           b.push_back(a.at(i + 1));
       }
       if (a.size() - amount * 3 == 2)
       {
           int tmp = a.at(a.size() - 1) + a.at(a.size() - 2);
           b.push_back(tmp/2);
       }
       if (a.size() - amount * 3 == 1)
       {
           int tmp = a.at(a.size() - 1);
           b.push_back(tmp);
       }
       for (int i = 0; i < a.size(); i++)
           cout << a[i]<<" ";
       cout << endl;
       for (int i = 0; i < b.size(); i++)
           cout<< b[i] << " ";
   return 0;
}
