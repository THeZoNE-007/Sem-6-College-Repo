Basic syntax:

class classname{
	data members;
	member functions
};

classname var_name;

----------------------------------------------------------------------

//Class to represent a box

class Box {
	public: //access specifier
		double length;
		double width;
		double height;
		
		//Function to calculate the volume of a box
		double volume() {
			return length * width * height;
		}
};

int main() {
	Box firstBox = {80.0, 50.0, 40.0}
	
	//Calculate the volume of the box
	double firstBoxVolume = firstBox.volume();
	cout << endl;
	cout << "Size of first box object is "
	     << firstBox.height
	     <<endl;
	cout<<"Volume 
