#include "AudioVisualProject.h"
#include "Source.h"

#include <AL/alut.h>

#include <iostream>
#include <thread>
#include <chrono>

namespace AVP {

Source::Source(const std::string& file)
{
    // buffer generation
    alGetError();
    alGenBuffers(1, &m_buffer);
    CHECK("buffer initialization");

    // loading wav data
    alutLoadWAVFile(reinterpret_cast<signed char*>(const_cast<char*>(file.c_str())), &m_format, &m_data, &m_size, &m_freq, &m_loop);
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


}

Source::~Source()
{

}

} // namespace AVP
