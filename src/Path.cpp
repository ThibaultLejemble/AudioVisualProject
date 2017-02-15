#include "AudioVisualProject.h"
#include "Path.h"

#include <fstream>
#include <cmath>
#include <limits>
#include <sstream>

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
    if(std::getline(stream, line))
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
    while(std::getline(stream, line)) {
        if(line.size()==0)
            ERROR("corrupted file (blank line)");

        n = sscanf(line.c_str(), "%f %f %f", &x, &y, &z);
        if(n!=3)
            ERROR("corrupted file (points)");

        m_positions.push_back({x,y,z});
    }

    stream.close();

    m_dt = m_duration/(m_positions.size()-1);
}


void Path::process()
{
    ALfloat maxDistance = 0;
    ALfloat minDistance = std::numeric_limits<float>::max();

    for(Point&pos : m_positions)
        if(!std::isinf(pos[0])&&!std::isinf(pos[1])&&!std::isinf(pos[2]))
        {
            maxDistance = std::max(maxDistance, length(pos));
            minDistance = std::min(minDistance, length(pos));
        }

    for(Point& pos : m_positions)
    {
        if(std::isinf(pos[0])||std::isinf(pos[1])||std::isinf(pos[2]))
            pos = {2000, 2000, 2000};
        else
            scale(1.0, 200, minDistance, maxDistance, pos);
    }
}


void Path::print() const
{
    std::stringstream time;
    std::stringstream pos;
    time << "time = [";
    pos << "pos = [";

    for(size_t k = 0; k < m_positions.size()-1; ++k)
    {
        time << ((double)k)/(m_positions.size()-1)*m_duration << ";";
        pos << m_positions[k][0] << "," << m_positions[k][1] << "," << m_positions[k][2] << ";";
    }
    time << m_duration << "]\n";
    pos << m_positions[m_positions.size()-1][0] << "," << m_positions[m_positions.size()-1][1] << "," << m_positions[m_positions.size()-1][2] << ";";

    std::cout << time.str() << pos.str() << "\n";
}

} // namespace AVP




















