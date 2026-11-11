#include "00/code_021acfd8.h"
#include "00/code_021ad018.h"
#include "00/code_021ad734.h"

u32 resolve_sub(const char *name, int dnsServer, u32 queryId) {
    u32 address;
    if (dnsServer == 0) {
        return 0xffffffff;
    }
    CPS_SocUse();
    CPS_SocDatagramMode();
    CPS_SocBind(0, 0x35, dnsServer);
    address = resolve_common(name, 1, (u32) queryId);
    CPS_SocRelease();
    return address;
}
