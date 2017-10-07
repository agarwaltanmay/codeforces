#include <iostream>

using namespace std;

bool checkValid(int dig, int s) {
    if (s < 0)
        return false;
    else if (dig != 0)
        return ((double)s / dig <= 9.0);
    else if (s == 0)
        return true;

    return false;
}

void findSmall(int m, int s) {
    if ((s == 0 && m != 1) || (double)s / m > 9.0) {
        cout << "-1";
        return;
    }

    int no[100] = { 0 };
    int dig = m;
    int ind = 0;

    for (int i = 1; i <= 9; i++)
    {
        if (checkValid(m - 1, s - i))
        {
            no[ind++] = i;
            m -= 1;
            s -= i;
            break;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= 9; j++){
            if (checkValid(m - i, s - j))
            {
                no[ind++] = j;
                // m -= 1;
                s -= j;
                break;
            }
        }
    }

    for (int i = 1; i <= dig; i++)
        cout << no[i - 1];

}

void findLarge(int m, int s) {
    if ((s == 0 && m != 1) || (double)s / m > 9.0) {
        cout << " -1";
        return;
    }

    int no1[100] = { 0 };
    int dig = m;
    int ind = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (checkValid(m - 1, s - i))
        {
            no1[ind++] = i;
            m -= 1;
            s -= i;
            break;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 9; j >= 0; j--){
            if (checkValid(m - i, s - j))
            {
                no1[ind++] = j;
                // m -= 1;
                s -= j;
                break;
            }
        }
    }

    cout << " ";
    for (int i = 1; i <= dig; i++)
        cout << no1[i - 1];
}

int main() {
    int m, s;
    cin >> m >> s;

    findSmall(m, s);
    findLarge(m, s);


    return 0;

}