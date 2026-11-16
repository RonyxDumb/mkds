#include "Main/Net/udp_socket_param.h"

SOCLSocketParam SOCLSocketParamUDP = {
    SOCKET_MODE_DATAGRAM_RECEIVE, 1, 0x5c0, 1, 0, 0, 0, 0, 0x2000, {0x800, 0xc, 8}, {0, 0, 0}};