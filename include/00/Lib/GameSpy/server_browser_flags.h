#pragma once

#include "types.h"

// Bits of SBServer.mStateFlags: which keys the server has, which query is pending, a timed-out query and a received
// reply (TimeoutOldQueries applies the timed-out bit and the pending clears to mFlags).
#define STATE_BASICKEYS (1 << 0)
#define STATE_FULLKEYS (1 << 1)
#define STATE_PENDINGBASICQUERY (1 << 2)
#define STATE_PENDINGFULLQUERY (1 << 3)
#define STATE_QUERYFAILED (1 << 4)
#define STATE_PENDINGICMPQUERY (1 << 5)
#define STATE_VALIDPING (1 << 6)

// Milliseconds a query may wait for its reply, and how long a local network scan waits for replies.
#define MAX_QUERY_MSEC 2500
#define SL_LAN_SEARCH_TIME 2000

// Bits of SBServer.mFlags: the flag byte of a server entry in the server list, which says which fields follow; the
// local scan also sets two of them itself.
#define UNSOLICITED_UDP_FLAG 1
#define PRIVATE_IP_FLAG 2
#define CONNECT_NEGOTIATE_FLAG 4
#define ICMP_IP_FLAG 8
#define NONSTANDARD_PORT_FLAG 16
#define NONSTANDARD_PRIVATE_PORT_FLAG 32
#define HAS_KEYS_FLAG 64
#define HAS_FULL_RULES_FLAG 128

// Kinds of update the browser asks the query engine for: a basic or a full query; the ICMP kind makes the engine do
// nothing.
#define QTYPE_BASIC 0
#define QTYPE_FULL 1
#define QTYPE_ICMP 2

// Request type of a message the list sends to the master server, and the types of the messages the master server pushes
// to the list.
#define SEND_MESSAGE_REQUEST 2
#define PUSH_KEYS_MESSAGE 1
#define PUSH_SERVER_MESSAGE 2
#define KEEPALIVE_MESSAGE 3
#define DELETE_SERVER_MESSAGE 4
#define MAPLOOP_MESSAGE 5
#define PLAYERSEARCH_MESSAGE 6

// Bits of SBServerList.mQueryOptions.
#define NO_SERVER_LIST 2
#define ALTERNATE_SOURCE_IP 8
#define LIMIT_RESULT_COUNT 128

// Port value the master server sends in place of the default port when an error text follows.
#define LIST_UNKNOWN_GAME_PORT 0xffff

// Port of the master server, as stored in network byte order (28910).
#define SB_MASTER_PORT_NETWORK_ORDER 0xee70

// First two bytes of a query for the query and reporting protocol.
#define QR2_MAGIC_1 0xFE
#define QR2_MAGIC_2 0xFD

// Reasons the server list gives its callback (SBListCallBackFn).
enum {
    slc_serveradded,
    slc_serverupdated,
    slc_serverdeleted,
    slc_initiallistcomplete,
    slc_disconnected,
    slc_queryerror,
    slc_publicipdetermined,
};

// Reasons the query engine gives its callback (SBEngineCallbackFn).
enum {
    qe_updatesuccess,
    qe_updatefailed,
    qe_engineidle,
};

// Reasons the matching code gives the browser callback of a MatchingServerList.
enum {
    sbc_serveradded,
    sbc_serverupdated,
    sbc_serverupdatefailed,
    sbc_serverdeleted,
    sbc_updatecomplete,
    sbc_queryerror,
};

// Values of the compareKind argument of SBServerListSort: how the values of the sort field are compared.
enum {
    sbcm_int,
    sbcm_float,
    sbcm_strcase,
    sbcm_stricase,
};
