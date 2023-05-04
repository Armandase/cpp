#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	 public:
		RPN();
		RPN(char *input);
		~RPN();
		RPN (const RPN &copy);
		RPN &operator=(const RPN&);

		void	printResult();
		void	applyCalcul(std::string digit);
	 private:
		std::stack<int> _calcul;
		int				_result;
		std::string			_input;
};

#endif
