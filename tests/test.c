
int n;

void putint(int k);
int getint();

int test(int a)
{
    n = n + 1;
    return a + 1;
}

int main()
{
    int a;
    int b[4];

    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;

    n = 2;

    a = getint();

    // notice right-> left
    b[n] = test(a);

    putint(b[2]);
    putint(b[3]);

    return 0;
}
