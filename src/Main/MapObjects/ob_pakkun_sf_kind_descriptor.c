#include "Main/MapObjects/ob_pakkun_sf_kind_descriptor.h"
#include "Main/MapObjects/pendulum.h"
#include "Main/MapObjects/ob_pakkun_sf.h"

const MapObjectKindDescriptor gObPakkunSfKindDescriptor = {0,
                                                           {0, 0},
                                                           0xbc,
                                                           InitObPakkunSf,
                                                           CreateObPakkunSfKindData,
                                                           (MapObjectList * (*) (void) ) CreateObPakkunSfDrawList,
                                                           0,
                                                           0,
                                                           CreateObPakkunSfUpdateList};
