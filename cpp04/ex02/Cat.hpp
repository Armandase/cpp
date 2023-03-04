#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	 public:
		Cat();
		~Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat &cat);
		Cat(std::string idea);

		void		makeSound(void) const;
		void		setIdea(std::string idea);
		void	getIdeas();
	 private:
		Brain	*_ideas;
		std::string	_type;
};

#endif
