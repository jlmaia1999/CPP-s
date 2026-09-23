#include "MutantStack.hpp"
#include <iostream>

int main()
{
	// Test 1: Create a MutantStack with integers
	std::cout << "========== Test 1: Create MutantStack<int> ==========" << std::endl;
	MutantStack<int> mstack;
	
	// Test 2: Push elements
	std::cout << "\nPushing elements: 5, 17, 3, 5, 273, 15, 9, 4" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(273);
	mstack.push(15);
	mstack.push(9);
	mstack.push(4);
	
	std::cout << "\nIterating forward (begin to end):" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "\nIterating reverse (rbegin to rend):" << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	

	std::cout << "\nStack size before popping: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Stack size after first pop: " << mstack.size() << std::endl;
	std::cout << "Top element after pop: " << mstack.top() << std::endl;

	std::cout << "\n========== Test 2: Copy Constructor ==========" << std::endl;
	MutantStack<int> mstack_copy(mstack);
	std::cout << "Copied stack (forward iteration):" << std::endl;
	for (MutantStack<int>::iterator it = mstack_copy.begin(); it != mstack_copy.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	

	std::cout << "\n========== Test 3: Assignment Operator ==========" << std::endl;
	MutantStack<int> mstack_assigned;
	mstack_assigned.push(100);
	mstack_assigned.push(200);
	std::cout << "Before assignment: " << mstack_assigned.top() << std::endl;
	mstack_assigned = mstack;
	std::cout << "After assignment: " << mstack_assigned.top() << std::endl;
	std::cout << "Assigned stack (forward iteration):" << std::endl;
	for (MutantStack<int>::iterator it = mstack_assigned.begin(); it != mstack_assigned.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	

	std::cout << "\n========== Test 4: MutantStack<double> ==========" << std::endl;
	MutantStack<double> mstack_double;
	mstack_double.push(3.14);
	mstack_double.push(2.71);
	mstack_double.push(1.41);
	
	std::cout << "Double stack (forward iteration):" << std::endl;
	for (MutantStack<double>::iterator it = mstack_double.begin(); it != mstack_double.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "\n========== Test 5: Empty Stack ==========" << std::endl;
	MutantStack<int> empty_stack;
	std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
	std::cout << "Empty stack iteration: ";
	for (MutantStack<int>::iterator it = empty_stack.begin(); it != empty_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << "(nothing)" << std::endl;
	
	return 0;
}
