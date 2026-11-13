#include "Main/MapObjects/vehicle_kind_descriptor.h"
#include "Main/MapObjects/choropu.h"

const MapObjectKindDescriptor gCarAKindDescriptor = {0,
                                                     {0, 0},
                                                     0x164,
                                                     InitVehicle,
                                                     CreateCarAKindData,
                                                     CreateVehicleDrawList,
                                                     NULL,
                                                     NULL,
                                                     CreateVehicleUpdateList,
                                                     NULL,
                                                     {NULL, NULL, NULL, NULL}};
const MapObjectKindDescriptor gTruckAKindDescriptor = {0,
                                                       {0, 0},
                                                       0x164,
                                                       InitVehicle,
                                                       CreateTruckAKindData,
                                                       CreateVehicleDrawList,
                                                       NULL,
                                                       NULL,
                                                       CreateVehicleUpdateList,
                                                       NULL,
                                                       {NULL, NULL, NULL, NULL}};
const MapObjectKindDescriptor gBusAKindDescriptor = {0,
                                                     {0, 0},
                                                     0x164,
                                                     InitVehicle,
                                                     CreateBusAKindData,
                                                     CreateVehicleDrawList,
                                                     NULL,
                                                     NULL,
                                                     CreateVehicleUpdateList,
                                                     NULL,
                                                     {NULL, NULL, NULL, NULL}};
const VehicleKindInfo gCarAKindInfo = {0xc000, 0x14000, 0x15000,      0x13000,     0xc4cc, 0x4333, 0xb000,
                                       0x1000, &gCarA,  &gCarAShadow, &gCarANsbtp, 0x190,  0x1ae,  gCarAName};
const VehicleKindInfo gTruckAKindInfo = {0xd000, 0x28000,  0x21000,        0x1c000,       0xd999, 0x4b33, 0x14000,
                                         0x1333, &gTruckA, &gTruckAShadow, &gTruckANsbtp, 0x18f,  0x1ad,  gTruckAName};
const VehicleKindInfo gBusAKindInfo = {0x15000, 0x37000, 0x37000,      0x37000, 0x16333, 0x7800, 0x1f000,
                                       0x2000,  &gBusA,  &gBusAShadow, NULL,    0x18e,   0x1ac,  gBusAName};
char gBusAName[8] = "\x83\x6f\x83\x58";
char gCarAName[12] = "\x8f\xe6\x97\x70\x8e\xd4\x82\x60";
char gTruckAName[12] = "\x83\x67\x83\x89\x83\x62\x83\x4e\x82\x60";
const s32 gGroupFollowerSpeed = 0x3000;
