#pragma once

#include "types.h"

typedef struct CPSSoc CPSSoc;

extern u32 (*gLinkIsOn)(void);

typedef struct OSThread OSThread;

// Frame start: two addresses and a type word.
typedef struct EthernetHeader {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u16 mEtherType;
} EthernetHeader;

typedef struct IpHeader {
    /* 00 */ u8 mVersionIhl;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mTotalLength;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u16 mFragOffset;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mProtocol;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mSourceAddressHigh;
    /* 0e */ u16 mSourceAddressLow;
    /* 10 */ u16 mDestAddressHigh;
    /* 12 */ u16 mDestAddressLow;
} IpHeader;

typedef struct UdpHeader {
    /* 00 */ u16 mSourcePort;
    /* 02 */ u16 mDestPort;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mChecksum;
} UdpHeader;

typedef struct TcpHeader {
    /* 00 */ u16 mSourcePort;
    /* 02 */ u16 mDestPort;
    /* 04 */ u16 mSeqNoHigh;
    /* 06 */ u16 mSeqNoLow;
    /* 08 */ u16 mAckNoHigh;
    /* 0a */ u16 mAckNoLow;
    /* 0c */ u8 mDataOffset;
    /* 0d */ u8 mFlags;
    /* 0e */ u16 mWindow;
    /* 10 */ u8 pad_10[4];
} TcpHeader;

typedef struct IpHeader IpHeader;
typedef struct TcpHeader TcpHeader;

typedef struct IcmpHeader {
    /* 00 */ u8 mType;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mChecksum;
    /* 04 */ u16 mIdentifier;
    /* 06 */ u16 mSequence;
} IcmpHeader;

typedef struct ArpPacket {
    /* 00 */ u16 mHardwareType;
    /* 02 */ u16 mProtocolType;
    /* 04 */ u16 mAddressLengths;
    /* 06 */ u16 mOperation;
    /* 08 */ u16 mSenderMac[3];
    /* 0e */ u16 mSenderAddressHigh;
    /* 10 */ u16 mSenderAddressLow;
    /* 12 */ u16 mTargetMac[3];
    /* 18 */ u16 mTargetAddressHigh;
    /* 1a */ u16 mTargetAddressLow;
} ArpPacket;

typedef struct CPSSoc CPSSoc;
typedef struct CPSArpCache CPSArpCache;

// Frame built by send_arprequest.
typedef struct ArpRequestFrame {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
    /* 16 */ u8 mUnk_16[6];
    /* 1c */ u16 mUnk_1c;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u8 mUnk_20[6];
    /* 26 */ u16 mUnk_26;
    /* 28 */ u16 mUnk_28;
} ArpRequestFrame;

typedef struct Unk021b0138 {
    /* 00 */ u8 pad_00[0xc];
    /* 0c */ u8 mUnk_0c[8];
} Unk021b0138;

extern void (*gDhcpCallback)(void);

// OSThread entry functions (not lifted yet).

#include "os_thread.h"

typedef struct CPSFragTable CPSFragTable;
typedef struct CPSConfig CPSConfig;

// Object linked from OSThread.mUnk_a4.
typedef struct Unk021b04f8 {
    /* 00 */ OSThread *mThread;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mState;
} Unk021b04f8;

#include "00/code_021a78a4.h"

extern u32 gIcmpEchoReplyEnabled;
extern u32 gHelperThreadsPriority;
extern u8 gMacBroadcast[6];
extern u8 gIpv4LlcSnapHeader[8];
extern u8 gSendFailed;
extern u16 gPingSequence;
extern u16 gMyMss;
extern u16 gEport;
extern u16 gIpId;
extern u32 CPSNetMask;
extern u32 gYieldWait;
extern u32 gWlanPutPnt;
extern u32 CPSGatewayIp;
extern u32 CPSMyIp;
extern OSThread *gReceiverThread;
// Objects whose layout isn't known yet.
extern u8 *gWlanBuf;
extern u32 gWlanBufLen;
extern u32 gWlanGetPnt;
// Objects whose layout isn't known yet.
extern u8 gTmpBufTcpHeader[];
extern CPSSoc gTmpSoc;
extern OSThread gScavengerThread;
extern OSThread gTcpipThread;
extern u8 gScavengerStackTop[];

u8 *pad_mem(u8 pattern, u32 minimum, u8 *position, u32 currentLength);
u8 *dhcp_setcommon(u8 *buffer, u8 type, u32 *transactionIdOut);
void scavenger(void);
void set_fixed_ip(void);
void CPS_SocFlush(void);
s32 CPS_SocGetLength(void);
s32 CPS_SocWrite(const u8 *buffer, s32 length);
s32 CPSi_SocWrite2(const u8 *buffer, s32 length, const u8 *secondBuffer, s32 secondLength);
s32 CPSi_TcpWrite2Raw(const u8 *buffer, u32 length, const u8 *secondBuffer, s32 secondLength, void *socketArgument);
void tcp_write_do2(const u8 *buffer, s32 length, const u8 *secondBuffer, s32 secondLength, CPSSoc *socket,
                   s32 probeFlag);
s32 tcp_write_do(const u8 *buffer, s32 length, CPSSoc *socket, s32 probeFlag);
void CPS_SocConsume(u32 length);
void CPSi_SocConsumeRaw(u32 length, CPSSoc *socket);
u8 *CPS_SocRead(u32 *length);
u8 *CPSi_TcpReadRaw(u32 *length, CPSSoc *socket);
u8 *udp_read_raw(u32 *length, CPSSoc *socket);
void CPS_TcpClose(void);
void CPS_TcpShutdown(void);
void CPSi_TcpShutdownRaw(CPSSoc *socket);
u32 CPS_SocWho(u16 *remotePort, u32 *localAddress);
u32 CPS_TcpConnect(void);
u32 CPSi_TcpConnectRaw(CPSSoc *socket);
void CPS_TcpListen(void);
void CPS_SetUdpCallback(Unk021a78a4Func callback);
void CPSi_TcpListenRaw(CPSSoc *socket);
void CPS_SocDup(OSThread *thread);
void CPS_SocRelease(void);
void CPS_SocUse(void);
void CPS_SocBind(int ownPort, u16 remotePort, int remoteAddress);
void CPS_SocDatagramMode(void);
void CPS_SocUnRegister(void);
void CPS_SocRegister(void *socket);
u32 get_seqno(void);
u16 CPS_SocGetEport(void);
void tcpip(void);
void dispatch_ip(IpHeader *packet, u32 length);
IpHeader *check_frag(IpHeader *packet, u32 *fragmented);
void dispatch_udp(IpHeader *ipHeader, UdpHeader *udpHeader, u32 length);
void dispatch_tcp(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length);
void dt_rst(const IpHeader *ipHeader, const TcpHeader *tcpHeader);
void dt_fin(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length);
void dt_ack(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length);
void dt_synack(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length);
void dt_syn(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length);
BOOL find_specific_socket(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length);
void dt_syn_listen(IpHeader *ipHeader, TcpHeader *tcpHeader, CPSSoc *socket);
void tcp_send_rst(IpHeader *ipHeader, TcpHeader *tcpHeader, u32 length, u16 urgent);
void tcp_send_finack(void *socket, u16 urgent);
void tcp_send_ack(void *socket, u16 urgent);
void tcp_send_handshake(CPSSoc *socket, u32 flag, u16 urgent);
u32 no_need_inq(u32 address);
void parse_mss(const TcpHeader *tcpHeader, CPSSoc *socket);
CPSSoc *find_socket(const IpHeader *ipHeader, const TcpHeader *tcpHeader);
BOOL check_socket(const IpHeader *ipHeader, const TcpHeader *tcpHeader, const CPSSoc *socket);
CPSSoc *check_listener(const IpHeader *ipHeader, const TcpHeader *tcpHeader);
void dispatch_icmp(IpHeader *ipHeader, IcmpHeader *icmp, u32 length);
BOOL valid_IP(int sourceAddress, int destAddress);
void process_icmp_reply(IpHeader *ipHeader, IcmpHeader *icmp, u32 length);
void reply_icmp(IpHeader *ipHeader, IcmpHeader *icmp, u32 length);
void dispatch_arp(ArpPacket *packet, u32 length);
void reply_arp(ArpPacket *packet);
void send_tcp(u8 *data, u32 length, CPSSoc *socket, u32 flag, u16 urgent);
void send_udp(u8 *data, u32 length, CPSSoc *socket);
void send_ping(u8 *pattern, u32 length, CPSSoc *socket);
void send_ip(u8 *header, u32 headerLength, u8 *body, u32 bodyLength, u32 addressTo, u8 protocol);
void send_ip_frag(u8 *header, u32 headerLength, void *body, u32 bodyLength, u32 addressTo, u32 offset);
void send_ether(u8 *header, u32 headerLength, void *body, u32 bodyLength, u32 addressTo, u16 type);
void reg_arpcache(u8 *mac, u32 address, u32 addedEntry);
u8 *arprequest(u32 address);
void send_arprequest(u32 address);
u8 *inq_arpcache(u32 address);
void throw_packet(void);
u8 *receive_packet(u32 *length);
void CPSi_RecvCallbackFunc(void *sourceAddress, void *destAddress, void *buffer, u16 size);
void put_in_buffer(const void *sourceAddress, const void *destAddress, u8 *firstBuffer, u32 firstSize,
                   void *secondBuffer, u32 secondSize);
void send_packet(u8 *header, u32 headerLength, const void *body, u32 bodyLength);
BOOL maccmp(const u16 *first, const u16 *second);
BOOL ip_isme(u32 address);
BOOL is_multicast(u32 address);
BOOL is_broadcast(u32 address);
u32 get_targetip(u32 address);
BOOL ip_islocal(u32 address);
BOOL check_tcpudpsum(const void *buffer, u32 length, const Unk021b0138 *header, u32 sum);
u16 calc_checksum(const void *buffer, u32 length);
u16 invert_checksum(u16 sum);
u32 calc_checksum_do(const void *buffer, u32 length, u32 sum);
void CPS_SetThreadPriority(s32 priority);
void CPS_Cleanup(void);
void CPS_SetScavengerCallback(UnkFunc *callback);
s32 CPS_CalmDown(void);
void CPS_Startup(CPSConfig *config);
BOOL default_link_is_on(void);
void empty_func(void);
void yield_thread(void);
void reset_network_vars(u32 reason);
