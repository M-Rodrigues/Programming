int toInt(string A) {
    if (A == "") return 0;
    return toInt(A.substr(0,A.size()-1))*26 + (A[0]-'A'+1);
}

int Solution::titleToNumber(string A) {
    return toInt(A);
}