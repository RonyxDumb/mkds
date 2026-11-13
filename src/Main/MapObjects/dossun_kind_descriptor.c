#include "Main/MapObjects/dossun_kind_descriptor.h"
#include "Main/MapObjects/dossun.h"

const Vec3 gKuriboItemNormal = {0, 0x1000, 0};
const MapObjectKindDescriptor gDossunKindDescriptor = {0,
                                                       {0, 0},
                                                       0x10c,
                                                       InitDossun,
                                                       CreateDossunKindData,
                                                       (MapObjectList *(*)(void)) CreateDossunDrawList,
                                                       0,
                                                       0,
                                                       CreateDossunUpdateList};
