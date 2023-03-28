#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <vector>
#include "insertSort.tpp"

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &copy){
	this->_deque = copy._deque;
	this->_vec = copy._vec;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &copy){
	if (this == &copy)
		return (*this);
	this->_deque = copy._deque;
	this->_vec = copy._vec;
	return (*this);
}

void	PmergeMe::printInput(char **input)
{
	std::cout << "Before: ";
	for (int i = 0; input[i]; i++){
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "After: ";
	for (std::deque<int>::iterator it = _deque.begin(); it != _deque.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::vector<int> mergeVecSort(std::vector<int>	vec){
	int	mid = vec.size() / 2;
	std::vector<int> ret;
	std::vector<int> right;
	std::vector<int> left;

	if (mid <= 1)
	{
		std::sort(vec.begin(), vec.end());
		return (vec);
	}
	
	left = mergeVecSort(std::vector<int>(vec.begin(), vec.begin() + mid));
	right = mergeVecSort(std::vector<int>(vec.begin() + mid, vec.begin() + vec.size()));

	//std::sort(left.begin(), left.end());
	//std::sort(right.begin(), right.end());
	insertSort(left, left.size() -1);
	insertSort(right, right.size() -1);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(ret));
	return (ret);
}

std::deque<int> mergeDequeSort(std::deque<int>	deque){
	int	mid = deque.size() / 2;
	std::deque<int> ret;
	std::deque<int> right;
	std::deque<int> left;

	if (mid <= 1)
	{
		std::sort(deque.begin(), deque.end());
		return (deque);
	}
	
	left = mergeDequeSort(std::deque<int>(deque.begin(), deque.begin() + mid));
	right = mergeDequeSort(std::deque<int>(deque.begin() + mid, deque.begin() + deque.size()));

	//std::sort(left.begin(), left.end());
	//std::sort(right.begin(), right.end());
	insertSort(left, left.size() -1);
	insertSort(right, right.size() -1);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(ret));
	return (ret);
}

PmergeMe::PmergeMe(char **input){
	long	nb;
	char	*cmp;


	for (int i = 0; input[i]; i++){
		nb = std::strtol(input[i], &cmp, 10);
		if (cmp == input[i] || nb < 0 || nb > 2147483647){
			throw PmergeMe::WrongInput();
		}
		_vec.push_back(static_cast<int>(nb));
		_deque.push_back(static_cast<int>(nb));
	}
	std::cout << std::endl;
	clock_t begin = clock();
	_vec = mergeVecSort(_vec);
	clock_t end = clock();
	double timeVec = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 1000;
	begin = clock();
	_deque = mergeDequeSort(_deque);
	end = clock();
	double timeDeque = static_cast<double>(end - begin) / CLOCKS_PER_SEC * 1000;
	printInput(input);
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vec : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << timeDeque << " us" << std::endl;
}
