//#include <iostream>

class Weapon{

	public:
		Weapon();
		Weapon(const Weapon	&copy);
		~Weapon();
		const std::string&	getType();
		void			setType(std::strign value);
	private:
		std::string	type;
};
