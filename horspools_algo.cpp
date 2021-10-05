#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
int st[27];
void shift_table(char *p)
{
    for (int i = 0; i < 27; i++)
    {
        st[i] = strlen(p);
    }
    for (int j = 0; j < strlen(p) - 1; j++)
    {
        st[p[j]] = strlen(p) - 1 - j;
    }
}
int horspool(char *s, char *p)
{
    int n = strlen(s);
    int m = strlen(p);
    //arr
    shift_table(p);
    int i = m - 1;
    while (i <= n - 1)
    {
        int k = 0;
        while (k <= m - 1 && (p[m - 1 - k] == s[i - k]))
        {
            k++;
        }
        if (k == m)
        {
            return i - m + 1;
        }
        else
        {
            i += st[s[i]];
        }
    }

    return -1;
}
int main()
{
    char s[] = "HELLO WORLD";

    cout << "enter the string " << endl;
    cout << s << endl;
    char p[] = "WORLD";
    cout << "enter the pattern" << endl;
    cout << p << endl;
    cout << "pattern is found at" << endl;
    clock_t start, end;
    start = clock();
    cout << horspool(s, p);
    end = clock();
    cout << endl;
    cout << "time required for execution : " << (float)(end - start) / CLOCKS_PER_SEC;

    return 0;
}