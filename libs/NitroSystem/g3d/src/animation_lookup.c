#include "animation_lookup.h"
#include "animation_object_calc.h"

#pragma explicit_zero_data on
Vec3 gSbcBillboardPosition = {0, 0, 0};
Vec3 gSbcBillboardScale = {0, 0, 0};
#pragma explicit_zero_data off

NNSG3dResTexPatAnm *BTP0_LoadRawData(NNSG3dResTexPatAnmSet *pAnmSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pAnmSet->mDict, pAnmSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResTexPatAnm, pAnmSet, setEntry->mOffset);
}

NNSG3dResTexPatAnmSet *MaybeLoadBTP0Format(const u8 *pFileHead) {
    return Anim_LoadFindAnimationBlock(pFileHead, FILE_SIGNATURE_TEXTURE_PATTERN_ANIM, 0x30544150);
}

NNSG3dResTexSRTAnm *BTA0_LoadRawData(NNSG3dResTexSRTAnmSet *pTexSRTSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pTexSRTSet->mDict, pTexSRTSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResTexSRTAnm, pTexSRTSet, setEntry->mOffset);
}

NNSG3dResTexSRTAnmSet *MaybeLoadBTA0Format(const u8 *pFileHead) {
    return Anim_LoadFindAnimationBlock(pFileHead, FILE_SIGNATURE_TEXTURE_SRT_ANIM, 0x30545253);
}

NNSG3dResMatCAnm *BMA0_LoadRawData(NNSG3dResMatCAnmSet *pAnmSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pAnmSet->mDict, pAnmSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResMatCAnm, pAnmSet, setEntry->mOffset);
}

NNSG3dResMatCAnmSet *MaybeLoadBMA0Format(const u8 *pFileHead) {
    return Anim_LoadFindAnimationBlock(pFileHead, FILE_SIGNATURE_MATERIAL_COLOR_ANIM, 0x3054414d);
}

NNSG3dResJntAnm *JNT0_LoadJointByIdx(NNSG3dResJntAnmSet *pJntAnmSet, int idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pJntAnmSet->mDict, pJntAnmSet->mDict.mOfsEntry);
    setEntry = DICT_ENTRY(NNSG3dResDictAnmSetData, dictEntries, idx);
    return OFFSET_PTR(NNSG3dResJntAnm, pJntAnmSet, setEntry->mOffset);
}

NNSG3dResJntAnmSet *Anim_NSBCA_LoadGetJNT0Block(const u8 *pFileHead) {
    return Anim_LoadFindAnimationBlock(pFileHead, FILE_SIGNATURE_JOINT_ANIM, 0x30544e4a);
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
    if (resDict->mNumEntry < G3D_DICT_LINEAR_SEARCH_LIMIT) {
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
int Dict_SomeFn_0(const void *dict, const u32 *name) {
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
    if (resDict->mNumEntry < G3D_DICT_LINEAR_SEARCH_LIMIT) {
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

NNSG3dResDataBlockHeader *Anim_GetBlock(const NNSG3dResFileHeader *header, u32 idx) {
    u32 *blockOffsets;

    blockOffsets = OFFSET_PTR(u32, header, header->mHeaderSize);
    return OFFSET_PTR(NNSG3dResDataBlockHeader, header, blockOffsets[idx]);
}
