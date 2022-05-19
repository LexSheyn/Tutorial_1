#pragma once

#include "../Screens/EScreen.h"

namespace wce
{
	struct FScreenData { EScreen FromScreen; EScreen ToScreen; };
	struct FButtonData { WORD Id; DWORD MouseButton; };
}