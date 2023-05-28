#include <iostream>
#include <cmath>
int main() {
    long long  n, count = 1;
    std::cin >> n;
    while (count * count < n) {
        count++;
    }
    count--;
    long long angularnumber = count * count + count + 1; //координаты углового числа

    if (n > angularnumber) { //наше левее углового
        std::cout << count << " " << count - (n - angularnumber);
    }
    else { //наше выше углового
        std::cout << count - (angularnumber - n) << " " << count;
    }

    /*long long int n, count = 0;
    std::cin >> n;
    count=(sqrtl(n));
    if(count*count==n){
      std::cout<<count<<" "<<1;
      return 0;
    }
    if(count*count+count+1<n){
       long long int i=count;
       count=count-(n-(count*count+count+1));
       std::cout<<i<<" "<<count;
       return 0;
    } else {
      std::cout<<n-(count*count+1)<<" "<<count;
          return 0;
    }
    /*int sidesize = count;
    int max = count * count;
    int ** ppa = new int *[sidesize];
    for (int i = 0; i < sidesize; i++) {
        ppa[i] = new int [sidesize];
    }
    do {                                  // заполнение массива
        for (int j = 0; j < count- 1; j++) {
            ppa[count - 1][j] = max;
            max--;
        }
        for (int i = count - 1; i >= 0; i--) {
            ppa[i][count - 1] = max;
            max--;
        }
        count--;
    } while (max != 0);

    for (int i = 0; i < sidesize; i++) {
        for (int j = 0; j < sidesize; j++) {
            if (ppa[i][j] == n) {
                std::cout << i << " " << j;
            }
        }
    }
    for (int i = 0; i < sidesize; i++) {
        delete ppa[i];
    }
    delete[] ppa;*/
    return 0;
}