#include "code_0200c0d8.h"

#include "mb_data.h"
#include "code_0214d018.h"

u8 gLastPieceIndex;
struct MbRequestPieceBuf *gPieceBuffer;
PieceSizes gPieceSizes;

#pragma thumb on

void MBi_SetChildMPMaxSize(s32 packetSize) {
    gPieceSizes.mPieceSize = packetSize - 2;
    gPieceSizes.mPieceCount = 0x1e / gPieceSizes.mPieceSize;
    gPieceSizes.mBufSize = 0x1e;
}

#pragma thumb off

#pragma thumb on
void MBi_SetParentPieceBuffer(MbRequestPieceBuf *buffer) {
    gPieceBuffer = buffer;
    MI_CpuFill8(buffer, 0, sizeof(MbRequestPieceBuf));
}
#pragma thumb off

#pragma thumb on

void MBi_ClearParentPieceBuffer(s32 child) {
    s32 childIndex;

    if (gPieceBuffer != NULL) {
        childIndex = child - 1;
        MI_CpuFill8(&gPieceBuffer->mDataBuf[childIndex * 0x20], 0, 0x1e);
        gPieceBuffer->mDataBmp[childIndex] = 0;
    }
}

#pragma thumb off

#pragma thumb on

u8 *MBi_MakeParentSendBuffer(u8 *input, u8 *output) {
    ParentMessage *message;
    u8 *cursor;
    message = (ParentMessage *) input;
    cursor = output;
    *cursor++ = message->mKind;
    switch (message->mKind) {
        case 4:
            *cursor++ = message->mFid;
            *cursor++ = (message->mFid & 0xff00) >> 8;
            *cursor++ = message->mSeqno;
            *cursor++ = (message->mSeqno & 0xff00) >> 8;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            break;
        default:
            return NULL;
    }
    return cursor;
}

u8 *MBi_SetRecvBufferFromChild(u8 *bytes, ChildMessage *message, u32 child) {
    u8 *result;
    message->mKind = bytes[0];
    switch (message->mKind) {
        case 7:
            if (IsGetAllRequestData(child) != 0) {
                return &gPieceBuffer->mDataBuf[(child - 1) * 0x20];
            }
            *(u8 *) &message->mPieceRequest = bytes[1];
            if (*(u8 *) &message->mPieceRequest > gPieceSizes.mPieceCount) {
                return NULL;
            }
            MI_CpuCopy8(bytes + 2, (u8 *) message + 3, gPieceSizes.mPieceSize);
            result = MBi_ReceiveRequestDataPiece(message, child);
            break;
        case 8:
            message->mPieceRequest = bytes[1] & 0xff;
            result = bytes + 3;
            message->mPieceRequest |= (bytes[2] << 8) & 0xff00;
            break;
        case 9:
            message->mPieceRequest = bytes[1] & 0xff;
            result = bytes + 3;
            message->mPieceRequest |= (bytes[2] << 8) & 0xff00;
            MI_CpuCopy8(result, message->mData, gPieceSizes.mPieceSize);
            result += gPieceSizes.mPieceSize;
            break;
        default:
            return NULL;
    }
    return result;
}

u8 *MBi_ReceiveRequestDataPiece(ChildMessage *message, u32 child) {
    MbRequestPieceBuf *pieceBuffer;
    u8 pieceIndex;
    u32 slotOffset;
    u32 slotIndex;
    pieceBuffer = gPieceBuffer;
    if (pieceBuffer == NULL) {
        return NULL;
    }
    pieceIndex = *(u8 *) &message->mPieceRequest;
    if (pieceIndex > gPieceSizes.mPieceCount) {
        return NULL;
    }
    slotIndex = child - 1;
    slotOffset = slotIndex << 5;
    MI_CpuCopy8((u8 *) message + 3, (u8 *) pieceBuffer + slotOffset + pieceIndex * gPieceSizes.mPieceSize,
                gPieceSizes.mPieceSize);
    gPieceBuffer->mDataBmp[slotIndex] |= 1 << pieceIndex;
    if (IsGetAllRequestData(child) != 0) {
        return &gPieceBuffer->mDataBuf[slotOffset];
    }
    return NULL;
}

u32 IsGetAllRequestData(u32 child) {
    u16 pieceIndex;
    s32 pieceCount;
    u32 receivedMask;
    pieceIndex = 0;
    pieceCount = gPieceSizes.mPieceCount;
    if (pieceCount > 0) {
        receivedMask = gPieceBuffer->mDataBmp[child - 1];
        do {
            if (((1 << pieceIndex) & receivedMask) == 0) {
                return 0;
            }
            pieceIndex++;
        } while (pieceIndex < pieceCount);
    }
    return 1;
}

u8 *MBi_MakeChildSendBuffer(ChildMessage *message, u8 *buffer) {
    u8 *cursor;
    cursor = buffer;
    *cursor++ = message->mKind;
    switch (message->mKind) {
        case 7:
            *cursor++ = *(u8 *) &message->mPieceRequest;
            if (*(u8 *) &message->mPieceRequest > gPieceSizes.mPieceCount) {
                return NULL;
            }
            MI_CpuCopy8((u8 *) message + 3, cursor, gPieceSizes.mPieceSize);
            cursor += gPieceSizes.mPieceSize;
            break;
        case 9:
            *cursor++ = message->mPieceRequest;
            *cursor++ = (message->mPieceRequest & 0xff00) >> 8;
            MI_CpuCopy8(message->mData, cursor, gPieceSizes.mPieceSize);
            cursor += gPieceSizes.mPieceSize;
            break;
        case 8:
        case 10:
        case 11:
            break;
        default:
            return NULL;
    }
    return cursor;
}

u8 MBi_SendRequestDataPiece(void *output, void *pieces) {
    gLastPieceIndex = (gLastPieceIndex + 1) % gPieceSizes.mPieceCount;
    MI_CpuCopy8((u8 *) pieces + gLastPieceIndex * gPieceSizes.mPieceSize, output, gPieceSizes.mPieceSize);
    return gLastPieceIndex;
}

u8 *MBi_SetRecvBufferFromParent(ParentMessage *message, u8 *buffer) {
    u8 *highByte;
    message->mKind = *buffer++;
    switch (message->mKind) {
        case 4:
            message->mFid = buffer[0];
            message->mFid |= buffer[1] << 8;
            message->mSeqno = buffer[2];
            highByte = buffer + 3;
            buffer += 4;
            message->mSeqno |= *highByte << 8;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            break;
        default:
            return NULL;
    }
    return buffer;
}

#pragma thumb off
