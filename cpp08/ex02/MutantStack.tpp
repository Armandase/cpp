#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T, typename U>
MutantStack<T, U>::MutantStack(){
}

template <typename T, typename U>
MutantStack<T, U>::~MutantStack(){
}

template <typename T, typename U>
MutantStack<T, U>::MutantStack(const MutantStack &copy){
	if (this != copy)
		*this = copy;
}

template <typename T, typename U>
MutantStack<T, U> & MutantStack<T, U>::operator=(const MutantStack &copy){
	*this = copy;
}

template <typename T, typename U>
typename MutantStack<T, U>::iterator MutantStack<T, U>::begin(){
	return(MutantStack->std::stack->begin());
}

template <typename T, typename U>
typename MutantStack<T, U>::iterator MutantStack<T, U>::end(){
	return(MutantStack->std::stack->end());
}

#endif
