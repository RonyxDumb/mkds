#pragma once

#include "types.h"

// One data set: the stations still expected and the stations whose data has arrived, then the data of every station.
typedef struct WMDataSet {
    // Stations whose data is still expected while the set fills; the stations of the share once it is finished.
    /* 00 */ u16 mAidBitmap;
    // Bit n is set when the data of station n has arrived in this set.
    /* 02 */ u16 mArrivedMembers;
    /* 04 */ u8 mData[0x1fc];
} WMDataSet;

// Work area of one data sharing, 0x820 bytes: four data sets, then the sequence numbers and the state.
// Values of WMDataSharingInfo.mStatus: not running, running, a send must be retried, or an error happened.
enum {
    DATA_SHARING_STATUS_STOPPED = 0,
    DATA_SHARING_STATUS_RUNNING = 1,
    DATA_SHARING_STATUS_RETRY_SEND = 4,
    DATA_SHARING_STATUS_FAILED = 5,
};

typedef struct WMDataSharingInfo {
    /* 000 */ WMDataSet mDs[4];
    /* 800 */ u16 mSeqNum[4];
    /* 808 */ u16 mWriteIndex;
    /* 80a */ u16 mSendIndex;
    /* 80c */ u16 mReadIndex;
    // Stations taking part, bit n for station n; 0 when no sharing is running.
    /* 80e */ u16 mMemberMask;
    // Bytes of data per station.
    /* 810 */ u16 mMemberDataSize;
    /* 812 */ u16 mStationNumber;
    /* 814 */ u16 mDataSetLength;
    // Port the sharing uses.
    /* 816 */ u16 mPort;
    /* 818 */ u16 mDoubleMode;
    /* 81a */ u16 mCurrentSeqNum;
    /* 81c */ u16 mStatus;
    /* 81e */ u16 mReserved;
} WMDataSharingInfo;

// Message passed to the data sharing callbacks. The first two members are the same as in WirelessMessage.
typedef struct PortCallbackMessage {
    /* 00 */ u16 mCommand;
    /* 02 */ u16 mResultCode;
    /* 04 */ u16 mState;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 *mData;
    /* 10 */ u16 mLength;
    /* 12 */ u16 mAid;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u16 mSeqNo;
    /* 1c */ WMDataSharingInfo *mArg;
    /* 20 */ u32 mUnk_20;
} PortCallbackMessage;

// Message passed to the data sharing send callback (the send layout of PortCallbackMessage).
typedef struct PortSendCallbackMessage {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mResultCode;
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u16 mPort;
    /* 0c */ u8 mUnk_0c[0xe];
    /* 1a */ u16 mSeqNo;
    /* 1c */ u8 mUnk_1c[4];
    /* 20 */ WMDataSharingInfo *mDataSharingInfo;
} PortSendCallbackMessage;

u8 *WmGetSharedDataAddress(WMDataSharingInfo *dsInfo, u32 aidBitmap, u8 *receiveBuf, u32 aid);
u8 *WM_GetSharedDataAddress(WMDataSharingInfo *dsInfo, WMDataSet *receiveData, u32 aid);
void WmDataSharingSendDataSet(WMDataSharingInfo *dsInfo, u32 delayed);
void WmDataSharingReceiveData(WMDataSharingInfo *dsInfo, u32 aid, const void *data);
void WmDataSharingReceiveCallback_Child(PortCallbackMessage *callback);
void WmDataSharingReceiveCallback_Parent(PortCallbackMessage *callback);
void WmDataSharingSetDataCallback(PortSendCallbackMessage *callback);
int WM_StepDataSharing(WMDataSharingInfo *dsInfo, void *sendData, WMDataSet *receiveData);
int WM_EndDataSharing(WMDataSharingInfo *dsInfo);
int WM_StartDataSharing(WMDataSharingInfo *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);
int WM_EndKeySharing(WMDataSharingInfo *buf);
int WM_StartKeySharing(WMDataSharingInfo *buf, u16 port);
