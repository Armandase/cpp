#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &copy){
	this->_list = copy._list;
	this->_vec = copy._vec;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &copy){
	if (this == &copy)
		return (*this);
	this->_list = copy._list;
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
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

std::list<int> mergeListSort(std::list<int>	list){
	if (list.size() == 1)
		return (list);
	std::list<int>	a;
	std::list<int>	b;
}

PmergeMe::PmergeMe(char **input){
	long	nb;
	char	*cmp;


	for (int i = 0; input[i]; i++){
		nb = std::strtol(input[i], &cmp, 10);
		if (cmp == input[i] || nb < 0 || nb > 2147483647){
			throw PmergeMe::WrongInput();
		}
		_list.push_back(static_cast<int>(nb));
		_vec.push_back(static_cast<int>(nb));
	}
	std::cout << std::endl;
	clock_t begin = clock();
	mergeListSort(_list);
	_list.sort();
	clock_t end = clock();
	double timeList = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
	begin = clock();
	std::sort(_vec.begin(), _vec.end());
	end = clock();
	double timeVec = static_cast<double>(end - begin) / CLOCKS_PER_SEC;
	printInput(input);
	std::cout << "Time to process a range of " << _list.size() << " elements with std::list : " << timeList << " us" << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vect : " << timeVec << " us" << std::endl;

}
