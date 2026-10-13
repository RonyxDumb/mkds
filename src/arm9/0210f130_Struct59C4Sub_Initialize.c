/* Decompiled C draft; module arm9; ROM address 0210f130. No matching claim. */
#include "types.h"
#include "deps/0210f130_Struct59C4Sub_Initialize.h"

void Struct59C4Sub_Initialize(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(uint *)((uint)puRam0210f1cc & 0xfffffffc) >> ((uint)puRam0210f1cc & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0210f1cc & 0xfffffffc) << ((uint)puRam0210f1cc & 3) * -8 + 0x20 == 0) {
    RegisterFifoMicrophone();
    PM_Initialize();
    func_0214fb3c(1);
    *puRam0210f1cc = 1;
  }
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0x41c) = 0;
  do {
    *(undefined1 *)(param_1 + iVar2) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x400);
  *(undefined4 *)(param_1 + 0x400) = 2;
  *(int *)(param_1 + 0x404) = param_1;
  uVar1 = uRam0210f1d0;
  *(undefined4 *)(param_1 + 0x408) = 0x400;
  *(undefined4 *)(param_1 + 0x40c) = uVar1;
  *(undefined4 *)(param_1 + 0x410) = 1;
  *(undefined4 *)(param_1 + 0x414) = 0;
  *(undefined4 *)(param_1 + 0x418) = 0;
  func_02020430();
  func_020203d4(0);
  func_0214fb24(3);
  return;
}

