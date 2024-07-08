#ifndef CIRCLE_H
#define CIRCLE_H

#include "Kinematics.h"

namespace kinematics
{
    class Circle1 : public Kinematics
    {
    public:
        Circle1();
        ~Circle1() = default;

    private:
        // Circular path's attributes
        double m_r;  // radius of circle in m
        double m_xc; // X co-ordinate of circle's centre in m
        double m_yc; // Y co-ordinate of circle's centre in m

        // Circular motion attributes
        double m_w;  // Angular velocity of circular motion in radian per sec
        double m_t0; // Starting time of simulation in s, that is the time at which the angular displacement = 0
        double m_tf; // End time of simulation in s
        double m_dt; // Time step in s

        // Output
        double m_acc; // Centripetal acceleration of the circular motion

        bool m_isInitialized;

        virtual void userInputs() override;
        virtual void printInputs() override;
        virtual void initialize() override;
        virtual void compute() override;
    };
}

#endif
