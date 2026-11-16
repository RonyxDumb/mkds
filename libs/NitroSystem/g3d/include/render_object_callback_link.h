#pragma once

#include "types.h"
#include "model_draw_state.h"

void StructML_SetSomeFields(NNSG3dRenderObj *pRenderObj, NNSG3dSbcCallBackFunc func, u8 *unused, u8 cmd,
                                 u32 timing);
void StructML_SomeFn_2(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj);
int removeLink_(NNSG3dAnmObj **head, NNSG3dAnmObj *item);
void StructML_SomeFn_3(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj);
void updateHintVec_(u32 *pVec, const NNSG3dAnmObj *pAnmObj);
void addLink_(NNSG3dAnmObj **head, NNSG3dAnmObj *item);
