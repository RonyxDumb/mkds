/* Decompiled C draft; module arm9; ROM address 02009ff4. No matching claim. */
#include "types.h"
#include "deps/02009ff4_SetupSomePointer_from_thumb.h"

undefined4
SetupSomePointer_from_thumb
          (int param_1,int param_2,undefined4 param_3,int param_4,undefined2 param_5)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 uVar3;
  short *psVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  uint uVar9;
  uint uVar10;
  int local_24;
  
  if ((*puRam0200a124 != 0) && (*(short *)(*puRam0200a124 + iRam0200a128) != 0)) {
    return 2;
  }
  uVar9 = param_1 + 0x1fU & 0xffffffe0;
  uVar10 = uVar9 + iRam0200a12c & 0xffffffe0;
  local_24 = param_4;
  if (param_4 == iRam0200a130) {
    local_24 = func_02142eac();
  }
  uVar3 = Os_DisableIrq();
  *puRam0200a134 = param_5;
  *puRam0200a138 = uVar9;
  *puRam0200a124 = uVar10;
  MIi_CpuClear32(0,uVar9,uRam0200a13c);
  Mem_CpuFill16(0,uVar10,uRam0200a140);
  puVar5 = (undefined2 *)(uVar9 + iRam0200a144);
  iVar7 = 0;
  iVar6 = param_2;
  if (*(char *)(param_2 + 1) != '\0') {
    do {
      *puVar5 = *(undefined2 *)(iVar6 + 2);
      puVar5 = puVar5 + 1;
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 2;
    } while (iVar7 < (int)(uint)*(byte *)(param_2 + 1));
  }
  puVar1 = puRam0200a14c;
  psVar8 = (short *)(uVar9 + iRam0200a148);
  iVar6 = 0;
  do {
    psVar4 = (short *)*puVar1;
    if (*psVar4 == 0) break;
    *puVar1 = psVar4 + 1;
    *psVar8 = *psVar4;
    psVar8 = psVar8 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  Mem_CpuCopy8(param_2,uVar10 + iRam0200a150,0x16);
  if (*(byte *)(param_2 + 1) < 10) {
    *(undefined2 *)(uVar10 + (uint)*(byte *)(param_2 + 1) * 2 + iRam0200a154) = 0;
  }
  *(short *)(uVar9 + iRam0200a15c) = (short)uRam0200a158;
  *(undefined2 *)(uVar9 + iRam0200a160) = 8;
  *(undefined2 *)(uVar9 + iRam0200a164) = 0;
  *(undefined2 *)(uVar9 + iRam0200a168) = 0;
  *(undefined2 *)(uVar9 + iRam0200a16c) = 1;
  *(uint *)(uVar9 + iRam0200a174) = uVar10 + iRam0200a170;
  *(undefined2 *)(uVar9 + 0xe) = 1;
  *(undefined2 *)(uVar9 + 0x12) = 0;
  *(undefined2 *)(uVar9 + 0x16) = 1;
  *(undefined2 *)(uVar9 + 0x14) = 0;
  *(undefined4 *)(uVar9 + 8) = param_3;
  *(short *)(uVar9 + 0xc) = (short)local_24;
  sVar2 = func_0200a184();
  *(short *)(uVar9 + 0x18) = sVar2 + 200;
  *(undefined2 *)(uVar9 + 0x10) = 0xf;
  *(undefined1 *)(uVar9 + iRam0200a178) = 0;
  *(undefined1 *)(uVar9 + iRam0200a17c) = 0;
  *(undefined2 *)(uVar10 + iRam0200a128) = 1;
  *(undefined4 *)(uVar10 + iRam0200a180) = 0;
  Os_RestoreIrq(uVar3);
  return 0;
}

