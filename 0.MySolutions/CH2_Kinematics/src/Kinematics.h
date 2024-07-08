#ifndef KINEMATICS_H
#define KINEMATICS_H

#define UINITIALIZED -99999
#define PI (atan(1) * 4)

namespace kinematics
{
    class Kinematics
    {
    public:
        Kinematics() = default;
        virtual ~Kinematics() = default;
        virtual void run();

    protected:
        virtual void userInputs() = 0;
        virtual void printInputs() = 0;
        virtual void initialize() = 0;
        virtual void compute() = 0;
    };
}

#endif