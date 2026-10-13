/* Decompiled C draft; module arm9_ov000; ROM address 021b02fc. No matching claim. */
#include "types.h"
#include "deps/021b02fc_FUN_021b02fc.h"

void FUN_021b02fc(undefined4 *param_1)

{
  longlong *plVar1;
  undefined4 uVar2;
  short extraout_r1;
  int iVar3;
  longlong lVar4;
  
  func_0x02000b44(DAT_021b0448);
  plVar1 = DAT_021b044c;
  iVar3 = param_1[6];
  if (iVar3 == 0 && param_1[5] == 0) {
    lVar4 = func_0x0200f5ac();
    plVar1 = DAT_021b044c;
    *DAT_021b044c = lVar4;
    uVar2 = DAT_021b0454;
    *(undefined4 *)(plVar1 + 1) = DAT_021b0450;
    *(undefined4 *)((int)plVar1 + 0xc) = uVar2;
    *(undefined4 *)(plVar1 + 2) = DAT_021b0458;
    *(undefined4 *)((int)plVar1 + 0x14) = 0;
  }
  else {
    *(undefined4 *)DAT_021b044c = param_1[5];
    *(int *)((int)plVar1 + 4) = iVar3;
    uVar2 = DAT_021b0454;
    *(undefined4 *)(plVar1 + 1) = DAT_021b0450;
    *(undefined4 *)((int)plVar1 + 0xc) = uVar2;
    *(undefined4 *)(plVar1 + 2) = DAT_021b0458;
    *(undefined4 *)((int)plVar1 + 0x14) = 0;
  }
  iVar3 = DAT_021b0464;
  if ((param_1[1] == 0) || (param_1[2] == 0)) {
    *DAT_021b045c = DAT_021b0464;
    *DAT_021b0460 = iVar3;
  }
  else {
    *DAT_021b045c = param_1[1];
    *DAT_021b0460 = param_1[2];
  }
  *DAT_021b0468 = *param_1;
  if (param_1[9] == 0) {
    *DAT_021b046c = (short)DAT_021b0470;
  }
  else {
    *DAT_021b046c = (short)param_1[9];
  }
  *DAT_021b0474 = param_1[10];
  *DAT_021b0478 = param_1[0xb];
  if (param_1[3] == 0) {
    *DAT_021b047c = DAT_021b0464;
  }
  else {
    *DAT_021b047c = param_1[3];
  }
  if (param_1[4] == 0) {
    *DAT_021b0480 = DAT_021b0484;
  }
  else {
    *DAT_021b0480 = param_1[4];
  }
  *DAT_021b0488 = param_1[7];
  *DAT_021b048c = param_1[8];
  *DAT_021b0490 = 0;
  *DAT_021b0494 = 0;
  lVar4 = func_0x02133048((int)DAT_021b044c[1],*(undefined4 *)((int)DAT_021b044c + 0xc),
                          (int)*DAT_021b044c,*(undefined4 *)((int)DAT_021b044c + 4));
  plVar1 = DAT_021b044c + 2;
  *DAT_021b044c = lVar4 + *plVar1;
  func_0x02133048((int)((ulonglong)(lVar4 + *plVar1) >> 0x20),0,DAT_021b0498,0);
  *DAT_021b04a0 = extraout_r1 + (short)DAT_021b049c;
  func_0x0200fe58(DAT_021b04a4);
  *DAT_021b04a8 = 0;
  func_0x0200e28c(DAT_021b04b4,DAT_021b04b8,0,DAT_021b04bc,DAT_021b04ac,*DAT_021b04b0);
  func_0x0200e28c(DAT_021b04c0,DAT_021b04c4,0,DAT_021b04c8,DAT_021b04ac,*DAT_021b04b0);
  func_0x0200df68(DAT_021b04b4);
  func_0x0200df68(DAT_021b04c0);
  return;
}

