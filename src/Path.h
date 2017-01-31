#ifndef AVP_PATH_H
#define AVP_PATH_H

#include <vector>
#include <array>
#include <string>

namespace AVP {

typedef std::array<double,3> Point;

class Path
{
public:
    Path(const std::string& file);
    ~Path();

    bool load(const std::string& file);

protected:

    Path(const std::vector<Point>& positions);

    std::vector<Point> m_positions;

    friend class PathFactory;

}; // class Path

class PathFactory
{
public:

    static Path* Create();

private:
    PathFactory() {}
    ~PathFactory() {}

}; // class PathFactory

} // namespace AVP

#endif // AVP_PATH_H
