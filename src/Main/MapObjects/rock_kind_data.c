#include "Main/MapObjects/rock_kind_data.h"
#include "Main/MapObjects/rock.h"

const MapObjectKindData gRockKindData = {(s32 (*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithRock,
                                         (s32 (*)(MapObject *, void *, void *, void *)) CollideItemObjectWithRock,
                                         1,
                                         0x1b000,
                                         0,
                                         0,
                                         NULL,
                                         1,
                                         1,
                                         0x17a,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0,
                                         0};
