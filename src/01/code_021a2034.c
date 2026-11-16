#include "01/code_021a2034.h"

#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020b4000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void func_ov001_021a2300(Unk021a2300 *p) {
    s32 i;
    Unk021a2048 *o;
    RaceProgress *d;
    RandomState64 *b;

    if (p != NULL) {
        i = 0;
        while (i < p->field4 && (o = p->field0[i]) != NULL) {
            d = gRaceStatus;
            b = &d->mLocalRandom;
            b->mValue = (s64) b->mMultiplier * (s64) b->mValue + b->mIncrement;
            o->fieldA0 = (u16) (((s64) (b->mValue >> 32) * 0x46) >> 32);
            o->field2 &= ~2;
            o->field2 &= ~8;
            o->field66 = 0x1f;
            i++;
        }
    }
}

void func_ov001_021a2284(void *p0, Unk021a2048 *p1) {
    RaceProgress *d;
    RandomState64 *b;

    p1->fieldA0 -= 1;
    if (p1->fieldA0 < 0) {
        d = gRaceStatus;
        b = &d->mLocalRandom;
        b->mValue = (s64) b->mMultiplier * (s64) b->mValue + b->mIncrement;
        p1->fieldA0 = (u16) (((s64) (b->mValue >> 32) * 0x46) >> 32) + 0x46;
        if (!(p1->field2 & 0x12)) {
            ptcm_createEmitter(0x435, &p1->field4);
        }
    }
}

void *func_ov001_021a226c(void) {
    return mobj_createLogicPart(func_ov001_021a2300, func_ov001_021a2284, NULL);
}

void ComputePointAheadOfCamera(Unk021a2048 *o, Camera *g, Vec3 *out) {
    out->x = g->mPos.x + (s32) (((s64) g->mForward.x * 0x58000) >> 12);
    out->y = o->field4.y;
    out->z = g->mPos.z + (s32) (((s64) g->mForward.z * 0x58000) >> 12);
}

void func_ov001_021a2048(void *p0, Unk021a2048 *p1) {
    Camera *g;
    Vec3 v = {0, 0, 0};

    g = race_getCamera();
    switch (p1->fieldA0) {
        case 0:
            p1->fieldA0 = 1;
            switch (p1->field9C->field28) {
                case 0:
                    ptcm_createEmitter(0x400, &v);
                    ptcm_createEmitter(0x3ff, &v);
                    ptcm_createEmitter(0x402, &v);
                    ptcm_createEmitter(0x403, &v);
                    ptcm_createEmitter(0x404, &v);
                    ptcm_createEmitter(0x405, &v);
                    ptcm_createEmitter(0x406, &v);
                    ptcm_createEmitter(0x407, &v);
                    ptcm_createEmitter(0x408, &v);
                    ptcm_createEmitter(0x409, &v);
                    ptcm_createEmitter(0x40a, &v);
                    ptcm_createEmitter(0x40b, &v);
                    p1->fieldA4 = ptcm_createEmitter(0x42f, &g->mPos);
                    break;
                case 1:
                    break;
                case 2:
                    ptcm_createEmitter(0x43c, &v);
                    ptcm_createEmitter(0x439, &v);
                    ptcm_createEmitter(0x43a, &v);
                    ptcm_createEmitter(0x43b, &v);
                    ptcm_createEmitter(0x438, &v);
                    ptcm_createEmitter(0x43d, &v);
                    ptcm_createEmitter(0x43e, &v);
                    ptcm_createEmitter(0x43f, &v);
                    ComputePointAheadOfCamera(p1, g, &v);
                    p1->fieldA4 = ptcm_createEmitter(0x437, &v);
                    break;
            }
            break;
        case 1:
            switch (p1->field9C->field28) {
                case 0:
                    ptcm_setEmitterPosition(p1->fieldA4, &g->mPos);
                    break;
                case 1:
                    break;
                case 2:
                    ComputePointAheadOfCamera(p1, g, &v);
                    ptcm_setEmitterPosition(p1->fieldA4, &v);
                    break;
            }
            break;
    }
}

void *func_ov001_021a2034(void) {
    return mobj_createLogicPart(NULL, func_ov001_021a2048, NULL);
}
