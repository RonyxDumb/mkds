/* Decompiled C draft; module arm9; ROM address 0200d028. No matching claim. */
#include "types.h"
#include "deps/0200d028_Os_InitializeLock.h"

void Os_InitializeLock(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  
  puVar2 = puRam0200d104;
  if (*(uint *)((uint)puRam0200d100 & 0xfffffffc) >> ((uint)puRam0200d100 & 3) * 8 != 0 ||
      *(uint *)((uint)puRam0200d100 & 0xfffffffc) << ((uint)puRam0200d100 & 3) * -8 + 0x20 != 0) {
    return;
  }
  *puRam0200d100 = 1;
  *puVar2 = 0;
  Os_Lock_TryLock(0x7e);
  puVar3 = puRam0200d104;
  sVar1 = *(short *)((int)puRam0200d104 + 6);
  puVar2 = puRam0200d10c;
  while (puRam0200d10c = puVar2, sVar1 != 0) {
    Os_Lock_Wait();
    puVar2 = puRam0200d10c;
    sVar1 = *(short *)((int)puVar3 + 6);
  }
  *puRam0200d108 = 0xffffffff;
  *puVar2 = 0xffff0000;
  MIi_CpuClear32(0,uRam0200d110,0x28);
  puVar4 = puRam0200d114;
  puVar2 = puRam0200d104;
  *puRam0200d114 = *puRam0200d114 | 0x800;
  *puVar4 = *puVar4 | 0x80;
  Os_Lock_Unlock(0x7e,puVar2,0);
  Os_Lock_TryLock(0x7f,puRam0200d104,0);
  return;
}

