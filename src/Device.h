#ifndef AVP_NAME2_H
#define AVP_NAME2_H

#include <AL/alc.h>

namespace AVP {

class Device
{
public:
    Device();
    ~Device();

    bool init();

protected:

    ALCdevice* m_internalDevice;
    ALCcontext* m_internalContext;

}; // class Device

} // namespace AVP


#endif // AVP_NAME2_H
