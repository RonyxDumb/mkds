#include "Main/MapObjects/kart_balloons_kind_descriptor.h"
#include "Main/MapObjects/shine16.h"

const MapObjectKindDescriptor gKartBalloonsKindDescriptor = {0,
                                                             {0, 0},
                                                             0x364,
                                                             InitKartBalloons,
                                                             CreateKartBalloonsKindData,
                                                             0,
                                                             0,
                                                             0,
                                                             CreateKartBalloonsUpdateList};
