#include "pizzaselector.h"

int main(){
    std::cout << "Hello, it's pizza time!" << std::endl; 
    PizzaSelector pizza_selector;
    std::string selected_pizza = pizza_selector.select_pizza();
    if(selected_pizza == "You have eaten all the pizzas"){
        std::cout << selected_pizza << std::endl; 
    }
    else{
        std::cout << "Your pizza for today: "<< selected_pizza << std::endl;
    }
    return 0;
}