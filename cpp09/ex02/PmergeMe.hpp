#ifndef PMEGEME_HPP
#define PMEGEME_HPP

#include <list>
#include <vector>

class PmergeMe
{
	 public:
		PmergeMe();
		~PmergeMe();
		PmergeMe (const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe&);
		PmergeMe(char **input);

		class WrongInput : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("The string given as parameter can't be use to a rpn");
			}
		};
	 private:
		void	printInput(char **input);
		std::list<int>	_list;
		std::vector<int>_vec;
};

#endif
