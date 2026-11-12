#include "01/MapObjects/map_object_nsbtp_frame.h"

#include "01/code_0218dce4.h"
#include "01/MapObjects/map_object_animation.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "01/code_02181000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"

u32 GetMapObjectNsbtpFrameIndex(MissionRunMapObject *mapObject) {
    return GetMapObjectModelNsbtpFrameIndex(mapObject->mNsbmd);
}
