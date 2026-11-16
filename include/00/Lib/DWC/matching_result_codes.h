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
    sbe_noerror,
    sbe_socketerror,
    sbe_dnserror,
    sbe_connecterror,
    sbe_dataerror,
    sbe_allocerror,
    sbe_paramerror,
};

// Errors of the reporter: the result of starting it and the errors it reports to its add error callback.
enum {
    e_qrnoerror,
    e_qrwsockerror,
    e_qrbinderror,
    e_qrdnserror,
    e_qrconnerror,
    e_qrnochallengeerror,
};

// Errors of starting a NAT negotiation.
enum {
    ne_noerror,
    ne_allocerror,
    ne_socketerror,
    ne_dnserror,
};

// Results of a NAT negotiation.
enum {
    nr_success,
    nr_deadbeatpartner,
    nr_inittimeout,
    nr_unknownerror,
};

// Results of gt2Connect and gti2CreateSocket.
enum {
    GT2Success,
    GT2OutOfMemory,
    GT2Rejected,
    GT2NetworkError,
    GT2AddressError,
    GT2DuplicateAddress,
    GT2TimedOut,
    GT2NegotiationError,
};

// Results of the stats connect calls.
enum {
    GE_NOERROR,
    GE_NOSOCKET,
    GE_NODNS,
    GE_NOCONNECT,
    GE_BUSY,
    GE_DATAERROR,
    GE_CONNECTING,
    GE_TIMEDOUT,
};

// Results of the service availability check.
enum {
    GSIACWaiting,
    GSIACAvailable,
    GSIACUnavailable,
    GSIACTemporarilyUnavailable,
};

// Why a connection was closed.
enum {
    GT2LocalClose,
    GT2RemoteClose,
    GT2CommunicationError,
    GT2SocketError,
    GT2NotEnoughMemory,
};
