#include "AudioVisualProject.h"
#include "Device.h"
#include "Source.h"
#include "Timer.h"

namespace AVP {

Device::Device() :
    m_device(NULL),
    m_context(NULL)
{   
    // device initialization
    m_device = alcOpenDevice(NULL);
    if(m_device)
    {
        m_context = alcCreateContext(m_device, NULL);
        alcMakeContextCurrent(m_context);
    }
    else
        ERROR("device initialization");

    // listener initialization
    alListener3f(AL_POSITION,5,0,0);
    ALfloat dir[] = {0,0,1,  1,0,0};
    alListenerfv(AL_ORIENTATION, dir);
}

Device::~Device()
{
    m_context = alcGetCurrentContext();
    m_device = alcGetContextsDevice(m_context);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(m_context);
    alcCloseDevice(m_device);
}


void Device::run(Source& source)
{
    double end = source.duration();
    double t = 0.0;

    source.play();

    Timer timer;

    while ((t=timer.timeSec())<end) {
        source.update(t);
        source.printCurrentPosition();
    }

}

} // namespace AVP
