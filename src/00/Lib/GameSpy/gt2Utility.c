#include "00/Lib/GameSpy/gt2Utility.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/unk_021b5000.h"
#include "00/code_021a8aa8.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/Lib/NitroWiFi/code_021a6d5c.h"

u32 gt2AddressToString(u32 ipAddress, u32 port, char *buffer) {
    SOCInAddr inAddress;
    char *addressString;

    addressString = buffer;
    if (addressString == NULL) {
        nIndex ^= 1;
        addressString = strAddressArray[nIndex];
    }
    if (ipAddress != 0) {
        inAddress.addr = ipAddress;
        if (port != 0) {
            sprintf(addressString, "%s:%d", SOC_InetNtoA(inAddress), port);
        } else {
            sprintf(addressString, "%s", SOC_InetNtoA(inAddress));
        }
    } else if (port != 0) {
        sprintf(addressString, ":%d", port);
    } else {
        addressString[0] = 0;
    }
    return (u32) addressString;
}

BOOL gt2StringToAddress(const char *string, u32 *ipOut, u16 *portOut) {
    char hostCopy[0x100];
    const char *portSeparator;
    const char *portCursor;
    s32 g;
    s32 character;
    u32 sourceIp;
    u32 sourcePort;
    SOCHostEnt *hostEntry;

    if (string == NULL || *(s8 *) string == 0) {
        sourceIp = 0;
        sourcePort = 0;
    } else {
        portSeparator = strchr(string, 0x3a);
        if (portSeparator == NULL) {
            sourcePort = 0;
        } else {
            if (portSeparator == string) {
                string = NULL;
                sourceIp = 0;
            } else {
                g = portSeparator - string;
                if (g >= 0x100) {
                    AssertionFailed("len < GTI2_STACK_HOSTLEN_MAX", "gt2Utility.c", NULL, 0x81);
                }
                memcpy(hostCopy, string, g);
                hostCopy[g] = 0;
                string = hostCopy;
            }
            portCursor = portSeparator + 1;
            character = *(s8 *) (portSeparator + 1);
            if (character != 0) {
                do {
                    if (character < 0 || character >= 0x80) {
                        g = 0;
                    } else {
                        g = gCharClassFlags[character] & 8;
                    }
                    if (g == 0) {
                        return FALSE;
                    }
                    portCursor++;
                    character = *(s8 *) portCursor;
                } while (character != 0);
            }
            g = StrtolBase10(portSeparator + 1);
            if (g < 0 || g > 0xffff) {
                return FALSE;
            }
            sourcePort = (u16) g;
        }
        if (string != NULL) {
            sourceIp = inet_addr((u32) string);
            if (sourceIp == -1) {
                hostEntry = SOC_GetHostByName(string);
                if (hostEntry == NULL) {
                    return FALSE;
                }
                sourceIp = **hostEntry->mAddrList;
            }
        }
    }
    if (ipOut != NULL) {
        *ipOut = sourceIp;
    }
    if (portOut != NULL) {
        *portOut = sourcePort;
    }
    return TRUE;
}
