#pragma once

#include "types.h"

typedef struct MissionGateObject MissionGateObject;

u16 func_ov001_02185b50(MissionGateObject *missionGateObject);
void menu_state18Vblank(void);
void menu_state18Render(void);
void func_ov001_02185ad8(u32 bits);
void func_ov001_02185abc(u32 bits);
void menu_state19Vblank(void);
void menu_state19Render(void);
void menu_ta_modeSelectStateVblank(void);
void menu_ta_setGhostReceive(s32 callbacksIndex);
void menu_ta_modeSelectStateRender(void);
void menu_ta_characterSelectStateVblank(void);
void menu_ta_characterSelectStateRender(void);
void menu_state22Vblank(void);
void menu_state22Render(void);
void menu_state23Vblank(void);
void func_ov001_021858b4(s32 value);
void func_ov001_021858a0(s32 value);
void menu_state23Render(void);
void menu_state25Vblank(void);
void menu_state25Render(void);
void WriteMainBg1Offset(u32 offsetX, u32 offsetY);
void func_ov001_021857a4(u32 bits);
