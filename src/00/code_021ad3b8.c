#include "00/code_021ad3b8.h"
#include "00/code_021a8878.h"
#include "00/code_021ad734.h"
#include "00/unk_021b6380.h"
#include "os_tick.h"

u32 dhcp_send_discover(void) {
    u32 queryId;
    u8 *cursor;
    u8 *message;

    message = gScavengerSendPayload;
    cursor = dhcp_setcommon(message, 1, &queryId);
    if (gOfferedMyIp != 0) {
        cursor[0] = 0x32;
        cursor[1] = 4;
        cursor[2] = (u16) (gOfferedMyIp >> 16) >> 8;
        cursor[3] = gOfferedMyIp >> 16;
        cursor[4] = (u16) gOfferedMyIp >> 8;
        cursor[5] = gOfferedMyIp;
        cursor += 6;
    }
    *cursor = 0xff;
    cursor++;
    cursor = pad_mem(0, 0x12c, cursor, cursor - message);
    CPS_SocWrite(message, cursor - message);
    return queryId;
}

u32 dhcp_send_request(s32 mode) {
    u32 queryId;
    u8 *cursor;
    u8 *message;

    message = gScavengerSendPayload;
    cursor = dhcp_setcommon(message, 3, &queryId);
    if (mode == 0) {
        cursor[0] = 0x32;
        cursor[1] = 4;
        cursor[2] = (u16) (gOfferedMyIp >> 16) >> 8;
        cursor[3] = gOfferedMyIp >> 16;
        cursor[4] = (u16) gOfferedMyIp >> 8;
        cursor[5] = gOfferedMyIp;
        cursor[6] = 0x36;
        cursor[7] = 4;
        cursor[8] = (u16) (CPSDhcpServerIp >> 16) >> 8;
        cursor[9] = CPSDhcpServerIp >> 16;
        cursor[10] = (u16) CPSDhcpServerIp >> 8;
        cursor[11] = CPSDhcpServerIp;
        cursor += 12;
    }
    *cursor = 0xff;
    cursor++;
    cursor = pad_mem(0, 0x12c, cursor, cursor - message);
    CPS_SocWrite(message, cursor - message);
    return queryId;
}

s32 dhcp_analyze_response(u32 queryId, s32 retry) {
    u32 startTick;
    s32 result;
    s32 waitTicks;
    u32 *dnsServers;
    u8 *reply;
    u8 *optionCursor;
    u8 *replyEnd;
    u32 assignedIp;
    u32 replyLength;
    s32 option;

    waitTicks = (retry + 1) * 15;
    startTick = OS_GetTick() >> 16;
    result = 0;
    dnsServers = CPSDnsIp;
    while (gLinkIsOn() != 0 && result == 0 && (s32) ((u32) (OS_GetTick() >> 16) - startTick) < waitTicks) {
        if (CPS_SocGetLength() == 0) {
            yield_thread();
            continue;
        }
        reply = CPS_SocRead(&replyLength);
        if (replyLength > 0xf0 && reply[0] == 2 &&
            queryId == ((u16) (*OFFSET_PTR(u16, reply, 4) >> 8 | *OFFSET_PTR(u16, reply, 4) << 8) << 16 |
                        (u16) (*OFFSET_PTR(u16, reply, 6) >> 8 | *OFFSET_PTR(u16, reply, 6) << 8)) &&
            maccmp((const u16 *) (reply + 0x1c), CPSMyMac) == FALSE) {
            result = 3;
            assignedIp = (u16) (reply[0x10] << 8 | reply[0x11]) << 16 | (u16) (reply[0x12] << 8 | reply[0x13]);
            replyEnd = reply + replyLength;
            if (reply[0xec] == 0x63 && reply[0xed] == 0x82 && reply[0xee] == 0x53) {
                optionCursor = reply + 0xf0;
                if (reply[0xef] == 0x63) {
                    while (optionCursor < replyEnd && (option = *optionCursor++) != 0xff) {
                        if (option == 0) {
                            continue;
                        }
                        switch (option) {
                            case 1:
                                CPSNetMask = (u16) (optionCursor[1] << 8 | optionCursor[2]) << 16 |
                                             (u16) (optionCursor[3] << 8 | optionCursor[4]);
                                break;
                            case 3:
                                CPSGatewayIp = (u16) (optionCursor[1] << 8 | optionCursor[2]) << 16 |
                                               (u16) (optionCursor[3] << 8 | optionCursor[4]);
                                break;
                            case 6:
                                if (optionCursor[0] < 8) {
                                    dnsServers[1] = 0;
                                } else {
                                    dnsServers[1] = (u16) (optionCursor[5] << 8 | optionCursor[6]) << 16 |
                                                    (u16) (optionCursor[7] << 8 | optionCursor[8]);
                                }
                                dnsServers[0] = (u16) (optionCursor[1] << 8 | optionCursor[2]) << 16 |
                                                (u16) (optionCursor[3] << 8 | optionCursor[4]);
                                break;
                            case 0x33:
                                gLeaseTime = (u16) (optionCursor[1] << 8 | optionCursor[2]) << 16 |
                                             (u16) (optionCursor[3] << 8 | optionCursor[4]);
                                break;
                            case 0x35:
                                switch (optionCursor[1]) {
                                    case 2:
                                        gOfferedMyIp = assignedIp;
                                        result = 1;
                                        break;
                                    case 5:
                                        CPSMyIp = assignedIp;
                                        result = 2;
                                        break;
                                }
                                break;
                            case 0x36:
                                CPSDhcpServerIp = (u16) (optionCursor[1] << 8 | optionCursor[2]) << 16 |
                                                  (u16) (optionCursor[3] << 8 | optionCursor[4]);
                                break;
                        }
                        optionCursor += *optionCursor + 1;
                    }
                }
            }
        }
        CPS_SocConsume(replyLength);
    }
    return result;
}
