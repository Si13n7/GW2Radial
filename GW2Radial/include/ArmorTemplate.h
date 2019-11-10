#pragma once
#include <Main.h>
#include <WheelElement.h>

namespace GW2Radial
{

	enum class ArmorTemplateType : uint
	{
		NONE = 0xFFFFFFFF,
		ONE = IDR_ARMOR1,
		TWO = IDR_ARMOR2,
		THREE = IDR_ARMOR3,
		FOUR = IDR_ARMOR4,
		FIVE = IDR_ARMOR5,
		SIX = IDR_ARMOR6,

		FIRST = ONE,
		LAST = SIX
	};
	const unsigned int ArmorTemplateTypeCount = 6;

	class ArmorTemplate : public WheelElement
	{
	public:
		ArmorTemplate(ArmorTemplateType m, IDirect3DDevice9* dev);

	protected:
		static const char* GetArmorTemplateNameFromType(ArmorTemplateType m)
		{
			switch (m)
			{
			case ArmorTemplateType::ONE:
				return "One";
			case ArmorTemplateType::TWO:
				return "Two";
			case ArmorTemplateType::THREE:
				return "Three";
			case ArmorTemplateType::FOUR:
				return "Four";
			case ArmorTemplateType::FIVE:
				return "Five";
			case ArmorTemplateType::SIX:
				return "Six";
			default:
				return "[Unknown]";
			}
		}
		static const char* GetArmorTemplateNicknameFromType(ArmorTemplateType m)
		{
			switch (m)
			{
			case ArmorTemplateType::ONE:
				return "one";
			case ArmorTemplateType::TWO:
				return "two";
			case ArmorTemplateType::THREE:
				return "three";
			case ArmorTemplateType::FOUR:
				return "four";
			case ArmorTemplateType::FIVE:
				return "five";
			case ArmorTemplateType::SIX:
				return "six";
			default:
				return "unknown";
			}
		}

		std::array<float, 4> color() override;
	};

}