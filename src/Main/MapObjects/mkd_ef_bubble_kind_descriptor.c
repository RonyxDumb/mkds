#include "Main/MapObjects/mkd_ef_bubble_kind_descriptor.h"
#include "Main/MapObjects/koopa_block.h"
#include "Main/MapObjects/group_item_box.h"

const u16 gMkdEfBubbleInitFlag = 0x200;
const MapObjectKindDescriptor gMkdEfBubbleKindDescriptor = {0,
                                                            {0, 0},
                                                            0xf4,
                                                            (void (*)(void *, CourseMapRow *, void *)) InitMkdEfBubble,
                                                            CreateMkdEfBubbleKindData,
                                                            (MapObjectList *(*)(void)) CreateMkdEfBubbleDrawList,
                                                            NULL,
                                                            NULL,
                                                            (MapObjectList *(*)(void)) CreateMkdEfBubbleUpdateList,
                                                            NULL,
                                                            {NULL, NULL, NULL, NULL}};
