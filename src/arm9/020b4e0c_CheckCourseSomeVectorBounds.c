/* Decompiled C draft; module arm9; ROM address 020b4e0c. No matching claim. */
#include "types.h"
#include "deps/020b4e0c_CheckCourseSomeVectorBounds.h"

undefined4 CheckCourseSomeVectorBounds(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_18 [16];
  
  uVar3 = 1;
  iVar2 = GetCurrentInternalCourseId_0();
  if ((iVar2 == 0x11) || (iVar2 == 0x13)) {
    uVar1 = GetCurrentPlayerRacerId();
    GetDriverVec354((undefined4 *)(void *)(auStack_18),uVar1);
    uVar3 = CheckVectorBounds_Clock_Airship((uint)(uintptr_t)(auStack_18));
  }
  return uVar3;
}

