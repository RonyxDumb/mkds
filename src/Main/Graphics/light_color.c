#include "Main/Graphics/light_color.h"
#include "ITCM/model_draw_and_irq_handler.h"

void SendLight01Color(u16 *colorPtr) {
    u32 color;
    u32 lightOneColor;
    color = *colorPtr;
    NNS_G3dGeBufferOP_N(0x33, (void *) ((u32) (&color)), 1);
    lightOneColor = *colorPtr | 0x40000000;
    NNS_G3dGeBufferOP_N(0x33, (void *) ((u32) (&lightOneColor)), 1);
}

void SendWhiteLight01Color(void) {
    u32 color;
    u32 lightOneColor[1];
    color = (0x00007fffu);
    NNS_G3dGeBufferOP_N(0x33, (void *) ((u32) (&color)), 1);
    lightOneColor[0] = (0x40007fffu);
    NNS_G3dGeBufferOP_N(0x33, lightOneColor, 1);
}
