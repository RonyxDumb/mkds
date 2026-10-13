/* Decompiled C draft; module arm9; ROM address 020092d0. No matching claim. */
#include "types.h"
#include "deps/020092d0_func_020092d0.h"

void func_020092d0(undefined4 param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  if (*(char *)(iRam02009454 + 0xe) != *(char *)(*(int *)(iRam02009454 + 4) + iRam02009458)) {
    func_02009494();
  }
  puVar7 = puRam0200945c;
  *(byte *)(puRam0200945c + 1) = *(byte *)(puRam0200945c + 1) & 0xfc | 2;
  iVar10 = iRam02009454;
  iVar6 = *(int *)(iRam02009454 + 4);
  *(undefined1 *)((int)puVar7 + 5) = *(undefined1 *)(iVar6 + iRam02009460);
  *(undefined1 *)((int)puVar7 + 6) = *(undefined1 *)(iVar10 + 0xe);
  puVar8 = (undefined4 *)(iVar6 + iRam02009464);
  *puVar7 = *puVar8;
  *(byte *)(puVar7 + 1) =
       *(byte *)(puVar7 + 1) & 3 | (byte)((*(byte *)(iVar6 + iRam02009468) & 0x3f) << 2);
  cVar1 = *(char *)(iVar10 + 0x11);
  *(char *)(iVar10 + 0x11) = cVar1 + '\x01';
  *(char *)((int)puVar7 + 7) = cVar1;
  *(undefined1 *)((int)puVar7 + 10) = *(undefined1 *)(iVar6 + iRam0200946c);
  *(undefined2 *)(puVar7 + 3) = *(undefined2 *)(iVar6 + iRam02009470);
  *(undefined2 *)((int)puVar7 + 0xe) = *(undefined2 *)(iVar6 + iRam02009474);
  if ((*piRam02009478 == 0) && ((code *)*puRam0200947c != (code *)0x0)) {
    (*(code *)*puRam0200947c)(*puVar8);
  }
  iVar10 = iRam02009480;
  iVar9 = 0;
  iVar6 = *(int *)(iRam02009454 + 4);
  puVar7 = puRam0200945c;
  do {
    *(undefined1 *)(puVar7 + 0x1a) = *(undefined1 *)(iVar6 + iVar10);
    iVar6 = iVar6 + 1;
    puVar7 = (undefined4 *)((int)puVar7 + 1);
    iVar9 = iVar9 + 1;
  } while (iVar9 < 8);
  Mem_CpuFill16(0,iRam02009484,0x58);
  uVar12 = 0;
  uVar2 = *(ushort *)(*(int *)(iRam02009454 + 4) + iRam02009488);
  uVar3 = *(ushort *)(*(int *)(iRam02009454 + 4) + iRam02009470);
  uVar11 = 0;
  iVar6 = 0;
  iVar10 = iRam02009484;
  do {
    uVar5 = 2 << (uVar11 & 0xff);
    if (((uVar2 ^ uVar3) & uVar5) != 0) {
      CopyMemory16(*(int *)(iRam02009454 + 4) + iRam0200948c + iVar6,iVar10,0x16);
      *(ushort *)(*(int *)(iRam02009454 + 4) + iRam02009488) =
           *(ushort *)(*(int *)(iRam02009454 + 4) + iRam02009488) | (ushort)uVar5;
      iVar10 = iVar10 + 0x16;
      uVar12 = uVar12 + 1;
      if (uVar12 == 4) break;
    }
    iVar6 = iVar6 + 0x16;
    uVar11 = uVar11 + 1;
  } while ((int)uVar11 < 0xf);
  if (uVar12 < 4) {
    *(byte *)(iRam02009484 + uVar12 * 0x16) = *(byte *)(iRam02009484 + uVar12 * 0x16) & 0xf;
  }
  *(undefined2 *)(puRam0200945c + 2) = 0;
  uVar4 = func_020088dc((ushort *)(uintptr_t)(uRam02009490),0x68);
  *(undefined2 *)(puRam0200945c + 2) = uVar4;
  if (*(short *)(*(int *)(iRam02009454 + 4) + iRam02009488) ==
      *(short *)(*(int *)(iRam02009454 + 4) + iRam02009470)) {
    *(undefined1 *)(iRam02009454 + 0xc) = 1;
  }
  func_021455a0(0,puRam0200945c,0x70,param_1,param_2,param_3 & 0xff | 2,param_1,param_2,param_3 | 2)
  ;
  if ((*piRam02009478 == 1) && ((code *)*puRam0200947c != (code *)0x0)) {
    (*(code *)*puRam0200947c)(*(undefined4 *)(*(int *)(iRam02009454 + 4) + iRam02009464));
  }
  return;
}

