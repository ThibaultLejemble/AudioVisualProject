#ifndef AVP_NAME2_H
#define AVP_NAME2_H

#include <AL/alc.h>

namespace AVP {

class Device
{
public:
    Device();
    ~Device();

protected:

    ALCdevice* m_device;
    ALCcontext* m_context;

}; // class Device

} // namespace AVP


#endif // AVP_NAME2_H
