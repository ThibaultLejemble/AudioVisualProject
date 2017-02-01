#ifndef AVP_NAME2_H
#define AVP_NAME2_H

#include <AL/alc.h>

namespace AVP {

class Source;

class Device
{
public:
    Device();
    ~Device();

    static void run(Source &source);

protected:

    ALCdevice* m_device;
    ALCcontext* m_context;

}; // class Device

} // namespace AVP


#endif // AVP_NAME2_H
