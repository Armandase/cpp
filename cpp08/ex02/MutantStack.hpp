#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <stack>

template <typename T>

class MutantStack : private std::stack<T>
{
	 public:
		MutantStack();
		~MutantStack();
		MutantStack (const MutantStack &copy);
		MutantStack &operator=(const MutantStack&);
	 private:
		
};

#endif
