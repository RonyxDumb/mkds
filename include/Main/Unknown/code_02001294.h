#pragma once

#include "types.h"

extern const char aCommon_bmg_36[];

void logo_eraseAllDoneMsgStateUpdate(void);
void logo_eraseAllDoneMsgStateInit(void);
void logo_eraseAllErasingMsgStateUpdate(void);
void logo_eraseAllErasingMsgStateInit(void);
void logo_eraseAllConfirmStateUpdate(void);
void logo_eraseAllConfirmStateInit(void);
void logo_corruptedDeletedMsgStateUpdate(void);
void logo_corruptedDeletedMsgStateInit(void);
void logo_corruptedErasingMsgStateUpdate(void);
void logo_corruptedErasingMsgStateInit(void);
void logo_corruptedMsgStateUpdate(void);
void logo_corruptedMsgStateInit(void);
void logo_waitSaveBusyStateUpdate(void);
