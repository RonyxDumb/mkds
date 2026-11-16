#include "Main/Graphics/kart_entry_name_texture.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/message_screen.h"

#pragma thumb on

void RenderKartEntryNameToTexture(u32 kartIndex, void *texBuffer, u32 textValue, u32 outlineValue) {
    u16 *messageScreenCharBuffer;
    RenderKartEntryName(kartIndex);
    messageScreenCharBuffer = GetMessageScreenCharBuffer();
    PlotNibblePixels(messageScreenCharBuffer, texBuffer, textValue, outlineValue, SetPixel2Bit);
}

#pragma thumb off
