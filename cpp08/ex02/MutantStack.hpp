#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <stack>

template <typename T, class container=std::deque<T> >

class MutantStack : public std::stack<T>
{
	 public:
		MutantStack();
		~MutantStack();
		MutantStack (const MutantStack &copy);
		MutantStack &operator=(const MutantStack&);
		typedef typename container::iterator iterator;
		iterator	end();
		iterator	begin();
	 protected:
		using std::stack<T>::c;
};

#endif
