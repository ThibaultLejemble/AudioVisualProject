#include "AudioVisualProject.h"
#include "Source.h"

#include <AL/alut.h>

#include <iostream>
#include <thread>
#include <chrono>

namespace AVP {

Source::Source(const std::string& WAVFile, const std::string &PathFile) :
    m_path(PathFile)
{
    // buffer generation
    alGetError();
    alGenBuffers(1, &m_buffer);
    CHECK("buffer initialization");

    // loading wav data
//    m_buffer = alutCreateBufferFromFile(file.c_str());
    alutLoadWAVFile(reinterpret_cast<signed char*>(const_cast<char*>(WAVFile.c_str())), &m_format, &m_data, &m_size, &m_freq, &m_loop);
    alBufferData(m_buffer, m_format, m_data, m_size, m_freq);
    CHECK("sending data to buffer");

    // unloading wav data
    alutUnloadWAV(m_format, m_data, m_size, m_freq);
    CHECK("unloading WAV data");

    // source generation
    alGenSources(1, &m_source);
    CHECK("source initialization");

    // attach buffer 0 to source
    alSourcei(m_source, AL_BUFFER, m_buffer);
    CHECK("attaching buffer to source");

//    m_duration = 0.25*m_size/m_freq;

    alSourcei(m_source, AL_LOOPING, AL_TRUE);



    /////////////////////////////////////////////////
    // TEST
//    float maxDistance;
//    alGetSourcef(m_source, AL_MAX_DISTANCE, &maxDistance);
//    LOG("maxDistance="<<maxDistance);

//    float refDistance;
//    alGetSourcef(m_source, AL_REFERENCE_DISTANCE, &refDistance);
//    LOG("refDistance="<<refDistance);

    alDistanceModel(AL_INVERSE_DISTANCE);
}

Source::~Source()
{

}

void Source::printCurrentPosition()const
{
    float x, y, z;
    alGetSource3f(m_source, AL_POSITION, &x, &y, &z);
    LOG(x<<" "<<y<<" "<<z);
}

} // namespace AVP
