#pragma once

#include "types.h"

void AdvanceEmblem(void);
void AdvanceEmblemChoisesScreen(void);
void AdvanceEmblemCameraScreen(void);
void AdvanceEmblemTemplateScreen(void);
void AdvanceEmblemGridScreen(void);
void AdvanceEmblemKartList(void);
void ActivateEmblemEntry(s32 entryIndex, s32 isTouch);
void AdvanceEmblemFadeInAtGrid(void);
void AdvanceEmblemFadeOutToGrid(void);
void AdvanceEmblemFadeInAtCamera(void);
void AdvanceEmblemFadeOutToCamera(void);
void StartEmblemFadeOutToGrid(void);
void StartEmblemFadeOutToCamera(void);
void AdvanceEmblemTemplateSlideOut(void);
void StartEmblemTemplateSlideOut(void);
void AdvanceEmblemTemplateSlideIn(void);
void StartEmblemTemplateSlideIn(void);
void StopEmblemChoises(void);
void StartEmblemChoises(void);
void UploadEmblemCameraSubScreen(void);
void UploadEmblemSubScreen(void);
void UploadEmblemMainScreen(void);
