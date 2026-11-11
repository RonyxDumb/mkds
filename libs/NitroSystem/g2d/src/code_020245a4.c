#include "code_020245a4.h"
#include "code_0200fc8c.h"

u16 NNSi_G2dSplitCharUTF16(u16 **stringPtr) {
    u16 *cursor;
    u16 character;

    cursor = *stringPtr;
    character = *cursor++;
    *stringPtr = cursor;
    return character;
}

static inline s32 NNSi_G2dIsBinFileSignatureValid(NNSG2dBinaryFileHeader *file) {
    if (file != 0 && file->mSignature == 0x4e465452) {
        return 1;
    }
    return 0;
}

static inline s32 NNSi_G2dIsBinFileVersionValid(NNSG2dBinaryFileHeader *file, u16 version) {
    if (file != 0 && file->mVersion == version) {
        return 1;
    }
    return 0;
}

static inline s32 NNS_G2dIsBinFileValid(NNSG2dBinaryFileHeader *file, u16 version) {
    if (file != 0) {
        return NNSi_G2dIsBinFileSignatureValid(file) && NNSi_G2dIsBinFileVersionValid(file, version);
    }
    return 0;
}

u16 NNSi_G2dSplitCharUTF8(u8 **stringPtr) {
    u8 *cursor;
    u16 character;

    cursor = *stringPtr;
    character = *cursor;
    if ((character & 0x80) == 0) {
        *stringPtr = cursor + 1;
    } else if ((character & 0xe0) == 0xc0) {
        character = ((character & 0x1f) << 6) | (cursor[1] & 0x3f);
        *stringPtr = cursor + 2;
    } else {
        character = ((character & 0x1f) << 12) | ((cursor[1] & 0x3f) << 6) | (cursor[2] & 0x3f);
        *stringPtr = cursor + 3;
    }
    return character;
}

u16 NNSi_G2dSplitCharShiftJIS(u8 **stringPtr) {
    u16 character;
    u8 *cursor;

    cursor = *stringPtr;
    character = *cursor;
    if ((character >= 0x81 && character < 0xa0) || character >= 0xe0) {
        character = cursor[1] | (character << 8);
        *stringPtr = *stringPtr + 2;
    } else {
        *stringPtr = *stringPtr + 1;
    }
    return character;
}

u16 NNSi_G2dSplitChar1Byte(u8 **stringPtr) {
    u8 *cursor;
    u8 character;

    cursor = *stringPtr;
    character = *cursor++;
    *stringPtr = cursor;
    return character;
}

u32 NNSi_G2dBitReaderRead(NNSiG2dBitReader *reader, s32 bitCount) {
    s32 availableBits;
    u32 bits;
    u32 result;
    u8 *src;

    availableBits = reader->mAvailableBits;
    bits = reader->mBits;
    if (availableBits < bitCount) {
        src = reader->mSrc;
        reader->mSrc = src + 1;
        result = bits << (bitCount - availableBits);
        reader->mBits = *src;
        reader->mAvailableBits = 8;
        result = NNSi_G2dBitReaderRead(reader, bitCount - availableBits) | result;
    } else {
        reader->mAvailableBits = availableBits - bitCount;
        result = bits >> (availableBits - bitCount);
    }
    return result & (0xff >> (8 - bitCount));
}

u32 NNSi_G2dGetUnpackedFont(NNSG2dBinaryFileHeader *file, NNSG2dFontInformation **fontOut) {
    u32 versionIndex;
    NNSG2dBinaryBlockHeader *part;

    if (NNS_G2dIsBinFileValid(file, 0x100)) {
        versionIndex = 0;
    } else if (NNS_G2dIsBinFileValid(file, 1)) {
        versionIndex = 1;
    } else {
        OS_Terminate();
    }
    NNSi_G2dUnpackNFT(file);
    part = FindPartByTag(file, 0x46494e46);
    if (part == 0) {
        *fontOut = 0;
        return 0;
    }
    *fontOut = (NNSG2dFontInformation *) (part + 1);
    if (versionIndex != 0) {
        (*fontOut)->mEncoding = (*fontOut)->mDefaultWidth.mCharWidth;
        (*fontOut)->mDefaultWidth.mCharWidth = 0;
    }
    return versionIndex + 1;
}

void NNSi_G2dUnpackNFT(NNSG2dBinaryFileHeader *file) {
    NNSG2dBinaryBlockHeader *block;
    s32 blockIndex;
    FontBlockData *blockData;

    block = OFFSET_PTR(NNSG2dBinaryBlockHeader, file, file->mHeaderSize);
    for (blockIndex = 0; blockIndex < file->mDataBlocks; blockIndex++) {
        switch (block->mKind) {
            case 0x46494e46:
                blockData = (FontBlockData *) (block + 1);
                blockData->mUnk_04[1] += (u32) file;
                if (blockData->mUnk_04[2] != 0) {
                    blockData->mUnk_04[2] += (u32) file;
                }
                if (blockData->mUnk_04[3] != 0) {
                    blockData->mUnk_04[3] += (u32) file;
                }
                break;
            case 0x43574448:
                blockData = (FontBlockData *) (block + 1);
                if (blockData->mUnk_04[0] != 0) {
                    blockData->mUnk_04[0] += (u32) file;
                }
                break;
            case 0x434d4150:
                blockData = (FontBlockData *) (block + 1);
                if (blockData->mUnk_04[1] != 0) {
                    blockData->mUnk_04[1] += (u32) file;
                }
                break;
            case 0x43474c50:
                break;
        }
        block = OFFSET_PTR(NNSG2dBinaryBlockHeader, block, block->mSize);
    }
}
