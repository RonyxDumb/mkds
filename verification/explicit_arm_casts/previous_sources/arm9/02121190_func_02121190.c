/* Decompiled C draft; module arm9; ROM address 02121190. No matching claim. */
#include "types.h"
#include "deps/02121190_func_02121190.h"

void func_02121190(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  func_0x0219bbfc();
  Mem_CpuFill8((*(uint *)(uRam0212135c & 0xfffffffc) >> (uRam0212135c & 3) * 8 |
               *(uint *)(uRam0212135c & 0xfffffffc) << (uRam0212135c & 3) * -8 + 0x20) +
               iRam02121360,0,0x18);
  Mem_CpuFill8((*(uint *)(uRam0212135c & 0xfffffffc) >> (uRam0212135c & 3) * 8 |
               *(uint *)(uRam0212135c & 0xfffffffc) << (uRam0212135c & 3) * -8 + 0x20) +
               iRam02121364,0,0x18);
  Mem_CpuFill8((*(uint *)(uRam0212135c & 0xfffffffc) >> (uRam0212135c & 3) * 8 |
               *(uint *)(uRam0212135c & 0xfffffffc) << (uRam0212135c & 3) * -8 + 0x20) +
               iRam02121368,0,0x18);
  Mem_CpuFill8((*(uint *)(uRam0212135c & 0xfffffffc) >> (uRam0212135c & 3) * 8 |
               *(uint *)(uRam0212135c & 0xfffffffc) << (uRam0212135c & 3) * -8 + 0x20) +
               iRam0212136c,0,0x18);
  iVar1 = iRam02121370;
  uVar2 = uRam0212135c;
  *(undefined1 *)
   ((*(uint *)(uRam0212135c & 0xfffffffc) >> (uRam0212135c & 3) * 8 |
    *(uint *)(uRam0212135c & 0xfffffffc) << (uRam0212135c & 3) * -8 + 0x20) + 0x194e) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x194c) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x194d) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1f52) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1f53) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1f54) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1f55) = 0;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1f56) = 0;
  Mem_CpuFill8((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
               *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + iVar1,0,0x60);
  uVar2 = uRam0212135c;
  *(undefined4 *)
   ((*(uint *)(uRam0212135c & 0xfffffffc) >> (uRam0212135c & 3) * 8 |
    *(uint *)(uRam0212135c & 0xfffffffc) << (uRam0212135c & 3) * -8 + 0x20) + 0x1904) = param_1;
  *(undefined1 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x194c) = 4;
  if (param_2 == 0) {
    *(undefined1 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18e0) = 1;
    *(undefined1 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18e1) = 2;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18e4) = 1;
  }
  else {
    *(undefined1 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18e0) = 1;
    *(undefined1 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18e1) = 2;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x18e4) = uRam02121374;
  }
  func_0x021a299c(0,(*(uint *)(uRam0212135c & 0xfffffffc) >> (uRam0212135c & 3) * 8 |
                    *(uint *)(uRam0212135c & 0xfffffffc) << (uRam0212135c & 3) * -8 + 0x20) +
                    iRam02121378,0);
  uVar2 = *(uint *)(uRam0212135c & 0xfffffffc) >> (uRam0212135c & 3) * 8 |
          *(uint *)(uRam0212135c & 0xfffffffc) << (uRam0212135c & 3) * -8 + 0x20;
  *(undefined2 *)(uVar2 + 0x18) = 3;
  *(undefined2 *)(uVar2 + 0x1a) = 1;
  return;
}

