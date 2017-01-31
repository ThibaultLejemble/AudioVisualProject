#ifndef AVP_AVP_H
#define AVP_AVP_H

#include <iostream>

#define LOG(message) {std::cout << ">> " << message << "\n";}
#define ERROR(message) {std::cout << ">> Error: " << __FILE__ << ":" << __LINE__ << " " << message << "\n"; throw std::runtime_error(message);}
#define ERROR_E(message,e) {std::cout << ">> Error: " << __FILE__ << ":" << __LINE__ << " " << message << " (" << e << ")\n"; throw std::runtime_error(message);}
#define CHECK(message)  {                           \
                        ALenum e = alGetError();    \
                        if(e!=AL_NO_ERROR)          \
                            ERROR_E(message,e);         \
                        }

#endif // AVP_AVP_H
