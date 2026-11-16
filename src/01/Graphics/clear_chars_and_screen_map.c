#include "01/Graphics/clear_chars_and_screen_map.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "Main/Net/multiboot_parent_finish.h"

#pragma optimize_for_size on

LogoScene *g_LogoContext;
s32 gTestSceneCharTableIndex;
TestScene *gTestScene;
u16 gTestSceneCharText[206];

void ClearChars(u16 *chars) {
    s32 charIndex;

    for (charIndex = 0; charIndex < 0x3000; charIndex++) {
        chars[charIndex] = 0;
    }
}

void FillScreenMapIndices(u16 *screenMap) {
    u16 index;

    for (index = 0; index < 0x300; index++) {
        screenMap[index] = index;
    }
}
