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
    std::vector<std::string> list_of_pizza = read_pizza_file("list_of_pizza.txt");
    std::vector<std::string> eaten_pizzas = read_pizza_file("list_of_eaten_pizzas.txt");
    if(list_of_pizza.size() == eaten_pizzas.size()){
        return "You have eaten all the pizzas";
    }
    srand (time(NULL)); 
    while(true){    
        std::string random_pizza = list_of_pizza[rand() % list_of_pizza.size()];
        bool pizza_found = false;
        for(int i = 0; i < eaten_pizzas.size(); i++){
            if(random_pizza == eaten_pizzas[i]){
                pizza_found = true; 
                break;
            }
        }
        if(!pizza_found){
            write_pizza_to_file("list_of_eaten_pizzas.txt", random_pizza);
            return random_pizza;
        }
    }
}

bool PizzaSelector::write_pizza_to_file(std::string pizza_file, std::string write_this_pizza){
    std::ofstream myfile(pizza_file, std::ios::app);
    myfile << write_this_pizza << "\n"; 
    myfile.close(); 
    return true; 
}
