#include "00/Lib/GameSpy/address_text_convert.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "string.h"
#include "print_memory_functions.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "narrow_string_functions.h"
#include "text_to_number.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"

char *gt2AddressToString(u32 ipAddress, u32 port, char *buffer) {
    SOCInAddr inAddress;
    char *addressString;
    static char strAddressArray[2][22];
    static s32 slotIndex;

    addressString = buffer;
    if (addressString == NULL) {
        slotIndex ^= 1;
        addressString = strAddressArray[slotIndex];
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
    return addressString;
}

BOOL gt2StringToAddress(const char *string, u32 *ipOut, u16 *portOut) {
    char hostCopy[0x100];
    const char *portSeparator;
    const char *portCursor;
    s32 value;
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
                value = portSeparator - string;
                if (value >= 0x100) {
                    AssertionFailed("len < GTI2_STACK_HOSTLEN_MAX", "gt2Utility.c", NULL, 0x81);
                }
                memcpy(hostCopy, string, value);
                hostCopy[value] = 0;
                string = hostCopy;
            }
            portCursor = portSeparator + 1;
            character = *(s8 *) (portSeparator + 1);
            if (character != 0) {
                do {
                    if (character < 0 || character >= 0x80) {
                        value = 0;
                    } else {
                        value = gCharClassFlags[character] & 8;
                    }
                    if (value == 0) {
                        return FALSE;
                    }
                    portCursor++;
                    character = *(s8 *) portCursor;
                } while (character != 0);
            }
            value = StrtolBase10(portSeparator + 1);
            if (value < 0 || value > 0xffff) {
                return FALSE;
            }
            sourcePort = (u16) value;
        }
        if (string != NULL) {
            sourceIp = inet_addr(string);
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
