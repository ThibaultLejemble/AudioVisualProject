#include "AudioVisualProject.h"
#include "Device.h"
#include "Path.h"
#include "Source.h"

int main(int argc, char *argv[])
{
    LOG("Audio-Visual Project");

    AVP::Device device;
    AVP::Source source("../data/01.wav");
    AVP::Path path("../data/01.txt");

    //TODO

    return 0;
}
