#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct MissionRunPrm MissionRunPrm;
typedef struct Unk02188950 Unk02188950;
typedef struct Unk0218d87c Unk0218d87c;

void *hchan_setupBodyLogicPart(void);
void *hchan_setupBodyRenderPart(void);
void hchan_setupBodyCollision(void);
void *hchan_setupHeadLogicPart(void);
void *hchan_setupHeadRenderPart(void);
void hchan_setupHeadCollision(void);
void RenderHanachan(void *a, Unk02188950 *b);
void LoadHanachan_1234(Unk0218d87c *d);
void LoadHanachan(Unk0218d87c *a);
void func_ov001_0218cbdc(Unk02188950 *a, MissionRunPrm *b);
void hchan_initBody(Unk02188950 *a);
void hchan_initHead(Unk02188950 *e);
void func_ov001_0218ce30(u32 a, Unk02188950 *b);
void func_ov001_0218ce90(Unk0218d87c *a);
void UpdateHanachan(u32 a, Unk02188950 *b);
void InitHanachanObjects(Unk0218d87c *a);
void func_ov001_0218cfe8(Unk02188950 *a);
void func_ov001_0218d01c(Unk02188950 *a);
void func_ov001_0218d050(Unk02188950 *a);
void func_ov001_0218d074(Unk02188950 *a);
void func_ov001_0218d0a8(Unk02188950 *a);
void func_ov001_0218d0d4(Unk02188950 *a);
s32 func_ov001_0218d0fc(Unk02188950 *a);
s32 func_ov001_0218d16c(Unk02188950 *a);
void func_ov001_0218d188(Unk02188950 *a);
void func_ov001_0218d1bc(Unk02188950 *a);
void func_ov001_0218d1e0(Unk02188950 *a);
void func_ov001_0218d214(Unk02188950 *a);
void func_ov001_0218d23c(Unk02188950 *a);
s32 func_ov001_0218d264(Unk02188950 *a);
void func_ov001_0218d280(void);
void func_ov001_0218d2c4(Unk02188950 *a);
