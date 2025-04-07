#include<iostream>
using namespace std;

void exampleFunction()
{
	//Local class inside the function
	class LocalClass
	{
	public:
		void greet()
		{
			cout<<"Hello from LocalClass!" << endl;
		}
	};
	
	//Create object and use it
	LocalClass obj;
	obj.greet();
}

int main()
{
	exampleFunction();
	return 0;
}

/*



*/
