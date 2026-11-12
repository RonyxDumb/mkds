#pragma once

#include "types.h"

u32 CPS_Resolve(const char *name);

u32 resolve_sub(const char *name, int dnsServer, u32 queryId);

BOOL rawip(const char *name, u32 *address);
u32 strtol10(const char *text, const char **end);
s32 resolve_common(const char *a, u32 b, s32 c);
u8 *dns_skipname(u8 *name);
void dhcp_release_server(void);
BOOL dhcp_request_server(u32 *sleep, s32 mode);

BOOL dhcp_discover_server(void);

s32 dhcp_analyze_response(u32 queryId, s32 retry);
u32 dhcp_send_request(s32 mode);
u32 dhcp_send_discover(void);
