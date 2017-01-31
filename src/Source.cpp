#include "AudioVisualProject.h"
#include "Source.h"

namespace AVP {

Source::Source()
{

}

Source::~Source()
{

}

bool Source::init()
{
    alGetError();
    alGenBuffers(1, &m_buffer);
    if(alGetError() != AL_NO_ERROR)
    {
        ERROR("Error initializing Source...");
        return false;
    }

    return true;
}


bool Source::load(const std::string& file)
{

    return true;
}

} // namespace AVP
