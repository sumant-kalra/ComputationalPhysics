#include "SimplePendulum.h"

#include <cassert>
#include <cmath>
#include <string>

using namespace kinematics;

SimplePendulum::SimplePendulum() : m_isInitialized(false) {}

void SimplePendulum::userInputs()
{
    std::string binBuffer;
    std::cout << "# Provide simulation inputs for Simple Pendulum:\n";
    std::cout << "## Length of the pendulum (m):\n";
    std::cin >> m_l;
    std::getline(std::cin, binBuffer);
    std::cout << "## Start time as T0(s), End time as Tf(s) and Time step as dt(s):\n";
    std::cin >> m_t0 >> m_tf >> m_dt;
    std::getline(std::cin, binBuffer);
    std::cout << "## Amplitude of the motion (rad) @t0:\n";
    std::cin >> m_theta0;
    std::getline(std::cin, binBuffer);
}

void SimplePendulum::printInputs()
{
    std::cout << "\n# Your simulation inputs are:\n";
    std::cout << "L(m) " << m_l << '\n';
    std::cout << "T0(s): " << m_t0 << ", Tf(s): " << m_tf << ", dt(s): " << m_dt << '\n';
    std::cout << "Theta0(rad): " << m_theta0 << '\n';
    assert(m_l > 0);
    assert(m_t0 >= 0);
    assert(m_tf > 0);
    assert(m_dt > 0);
    assert(m_theta0 >= 0);
}

void SimplePendulum::initialize()
{
    this->m_isInitialized = true;
}

void SimplePendulum::compute()
{
    assert(m_isInitialized);
    std::cout << "W(rad/s): " << m_w << '\n';
}
