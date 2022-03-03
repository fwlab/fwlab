#ifndef GL_LIGHT_LIGHT_H
#define GL_LIGHT_LIGHT_H
#include <filament/LightManager.h>
#include <math/vec3.h>
#include <utils/Entity.h>
#include <utils/EntityManager.h>
#include "../core/Object3D.h"

namespace gl::light
{
	class Light : public gl::core::Object3D
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
		void forEachComponent(F func) noexcept;
		const filament::math::float3 getColor() const noexcept;
		size_t getComponentCount() const noexcept;
		const filament::math::float3 getDirection() const noexcept;
		const utils::Entity *getEntities() const noexcept;
		float getFalloff() const noexcept;
		float getIntensity() const noexcept;
		bool getLightChannel(unsigned int channel) const noexcept;
		filament::math::float3 getPosition() const noexcept;
		filament::LightManager::ShadowOptions getShadowOptions() const noexcept;
		filament::LightManager::Type getType() const noexcept;
		inline bool isDirectional() const noexcept;
		inline bool isPointLight() const noexcept;
		bool isShadowCaster() const noexcept;
		inline bool isSpotLight() const noexcept;
		void setColor(const filament::LinearColor color) noexcept;
		void setDirection(const filament::math::float3 direction) noexcept;
		void setFalloff(float radius) noexcept;
		void setIntensity(float watts, float efficiency) noexcept;
		void setIntensityCandela(float intensity) noexcept;
		void setLightChannel(unsigned int channel, bool enable) noexcept;
		void setPosition(const filament::math::float3 position) noexcept;
		void setShadowCaster(bool castShadows) noexcept;
		void setShadowOptions(filament::LightManager::ShadowOptions const &options) noexcept;
	};
}

#endif