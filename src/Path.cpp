#include "AudioVisualProject.h"
#include "Path.h"

#include <fstream>
#include <cmath>

#define FACTOR 1000

namespace AVP {

Path::Path(const std::string& file) :
    m_positions(),
    m_duration(),
    m_dt()
{
    load(file);
}

Path::~Path()
{

}

inline ALfloat validate(ALfloat x) {
    return std::isinf(x) ? FACTOR*1e9 : FACTOR*x;
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

        m_positions.push_back({validate(x),validate(y),validate(z)});
    }

    stream.close();

    m_dt = m_duration/(m_positions.size()-1);
}

} // namespace AVP
