#include "03/Menu/sub_screen_message.h"
#include "03/Graphics/messages.h"
#include "03/unk_021da000.h"
#include "03/Menu/menu_pair_loading.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021d5000.h"

#include "03/unk_021d6000.h"
#include "gx_load2d.h"
#include "registers.h"

void ClearSubScreenMessageShown(void) {
    *(u8 *) &gSubScreenMessageShown = 0;
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
