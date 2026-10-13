#pragma once
/* Function-specific inferred declarations. */
void WriteSaveDataSection_MissionRun_from_thumb(undefined4 param_1);
void WriteSaveDataMissionRunSection_from_thumb(void);
#define pcRam020563e8 (*(__typeof__(WriteSaveDataSection_MissionRun_from_thumb) **)(uintptr_t)0x20563e8u)
#define piRam020563e4 (*(int **)(uintptr_t)0x20563e4u)
