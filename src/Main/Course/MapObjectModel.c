#include "Main/Course/MapObjectModel.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020ea514.h"

#pragma thumb on
void *mobj_loadModel(void *a, const char *b) {
    MapObjectModel *o;

    o = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->field18 = 1;
    }
    o->mNsbmdFile = mobj_getMapObjFile(b);
    o->mAnimatedModel = heap_alloc(proc_getHeap(proc_getCurrent()), 0x6c);
    model_initFromNsbmd(o->mAnimatedModel, o->mNsbmdFile);
    model_setEmi(o->mAnimatedModel, 0x294a);
    model_setLightEnableFlag(o->mAnimatedModel, 2);
    o->mScale = data_021565c4;
    return o;
}
#pragma thumb off

#pragma thumb on
void mobj_loadNsbcaAnim(MapObjectModel *a, const char *b) {
    void *x;

    x = mobj_getMapObjFile(b);
    a->mAnimations[0] = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    anim_20EA514(0, a->mAnimatedModel, a->mAnimations[0], a->mNsbmdFile, x);
}
#pragma thumb off

#pragma thumb on
void mobj_loadNsbtaAnim(MapObjectModel *a, const char *b) {
    void *x;

    x = mobj_getMapObjFile(b);
    a->mAnimations[3] = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    anim_20EA514(1, a->mAnimatedModel, a->mAnimations[3], a->mNsbmdFile, x);
}
#pragma thumb off

#pragma thumb on
void mobj_loadNsbtpAnim(MapObjectModel *a, const char *b) {
    void *x;

    x = mobj_getMapObjFile(b);
    a->mAnimations[1] = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    anim_20EA514(2, a->mAnimatedModel, a->mAnimations[1], a->mNsbmdFile, x);
}
#pragma thumb off

#pragma thumb on
void *mobj_loadShadowModel(void *a, const char *b) {
    MapObjectModel *o;
    void *x;

    o = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    x = mobj_getMapObjFile(b);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->field18 = 1;
    }
    o->mShadowModel = heap_alloc(proc_getHeap(proc_getCurrent()), 0x74);
    InitShadowModel(o->mShadowModel, x, 0x3f);
    o->mScale = data_021565b8;
    return o;
}
#pragma thumb off

#pragma thumb on
void *mobj_loadBillboardModel(void *a, const char *b) {
    MapObjectModel *o;
    void *x;
    NsbmdModel *m;

    o = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    x = mobj_getMapObjFile(b);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->field18 = 2;
    }
    o->mNsbmdModel = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    bbm_initFromNsbmd(o->mNsbmdModel, x, NULL, 0);
    m = o->mNsbmdModel;
    m->field10 &= 0x8000ffff;
    m->field10 |= 0x294a0000;
    m = o->mNsbmdModel;
    m->field14 &= ~0xf;
    m->field14 |= 2;
    o->mScale = data_021565ac;
    return o;
}
#pragma thumb off

#pragma thumb on
// Like mobj_loadBillboardModel with a second file, the .nsbtp (named like Init<Kind><Kind>).
void *mobj_loadTexAnimBillboardModel(void *a, const char *b, const char *c) {
    MapObjectModel *o;
    void *x;
    void *y;
    NsbmdModel *m;

    o = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    x = mobj_getMapObjFile(b);
    y = mobj_getMapObjFile(c);
    if (a != NULL) {
        ((Unk0209bc74_a *) a)->field18 = 2;
    }
    o->mNsbmdModel = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    bbm_initFromNsbmd(o->mNsbmdModel, x, y, 0);
    m = o->mNsbmdModel;
    m->field10 &= 0x8000ffff;
    m->field10 |= 0x294a0000;
    m = o->mNsbmdModel;
    m->field14 &= ~0xf;
    m->field14 |= 2;
    o->mScale = data_021565a0;
    return o;
}
#pragma thumb off
