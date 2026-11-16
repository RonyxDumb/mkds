#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;
typedef struct GpiProfile GpiProfile;

GpiProfile *gpiFindBuddy(GpConnection *gpConnection, u32 buddyIndex);
