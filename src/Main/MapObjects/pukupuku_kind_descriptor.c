#include "Main/MapObjects/pukupuku_kind_descriptor.h"
#include "Main/MapObjects/pukupuku.h"
#include "Main/MapObjects/pukupuku_init.h"

const MapObjectKindDescriptor gPukupukuKindDescriptor = {0,
                                                         {0, 0},
                                                         0x10c,
                                                         (void (*)(void *, CourseMapRow *, void *)) InitPukupuku,
                                                         CreatePukupukuKindData,
                                                         (MapObjectList *(*)(void)) CreatePukupukuDrawList,
                                                         (MapObjectList *(*)(void)) CreatePukupukuShadowDrawList,
                                                         NULL,
                                                         CreatePukupukuUpdateList,
                                                         NULL,
                                                         {NULL, NULL, NULL, NULL}};
