#include "AudioVisualProject.h"
#include "Device.h"
#include "Path.h"

int main(int argc, char *argv[])
{
    LOG("Audio-Visual Project");

    AVP::Device device;
    if(!device.init())
        return 1;

    AVP::Path* path = AVP::PathFactory::Create();

    //TODO


    return 0;
}
