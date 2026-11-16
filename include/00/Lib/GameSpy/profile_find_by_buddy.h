#pragma once

#include "types.h"

typedef struct GPConnection GPConnection;
typedef struct GPIProfile GPIProfile;

GPIProfile *gpiFindBuddy(GPConnection *gpConnection, u32 buddyIndex);
