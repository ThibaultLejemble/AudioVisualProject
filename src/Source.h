#ifndef AVP_SOURCE_H
#define AVP_SOURCE_H

#include "Path.h"

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alut.h>

namespace AVP {

class Source
{
public:
    Source(const std::string& WAVFile, const std::string& PathFile);
    ~Source();

    inline const double& duration() const {
        return m_path.duration();
    }

    inline void play() const {
        alSourcePlay(m_source);
    }

    inline void update(double t) {
        alSourcefv(m_source, AL_POSITION, m_path.at(t));
//        //TODO delete
//        Point p = m_path.pointAt(t);
//        std::cout << p[0]<<" "<< p[1]<<" "<< p[2]<<"\n";
    }

    void printCurrentPosition()const;

protected:

    Path m_path;

    ALuint  m_buffer;
    ALuint  m_source;

    ALenum  m_format;
    ALvoid* m_data;
    ALsizei m_size;
    ALsizei m_freq;
    ALboolean m_loop;

//    double m_duration;

}; // class Source

} // namespace AVP

#endif // AVP_SOURCE_H
