#include "AudioVisualProject.h"
#include "Device.h"
#include "Path.h"
#include "Source.h"
#include "Timer.h"

int main(int argc, char *argv[])
{
    LOG("Audio-Visual Project");

    AVP::Device device;
    AVP::Source source("../data/01.wav", "../data/01.txt");

    device.run(source);

    return 0;
}
