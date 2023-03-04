#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	 public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat &cat);
		Cat(std::string idea);

		void		makeSound(void) const;
		void		setIdea(std::string idea);
		void		getIdeas();
	 private:
		Brain	*_ideas;
		std::string	_type;
};

#endif
