#pragma once

#include "types.h"

s32 dhcp_analyze_response(u32 queryId, s32 retry);
u32 dhcp_send_request(s32 mode);
u32 dhcp_send_discover(void);
