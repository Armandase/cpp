#include "easyfind.tpp"
#include <vector>
#include <list>
#include <deque>

int    main(void)
{
    {
        std::vector<int> container;

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
    }
    return (0);
}
