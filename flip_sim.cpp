// flip_sim.cpp : このファイルには 'main' 関数が含まれています。

#include <iostream>

int calc_bits(int n);
int comb(int n, int k);
void statistics(int n);

int main(int argc, char * argv[])
{
    int n = atoi(argv[1]);

    std::cout << argv[0] << "\n";

    std::cout << "n is " << n << "\n";

    if (n <= 1 || n % 2 == 1)
    {
        std::cout << "Invalid n. n must be over 2 and even.\n";
        return 1;
    }
    std::cout << "result---\n";
    statistics(n);

}

void statistics(int n)
{
    int i;
    for (i = 2; i <= n; i += 2) {
        std::cout << i << " ";
        double nofbits = calc_bits(i);
        std::cout << nofbits << " ";
        int delim = i * std::pow(2, i - 1);
        std::cout << delim<< " ";
        std::cout << nofbits / delim << "\n";
    }
}

int calc_bits(int n) {
    int i;
    int s = 0;
    for (i = 1; i <= n / 2; i++) {
        s += i * comb(n + 1, i);
    }
    return s;
}

int comb(int n, int k) {
    int i;
    int c = 1;
    for (i = 0; i < k; i++) {
        c *= (n - i);
    }
    for (i = 0; i < k; i++) {
        c /= (k - i);
    }
    //std::cout << "comb " << n << " " << k << " " << c << "\n";
    return c;
}