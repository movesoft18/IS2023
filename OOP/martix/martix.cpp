
#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
    int m[3][3]{
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
public:
    int& operator () (int row, int col)
    {
        assert(row >= 0 && row <= 2);
        assert(col >= 0 && col <= 2);
        return m[row][col];
    }

    void operator()()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                m[i][j] = 0;
    }
};

int main()
{
    Matrix m;
    cout << m(2, 2) << endl;
    m();
    cout << m(2, 2) << endl;
}

