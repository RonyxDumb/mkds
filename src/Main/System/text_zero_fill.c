#include "Main/System/text_zero_fill.h"

// Zero fill kept in .text between the logo scene code and main.
#pragma explicit_zero_data on
#pragma define_section MAIN_TEXT ".text"                                                                               \
                                 ".text" abs32 RWX
#pragma section MAIN_TEXT begin

u32 gTextZeroFill[0x11ac / 4] = {0};

#pragma section MAIN_TEXT end
#pragma explicit_zero_data off
