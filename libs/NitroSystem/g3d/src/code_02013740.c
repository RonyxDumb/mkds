#include "code_02013740.h"
#include "code_02013bdc.h"

#pragma explicit_zero_data on
Vec3 gSbcBillboardPosition = {0, 0, 0};
Vec3 gSbcBillboardScale = {0, 0, 0};
#pragma explicit_zero_data off

NNSG3dResTexPatAnm *NNS_G3dGetTexPatAnmByIdx(NNSG3dResTexPatAnmSet *pAnmSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pAnmSet->mDict, pAnmSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResTexPatAnm, pAnmSet, setEntry->mOffset);
}

NNSG3dResTexPatAnmSet *NNS_G3dGetTexPatAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30505442, 0x30544150);
}

NNSG3dResTexSRTAnm *NNS_G3dGetTexSRTAnmByIdx(NNSG3dResTexSRTAnmSet *pTexSRTSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pTexSRTSet->mDict, pTexSRTSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResTexSRTAnm, pTexSRTSet, setEntry->mOffset);
}

NNSG3dResTexSRTAnmSet *NNS_G3dGetTexSRTAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30415442, 0x30545253);
}

NNSG3dResMatCAnm *NNS_G3dGetMatCAnmByIdx(NNSG3dResMatCAnmSet *pAnmSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pAnmSet->mDict, pAnmSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResMatCAnm, pAnmSet, setEntry->mOffset);
}

NNSG3dResMatCAnmSet *NNS_G3dGetMatCAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30414d42, 0x3054414d);
}

NNSG3dResJntAnm *NNS_G3dGetJntAnmByIdx(NNSG3dResJntAnmSet *pJntAnmSet, int idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pJntAnmSet->mDict, pJntAnmSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResJntAnm, pJntAnmSet, setEntry->mOffset);
}

NNSG3dResJntAnmSet *NNS_G3dGetJntAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30414342, 0x30544e4a);
}

// Dictionaries of 16 or more entries are searched through their tree.
void *NNS_G3dGetResDataByName(const void *dict, const u32 *name) {
    const NNSG3dResDict *resDict;
    const NNSG3dResDictEntryHeader *dictEntries;
    const NNSG3dResDictTreeNode *base;
    const NNSG3dResDictTreeNode *prev;
    const NNSG3dResDictTreeNode *node;
    const u32 *entryName;
    u32 entryIndex;
    u32 nameWord0;
    u32 nameWord1;
    u32 nameWord2;
    u32 nameWord3;

    resDict = dict;
    if (resDict->mNumEntry < 0x10) {
        nameWord0 = name[0];
        nameWord1 = name[1];
        nameWord2 = name[2];
        nameWord3 = name[3];
        for (entryIndex = 0; entryIndex < resDict->mNumEntry; entryIndex++) {
            dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, resDict, resDict->mOfsEntry);
            entryName = DICT_ENTRY_NAME(dictEntries, entryIndex);
            if (entryName[0] == nameWord0 && entryName[1] == nameWord1 && entryName[2] == nameWord2 &&
                entryName[3] == nameWord3) {
                dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, resDict, resDict->mOfsEntry);
                return (dictEntries->mData + dictEntries->mSizeUnit * entryIndex);
            }
        }
    } else {
        base = resDict->mNode;
        prev = base;
        if (prev->mIdxLeft != 0) {
            node = base + prev->mIdxLeft;
            while (prev->mRefBit > node->mRefBit) {
                prev = node;
                node = base + (&node->mIdxLeft)[(name[node->mRefBit >> 5] >> (node->mRefBit & 0x1f)) & 1];
            }
            dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, resDict, resDict->mOfsEntry);
            entryName = DICT_ENTRY_NAME(dictEntries, node->mIdxEntry);
            if (entryName[0] == name[0] && entryName[1] == name[1] && entryName[2] == name[2] &&
                entryName[3] == name[3]) {
                dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, resDict, resDict->mOfsEntry);
                return (dictEntries->mData + dictEntries->mSizeUnit * node->mIdxEntry);
            }
        }
    }
    return 0;
}

// Dictionaries of 16 or more entries are searched through their tree.
int NNS_G3dGetResDictIdxByName(const void *dict, const u32 *name) {
    const NNSG3dResDict *resDict;
    const NNSG3dResDictEntryHeader *dictEntries;
    const NNSG3dResDictTreeNode *base;
    const NNSG3dResDictTreeNode *prev;
    const NNSG3dResDictTreeNode *node;
    const u32 *entryName;
    u32 entryIndex;
    u32 nameWord0;
    u32 nameWord1;
    u32 nameWord2;
    u32 nameWord3;

    resDict = dict;
    if (resDict->mNumEntry < 0x10) {
        nameWord0 = name[0];
        nameWord1 = name[1];
        nameWord2 = name[2];
        nameWord3 = name[3];
        for (entryIndex = 0; entryIndex < resDict->mNumEntry; entryIndex++) {
            dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, resDict, resDict->mOfsEntry);
            entryName = DICT_ENTRY_NAME(dictEntries, entryIndex);
            if (entryName[0] == nameWord0 && entryName[1] == nameWord1 && entryName[2] == nameWord2 &&
                entryName[3] == nameWord3) {
                return entryIndex;
            }
        }
    } else {
        base = resDict->mNode;
        prev = base;
        if (prev->mIdxLeft != 0) {
            node = base + prev->mIdxLeft;
            while (prev->mRefBit > node->mRefBit) {
                prev = node;
                node = base + (&node->mIdxLeft)[(name[node->mRefBit >> 5] >> (node->mRefBit & 0x1f)) & 1];
            }
            dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, resDict, resDict->mOfsEntry);
            entryName = DICT_ENTRY_NAME(dictEntries, node->mIdxEntry);
            if (entryName[0] == name[0] && entryName[1] == name[1] && entryName[2] == name[2] &&
                entryName[3] == name[3]) {
                return node->mIdxEntry;
            }
        }
    }
    return -1;
}

NNSG3dResDataBlockHeader *NNS_G3dGetDataBlockHeaderByIdx(const NNSG3dResFileHeader *header, u32 idx) {
    u32 *blockOffsets;

    blockOffsets = OFFSET_PTR(u32, header, header->mHeaderSize);
    return OFFSET_PTR(NNSG3dResDataBlockHeader, header, blockOffsets[idx]);
}
