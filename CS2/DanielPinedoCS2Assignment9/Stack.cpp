/*
Author: Daniel Pinedo
Templated Growing Stack
*/
#include <iostream>
using namespace std;

template<typename T>
void Stack<typename T>::push(T item)
{
	if (arrayCapacity > this->numItems)
	{
		cout << "**********>  Using the existing array to push. <******************* \n";
		top_position++;
		items[top_position] = item;
		numItems++;
		cout << "Number of items in stack now: " << numItems << endl;
	}
	else
	{
		cout << "**********> Expanding the array to push. <*******************\n";
		
		size_t len = arrayCapacity + GROWBY;
		T * Temp;

		Temp = new T[len];

		for (size_t index = 0; index<this->numItems; index++)
		{
			Temp[index] = items[index];
		}

		delete[] items;
		items = Temp;
		Temp = nullptr;
		arrayCapacity = len;
		top_position++;
		items[top_position] = item;
		numItems++;
		cout << "Number of items in stack now: " << numItems << endl;
	}
}

template<typename T>
void Stack<typename T>::pop()
{
	if (isEmpty())
	{
		cerr << "The stack is empty.\n";
		return;
	}
	else
	{
		top_position--;
		numItems--;
	}
}
template<typename T>
T Stack<typename T>::top() const
{
	if (isEmpty())
	{
		throw "Stack is empty";
	}
	else
	{
		return items[top_position];
	}
}
template<typename T>
bool Stack<typename T>::isEmpty() const
{
	return (numItems == 0);
}

template<typename T>
Stack<typename T>::Stack() : top_position(-1), items(new T[MAX]),
numItems(0), arrayCapacity(MAX)
{
	cout << "From Stack Constructor. \n";
}

template<typename T>
Stack<typename T>::~Stack()
{
	delete[] items;
	cout << "From Stack Destructor.\n";
}
template<typename T>
Stack<typename T>::Stack(const Stack & st)
{
	if (this == &st) {
		cout << "Self copy is prohibited. Exiting." << endl;
		exit(1);
	}
	this->top_position = st.top_position;
	this->items = new T[st.arrayCapacity];
	for (size_t i = 0; i < st.arrayCapacity; i++)
	{
		this->items[i] = st.items[i];
	}
	this->numItems = st.numItems;
	this->arrayCapacity = st.arrayCapacity;
	
	cout << "From Stack Copy Constructor.\n";
}

/*
Assignment operator is a part of rule of three implementation.
Default assignment operator provided by C++ only makes shallow copies. To make deep
copies of data pointed to by a pointer and allocated dynamically at runtime
a programmer defined assignment operator that would do that is needed.
Assignment operator is used when one object is copied into another using the
= operator. This must also work if = is used in a cascaded manner.
For example it must work if one does the following:
Stack X, Y, Z, T;
X= Y = Z = T;
The assignment operator MUST work correctly even when user attempts a self-copy. Example of
Self-copy is below.
Stack ST;
ST = ST;
For me to ascertain that your code follows rule of three and has no memory leak, please place
The code line below before the return statement in the assignment operator.
cout << "From Stack Assignment operator.\n";
@param Stk is the stack object on right side of assignment operator
@return the value to be copied in the left side of assignment operator.
*/

template<typename T>
const Stack<T> & Stack<typename T>::operator = (const Stack & Stk)
{
	if (this != &Stk)
	{
		delete[] items;
		this->top_position = Stk.top_position;
		this->items = new T[Stk.arrayCapacity];
		for (size_t i = 0; i < Stk.arrayCapacity; i++)
		{
			this->items[i] = Stk.items[i];
		}
		this->numItems = Stk.numItems;
		this->arrayCapacity = Stk.arrayCapacity;
	}

	return *this;
	cout << "From Stack Assignment operator.\n";
}
/*
Function getArrayCapacity returns the capacity of the array used for stack when call to
this function is made.
@return the capacity of array used to hold stack elements.
*/
template<typename T>
size_t Stack<typename T>::getArrayCapacity() const
{
	return arrayCapacity;
}
/*
Function getNumItems returns the number of items in the stack at the time when this function
is called.
@return the number of elements stored in the stack.
*/
template<typename T>
size_t Stack<typename T>::getNumItems() const
{
	return numItems;
}
//protected:
	/*
	copy function is optional. However it condenses the copy code that would be used in both
	the copy constructor and in the assignment operator. Use of this function advances
	the code re-use technology.
	@param Stk is the stack object to be copied to this Stack object.
	*/
	//void Stack::copy(const Stack & Stk);
// private:
	/*
	Function isFull is not needed in the dynamically growing stack. However,
	we must give it a body because it was a pure virtual function in StackInterface
	class and since Stack class derives from StackInterface class, it must be
	implemented to allow to create objects of type Stack. [Recall that if a base class
	pure virtual function is not implemented by the derived class, then derived class
	will also become abstract, and cannot be instantiated]. You can just have the
	function return false as the dynamically growing stack will never be full.
	@return false because dynamically growing stack always has capacity to add more elements.
	*/
template<typename T>
bool Stack<typename T>::isFull() const
{
	return (numItems == arrayCapacity);
}
