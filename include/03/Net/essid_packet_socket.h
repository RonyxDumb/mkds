#pragma once

#include "types.h"

static inline u16 SwapBytes16_inline(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

typedef struct SOCConfig SOCConfig;

#include "03/Net/essid_packet_steps.h"

typedef struct SocketAddress SocketAddress;
typedef struct PacketTag PacketTag;
typedef struct SendPacketScratch SendPacketScratch;

// The state of a byte stream made from a table that key bytes permute: its two indices, the table and its entry count.
typedef struct KeyStreamState {
    /* 00 */ u32 mIndex;
    /* 04 */ u32 mSwapIndex;
    /* 08 */ u8 *mTable;
    /* 0c */ u32 mTableCount;
} KeyStreamState;

// A payload when the packet flags ask for the key stream: its length, two key bytes and the xored bytes.
typedef struct PayloadRecord {
    /* 00 */ u16 mLength;
    /* 02 */ u8 mKeyPrefix[2];
    /* 04 */ u8 mBytes[1];
} PayloadRecord;

// The header of a packet: its kind, payload length, flags, payload check byte, magic byte and tag.
typedef struct PacketHeader {
    /* 00 */ u16 mNonzeroWord;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mKind;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mPayloadLength;
    /* 0c */ u16 mFlags;
    /* 0e */ s8 mPayloadCrc;
    /* 0f */ s8 mMagicByte;
    /* 10 */ u8 mTag[8];
} PacketHeader;

// One item of an outgoing packet: its type, length, offset of the next item and value bytes.
typedef struct OutgoingPacketItem {
    /* 00 */ s8 mType;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mLength;
    /* 04 */ u16 mNextOffset;
    /* 06 */ u8 mValue[1];
} OutgoingPacketItem;

// A container of packet items: its length and the items.
typedef struct ItemContainer {
    /* 00 */ u8 mUnk_00;
    /* 02 */ u16 mLength;
    /* 04 */ u8 mItems[1];
} ItemContainer;

// The payload check byte, payload length, flags and tag that SendItemChainPacket collects for the header of the packet
// it sends.
typedef struct PacketFieldValues {
    /* 00 */ s8 mPayloadCrc;
    /* 02 */ s16 mPayloadLength;
    /* 04 */ s16 mFlags;
    /* 06 */ u8 mTag[8];
} PacketFieldValues;

// Values of ItemContainerView.mType, the type of the first item of a packet payload.
enum {
    PAYLOAD_ITEM_CHAIN = 1,
    PAYLOAD_ITEM_WANTED_MASK = 2,
    PAYLOAD_ITEM_STATUS = 7,
};

// Values of PacketItem.mType in the chain read by ParseItemChain. SLOT0 to SLOT2 copy the value to the 0x80-byte slot
// of that index; 3 and 4 are counts, handled alike (bare).
enum {
    CHAIN_ITEM_SLOT0,
    CHAIN_ITEM_SLOT1,
    CHAIN_ITEM_SLOT2,
    CHAIN_ITEM_DESTINATION_ADDRESS = 5,
    CHAIN_ITEM_ADDRESS_MASK,
};

// Type of the second item BuildTwoItemChain writes.
#define PACKET_ITEM_TRAILER 0x60

// Values of PacketItem.mType in the top-level items FindItemAndParseSubItems looks for.
enum {
    PACKET_GROUP_ITEM_SECOND = 8,
    PACKET_GROUP_ITEM_FIRST,
};

// Values of PacketItem.mType inside a group item.
enum {
    GROUP_SUB_ITEM_WEP_KEYS_5_BYTES = 3,
    GROUP_SUB_ITEM_WEP_KEYS_13_BYTES,
    GROUP_SUB_ITEM_SINGLE_VALUE_RECORD0,
    GROUP_SUB_ITEM_SINGLE_VALUE_RECORD1,
    GROUP_SUB_ITEM_SLOT_BYTES = 10,
};

// Values of PacketItem.mType inside a record item: the four WEP keys (SHORT up to 5 bytes, LONG up to 13) and the
// string of the record.
// Types 0x30 and 0x40 (strings 0x35 and 0x45) are handled alike and stay bare in ParseSingleValueItems.
enum {
    RECORD_ITEM_WEP_KEY_SHORT0 = 0x10,
    RECORD_ITEM_WEP_KEY_SHORT1,
    RECORD_ITEM_WEP_KEY_SHORT2,
    RECORD_ITEM_WEP_KEY_SHORT3,
    RECORD_ITEM_STRING_FIRST = 0x15,
    RECORD_ITEM_WEP_KEY_LONG0 = 0x20,
    RECORD_ITEM_WEP_KEY_LONG1,
    RECORD_ITEM_WEP_KEY_LONG2,
    RECORD_ITEM_WEP_KEY_LONG3,
    RECORD_ITEM_STRING_SECOND = 0x25,
};

// Type of the item CopyFirstItemValueIfSlotBytes copies.
#define SLOT_BYTES_ITEM 0x70

// One item of a packet payload: its type, length, offset of the next item and value bytes.
typedef struct PacketItem {
    /* 00 */ u8 mType;
    /* 02 */ u16 mLength;
    /* 04 */ u16 mNextOffset;
    /* 06 */ u8 mValue[1];
} PacketItem;

// A record with one value: its value length, string and value bytes.
typedef struct SingleValueRecord {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u32 mValueLength;
    /* 08 */ u8 mString[0x28];
    /* 30 */ u8 mValue[0x40];
} SingleValueRecord;

// A record with four values: its value length, a string and four WEP keys.
typedef struct FourValueRecord {
    /* 000 */ u8 pad_000[4];
    /* 004 */ u32 mValueLength;
    /* 008 */ u8 mString[0x28];
    /* 030 */ u8 mWepKeys[4][0x40];
} FourValueRecord;

// The parsed items of a packet: two four-value records and two single-value records.
typedef struct ParsedItems {
    /* 000 */ u8 pad_000[8];
    /* 008 */ FourValueRecord mFourValueRecord0;
    /* 138 */ FourValueRecord mFourValueRecord1;
    /* 268 */ SingleValueRecord mSingleValueRecord0;
    /* 2d8 */ SingleValueRecord mSingleValueRecord1;
    /* 348 */ u8 pad_348[8];
} ParsedItems;

typedef struct EssidEntryList EssidEntryList;
typedef struct EssidMelcoRequest EssidMelcoRequest;
typedef struct PacketTag PacketTag;
typedef struct PacketBuffer PacketBuffer;

// A packet: its kind, payload length, flags, payload check byte, tag and payload bytes.
typedef struct Packet {
    /* 00 */ u16 mNonzeroWord;
    /* 02 */ u8 pad_02[4];
    /* 06 */ u16 mKind;
    /* 08 */ u8 pad_08[2];
    /* 0a */ u16 mPayloadLength;
    /* 0c */ u16 mFlags;
    /* 0e */ u8 mPayloadCrc;
    /* 0f */ u8 mMagicByte;
    /* 10 */ PacketTag mTag;
    /* 18 */ u8 mPayload[1];
} Packet;

u16 NextRandomValue(void);
int GetStringLength(const void *string);
u16 SwapBytes16(u16 value);
u32 PacketSwapBytes32(u32 input);
u16 PacketSwapBytes16(u16 value);
u32 SwapBytes32(u32 input);
s32 CloseSocket(s32 descriptor);
s32 BindSocket(s32 id, SocketAddress *addr, u32 length);
s32 OpenSocket(s32 domain, s32 type, s32 protocol);
s32 SocketReturnArgument(s32 id, s32 unusedLevel, s32 unusedOption, void *value, s32 length);
s32 SendToSocket(s32 descriptor, void *buffer, s32 length, s32 flags, SocketAddress *address, u32 addressLength);
s32 PollSocketWithTimeout(s32 descriptorCount, PollEntry *set, void *unusedSecondSet, void *unusedThirdSet,
                          WaitTimeout *timeout);
s32 RecvFromSocket(s32 id, void *buffer, s32 length, s32 flags, SocketAddress *out, s32 *outLength);
void FillBytes(void *destination, s32 fillValue, u32 size);
void CopyBytes(void *destination, const void *source, u32 size);
s32 CompareBytes(const u8 *left, const u8 *right, s32 count);
s32 StopSocketsAndDisconnectEssid(void);
s32 StartSocketsWithAddress(u32 address, u32 mask, u32 router);
void FreeSocketMemory(u32 name, void *pointer, u32 size);
void *AllocSocketMemory(u32 name, int size);
void SwapBufferHalves(u8 *buffer, u32 size, u8 *scratch);
void XorSecondHalf(const s8 *key, u8 *buffer, s32 size);
void FillIndexXorKeyBytes(s32 round, s8 *output, s32 size, const s8 *key, s32 keyLength);
s32 XorAndSwapBytesWithKey(u8 *buffer, s32 size, const s8 *key, s32 keyLength);
void InitCrcTable(s32 unused, u32 *table);
u32 ComputeCrc(u32 crc, const u8 *bytes, s32 count, s32 tableBuilt, u32 *table);
u8 ComputeCrcLowByte(const u8 *bytes, s32 count);
u32 NextKeyStreamByte(KeyStreamState *state);
void XorWithKeyStream(KeyStreamState *state, u8 *dst, const u8 *src, u32 count);
void InitKeyStream(KeyStreamState *state, const u8 *key, u32 keyLength, u32 count);
s32 XorBytesWithKeyStreamAndCheckCrc(const u8 *src, u8 *dst, s32 length, u32 expectedCrc, const u8 *keyPrefix,
                                     const u8 *keyTail, s32 keyTailLength);
s32 XorBytesWithRandomKeyStreamAndComputeCrc(const u8 *src, u8 *dst, s32 length, s8 *crc, u8 *keyPrefix,
                                             const u8 *keyTail, s32 keyTailLength);
s32 SendPacket(void *packet, s32 length, u32 target, s32 descriptor);
void FillPacketHeader(void *buffer, s32 kind, s32 payloadLength, s32 flags, s8 payloadCrc, s8 byte0f,
                      const u8 *tagBytes);
void FillPayloadRecord(s32 useKeyStream, void *destination, const void *source, s16 *length, s16 *flags, s8 *crc);
s16 BuildTwoItemChain(void *buffer);
s32 SendFinishPacket(SendPacketScratch *buf, PacketTag *list, s32 descriptor);
s32 SendWantedMaskPacket(SendPacketScratch *buf, PacketTag *list, s32 descriptor);
s32 SendItemChainPacket(SendPacketScratch *buf, PacketTag *list, s32 descriptor);
s32 ReportStateAndSendPacketForMode(s32 mode, SendPacketScratch *buf, PacketTag *list, s32 id);
s32 IsKeyStreamAcceptedBitSet(u32 value);
s32 FindItemAndParseSubItems(s32 index, PacketItem *item, s32 remaining, ParsedItems *parsedItems, u8 *slots);
s32 CopyFirstItemValueIfSlotBytes(PacketItem *container, u8 *output);
s32 ParseSingleValueItems(PacketItem *container, SingleValueRecord *record);
s32 ParseFourValueItems(PacketItem *container, FourValueRecord *record);
u32 ReadLittleEndianValue(const u8 *bytes, s32 count);
s32 ParseItemChain(PacketItem *firstItem, u8 *slots);
s32 XorSwapAndCheckTag(PacketTag *expectedTag, PacketTag *incomingTag);
s32 CheckTagAgainstSavedBytesOrFirstRequest(s32 kind, const u8 *tag);
s32 CheckPacketAndXorPayload(Packet *packet);
s32 AdvanceStepForFinishReply(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list);
s32 AdvanceStepForRecordsReply(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list);
s32 AdvanceStepForItemChainReply(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list);
s32 AdvanceStepByKind(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list, s32 descriptor);
s32 ReportStateChange(s32 state);
void FillPacketTags(s32 count, PacketTag *tags, const u8 *tagBytes);
s32 FillEssidAossAndMelcoRequest(EssidMelcoRequest *request);
s32 CheckSingleEssidAossEntry(EssidEntryList *entryList);
s32 CheckBytesInRange0x20To0x7f(const u8 *bytes, s32 count);
s32 CheckAndCopyValueRecordsToRequest(ValueRecordsRequest *request);
s32 GetErrorCode(void);
