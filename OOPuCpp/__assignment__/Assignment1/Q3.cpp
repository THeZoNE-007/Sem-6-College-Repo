#include <iostream>

using namespace std;

int *createArray(int M)
{
    int *arr = new int[M];
    return arr;
}

int main()
{
    int user_size;
    cout << "Enter the size of the array: ";
    cin >> user_size;

    int *myArr = createArray(user_size);

    for (int i = 0; i < user_size; ++i)
    {
        myArr[i] = i;
        cout << myArr[i] << " ";
    }

    delete[] myArr;

    return 0;
}
