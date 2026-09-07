#include <iostream>
#include "simulator.h"


#include <vector>

int main(){

    
    Simulator* s = new Simulator(7l,6,std::vector<int>{20,10});
    
    while (1){
        std::cout << "Menu what you want to do?" << std::endl;
        std::cout << "p = play agents best ai" << std::endl;
        std::cout << "t = train" << std::endl;
        std::cout << "q = quit" << std::endl;
        
        std::string in;
        
        std::cin >> in;
        
        if(in == "q")break;
        
        if(in == "p")s->play_top_ai();
        
        if(in == "t"){
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "How many generations?" << std::endl;
            
            int in_gen;
            
            std::cin >> in_gen;
            
            std::cout << "Visual? 0=false, 1=true" << std::endl;
            
            bool in_visual;
            
            std::cin >> in_visual;

            s->simulate(in_gen,in_visual);

        }

    }

    delete s;
}