#ifndef FWLAB_LIGHT_LIGHT_H
#define FWLAB_LIGHT_LIGHT_H
#include <filament/LightManager.h>
#include <math/vec3.h>
#include <utils/Entity.h>
#include <utils/EntityManager.h>
#include "../core/Object3D.h"

namespace fwlab::light
{
	class Light : public core::Object3D
	{
	public:
		Light(
			filament::LightManager::Type type = filament::LightManager::Type::SUN,
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000);
		virtual ~Light();

		// Light Manager
		const float EFFICIENCY_FLUORESCENT = filament::LightManager::EFFICIENCY_FLUORESCENT;
		const float EFFICIENCY_HALOGEN = filament::LightManager::EFFICIENCY_HALOGEN;
		const float EFFICIENCY_INCANDESCENT = filament::LightManager::EFFICIENCY_INCANDESCENT;
		const float EFFICIENCY_LED = filament::LightManager::EFFICIENCY_LED;
		template <typename F>
		void forEachComponent(F func);
		const filament::math::float3 getColor() const;
		size_t getComponentCount() const;
		const filament::math::float3 getDirection() const;
		const ::utils::Entity* getEntities() const;
		float getFalloff() const;
		float getIntensity() const;
		bool getLightChannel(unsigned int channel) const;
		filament::math::float3 getPosition() const;
		filament::LightManager::ShadowOptions getShadowOptions() const;
		filament::LightManager::Type getType() const;
		inline bool isDirectional() const;
		inline bool isPointLight() const;
		bool isShadowCaster() const;
		inline bool isSpotLight() const;
		void setColor(const filament::LinearColor color);
		void setDirection(const filament::math::float3 direction);
		void setFalloff(float radius);
		void setIntensity(float watts, float efficiency);
		void setIntensityCandela(float intensity);
		void setLightChannel(unsigned int channel, bool enable);
		void setPosition(const filament::math::float3 position);
		void setShadowCaster(bool castShadows);
		void setShadowOptions(filament::LightManager::ShadowOptions const& options);
	};
}

#endif