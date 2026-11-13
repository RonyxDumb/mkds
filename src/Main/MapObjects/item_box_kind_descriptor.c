#include "Main/MapObjects/item_box_kind_descriptor.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/earthen_pipe_create.h"

const u16 gItemBoxTriangleFlag2Flag = 0x20;
const u32 gItemBoxInitDistanceFlag = 0x10;
const MapObjectKindDescriptor gItemBoxKindDescriptor = {0,
                                                        {0, 0},
                                                        0x108,
                                                        (void (*)(void *, CourseMapRow *, void *)) InitItemBox,
                                                        CreateItemBoxKindData,
                                                        CreateItemBoxShadowDrawList,
                                                        CreateQuestionDrawList,
                                                        CreateBoxDrawList,
                                                        CreateItemBoxUpdateList,
                                                        NULL,
                                                        {NULL, NULL, NULL, NULL}};
