/*H***********************************************************
* FILENAME :  main.cpp        REF : BTF3231
*
* PROJECT :
*  World of the fittest
*
* COMPANY :
*   Bern University of Applied Sciences
*
* DESCRIPTION :
*   The mini-project is about a simulator of the interaction between predators and pray written in C++.
*   The life forms interact with each otheron a simulation cycle basis.The simulator shows what happens
*   when one life form dominates the others. Beside of the core business logic – the simulator,
*   there is a builder which holds all together and a visualization of the world of living thing.
*
* DATE:
*    06.2018
*
* NOTES :
*
*   Copyright Valerio MOLLET, Tobias HUSY 2018.  All rights reserved.
*
* AUTHOR:
*    Valerio MOLLET <valerio.mollet@students.bfh.ch>
*    Tobias HUSY <tobias.husy@students.bfh.ch>
*
*H*/
#include <iostream>
#include "simulation.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int main()
{
    unsigned cycles;
    cout<<"Enter the number of cycles: ";
    cin>>cycles;
    Simulation Test;

    for (unsigned i = 1; i <= cycles; i++){
        Test.oneCycle();
        system("clear");
        Test.display();
        cout<<"      Cycle: "<<i<<endl;
        Sleep(1000);
    }
    cout<<"END OF PROGRAMM";
}
