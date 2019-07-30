#include "Light.h"

Light::Light(float px, float py, float pz, float b){
    x = px;
    y = py;
    z = pz;
    SetBrightness(b);
}

Light::~Light() {
}

void Light::SetBrightness(float b){
    brightness = std::fminf(std::fmaxf(b, 0), 1);
}
