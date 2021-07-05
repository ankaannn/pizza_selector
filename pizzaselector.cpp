#include "pizzaselector.h"
#include <fstream> 
#include <cstdlib>
#include <time.h>

PizzaSelector::PizzaSelector(){
    list_of_pizza = this->read_pizza_file("list_of_pizza.txt");
}

std::vector<std::string> PizzaSelector::read_pizza_file(std::string pizza_file){
    std::ifstream myfile(pizza_file);
    if(!myfile.good()){
        std::cout << "can not open file" << std::endl; 
    }
    std::vector<std::string> list_of_pizza;
    std::string temp_string; 
    while(getline(myfile, temp_string).good() != false){
        list_of_pizza.push_back(temp_string);
    }
    return list_of_pizza; 
}

std::string PizzaSelector::select_pizza(){
    srand (time(NULL));
    std::string random_pizza = list_of_pizza[rand() % list_of_pizza.size()];

    return random_pizza; 
}