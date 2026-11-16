#include "Main/Unknown/code_020d2450.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffdee4.h"

void mobj_setDirectionFromFloor(void *mapObject) {
    int hit;
    u8 normal[12];
    u8 quaternion[20];
    hit = col_collide(((s32 *) (mapObject + 4)), NULL, 0, 0xa000, 8, 0xfffffffe, NULL, (normal), NULL, NULL, NULL,
                        NULL, NULL, NULL);
    if (hit != 0) {
        qrtn_fromForwardVec((Vec3 *) normal, ((u32 *) (void *) quaternion));
        qtrn_toMtx33(((s32 *) (mapObject + 0x28)), quaternion);
        return;
    }
}
