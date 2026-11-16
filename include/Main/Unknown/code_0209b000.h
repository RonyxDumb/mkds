#pragma once

#include "types.h"

typedef struct MapObjectModel MapObjectModel;

void mobj_loadNsbcaAnim(MapObjectModel *a, const char *b);
void *mobj_loadModel(void *a, const char *b);
void *mobj_loadTexAnimBillboardModel(void *a, const char *b, const char *c);
void *mobj_loadBillboardModel(void *a, const char *b);
void *mobj_loadShadowModel(void *a, const char *b);
void mobj_loadNsbtpAnim(MapObjectModel *a, const char *b);
void mobj_loadNsbtaAnim(MapObjectModel *a, const char *b);
