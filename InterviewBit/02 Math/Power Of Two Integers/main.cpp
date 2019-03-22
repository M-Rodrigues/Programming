int Solution::isPower(int A) {
    if (A == 1) return true;
    for (int b = 2; b*b <= A; b++) {
        for (int p = 2; pow(b,p) <= A; p++) {
            if (pow(b,p) == A) return true;
        }
    }
    return false;
}
