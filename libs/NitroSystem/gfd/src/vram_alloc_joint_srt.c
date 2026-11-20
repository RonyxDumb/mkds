#include "vram_alloc_joint_srt.h"
#include "ITCM/model_draw_and_irq_handler.h"

u32 AllocPlttVram_(u32 szByte, BOOL b4Pltt, u32 opt) {
    return 0;
}

s32 FreePlttVram_(u32 plttKey) {
    return -1;
}

u32 AllocTexVram_(u32 szByte, BOOL is4x4comp, u32 opt) {
    return 0;
}

s32 FreeTexVram_(u32 texKey) {
    return -1;
}

void NNSi_G3dSendJointSRTBasic(const NNSG3dJntAnmResult *result) {
    u32 flag;

    flag = result->mFlag;
    if ((flag & JOINT_RESULT_NO_MOVE) == 0) {
        if ((flag & JOINT_RESULT_NO_ROT) == 0) {
            NNS_G3dGeBufferOP_N(0x19, &result->mRot, 0xc);
        } else {
            NNS_G3dGeBufferOP_N(0x1c, &result->mTrans, 3);
        }
    } else if ((flag & JOINT_RESULT_NO_ROT) == 0) {
        NNS_G3dGeBufferOP_N(0x1a, &result->mRot, 9);
    }
    if ((result->mFlag & JOINT_RESULT_NO_SCALE) == 0) {
        NNS_G3dGeBufferOP_N(0x1b, &result->mScale, 3);
    }
}

void NNSi_G3dGetJointScaleBasic(NNSG3dJntAnmResult *pResult, const s32 *scale, const u8 *cmd, u32 srtflag) {
    if (srtflag & 4) {
        pResult->mFlag |= JOINT_RESULT_NO_SCALE;
    } else {
        pResult->mScale.x = scale[0];
        pResult->mScale.y = scale[1];
        pResult->mScale.z = scale[2];
    }
    pResult->mFlag |= JOINT_RESULT_NO_SCALE_BOTH_EX;
}
