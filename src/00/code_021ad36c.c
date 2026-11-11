#include "00/code_021ad36c.h"
#include "00/code_021ad3b8.h"
#include "00/code_021ad734.h"

BOOL dhcp_discover_server(void) {
    u32 queryId;
    int result;
    int retry;
    func_ov000_021ae270();
    func_ov000_021ae2d8();
    func_ov000_021ae290(0x44, 0x43, 0xffffffff);
    retry = 0;
    do {
        queryId = dhcp_send_discover();
        result = dhcp_analyze_response(queryId, retry);
        if (result == 1) {
            break;
        }
        retry = retry + 1;
    } while (retry < 4);
    func_ov000_021ae258();
    if (result == 1) {
        return 1;
    }
    return 0;
}
