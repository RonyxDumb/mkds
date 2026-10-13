/* Decompiled C draft; module arm9; ROM address 02009ce4. No matching claim. */
#include "types.h"
#include "deps/02009ce4_func_02009ce4.h"

undefined4 func_02009ce4(undefined2 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  uVar3 = Os_DisableIrq();
  *(undefined2 *)(*piRam02009e0c + 0x32) = param_1;
  iVar4 = *piRam02009e10;
  *puRam02009e18 = iVar4 + iRam02009e14 & 0xffffffe0;
  uVar7 = *(undefined4 *)(iVar4 + iRam02009e1c);
  Mem_CpuFill16(0,iVar4 + iRam02009e20,uRam02009e24);
  func_02007ea0(uVar7);
  piVar1 = piRam02009e0c;
  *(uint *)(*piRam02009e10 + iRam02009e2c) = *(ushort *)(*piRam02009e0c + iRam02009e28) - 6;
  func_0200c448(*(undefined2 *)(*piVar1 + iRam02009e30));
  func_0200c430(*piRam02009e10 + iRam02009e34);
  iVar2 = iRam02009e3c;
  iVar4 = iRam02009e38;
  piVar1 = piRam02009e10;
  iVar6 = 0;
  iVar5 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar5 + iVar4) = 0;
    *(undefined1 *)(*piVar1 + iVar6 + iVar2) = 0xff;
    iVar5 = iVar5 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xf);
  *(undefined1 *)(*piVar1 + iRam02009e40) = 0;
  Mem_CpuFill16(0,*piVar1 + iRam02009e44,uRam02009e48);
  Mem_CpuFill8(*piRam02009e10 + iRam02009e4c,0,0x1e);
  piVar1 = piRam02009e0c;
  *(undefined2 *)(*piRam02009e0c + iRam02009e50) = 1;
  *(undefined4 *)(*piVar1 + iRam02009e58) = uRam02009e54;
  *(undefined4 *)(*piVar1 + iRam02009e60) = uRam02009e5c;
  *(undefined2 *)(*piVar1 + 0x34) = *(undefined2 *)(*piVar1 + iRam02009e28);
  *(ushort *)(*piVar1 + iRam02009e64) = *(short *)(*piVar1 + 0x34) + 0x23U & 0xffe0;
  *(undefined2 *)(*piVar1 + 0x36) = *(undefined2 *)(*piVar1 + iRam02009e30);
  *(short *)(*piVar1 + iRam02009e68) =
       (short)(((*(ushort *)(*piVar1 + 0x36) + 0xe) * 0xf + 0x29 & 0xffffffe0) << 1);
  func_020096d4();
  uVar7 = func_02009e70();
  Os_RestoreIrq(uVar3);
  uVar3 = Fifo_IsHandlerReady(0xf,1);
  *(undefined4 *)(*piRam02009e10 + iRam02009e6c) = uVar3;
  return uVar7;
}

