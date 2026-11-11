#pragma once

#include "types.h"

BOOL rawip(const char *name, u32 *address);
u32 strtol10(const char *text, const char **end);
s32 resolve_common(const char *a, u32 b, s32 c);
u8 *dns_skipname(u8 *name);
void dhcp_release_server(void);
BOOL dhcp_request_server(u32 *sleep, s32 mode);
