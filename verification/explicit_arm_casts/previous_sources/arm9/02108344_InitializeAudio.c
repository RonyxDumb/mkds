/* Decompiled C draft; module arm9; ROM address 02108344. No matching claim. */
#include "types.h"
#include "deps/02108344_InitializeAudio.h"

/* WARNING: Removing unreachable block (ram,0x02108380) */
/* WARNING: Removing unreachable block (ram,0x02108388) */
/* WARNING: Removing unreachable block (ram,0x021083b4) */
/* WARNING: Removing unreachable block (ram,0x021083ac) */

void InitializeAudio(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  *puRam0210853c = 0;
  iVar5 = iRam0210854c;
  uVar2 = uRam02108558;
  if (param_3 == 0) {
    param_2 = param_2 - iRam02108540;
    *puRam02108554 = 2;
    param_2 = param_2 - iVar5;
    uVar2 = 0;
  }
  Sound_InitializeWithData(param_1,param_2,uVar2);
  func_021105d8();
  Sound_ReadSdatFromMemory(uRam0210855c,uRam02108560);
  Sound_MaybeSetActiveSdat(uRam02108564);
  puVar1 = puRam0210856c;
  iVar5 = iRam02108540;
  if (param_3 == 0) {
    uVar3 = uRam02108568 + 4 & 3;
    uVar4 = *(uint *)(uRam02108568 + 4 & 0xfffffffc);
    *puRam0210856c =
         *(uint *)(uRam02108568 & 0xfffffffc) >> (uRam02108568 & 3) * 8 |
         *(uint *)(uRam02108568 & 0xfffffffc) << (uRam02108568 & 3) * -8 + 0x20;
    puVar1[1] = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
    uVar2 = Sound_InitializeContext(param_1 + param_2,iVar5);
    iVar5 = iRam02108540;
    *puRam02108570 = uVar2;
    CreateSetGlobalCX(param_1 + param_2 + iVar5,iRam0210854c);
  }
  else {
    LoadCertainSwarSbnkSarc();
  }
  *puRam02108574 = 0x69;
  MaybeSendArm7SoundShit(1);
  func_020250a8();
  func_0210ef50();
  func_0210efac();
  func_0210ef5c();
  func_0210efac();
  iVar6 = 0;
  iVar5 = iRam02108578;
  do {
    func_0212c6a0(iVar5);
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar6 < 0xc);
  func_0210e2c4(uRam0210857c,uRam02108580,3,8);
  func_0212c6a0(uRam02108584);
  func_0212c6a0(uRam02108588);
  func_0212c6a0(uRam0210858c);
  func_0212ba68(0x7f);
  func_0212ba34(0);
  func_0210d970(0x1e);
  uVar3 = FX_Div(0x7f000,0x46000);
  puRam02108590[7] = uVar3;
  uVar3 = FX_Div(0x7f000,0x3c000);
  puVar1 = puRam02108590;
  puRam02108590[8] = uVar3;
  puVar1[5] = 0xff;
  puVar1[6] = 0x7f;
  uVar3 = (uint)(puVar1 + 7) & 3;
  uVar4 = *(uint *)((uint)(puVar1 + 7) & 0xfffffffc);
  *puVar1 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  puVar1[1] = 0;
  func_0210912c();
  *puRam02108594 = 0;
  func_0210b6a0();
  return;
}

