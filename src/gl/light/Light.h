#ifndef GL_LIGHT_LIGHT_H
#define GL_LIGHT_LIGHT_H
#include <filament/LightManager.h>
#include <math/vec3.h>
#include <utils/Entity.h>
#include <utils/EntityManager.h>
#include "../core/Object3D.h"

namespace gl::light
{
	class Light : public gl::core::Object3D {
	public:
		Light(
			filament::LightManager::Type type = filament::LightManager::Type::SUN,
			filament::sRGBColor color = filament::sRGBColor(0.98f, 0.92f, 0.89f),
			float intensity = 110000,
			filament::math::float3 direction = { 0.7, -1, -0.8 }
		);
		virtual ~Light();

		// Light Manager
		const float EFFICIENCY_FLUORESCENT = filament::LightManager::EFFICIENCY_FLUORESCENT;
		const float EFFICIENCY_HALOGEN = filament::LightManager::EFFICIENCY_HALOGEN;
		const float EFFICIENCY_INCANDESCENT = filament::LightManager::EFFICIENCY_INCANDESCENT;
		const float EFFICIENCY_LED = filament::LightManager::EFFICIENCY_LED;
		template<typename F>
		void forEachComponent(F func) noexcept;
		const filament::math::float3 getColor(filament::LightManager::Instance i) const noexcept;
		size_t getComponentCount() const noexcept;
		const filament::math::float3 getDirection(filament::LightManager::Instance i) const noexcept;
		utils::Entity* getEntities() const noexcept;
		float getFalloff(filament::LightManager::Instance i) const noexcept;
		float getIntensity(filament::LightManager::Instance i) const noexcept;
		bool getLightChannel(filament::LightManager::Instance i, unsigned int channel) const noexcept;
		filament::math::float3 getPosition(filament::LightManager::Instance i) const noexcept;
		filament::LightManager::ShadowOptions getShadowOptions(filament::LightManager::Instance i) const noexcept;
		float getSpotLightInnerCone(filament::LightManager::Instance i) const noexcept;
		float getSpotLightOuterCone(filament::LightManager::Instance i) const noexcept;
		float getSunAngularRadius(filament::LightManager::Instance i) const noexcept;
		float getSunHaloFalloff(filament::LightManager::Instance i) const noexcept;
		float getSunHaloSize(filament::LightManager::Instance i) const noexcept;
		filament::LightManager::Type getType(filament::LightManager::Instance i) const noexcept;
		inline bool isDirectional(filament::LightManager::Instance i) const noexcept;
		inline bool isPointLight(filament::LightManager::Instance i) const noexcept;
		bool isShadowCaster(filament::LightManager::Instance i) const noexcept;
		inline bool isSpotLight(filament::LightManager::Instance i) const noexcept;
		void setColor(filament::LightManager::Instance i, const filament::LinearColor color) noexcept;
		void setDirection(filament::LightManager::Instance i, const filament::math::float3 direction) noexcept;
		void setFalloff(filament::LightManager::Instance i, float radius) noexcept;
		void setIntensity(filament::LightManager::Instance i, float watts, float efficiency) noexcept;
		void setIntensityCandela(filament::LightManager::Instance i, float intensity) noexcept;
		void setLightChannel(filament::LightManager::Instance i, unsigned int channel, bool enable) noexcept;
		void setPosition(filament::LightManager::Instance i, const filament::math::float3 position) noexcept;
		void setShadowCaster(filament::LightManager::Instance i, bool castShadows) noexcept;
		void setShadowOptions(filament::LightManager::Instance i, filament::LightManager::ShadowOptions const& options) noexcept;
		void setSpotLightCone(filament::LightManager::Instance i, float inner, float outer) noexcept;
		void setSunAngularRadius(filament::LightManager::Instance i, float angularRadius) noexcept;
		void setSunHaloFalloff(filament::LightManager::Instance i, float haloFalloff) noexcept;
		void setSunHaloSize(filament::LightManager::Instance i, float haloSize) noexcept;
	};
}

#endif