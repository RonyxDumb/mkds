#include "Main/MapObjects/bridge_kind_descriptor.h"
#include "Main/MapObjects/rotary.h"
#include "Main/MapObjects/bridge.h"

const u16 gBridgeInitFlag = 1;
const MapObjectKindDescriptor gBridgeKindDescriptor = {0,
                                                       {0, 0},
                                                       0x158,
                                                       (void (*)(void *, CourseMapRow *, void *)) InitBridge,
                                                       CreateBridgeKindData,
                                                       (MapObjectList *(*)(void)) CreateBridgeDrawList,
                                                       NULL,
                                                       NULL,
                                                       CreateBridgeUpdateList,
                                                       NULL,
                                                       {NULL, NULL, NULL, NULL}};
