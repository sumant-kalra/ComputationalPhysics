#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
#include <fstream>
#include "Circle.h"

kinematics::Circle1::Circle1() : m_isInitialized(false) {}
kinematics::Circle1::~Circle1() {}

void kinematics::Circle1::run()
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
    std::cout << "Xc(m),Yc(m): (" << m_xc << "," << m_yc << ")\n";
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

    double t = m_t0;
    double x, y, vx, vy, ax, ay, theta, theta_deg;
    x = y = vx = vy = ax = ay = theta = theta_deg = UINITIALIZED;

    std::string outFileName("Circle1.out");

    std::ofstream outputFile(outFileName.c_str());
    outputFile.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    if (!outputFile.is_open())
        throw std::invalid_argument(("Failed to open the file: " + outFileName).c_str());

    outputFile << "t x y vx vy ax ay theta_deg\n";

    while (t <= m_tf)
    {
        theta = m_w * (t - m_t0);
        x = m_xc + m_r * cos(theta);
        y = m_yc + m_r * sin(theta);
        vx = -1 * m_r * m_w * sin(theta);
        vy = m_r * m_w * cos(theta);
        ax = -1 * pow(m_w, 2) * m_r * cos(theta);
        ay = -1 * pow(m_w, 2) * m_r * sin(theta);
        theta_deg = atan((y - m_yc) / (x - m_xc)) * 180 / PI;

        outputFile << t << " " << x << " " << y << " " << vx << " " << vy << " " << ax << " " << ay << " " << theta_deg << '\n';

        t += m_dt;
    }

    outputFile.close();

    m_acc = pow(m_w, 2) * m_r;
    std::cout << "\n# Outputs:\n";
    std::cout << "## Centripetal acceleration (rad/s^2): " << m_acc << '\n';
}
