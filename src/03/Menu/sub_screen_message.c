#include "03/Menu/sub_screen_message.h"
#include "03/Graphics/messages.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"

#include "03/Menu/wifi_menu_tables.h"
#include "vram_load_2d_graphics.h"
#include "registers.h"
#include "03/Menu/main_menu.h"

const u16 gSubScreenMessageRect[4] = {0x14, 0, 0xd8, 0x40};
u8 gJtNullNscName[17] = {0x63, 0x68, 0x61, 0x72, 0x2f, 0x6a, 0x74, 0x4e, 0x75,
                         0x6c, 0x6c, 0x2e, 0x6e, 0x73, 0x63, 0x2e, 0x6c};
u8 gSubScreenMessageShown;

void ClearSubScreenMessageShown(void) {
    gSubScreenMessageShown = 0;
}

BOOL ShowSubScreenMessage(u32 index, s32 column, u32 value) {
    void *canvas;
    void *message;

    if (gSubScreenMessageShown != 0) {
        return 0;
    }
    LoadFileToVram(gJtNullNscName, GXS_LoadBG0Scr);
    reg_G2S_DB_BG0OFS = 0x1920000;
    canvas = InitBgTextCanvas(1, 0);
    message = GetMessageEntryAndWriteDigit(gMessages, index, column, value);
    DrawCanvasTextRect(canvas, gSubScreenMessageRect[0], gSubScreenMessageRect[1], gSubScreenMessageRect[2],
                       gSubScreenMessageRect[3], 2, GetLanguageTextFlags(), message);
    RequestBgTextCanvasUpload(canvas);
    gSubScreenMessageShown = 1;
    return 1;
}

BOOL HideSubScreenMessage(void) {
    if (gSubScreenMessageShown == 0) {
        return 0;
    }
    ReleaseBgTextCanvasOfScreen(1);
    gSubScreenMessageShown = 0;
    return 1;
}
