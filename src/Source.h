#ifndef AVP_SOURCE_H
#define AVP_SOURCE_H

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

namespace AVP {

class Source
{
public:
    Source(const std::string& file);
    ~Source();

protected:

//    static bool LoadWAVFile(const char* filename, ALenum* format, ALvoid** data, ALsizei* size, ALsizei* freq, Float64* estimatedDurationOut);

protected:

    ALuint  m_buffer;
    ALuint  m_source;

    ALenum  m_format;
    ALvoid* m_data;
    ALsizei m_size;
    ALsizei m_freq;
    ALboolean m_loop;

}; // class Source

} // namespace AVP

#endif // AVP_SOURCE_H
