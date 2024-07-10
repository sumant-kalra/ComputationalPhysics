#include "SimplePendulum.h"

#include <cassert>
#include <cmath>
#include <string>
#include <fstream>

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

    std::ofstream outFile("SimplePendulum.out");
    if (!outFile.is_open())
        throw std::invalid_argument("Failed to open the file - SimplePendulum.out");

    outFile.exceptions(std::ios_base::failbit | std::ios_base::badbit);

    m_w = sqrt(g / m_l);
    std::cout << "W(Hz): " << m_w << '\n';
    double theta, thetaD, thetaDD;
    double x, y, vx, vy, ax, ay;
    theta = thetaD = thetaDD = x = y = vx = vy = ax = ay = 0.0;

    outFile << "t x y vx vy ax ay theta_deg\n";

    double t = m_t0;
    while (t <= m_tf)
    {
        theta = m_theta0 * cos(m_w * (t - m_t0));
        thetaD = -1 * m_theta0 * m_w * sin(m_w * (t - m_t0));
        thetaDD = -1 * pow(m_w, 2) * m_theta0 * cos(m_w * (t - m_t0));

        x = m_l * sin(theta);
        y = -1 * m_l * cos(theta);
        vx = m_l * thetaD * cos(theta);
        vy = m_l * thetaD * sin(theta);
        ax = m_l * (thetaDD * cos(theta) - sin(theta) * pow(thetaD, 2));
        ay = m_l * (thetaDD * sin(theta) + cos(theta) * pow(thetaD, 2));

        outFile << t << ' ' << x << ' ' << y << ' ' << vx << ' ' << vy << ' ' << ax << ' ' << ay << ' ' << theta * 180 / PI << '\n';

        t += m_dt;
    }

    outFile.close();
}
