#include "easyfind.tpp"
#include <exception>
#include <vector>
#include <list>
#include <deque>

int    main(void)
{
    {
        std::vector<int> container;
		std::vector<int>::iterator it;

        for (int i = 0; i < 10; i++)
            container.push_back(i);
		try{
        	it = easyfind(container, 5);
			std::cout << "result: " << *it << std::endl;
        	it = easyfind(container, 15);        
			std::cout << "result: " << *it << std::endl;
		} catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
    }
    {
        std::list<int> container;
        std::list<int>::iterator it;

        for (int i = 100; i < 110; i++)
            container.push_back(i);
		try{
        	it = easyfind(container, 107);
			std::cout << "result: " << *it << std::endl;
        	it = easyfind(container, 15);        
			std::cout << "result: " << *it << std::endl;
		} catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
    }
    return (0);
}
