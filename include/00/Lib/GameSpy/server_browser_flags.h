#pragma once

#include "types.h"

// Bits of SBServer.mStateFlags: which keys the server has, which query is pending, a timed-out query and a received
// reply (TimeoutOldQueries applies the timed-out bit and the pending clears to mFlags).
#define SERVER_STATE_HAS_BASIC_KEYS (1 << 0)
#define SERVER_STATE_HAS_FULL_KEYS (1 << 1)
#define SERVER_STATE_BASIC_QUERY_PENDING (1 << 2)
#define SERVER_STATE_FULL_QUERY_PENDING (1 << 3)
#define SERVER_STATE_QUERY_TIMED_OUT (1 << 4)
#define SERVER_STATE_ICMP_QUERY_PENDING (1 << 5)
#define SERVER_STATE_HAS_PING (1 << 6)

// Milliseconds a query may wait for its reply, and how long a local network scan waits for replies.
#define QUERY_TIMEOUT_MSEC 2500
#define LOCAL_SCAN_DURATION_MSEC 2000

// Bits of SBServer.mFlags: the flag byte of a server entry in the server list, which says which fields follow; the
// local scan also sets two of them itself.
#define SERVER_FLAG_UDP_QUERY 1
#define SERVER_FLAG_PRIVATE_IP 2
#define CONNECT_NEGOTIATE_FLAG 4
#define SERVER_FLAG_ICMP_IP 8
#define SERVER_FLAG_NOT_DEFAULT_PORT 16
#define SERVER_FLAG_NOT_DEFAULT_PRIVATE_PORT 32
#define SERVER_FLAG_HAS_KEY_VALUES 64
#define SERVER_FLAG_HAS_RULE_ENTRIES 128

// Kinds of update the browser asks the query engine for: a basic or a full query; the ICMP kind makes the engine do
// nothing.
#define SERVER_UPDATE_KIND_BASIC 0
#define SERVER_UPDATE_KIND_FULL 1
#define SERVER_UPDATE_KIND_ICMP 2

// Request type of a message the list sends to the master server, and the types of the messages the master server pushes
// to the list.
#define LIST_REQUEST_RELAY_TO_SERVER 2
#define LIST_MESSAGE_PUSH_KEY_LIST 1
#define LIST_IN_ADD_SERVER 2
#define LIST_MESSAGE_ECHO 3
#define LIST_IN_REMOVE_SERVER 4
#define LIST_IN_MAPLOOP 5
#define LIST_MESSAGE_PLAYER_SEARCH 6

// Bits of SBServerList.mQueryOptions.
#define LIST_OPTION_SKIP_SERVER_TABLE 2
#define LIST_OPTION_SEND_SOURCE_IP 8
#define LIST_OPTION_SEND_MAX_SERVERS 128

// Port value the master server sends in place of the default port when an error text follows.
#define LIST_ERROR_PORT 0xffff

// Port of the master server, as stored in network byte order (28910).
#define SB_MASTER_PORT_NETWORK_ORDER 0xee70

// First two bytes of a query for the query and reporting protocol.
#define QUERY_PACKET_FIRST_BYTE 0xFE
#define QUERY_PACKET_SECOND_BYTE 0xFD

// Reasons the server list gives its callback (SBListCallBackFn).
enum {
    SERVER_LIST_REASON_SERVER_ADDED,
    SERVER_LIST_REASON_SERVER_UPDATED,
    SERVER_LIST_REASON_SERVER_DELETED,
    SERVER_LIST_REASON_LIST_FINISHED,
    SERVER_LIST_REASON_DISCONNECTED,
    SERVER_LIST_REASON_QUERY_ERROR,
    SERVER_LIST_REASON_PUBLIC_IP_RECEIVED,
};

// Reasons the query engine gives its callback (SBEngineCallbackFn).
enum {
    QUERY_ENGINE_REASON_REPLY_PARSED,
    QUERY_ENGINE_REASON_QUERY_TIMED_OUT,
    QUERY_ENGINE_REASON_QUERY_LIST_EMPTY,
};

// Reasons the matching code gives the browser callback of a MatchingServerList.
enum {
    BROWSER_REASON_SERVER_ADDED,
    BROWSER_REASON_SERVER_UPDATED,
    BROWSER_REASON_SERVER_UPDATE_FAILED,
    BROWSER_REASON_SERVER_DELETED,
    BROWSER_REASON_UPDATE_COMPLETE,
    BROWSER_REASON_QUERY_ERROR,
};

// Values of the compareKind argument of SBServerListSort: how the values of the sort field are compared.
enum {
    SORT_COMPARE_INT,
    SORT_COMPARE_FLOAT,
    SORT_COMPARE_STRING,
    SORT_COMPARE_STRING_IGNORE_CASE,
};
