#include "Main/MapObjects/ob_pakkun_sf_list_data.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/pendulum.h"

const MapObjectList gObPakkunSfUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateObPakkunSf, NULL, 0, NULL, 0, NULL};
const MapObjectDrawList gObPakkunSfDrawListData = {{NULL,
                                                    0,
                                                    {0, 0},
                                                    (void (*)(MapObjectList *)) CreateObPakkunSf,
                                                    (void (*)(MapObjectList *)) SetupDrawObPakkunSf,
                                                    (MapObjectForEachCallback) DrawObPakkunSf,
                                                    NULL,
                                                    2,
                                                    NULL,
                                                    0,
                                                    NULL},
                                                   0};
const MapObjectKindData gObPakkunSfKindData = {
    (s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithObPakkunSf,
    (s32(*)(MapObject *, void *, void *, void *)) CollideItemObjectWithObPakkunSf,
    2,
    0x8000,
    0x12000,
    0,
    NULL,
    1,
    0,
    0x164,
    0,
    0,
    0,
    0,
    0,
    0};
