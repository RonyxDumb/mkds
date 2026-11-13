#include "Main/MapObjects/koopa_block_kind_descriptor.h"
#include "Main/MapObjects/code_020e01f0.h"
#include "Main/MapObjects/koopa_block.h"

const u16 gKoopaBlockFlag = 1;
const MapObjectKindDescriptor gKoopaBlockKindDescriptor = {0,
                                                           {0, 0},
                                                           0x170,
                                                           InitKoopaBlock,
                                                           CreateKoopaBlockKindData,
                                                           (MapObjectList *(*)(void)) CreateKoopaBlockDrawList,
                                                           NULL,
                                                           NULL,
                                                           CreateKoopaBlockUpdateList,
                                                           NULL,
                                                           {NULL, NULL, NULL, NULL}};
