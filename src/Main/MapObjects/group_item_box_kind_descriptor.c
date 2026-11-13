#include "Main/MapObjects/group_item_box_kind_descriptor.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/group_item_box.h"

const Vec3 gItemBoxDefaultScale = {0x1000, 0x1000, 0x1000};
const MapObjectKindDescriptor gGroupItemBoxKindDescriptor = {
    0,
    {0, 0},
    0x140,
    InitGroupItemBox,
    CreateGroupItemBoxKindData,
    CreateItemBoxShadowDrawList,
    CreateQuestionDrawList,
    CreateBoxDrawList,
    CreateGroupItemBoxUpdateList,
    NULL,
    {NULL, NULL, NULL, NULL}};
