#include <iostream>
#include "Kinematics.h"

using namespace kinematics;

void Kinematics::run()
{
    try
    {
        //[0] Taking user inputs
        this->userInputs();

        //[1] Inform users about the inputs
        this->printInputs();

        //[2] Initialization and sanity checks
        this->initialize();

        //[3] Compute the results and output to file
        this->compute();
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << "Error while opening the file: " << e.what() << '\n';
        exit(-4);
    }
    catch (std::ios_base::failure &e)
    {
        std::cerr << "Error in writing to the file: " << e.what() << '\n';
        exit(-3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
        exit(-2);
    }
    catch (...)
    {
        std::cerr << "Unknown exception!\n";
        exit(-1);
    }
}
