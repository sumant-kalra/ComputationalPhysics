/*
* CH2: KINEMATICS: UNIFORM CIRCULAR MOTION: TRACE THE TRAJECTORY OF THE PARTICLE

*/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

int main(int argc, char *argv[])
{
    //[0] Inputs

    double cx, cy, R, w, t0, tf, dt;
    std::string garbageBuffer;
    std::cout << "# Provide the following inputs:\n";
    std::cout << "cx: CentreX(m) cy: CentreY(m) R: Radius(m)\n";
    std::cin >> cx >> cy >> R;
    std::getline(std::cin, garbageBuffer);
    std::cout << "w: AngularVelocity(radians/s)\n";
    std::cin >> w;
    std::getline(std::cin, garbageBuffer);
    std::cout << "t0: StartTime(s) tf: EndTime(s) dt: OutputInterval(s)\n";
    std::cin >> t0 >> tf >> dt;
    std::getline(std::cin, garbageBuffer);
    /// Print the inputs to the console for verification
    std::cout << "\n# The inputs provided are the following:\n";
    std::cout.flags(std::ios_base::fixed);
    std::cout.precision(3);
    std::cout << "cx: " << cx << '\n';
    std::cout << "cy: " << cy << '\n';
    std::cout << "R: " << R << '\n';
    std::cout << "w: " << w << '\n';
    std::cout << "t0: " << t0 << '\n';
    std::cout << "tf: " << tf << '\n';
    std::cout << "dt: " << dt << '\n';

    //[1] Compute and output to a text file

    double t = t0;
    double x = 0.0;
    double y = 0.0;
    double vx = 0.0;
    double vy = 0.0;
    double ax = 0.0;
    double ay = 0.0;

    std::ofstream outFile("Circle.out");
    if (!outFile.is_open())
        std::cerr << "Could not open the file for output!\n";

    outFile.flags(std::ios_base::fixed);
    outFile.precision(3);

    while (t <= tf)
    {
        x = cx + R * cos(w * (t - t0));
        y = cy + R * sin(w * (t - t0));
        vx = -1 * w * R * sin(w * (t - t0));
        vy = w * R * cos(w * (t - t0));
        ax = -1 * w * w * R * cos(w * (t - t0));
        ay = -1 * w * w * R * sin(w * (t - t0));
        /// t x y vx vy ax ay
        outFile << t << ' ' << x << ' ' << y << ' ' << vx << ' ' << vy << ' ' << ax << ' ' << ay << '\n';

        t += dt;
    }

    outFile.close();

    return 0;
}