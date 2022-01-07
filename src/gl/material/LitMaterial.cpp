#include "resources/resources.h"
#include "LitMaterial.h"

using namespace gl::material;

LitMaterial::LitMaterial()
{
}

LitMaterial::~LitMaterial()
{

}

void LitMaterial::create()
{
	Material::createMaterial(RESOURCES_LIT_DATA, RESOURCES_LIT_SIZE);
	instance->setParameter("baseColor", filament::RgbaType::LINEAR, baseColor);
	instance->setParameter("metallic", metallic);
	instance->setParameter("roughness", roughness);
	instance->setParameter("reflectance", reflectance);
	instance->setParameter("sheenColor", filament::RgbType::LINEAR, sheenColor);
	instance->setParameter("sheenRoughness", sheenRoughness);
	instance->setParameter("clearCoat", clearCoat);
	instance->setParameter("clearCoatRoughness", clearCoatRoughness);
	instance->setParameter("anisotropy", anisotropy);
	instance->setParameter("anisotropyDirection", anisotropyDirection);
	instance->setParameter("ambientOcclusion", ambientOcclusion);
	instance->setParameter("emissive", filament::RgbaType::LINEAR, emissive);
	// instance->setParameter("ior", ior);
}
