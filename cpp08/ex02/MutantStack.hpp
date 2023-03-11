#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>
#include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	 public:
		MutantStack();
		~MutantStack();
		MutantStack (const MutantStack &copy);
		MutantStack &operator=(const MutantStack&);
		class iterator
		{
			 public:
				iterator();
				~iterator();
				iterator (const iterator &copy);
				iterator &operator=(const iterator&);
			 private:
				int	_index;
				
		};


		//A deplacer dans iterator.cpp
		iterator::iterator(){
		}

		iterator::~iterator(){
		}

		iterator::iterator(const iterator &copy){
		}

		iterator & iterator::operator=(const iterator &copy){
		}

		
	 private:
		
};

#endif
