#include "gradiente_coniugato.hpp"
#include <iostream>

using namespace std;

int main(){

    for(int dim = 1; dim < 50; dim++){
        if(GradConiugato(dim) != 0){
            return EXIT_FAILURE;
            }
    }
    return EXIT_SUCCESS;
}