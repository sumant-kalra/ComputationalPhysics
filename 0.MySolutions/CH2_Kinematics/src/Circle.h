#ifndef CIRCLE_H
#define CIRCLE_H

#define UINITIALIZED -99999
#define PI (atan(1) * 4)

namespace kinematics
{
    class Circle1
    {
    public:
        Circle1();
        ~Circle1();

        void run();

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

        void userInputs();
        void printInputs();
        void initialize();
        void compute();
    };
}

#endif
