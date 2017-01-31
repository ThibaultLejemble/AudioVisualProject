#include "AudioVisualProject.h"
#include "Device.h"

namespace AVP {

Device::Device() :
    m_device(NULL),
    m_context(NULL)
{
    m_device = alcOpenDevice(NULL);

    if(m_device)
    {
        m_context = alcCreateContext(m_device, NULL);
        alcMakeContextCurrent(m_context);
    }
    else
        ERROR("device initialization");
}

Device::~Device()
{
    // Exit
    m_context = alcGetCurrentContext();
    m_device = alcGetContextsDevice(m_context);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(m_context);
    alcCloseDevice(m_device);
}

} // namespace AVP
