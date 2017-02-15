#ifndef AVP_PATH_H
#define AVP_PATH_H

#include <AL/al.h>
#include <AL/alc.h>

#include <vector>
#include <array>
#include <string>
#include <cmath>

namespace AVP {

typedef std::array<ALfloat,3> Point;

inline float length(const Point& p) {
    return std::sqrt(p[0]*p[0] + p[1]*p[1] + p[2]*p[2]);
}

inline void multiply(Point& p, float x) {
    p[0] *= x;
    p[1] *= x;
    p[2] *= x;
}

inline void scale(float a, float b, float minDist, float maxDist, Point& p) {
    //TODO improve this code
    float dist = length(p);
    float t = (dist-minDist)/(maxDist-minDist);
    float distScaled = (1.0-t)*a+t*b;
    multiply(p, distScaled/dist);
}

class Path
{
public:
    Path(const std::string& file);
    ~Path();


    inline const ALfloat* at(double t) const {
        return m_positions[(size_t)(t/m_dt)].data();
    }

    inline const Point& pointAt(double t) const {
        return m_positions[(size_t)(t/m_dt)];
    }

    inline const double& duration() const {
        return m_duration;
    }

protected:

    void load(const std::string& file);
    void process();

    void print() const;

    std::vector<Point> m_positions;
    double m_duration;
    double m_dt;



}; // class Path

} // namespace AVP

#endif // AVP_PATH_H
