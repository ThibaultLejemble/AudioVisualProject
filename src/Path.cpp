#include "AudioVisualProject.h"
#include "Path.h"

#include <fstream>
#include <cmath>
#include <limits>

namespace AVP {

Path::Path(const std::string& file) :
    m_positions(),
    m_duration(),
    m_dt()
{
    load(file);
    process();
}

Path::~Path()
{

}

void Path::load(const std::string& file)
{
    // opening file
    std::ifstream stream(file);
    if(!stream.is_open())
        ERROR("opening file");

    std::string line;
    ALfloat x, y, z;
    uint n;

    // init
    m_positions.clear();
    m_duration = 0;
    m_dt = 0;

    // parse heander
    if(std::getline(stream, line, '\r'))
    {
        if(line.size()==0)
            ERROR("corrupted file (blank line)");

        n = sscanf(line.c_str(), "%lf", &m_duration);
        if(n!=1)
            ERROR("corrupted file (header)");
    }
    else
    {

    }

    // parse points
    while(std::getline(stream, line, '\r')) {
        if(line.size()==0)
            ERROR("corrupted file (blank line)");

        n = sscanf(line.c_str(), "%f %f %f", &x, &y, &z);
        if(n!=3)
            ERROR("corrupted file (points)");

        m_positions.push_back({5,x,5});
    }

    stream.close();

    m_dt = m_duration/(m_positions.size()-1);
}

void Path::process()
{
    ALfloat maxY = 0;
    ALfloat minY = std::numeric_limits<float>::max();

    for(Point&pos : m_positions)
        if(!std::isnan(pos[0])&&!std::isnan(pos[1])&&!std::isnan(pos[2])&&
           !std::isinf(pos[0])&&!std::isinf(pos[1])&&!std::isinf(pos[2]))
        {
            maxY = std::max(maxY, pos[1]);
            minY = std::min(minY, pos[1]);
        }

    for(Point& pos : m_positions)
    {
        if(std::isnan(pos[0])||std::isnan(pos[1])||std::isnan(pos[2])||
           std::isinf(pos[0])||std::isinf(pos[1])||std::isinf(pos[2]))
            pos = {2000, 2000, 2000};
        else
            scaleY(-50, 50, minY, maxY, pos[1]);
    }
}

} // namespace AVP








