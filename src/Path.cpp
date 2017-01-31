#include "AudioVisualProject.h"
#include "Path.h"

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

bool Path::load(const std::string& file)
{
    //TODO
    return false;
}

Path* PathFactory::Create()
{
    std::vector<Point> positions;

    //TODO

    return new Path(positions);
}


} // namespace AVP
