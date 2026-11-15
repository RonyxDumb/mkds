#include "geometry_fast_dma_switch.h"
#include "particle_random_state.h"
#include "linked_palette_vram_alloc.h"
#include "microphone_sampling.h"
#include "linked_texture_vram_alloc.h"
#include "ITCM/g3d_texture_matrix.h"
#include "vram_alloc_joint_srt.h"
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
