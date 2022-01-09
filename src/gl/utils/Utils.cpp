#include <cmath>
#include "Utils.h"

using namespace gl::utils;

float Utils::reflectanceToIOR(float reflectance)
{
	return 2.0 / (1.0 - std::sqrt(reflectance)) - 1;
}

float Utils::iorToReflectance(float ior)
{
	return std::pow(1.0 - 2.0 / (ior + 1.0), 2);
}