#pragma once
#include <Main.h>
#include <WheelElement.h>

namespace GW2Radial
{

	enum class BuildTemplateType : uint
	{
		NONE = 0xFFFFFFFF,
		ONE = IDR_BUILD1,
		TWO = IDR_BUILD2,
		THREE = IDR_BUILD3,
		FOUR = IDR_BUILD4,
		FIVE = IDR_BUILD5,
		SIX = IDR_BUILD6,

		FIRST = ONE,
		LAST = SIX
	};
	const unsigned int BuildTemplateTypeCount = 6;

	class BuildTemplate : public WheelElement
	{
	public:
		BuildTemplate(BuildTemplateType m, IDirect3DDevice9* dev);

		bool isActive() const override;

	protected:
		static const char* GetBuildTemplateNameFromType(BuildTemplateType m)
		{
			switch (m)
			{
			case BuildTemplateType::ONE:
				return "One";
			case BuildTemplateType::TWO:
				return "Two";
			case BuildTemplateType::THREE:
				return "Three";
			case BuildTemplateType::FOUR:
				return "Four";
			case BuildTemplateType::FIVE:
				return "Five";
			case BuildTemplateType::SIX:
				return "Six";
			default:
				return "[Unknown]";
			}
		}
		static const char* GetBuildTemplateNicknameFromType(BuildTemplateType m)
		{
			switch (m)
			{
			case BuildTemplateType::ONE:
				return "one";
			case BuildTemplateType::TWO:
				return "two";
			case BuildTemplateType::THREE:
				return "three";
			case BuildTemplateType::FOUR:
				return "four";
			case BuildTemplateType::FIVE:
				return "five";
			case BuildTemplateType::SIX:
				return "six";
			default:
				return "unknown";
			}
		}

		std::array<float, 4> color() override;
	};

}