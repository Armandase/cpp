#ifndef PMEGEME_HPP
#define PMEGEME_HPP

#include <deque>
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
				return ("wrong parameters");
			}
		};
	 private:
		void	printInput(char **input);
		std::deque<int>	_deque;
		std::vector<int>_vec;
};

#endif
