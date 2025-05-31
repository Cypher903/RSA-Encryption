int modInverse(int e, int m) {
    int m0 = m, t = 0, x = 1;
    if (m == 1) return 0;

    while (e > 1) {
        int q = e / m;
        int temp = m;

        m = e % m;
        e = temp;

        temp = t;
        t = x - q * t;
        x = temp;
    }

    if (x < 0) x += m0;
    return x;
}
