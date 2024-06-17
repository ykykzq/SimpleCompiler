int n;

int getint();
void putint(int k);

int main()
{
    int a, b;

    a = getint();
    b = getint();

    int c;
    c = getint();

    if(!((a < b) && (a > c))) {
        putint(2);
    } else {
        putint(1);
    }

    if((a > 5) && ((c < 10) && (c > 0))) {
        putint(3);
    } else {
        putint(4);
    }

    return 0;
}