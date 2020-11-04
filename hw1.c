#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
    return -1;
}

int inverse(int a, int m) {
    int a_ = a % m;
    for (int i = 1; i < m; i++) {
        if ((a_ * i) % m == 1) {
            return i;
        }
    }
    return -1;
}

long int power(long int x, long int n, int p)
{
    int m = 0;

    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        m = power(x, n / 2, p) % p;
        return (m * m);
    }
    else {
        return x * power(x, n - 1, p) % p;
    }
}

int prime_check(int p) {
    long int a = rand() % p;
    long int n = ((p - 1) / 2);
    long int a_ = power(a, n, p);

    if ((gcd(a/1, p) > 1) || ((a_ != 1) && (a_ != -1))) {
        return 0;
    }
    else {
        return 1;
    }
}

int main() {
    // Greatest Common Devisor
    printf("gcd for %d, %d: %d \n", 60, 24, gcd(60, 24));
    printf("gcd for %d, %d: %d \n", 6, 9, gcd(6, 9));
    printf("gcd for %d, %d: %d \n", 50, 125, gcd(50, 125));

    // Inverse Element
    printf("inverse element for a = %d and b = %d: %d \n", 5, 7, inverse(5, 7));
    printf("inverse element for a = %d and b = %d: %d \n", 3, 26, inverse(3, 26));
    printf("inverse element for a = %d and b = %d: %d \n", 25, 7, inverse(25, 7));

    // Prime
    int v[] = {103, 523, 137, 691};

    printf("p = %d: %s \n", v[0], prime_check(v[0]) == 1 ? "prime" : "composite");
    printf("p = %d: %s \n", v[1], prime_check(v[1]) == 1 ? "prime" : "composite");
    printf("p = %d: %s \n", v[2], prime_check(v[2]) == 1 ? "prime" : "composite");
    printf("p = %d: %s \n", v[3], prime_check(v[3]) == 1 ? "prime" : "composite");

    for (int i = 0; i < 4; i++) {
        int temp = 0;
        for (int j =0; j < 1000; j++) {
            if (prime_check(v[i]) == 1) {
                temp++;
            }
        }
        printf("wrong prime accuracy %d: %f \n", v[i], (1000 - temp) / 1000.0);
    }

    // RSA
    double p = 3, q = 7;
    double n = p * q;

    return -1;
}