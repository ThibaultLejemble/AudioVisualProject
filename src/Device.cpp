#include "AudioVisualProject.h"
#include "Device.h"

namespace AVP {

Device::Device() :
    m_internalDevice(NULL),
    m_internalContext(NULL)
{

}

Device::~Device()
{

}

bool Device::init()
{
    m_internalDevice = alcOpenDevice(NULL);

    if(m_internalDevice)
    {
        m_internalContext = alcCreateContext(m_internalDevice, NULL);
        alcMakeContextCurrent(m_internalContext);
    }
    else
    {
        ERROR("Error initializing Device...");
        return false;
    }
    return true;
}

} // namespace AVP
