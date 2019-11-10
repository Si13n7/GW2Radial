#include <ArmorTemplate.h>
#include <Wheel.h>

namespace GW2Radial
{

	ArmorTemplate::ArmorTemplate(ArmorTemplateType m, IDirect3DDevice9* dev)
		: WheelElement(uint(m), std::string("armortemplate_") + GetArmorTemplateNicknameFromType(m), "ArmorTemplates", GetArmorTemplateNameFromType(m), dev)
	{ }

	bool ArmorTemplate::isActive() const
	{
		return WheelElement::isActive();
	}

	template<>
	void Wheel::Setup<ArmorTemplate>(IDirect3DDevice9* dev)
	{
		SetAlphaBlended(true);
		for (auto i = ArmorTemplateType::FIRST; i <= ArmorTemplateType::LAST; i = ArmorTemplateType(uint(i) + 1))
			AddElement(std::make_unique<ArmorTemplate>(i, dev));
	}

	std::array<float, 4> ArmorTemplate::color()
	{
		auto mt = ArmorTemplateType(elementId_);
		switch (mt)
		{
		case ArmorTemplateType::ONE:
			return { 213 / 255.f, 100 / 255.f, 89 / 255.f, 1 };
		case ArmorTemplateType::TWO:
			return { 212 / 255.f, 198 / 255.f, 94 / 255.f, 1 };
		case ArmorTemplateType::THREE:
			return { 108 / 255.f, 128 / 255.f, 213 / 255.f, 1 };
		case ArmorTemplateType::FOUR:
			return { 120 / 255.f, 183 / 255.f, 197 / 255.f, 1 };
		case ArmorTemplateType::FIVE:
			return { 199 / 255.f, 131 / 255.f, 68 / 255.f, 1 };
		case ArmorTemplateType::SIX:
			return { 136 / 255.f, 123 / 255.f, 195 / 255.f, 1 };
		default:
			return { 1, 1, 1, 1 };
		}
	}

}