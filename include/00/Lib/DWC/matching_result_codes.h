#pragma once

// Result codes of the profile, server browser, reporter, NAT negotiation, transport, stats connect and availability
// check calls, and why a transport connection closed, that the matching, login and friend code turn into their error
// codes.

// Results of the profile calls.
enum {
    GP_NO_ERROR,
    GP_MEMORY_ERROR,
    GP_PARAMETER_ERROR,
    GP_NETWORK_ERROR,
    GP_SERVER_ERROR,
};

// Errors of the server browser calls.
enum {
    SERVER_BROWSER_ERROR_NONE,
    SERVER_BROWSER_ERROR_SOCKET,
    SERVER_BROWSER_ERROR_HOST_LOOKUP,
    SERVER_BROWSER_ERROR_CONNECTION,
    SERVER_BROWSER_ERROR_BAD_DATA,
    SERVER_BROWSER_ERROR_NO_MEMORY,
    SERVER_BROWSER_ERROR_PARAM_TOO_LONG,
};

// Errors of the reporter: the result of starting it and the errors it reports to its add error callback.
enum {
    REPORTER_ERROR_NONE,
    e_qrwsockerror,
    e_qrbinderror,
    REPORTER_ERROR_HOST_LOOKUP,
    e_qrconnerror,
    REPORTER_ERROR_NO_CHALLENGE,
};

// Errors of starting a NAT negotiation.
enum {
    NAT_START_ERROR_NONE,
    NAT_START_ERROR_NO_MEMORY,
    ne_socketerror,
    NAT_START_ERROR_HOST_LOOKUP,
};

// Results of a NAT negotiation.
enum {
    NAT_RESULT_SUCCESS,
    NAT_RESULT_PARTNER_FAILED,
    NAT_RESULT_TIMED_OUT,
    NAT_RESULT_OTHER_ERROR,
};

// Results of gt2Connect and gti2CreateSocket.
enum {
    TRANSPORT_RESULT_OK,
    TRANSPORT_RESULT_NO_MEMORY,
    TRANSPORT_RESULT_REJECTED,
    TRANSPORT_RESULT_SOCKET_FAILED,
    TRANSPORT_RESULT_BAD_ADDRESS,
    TRANSPORT_RESULT_CONNECTION_EXISTS,
    TRANSPORT_RESULT_TIMED_OUT,
    TRANSPORT_RESULT_COMMUNICATION_ERROR,
};

// Results of the stats connect calls.
enum {
    GE_NOERROR,
    GE_NOSOCKET,
    GE_NODNS,
    GE_NOCONNECT,
    GE_BUSY,
    STATS_CONNECT_DATA_ERROR,
    GE_CONNECTING,
    GE_TIMEDOUT,
};

// Results of the service availability check.
enum {
    SERVICE_CHECK_PENDING,
    SERVICE_CHECK_AVAILABLE,
    SERVICE_CHECK_DISABLED_BIT_0,
    SERVICE_CHECK_DISABLED_BIT_1,
};

// Why a connection was closed.
enum {
    CLOSE_REASON_LOCAL,
    CLOSE_REASON_REMOTE,
    CLOSE_REASON_COMMUNICATION_ERROR,
    GT2SocketError,
    CLOSE_REASON_NO_MEMORY,
};
