#include <iostream> 
#include <vector> 
#include <string> 

class PizzaSelector{
private: 
    std::vector<std::string> list_of_pizza;
public: 
    PizzaSelector();
    std::vector<std::string> read_pizza_file(std::string pizza_file);
    std::string select_pizza (); 
};