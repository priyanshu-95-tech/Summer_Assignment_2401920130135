int romanToInt(char * s) {
    int a = 0;
    while (s[a] != '\0') {
        a++;
    }
    int total = 0;
    int c = 0;
    for (int i = a - 1; i >= 0; i--) {
        int b = 0;
        switch (s[i]) {
            case 'I': b = 1; break;
            case 'V': b = 5; break;
            case 'X': b = 10; break;
            case 'L': b = 50; break;
            case 'C': b = 100; break;
            case 'D': b = 500; break;
            case 'M': b = 1000; break;
        }
        if (b < c) {
            total -= b;
        } else {
            total += b;
            c = b;
        }
    }
    return total;
}