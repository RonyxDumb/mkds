#include "Main/MapObjects/pendulum_kind_descriptor.h"
#include "Main/MapObjects/pendulum.h"

const MapObjectKindDescriptor gPendulumKindDescriptor = {0,
                                                         {0, 0},
                                                         0x110,
                                                         (void (*)(void *, CourseMapRow *, void *)) InitPendulum,
                                                         CreatePendulumKindData,
                                                         (MapObjectList * (*) (void) ) CreatePendulumDrawList,
                                                         0,
                                                         0,
                                                         CreatePendulumUpdateList};
