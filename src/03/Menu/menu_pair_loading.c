#include "03/Menu/menu_pair_loading.h"
#include "03/code_021cdd28.h"
#include "03/code_021ce110.h"
#include "03/Graphics/text_canvas.h"
#include "03/unk_021da000.h"
#include "03/Menu/sub_screen_message.h"
#include "03/code_021bf000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/System/dwc_archive.h"

#include "03/code_021c2530.h"
#include "03/unk_021d5000.h"
#include "03/code_021d1000.h"
#include "03/System/application.h"
#include "os_thread.h"
#include "code_0200eddc.h"
#include "code_02139f70.h"

const u8 gLanguagePathLetters[6] = {0x6a, 0x65, 0x66, 0x67, 0x69, 0x73};
const u16 gPrintMessageRect[4] = {0xd, 0x28, 0xe6, 0x70};
const u16 gPrintMessageAndTextRect[4] = {0xd, 0x3c, 0xe6, 0x5e};
const u8 gLanguageTextFlags[22] = {0x80, 4, 0, 0, 0x80, 2, 0, 0, 0x80, 2, 0, 0, 0x80, 2, 0, 0, 0x80, 2, 0, 0, 0x80, 2};
const u16 gPrintMessageTextXPositions[12] = {0x6b, 0x22, 0x6c, 0x22, 0x7c, 0x22, 0x5d, 0x22, 0x5f, 0x22, 0x7d, 0x22};
u8 gLanguagePathBuffer[64];

u8 *BuildFilePathWithLanguage(const u8 *path) {
    u32 language;

    strncpy((char *) gLanguagePathBuffer, (const char *) path, 0x3f);
    if (path[5] == 0x78) {
        return gLanguagePathBuffer;
    }
    language = GetLanguageIndex();
    if (path[5] == 0x79 && language != 0) {
        return gLanguagePathBuffer;
    }
    gLanguagePathBuffer[5] = gLanguagePathLetters[language];
    return gLanguagePathBuffer;
}

u32 LoadFileToVram(void *path, void *loader) {
    u32 size;
    void *data;

    data = LoadFile(BuildFilePathWithLanguage(path), &size, 4);
    DC_FlushRange(data, size);
    ((void (*)(void *, u32, u32)) loader)(data, 0, size);
    DeleteLoadedFile(data);
}

void CreateObjectsForMenuPair(u32 a) {
    int firstValue[2];
    GetPrimaryMenuPair(firstValue, NULL);
    if (firstValue[0] == 1) {
        CreateMenuPairObjects(a);
        return;
    }
    if (firstValue[0] == 2) {
        ChangeMenuPairObjectImages(a);
    }
}

void CreateSlideButtonsForMenuPair(u32 variant) {
    int secondValue[2];
    GetPrimaryMenuPair(NULL, secondValue);
    if (secondValue[0] == 1) {
        CreateSlideButtons(variant);
    }
}

void PrintMessage(u32 messageIndex) {
    void *canvas;
    void *message;

    canvas = InitBgTextCanvas(0, 0);
    message = GetMessageEntry(gMessages, messageIndex);
    DrawCanvasTextRect(canvas, gPrintMessageRect[0], gPrintMessageRect[1], gPrintMessageRect[2], gPrintMessageRect[3],
                       2, GetLanguageTextFlags(), message);
    RequestBgTextCanvasUpload(canvas);
}

void PrintMessageAndText(u32 text, u32 messageIndex) {
    void *canvas;
    void *message;

    canvas = InitBgTextCanvas(0, 0);
    message = GetMessageEntry(gMessages, messageIndex);
    DrawCanvasTextRect(canvas, gPrintMessageAndTextRect[0], gPrintMessageAndTextRect[1], gPrintMessageAndTextRect[2],
                       gPrintMessageAndTextRect[3], 2, GetLanguageTextFlags(), message);
    DrawCanvasText((u32) canvas, gPrintMessageTextXPositions[GetLanguageIndex() * 2],
                   (gPrintMessageTextXPositions + 1)[GetLanguageIndex() * 2], 2, 0x209, text);
    RequestBgTextCanvasUpload(canvas);
}

u32 GetLanguageTextFlags(void) {
    u32 value0;
    u32 value1;
    value0 = GetLanguageIndex();
    value1 = (value0 << 2);
    value0 = (u32) &gLanguageTextFlags;
    value0 = *(const u32 *) ((value0) + (value1));
    return value0;
}
