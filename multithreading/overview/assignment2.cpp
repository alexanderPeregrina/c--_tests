/*
The attached program finds the number of elements in a vector which are divisible by 2. 

Your assignment is to modify this code so that it will find the number of elements divisible by a number entered by the user.

For example, if the user enters 3 when prompted, the program will display the number of elements which are divisible by 3.
*/
// Algorithm call with predicate
// Using lambda expression
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> vec{4, 2, 3, 5, 1};
	
	std::cout << "Elements of vector: ";
	
	for (auto i : vec)
		std::cout << i << ", ";
	std::cout << '\n';
	
    int num;
    std::cout<< "Introduce the divisor number: ";
    std::cin >> num;

	// Call std::count_if() algorithm using a lambda expression as predicate
	auto count = std::count_if(vec.begin(), vec.end(), 
	
		// The lambda definition goes inside the call!
		[&num] (int n)
		{ 
			return (n % num == 0);
		}
	);

	std::cout << "The vector has " << count << " element(s) divisible by " << num << "\n";
}