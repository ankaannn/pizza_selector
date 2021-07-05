#include "pizzaselector.h"

int main(){
    std::cout << "Hello" << std::endl; 
    PizzaSelector pizza_selector;
    std::string selected_pizza = pizza_selector.select_pizza();
    std::cout << "You are going to eat: "<< selected_pizza << std::endl;
    return 0;
}