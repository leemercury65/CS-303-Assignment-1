#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool getArray(int arr[], int* length) //Gets array from file.
{
	ifstream file("array.txt");

	if (!file.is_open())
	{
		cout << "File is not loaded properly"; //Prints message if file is not opened.
		return false;
	}

	*length = 0;   

	while (file >> arr[*length]) 
	{
		*length = *length + 1;
	}

	file.close();

	return true;
}

void printArray(int arr[], int length) //prints input array from file
{
	cout << endl << "The elements are: ";

	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";

	cout << endl;
}

int findElement(int arr[], int length, int key) // searches element in array
{
	int i;

	for (i = length - 1; i >= 0; i--)
		if (arr[i] == key)
			return i;

	return i;
}

int changeIndex(int arr[], int index) //changes value of index
{
	int key;

	cout << "Enter new value to be changed: ";
	cin >> key;

	arr[index] = key;

	return key;
}

void newElement(int arr[], int* length) //prompts user to input of new element
{
	int element;

	cout << endl << "Enter new element: ";
	cin >> element;

	arr[*length] = element;

	*length = *length + 1;

	cout << "Element Inserted";
}

void removeIndex(int arr[], int* length) //prompt user to input index to be removed
{
	int index;

	cout << endl << "Enter index to be removed: ";
	cin >> index;

	for (int i = index; i < *length - 1; i++)
		arr[i] = arr[i + 1];

	*length = *length - 1;

}

int main()
{
	int arr[50], length, index, key;

	if (!getArray(arr, &length))
		return 0;

	printArray(arr, length);

	cout << "Enter the element to be searched: "; //enables user to enter element to be search
	cin >> key;

	index = findElement(arr, length, key); 

	if (index == -1)
		cout << "Element not found"; //prints if elements is not found

	else

		cout << key << " is present at index " << index;

	cout << endl << endl << "Enter the index to be changed: "; //prompts user to enter index to be changed
	cin >> index;

	key = changeIndex(arr, index);

	cout << arr[index] << " Value changed to " << key; 

	cout << endl << "New Array";
	printArray(arr, length);

	newElement(arr, &length); //adds new element

	cout << endl << "New Array";
	printArray(arr, length);

	removeIndex(arr, &length); //removes new element
	cout << endl << "New Array";
	printArray(arr, length);

	return 0;
}
