#include "00/code_021acfd8.h"
#include "00/code_021ad018.h"
#include "00/code_021ad734.h"

u32 resolve_sub(const char *name, int dnsServer, u32 queryId) {
    u32 address;
    if (dnsServer == 0) {
        return 0xffffffff;
    }
    func_ov000_021ae270();
    func_ov000_021ae2d8();
    func_ov000_021ae290(0, 0x35, dnsServer);
    address = resolve_common(name, 1, (u32) queryId);
    func_ov000_021ae258();
    return address;
}
