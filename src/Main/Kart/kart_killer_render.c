#include "Main/Kart/kart_killer_render.h"
#include "Main/Kart/kart_call.h"
#include "code_020109c4.h"

void SetKillerItemRenderCallback(void *model) {
    NNS_G3dRenderObjSetCallBack(model, PlaceKartKillerEffectCallback, 0, 6, (u8) 3);
}

// Calls slot 8 of the kart's function table.
void CallKartReleaseFunction(struct Kart *kart) {
    u32 slotFunction = (*(u32 *) (((u32) kart) + (556)));
    u32 result = ((u32(*)(u32))(slotFunction))((u32) kart);
}
