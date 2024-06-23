#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
#include "Circle.h"

kinematics::Circle1::Circle1() : m_isInitialized(false) {}
kinematics::Circle1::~Circle1() {}

void kinematics::Circle1::run()
{
    //[0] Taking user inputs
    userInputs();

    //[1] Inform users about the inputs
    printInputs();

    //[2] Initialization and sanity checks
    initialize();

    //[3] Compute the results and output to file
    compute();
}

void kinematics::Circle1::userInputs()
{
    std::cout << "# Provide simulation inputs:\n";

    std::string binBuffer;
    // Circle related inputs
    std::cout << "## Radius as R(m), Centre of Circle as Xc(m), Yc(m):\n";
    std::cin >> m_r >> m_xc >> m_yc;
    std::getline(std::cin, binBuffer);

    // Circular motion parameters
    std::cout << "## Angular velocity as W(rad/s):\n";
    std::cin >> m_w;
    std::getline(std::cin, binBuffer);
    std::cout << "## Start time as T0(s), End time as Tf(s) and Time step as dt(s):\n";
    std::cin >> m_t0 >> m_tf >> m_dt;
    std::getline(std::cin, binBuffer);
}

void kinematics::Circle1::printInputs()
{
    std::cout << "\n# Your simulation inputs are:\n";
    std::cout << "R(m): " << m_r << '\n';
    std::cout << "Xc(m), Yc(m): (" << m_xc << ", " << m_yc << ")\n";
    std::cout << "W(rad/s): " << m_w << '\n';
    std::cout << "T0(s): " << m_t0 << ", Tf(s): " << m_tf << ", dt(s): " << m_dt << '\n';
    assert(m_r > 0);
    assert(m_w > 0);
    assert(m_t0 >= 0);
    assert(m_tf > 0);
    assert(m_dt > 0);
}

void kinematics::Circle1::initialize()
{
    m_isInitialized = true;
}

void kinematics::Circle1::compute()
{
    assert(m_isInitialized);

    m_acc = pow(m_w, 2) * m_r;
    std::cout << "\n# Outputs:\n";
    std::cout << "## Centripetal acceleration (rad/s^2): " << m_acc << '\n';
}
