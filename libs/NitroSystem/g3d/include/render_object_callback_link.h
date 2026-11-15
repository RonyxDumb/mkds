#pragma once

#include "types.h"
#include "model_draw_state.h"

void NNS_G3dRenderObjSetCallBack(NNSG3dRenderObj *pRenderObj, NNSG3dSbcCallBackFunc func, u8 *unused, u8 cmd,
                                 u32 timing);
void NNS_G3dRenderObjRemoveAnmObj(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj);
int removeLink_(NNSG3dAnmObj **head, NNSG3dAnmObj *item);
void NNS_G3dRenderObjAddAnmObj(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj);
void updateHintVec_(u32 *pVec, const NNSG3dAnmObj *pAnmObj);
void addLink_(NNSG3dAnmObj **head, NNSG3dAnmObj *item);
