#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;
typedef struct GpiProfile GpiProfile;

GpiProfile *GpiFindProfileByBuddyIndex(GpConnection *gpConnection, u32 buddyIndex);
