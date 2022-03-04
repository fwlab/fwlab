#include "AmbientLight.h"

using namespace gl::light;

AmbientLight::AmbientLight(utils::Path iblPath)
{
    //mIBL = std::make_unique<IBL>(*mEngine);

    //if (!iblPath.isDirectory()) {
    //    if (!mIBL->loadFromEquirect(iblPath)) {
    //        std::cerr << "Could not load the specified IBL: " << iblPath << std::endl;
    //        mIBL.reset(nullptr);
    //        return;
    //    }
    //}
    //else {
    //    if (!mIBL->loadFromDirectory(iblPath)) {
    //        std::cerr << "Could not load the specified IBL: " << iblPath << std::endl;
    //        mIBL.reset(nullptr);
    //        return;
    //    }
    //}
}

AmbientLight::~AmbientLight()
{
}