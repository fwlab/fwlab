# Material

```c++
	class BaseColors {
	public:
		// Non-metals (dielectrics)	range: [0.04, 0.94]	[10, 240]
		static const filament::math::float3 coal = { 0.19, 0.19, 0.19 }; // #323232
		static const filament::math::float3 rubber = { 0.21, 0.21, 0.21 }; // #353535
		static const filament::math::float3 mud = { 0.33, 0.24, 0.19 }; // #553d31
		static const filament::math::float3 wood = { 0.53, 0.36, 0.24 }; // #875c3c
		static const filament::math::float3 vegetation = { 0.48, 0.51, 0.31 }; // #7b824e
		static const filament::math::float3 brick = { 0.58, 0.49, 0.46 }; // #947d75
		static const filament::math::float3 sand = { 0.69, 0.66, 0.52 }; // #b1a884
		static const filament::math::float3 concrete = { 0.75, 0.75, 0.73 }; // #c0bfbb

		// Metals (conductors) range: [0.66, 1.0] [170, 255]
		static const filament::math::float3 silver = { 0.97, 0.96, 0.91 }; // #f7f4e8
		static const filament::math::float3 aluminum = { 0.91, 0.92, 0.92 }; // #e8eaea
		static const filament::math::float3 titanium = { 0.76, 0.73, 0.69 }; // #c1baaf
		static const filament::math::float3 iron = { 0.77, 0.78, 0.78 }; // #c4c6c6
		static const filament::math::float3 platinum = { 0.83, 0.81, 0.78 }; // #d3cec6
		static const filament::math::float3 gold = { 1.00, 0.85, 0.57 }; // #ffd891
		static const filament::math::float3 brass = { 0.98, 0.90, 0.59 }; // #f9e596
		static const filament::math::float3 copper = { 0.97, 0.74, 0.62 }; // #f7bc9e
	};

	class Metallics
	{
	public:
		static const float metallic = 1;
		static const float conductor = 1;
		static const float nonMetallic = 0;
		static const float dielectric = 0;
	};

	enum class RefractionType
	{
		thin,
		solid
	};

	enum class RefractionMode
	{
		cubemap,
		screenspace.
	};

	class Reflectance
	{
	public:
		// Values below 0.35 (2% reflectance) should be avoided as no real-world materials have such low reflectance.
		static const float water = 0.02; // 2%
		static const float fabric = 0.05; // 4% to 5.6%
		static const float commonLiquids = 0.03; // 2% to 4%
		static const float commonGemstones = 0.1; // 5% to 16%
		static const float plastics = 0.45; // 4% to 5%
		static const float glass = 0.45; // 4% to 5%
		static const float otherDielectricMaterials = 0.35; // 2% to 5%
		static const float eyes = 0.025; // 2.5%
		static const float skin = 0.028; // 2.8%
		static const float hair = 0.046; // 4.6%
		static const float teeth = 0.058; // 5.8%
		static const float defaultValue = 0.04; // 4%
	};

	class IOR
	{
	public:
		static const float water = 1.33; // 1.33
		static const float fabric = 1.58; // 1.5 to 1.62
		static const float commonLiquids = 0.42; // 1.33 to 1.5
		static const float commonGemstones = 1.9; // 1.58 to 2.33
		static const float plastics = 1.54; // 1.5 to 1.58
		static const float glass = 1.54; // 1.5 to 1.58
		static const float otherDielectricMaterials = 1.42; // 1.33 to 1.58
		static const float eyes = 1.38; // 1.38
		static const float skin = 1.4; // 1.4
		static const float hair = 1.55; // 1.55
		static const float teeth = 1.63; // 1.63
		static const float defaultValue = 1.5; // 1.5
	};
```