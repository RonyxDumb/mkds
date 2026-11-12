#include "Main/MapObjects/dossun_list_data.h"
#include "Main/MapObjects/dossun.h"

const MapObjectList gDossunUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, (UnkFunc *) UpdateDossun,
                                             NULL, 0, NULL,   0,    NULL};
const struct DossunDrawList gDossunDrawListData = {{NULL,
                                                    0,
                                                    {0, 0},
                                                    (void (*)(MapObjectList *)) CreateDossunAndDossunShadow,
                                                    NULL,
                                                    (UnkFunc *) DrawDossun,
                                                    NULL,
                                                    1,
                                                    NULL,
                                                    0,
                                                    NULL},
                                                   0};
const MapObjectKindData gDossunKindData = {(s32(*)(MapObject *, void *, s32 *, s32 *)) CollideKartWithDossun,
                                           NULL,
                                           2,
                                           0x24000,
                                           0x2d000,
                                           0,
                                           NULL,
                                           1,
                                           2,
                                           0x18a,
                                           0,
                                           0,
                                           0,
                                           0,
                                           0,
                                           0};