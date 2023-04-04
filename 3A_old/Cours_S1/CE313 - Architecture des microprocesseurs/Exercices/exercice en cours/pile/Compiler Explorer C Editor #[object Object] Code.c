int square(int num){
    return num * num;
}

int sum(int a, int b){
    return a+ 2*b;
}

int toto(int a, int b){
    return sum(b, square(a));
}