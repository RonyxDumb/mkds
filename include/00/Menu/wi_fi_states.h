#pragma once

#include "types.h"
#include "00/Menu/wi_fi_state_machine.h"

BOOL IsWiFiSessionOffOutsideLoginWrapper(void);

extern struct WiFiStates *gWiFiStates;
