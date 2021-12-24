#include "resources/resources.h"
#include "StandardMaterial.h"

StandardMaterial::StandardMaterial(Context* context) : Material(context)
{
}

StandardMaterial::~StandardMaterial()
{

}

void StandardMaterial::create()
{
	Material::createMaterial(RESOURCES_STANDARD_MATERIAL_DATA, RESOURCES_STANDARD_MATERIAL_SIZE);
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
	instance->setParameter("ior", ior);
}
