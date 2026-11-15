#include "gecom.h"
#include "data_02173000.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h"
#include "gfd_LinkedListTexVramMan.h"
#include "ITCM/code_01ff9320.h"
#include "code_02015eb8.h"
#include "ITCM/kart_ground_contact.h"

void (*NNS_G3dSendTexSRT_FuncArray[4])(NNSG3dMatAnmResult *) = {NNSi_G3dSendTexSRTMaya, NULL, NULL, NULL};
void (*NNS_G3dSendJointSRT_FuncArray[3])(NNSG3dJntAnmResult *) = {
    (void (*)(NNSG3dJntAnmResult *)) NNSi_G3dSendJointSRTBasic, NNSi_G3dSendJointSRTMaya, NULL};
NNSG3dGetJointScale NNS_G3dGetJointScale_FuncArray[3] = {
    (void (*)(NNSG3dJntAnmResult *, void *, u8 *, u32)) NNSi_G3dGetJointScaleBasic,
    (void (*)(NNSG3dJntAnmResult *, void *, u8 *, u32)) NNSi_G3dGetJointScaleMaya, NULL};

vu32 NNS_G3dFlagGXDmaAsync;
BOOL NNS_G3dFlagUseFastDma;
GxCommandBuffer *NNS_G3dGeBuffer;

// Selects the fast DMA transfer for display lists when set.
void NNS_G3dGeUseFastDma(BOOL enabled) {
    NNS_G3dFlagUseFastDma = enabled;
}
