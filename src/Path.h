#ifndef AVP_PATH_H
#define AVP_PATH_H

#include <AL/al.h>
#include <AL/alc.h>

#include <vector>
#include <array>
#include <string>

namespace AVP {

typedef std::array<ALfloat,3> Point;

class Path
{
public:
    Path(const std::string& file);
    ~Path();

    void load(const std::string& file);

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

    std::vector<Point> m_positions;
    double m_duration;
    double m_dt;

}; // class Path

} // namespace AVP

#endif // AVP_PATH_H
