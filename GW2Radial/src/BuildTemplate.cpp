#include <BuildTemplate.h>
#include <Wheel.h>

namespace GW2Radial
{

	BuildTemplate::BuildTemplate(BuildTemplateType m, IDirect3DDevice9* dev)
		: WheelElement(uint(m), std::string("buildtemplate_") + GetBuildTemplateNicknameFromType(m), "BuildTemplates", GetBuildTemplateNameFromType(m), dev)
	{ }

	template<>
	void Wheel::Setup<BuildTemplate>(IDirect3DDevice9* dev)
	{
		SetAlphaBlended(true);
		for (auto i = BuildTemplateType::FIRST; i <= BuildTemplateType::LAST; i = BuildTemplateType(uint(i) + 1))
			AddElement(std::make_unique<BuildTemplate>(i, dev));
	}

	std::array<float, 4> BuildTemplate::color()
	{
		auto mt = BuildTemplateType(elementId_);
		switch (mt)
		{
		case BuildTemplateType::ONE:
			return { 213 / 255.f, 100 / 255.f, 89 / 255.f, 1 };
		case BuildTemplateType::TWO:
			return { 212 / 255.f, 198 / 255.f, 94 / 255.f, 1 };
		case BuildTemplateType::THREE:
			return { 108 / 255.f, 128 / 255.f, 213 / 255.f, 1 };
		case BuildTemplateType::FOUR:
			return { 120 / 255.f, 183 / 255.f, 197 / 255.f, 1 };
		case BuildTemplateType::FIVE:
			return { 199 / 255.f, 131 / 255.f, 68 / 255.f, 1 };
		case BuildTemplateType::SIX:
			return { 136 / 255.f, 123 / 255.f, 195 / 255.f, 1 };
		default:
			return { 1, 1, 1, 1 };
		}
	}

}