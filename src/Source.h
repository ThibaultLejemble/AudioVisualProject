#ifndef AVP_SOURCE_H
#define AVP_SOURCE_H

#include <AL/al.h>
#include <AL/alc.h>

namespace AVP {

class Source
{
public:
    Source();
    ~Source();

    bool init();
    bool load(const std::string& file);

protected:

    ALuint m_buffer;

}; // class Source

} // namespace AVP

#endif // AVP_SOURCE_H
