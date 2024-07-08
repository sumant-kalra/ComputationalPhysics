#ifndef SIMPLE_PENDULUM_H
#define SIMPLE_PENDULUM_H

#include <iostream>
#include "Kinematics.h"

#define g 9.81

namespace kinematics
{
    class SimplePendulum : public Kinematics
    {
    private:
        // Inputs
        double m_theta0;
        double m_l;
        double m_t0;
        double m_tf;
        double m_dt;

        // Outputs
        double m_w;

        bool m_isInitialized;

        virtual void userInputs() override;
        virtual void printInputs() override;
        virtual void initialize() override;
        virtual void compute() override;

    public:
        SimplePendulum();
        ~SimplePendulum() = default;
    };
}

#endif