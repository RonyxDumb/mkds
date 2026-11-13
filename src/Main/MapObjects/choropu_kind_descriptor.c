#include "Main/MapObjects/choropu_kind_descriptor.h"
#include "Main/MapObjects/bridge.h"
#include "Main/MapObjects/choropu.h"

const u16 gChoropuInitFlag = 0x200;
const MapObjectKindDescriptor gChoropuKindDescriptor = {0,
                                                        {0, 0},
                                                        0xf0,
                                                        InitChoropu,
                                                        CreateChoropuKindData,
                                                        (MapObjectList *(*)(void)) CreateChoropuDrawList,
                                                        (MapObjectList *(*)(void)) CreateChoropuShadowDrawList,
                                                        NULL,
                                                        CreateChoropuUpdateList,
                                                        NULL,
                                                        {NULL, NULL, NULL, NULL}};
