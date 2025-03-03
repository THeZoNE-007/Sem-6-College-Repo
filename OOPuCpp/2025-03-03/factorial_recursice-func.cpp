#include<iostream>
using namespace std;

int fact(int n) //function header
{
	if(n==0 | n==1)
	{
		return 1; //base case
	}
	else
		return n*fact(n-1); //recursive case
}

int main()
{
	int a = 3;
	int k = fact(a);
	cout << "Factorial = " << k << endl;
	return 0;
}
