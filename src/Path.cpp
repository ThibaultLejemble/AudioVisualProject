#include "AudioVisualProject.h"
#include "Path.h"

#include <fstream>

namespace AVP {

Path::Path(const std::vector<Point> &positions) :
    m_positions(positions)
{

}

Path::Path(const std::string& file) :
    m_positions()
{
    load(file);
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

    m_positions.clear();

    while(std::getline(stream, line)) {
        if(line.size()==0)
            continue;

        n = sscanf(line.c_str(), "%f %f %f", &x, &y, &z);
        if(n!=3)
            ERROR("corrupted file");

        m_positions.push_back({x,y,z});
    }

    stream.close();
}

Path PathFactory::Create()
{
    std::vector<Point> positions;

    //TODO

    return Path(positions);
}


} // namespace AVP
