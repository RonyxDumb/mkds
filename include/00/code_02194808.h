#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;
typedef struct GpiProfile GpiProfile;

GpiProfile *GpiFindProfileByBuddyIndex(GpConnection *a, u32 b);
