#include "01/code_0219b250.h"

#include "01/unk_021a6000.h"
#include "Main/System/Heap.h"
#include "Main/System/ArchiveFiles.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/unk_021a9000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "code_02134398.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ea514.h"

const Vec3 data_ov001_021a6b20 = {4096, 4096, 4096};
const Vec3 data_ov001_021a6b2c = {4096, 4096, 4096};

void *func_ov001_0219b510(void *p0, void *p1, void *p2, u32 p3, u16 p4, u16 p5, u16 p6) {
    MapObjectKindData *r = mobj_createConfig(p0, p1, p2, p3, p4);
    r->field24 = p5;
    r->field28 = p6;
    r->field38 = 0x270f000;
    r->field3C = 0xfd8f1000;
    return r;
}

void *LoadFileInMissionRunFolder(const char *p0) {
    char buf[0x100];
    void *out = NULL;
    snprintf(buf, 0x100, "data/MissionRun/%s", p0);
    arc_loadFile(buf, proc_getHeap(proc_getCurrent()), &out);
    return out;
}

// Overlay-1 version of mobj_loadModel; the file comes from LoadFileInMissionRunFolder.
Unk0219b250 *LoadMapObjectModelAnimated(Unk0219b478 *p0, const char *p1) {
    Unk0219b250 *o = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    if (p0 != NULL) {
        p0->field18 = 1;
    }
    o->mNsbmdFile = LoadFileInMissionRunFolder((p1));
    o->mAnimatedModel = heap_alloc(proc_getHeap(proc_getCurrent()), 0x6c);
    model_initFromNsbmd(o->mAnimatedModel, o->mNsbmdFile);
    mobj_setModelFogEnableFlag(o, 0);
    o->mScale = data_ov001_021a6b2c;
    return o;
}

// Overlay-1 version of mobj_loadShadowModel; the file comes from LoadFileInMissionRunFolder.
Unk0219b250 *LoadMapObjectModelShadow(Unk0219b478 *p0, const char *p1) {
    Unk0219b250 *o = heap_alloc(proc_getHeap(proc_getCurrent()), 0x2c);
    void *r = LoadFileInMissionRunFolder((p1));
    if (p0 != NULL) {
        p0->field18 = 1;
    }
    o->mShadowModel = heap_alloc(proc_getHeap(proc_getCurrent()), 0x74);
    InitShadowModel(o->mShadowModel, r, 0x3f);
    mobj_setModelFogEnableFlag(o, 0);
    o->mScale = data_ov001_021a6b20;
    return o;
}

void LoadMapObjectModelNsbcaAnimation(Unk0219b250 *p0, const char *p1) {
    void *r = LoadFileInMissionRunFolder((p1));
    u8 v;
    p0->mNsbcaAnimation = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    v = NNS_G3dGetJntAnmSet(r)->mDict.mNumEntry;
    anim_initManager(0, p0->mNsbcaAnimation, p0->mAnimatedModel, v, proc_getHeap(proc_getCurrent()), p0->mNsbmdFile);
    anim_registerAllAnims(p0->mNsbcaAnimation, r, proc_getHeap(proc_getCurrent()));
    anim_setAnim(p0->mNsbcaAnimation, 0);
}

void LoadMapObjectModelNsbmaAnimation(Unk0219b250 *p0, const char *p1) {
    void *r = LoadFileInMissionRunFolder((p1));
    p0->mNsbmaAnimation = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    anim_20EA514(4, (p0->mAnimatedModel), (p0->mNsbmaAnimation), (p0->mNsbmdFile), (r));
}

void LoadMapObjectModelNsbtaAnimation(Unk0219b250 *p0, const char *p1) {
    void *r = LoadFileInMissionRunFolder((p1));
    u8 v;
    p0->mNsbtaAnimation = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    v = NNS_G3dGetTexSRTAnmSet(r)->mDict.mNumEntry;
    anim_initManager(1, p0->mNsbtaAnimation, p0->mAnimatedModel, v, proc_getHeap(proc_getCurrent()), p0->mNsbmdFile);
    anim_registerAllAnims(p0->mNsbtaAnimation, r, proc_getHeap(proc_getCurrent()));
    anim_setAnim(p0->mNsbtaAnimation, 0);
}

void LoadMapObjectModelNsbtpAnimation(Unk0219b250 *p0, const char *p1) {
    void *r = LoadFileInMissionRunFolder((p1));
    p0->mNsbtpAnimation = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    anim_20EA514(2, (p0->mAnimatedModel), (p0->mNsbtpAnimation), (p0->mNsbmdFile), (r));
}

void func_ov001_0219b28c(Unk0219b250 *p0, void *p1) {
    u8 v;
    p0->mNsbcaAnimation = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    v = NNS_G3dGetJntAnmSet(p1)->mDict.mNumEntry;
    anim_initManager(0, p0->mNsbcaAnimation, p0->mAnimatedModel, v, proc_getHeap(proc_getCurrent()), p0->mNsbmdFile);
    anim_registerAllAnims(p0->mNsbcaAnimation, p1, proc_getHeap(proc_getCurrent()));
    anim_setAnim(p0->mNsbcaAnimation, 0);
}

void func_ov001_0219b25c(Unk0219b250 *p0, void *p1) {
    p0->mNsbtpAnimation = heap_alloc(proc_getHeap(proc_getCurrent()), 0x38);
    anim_20EA514(2, (p0->mAnimatedModel), (p0->mNsbtpAnimation), (p0->mNsbmdFile), (p1));
}

void func_ov001_0219b250(Unk0219b250 *p0) {
    anim_update(p0->mNsbcaAnimation);
}
