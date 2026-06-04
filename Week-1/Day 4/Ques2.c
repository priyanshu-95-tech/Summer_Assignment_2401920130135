int climbStairs(int n) {
    if (n<=2) {
        return n;
    }
    int prev_two = 1;
    int prev_one =2;
    int current = 0;
    for (int i =3; i<=n;i++) {
        current=prev_one + prev_two;
        prev_two= prev_one;
        prev_one=current;
    }
    return prev_one;
}