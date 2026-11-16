#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// 8-byte entries of two words: a string and a number.
typedef struct Unk02154228 {
    /* 00 */ const char *field0;
    /* 04 */ u8 field4;
    /* 05 */ u8 field5[0x3];
} Unk02154228;

extern Unk02154228 sCourseDefs[];
extern const char aTex[];
extern const char g_EmptyString[];
extern const char aD_0[];
extern const char g_EmptyString_0[];
extern const char aDataCourseSSS_[];

void arc_getSceneArcPath(char *path, const char *sceneName);
void arc_getLocalizedSceneArcPath(char *path, const char *sceneName);
u32 GetMPLanguageCode(void);
u32 arc_getLocalizationPostfix(void);
void arc_getCourseArcPath(char *path, s32 courseId, s32 useTexture);
void *arc_loadFileToHeap(const char *path, s32 alignment);
u32 arc_loadFile(char *path, NNSiFndHeapHead *heap, void **outData);
u32 arc_readFile(void *path, void *buffer, u32 size);
int arc_readFileToEnd(const char *path, void *buffer, u32 maxSize);
void arc_init(void *heap);
