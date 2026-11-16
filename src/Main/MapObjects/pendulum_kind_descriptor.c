#include "Main/MapObjects/pendulum_kind_descriptor.h"
#include "Main/MapObjects/pendulum.h"

const MapObjectKindDescriptor gPendulumKindDescriptor = {0,
                                                         {0, 0},
                                                         0x110,
                                                         InitPendulum,
                                                         CreatePendulumKindData,
                                                         (MapObjectList * (*) (void) ) CreatePendulumDrawList,
                                                         0,
                                                         0,
                                                         CreatePendulumUpdateList};
