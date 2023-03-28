#include "easyfind.tpp"
<<<<<<< HEAD
#include <exception>
=======
>>>>>>> 1e5bc1e0a6f7dbe6f19d0e2cf3c48a8804a1cf5a
#include <vector>
#include <list>
#include <deque>

int    main(void)
{
    {
        std::vector<int> container;
<<<<<<< HEAD
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
        std::deque<int> container;
        std::deque<int>::iterator it;

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
=======

        for (int i = 0; i < 10; i++)
            container.push_back(i);
        easyfind(container, 5);        
        easyfind(container, 15);        
    }
    {
        std::deque<int> container;

        for (int i = 0; i < 10; i++)
            container.push_back(i);
        easyfind(container, 5);        
        easyfind(container, 15);        
    }
    {
        std::list<int> container;

        for (int i = 0; i < 10; i++)
            container.push_back(i);
        easyfind(container, 5);        
        easyfind(container, 15);        
>>>>>>> 1e5bc1e0a6f7dbe6f19d0e2cf3c48a8804a1cf5a
    }
    return (0);
}
