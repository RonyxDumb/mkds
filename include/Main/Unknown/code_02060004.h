#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

void ClearCourseTimeRecords(s32 courseId);
BOOL IsCourseGhostRecordMissing(s32 courseId);
BOOL GetBuddyFriendKeyText(u8 recordIndex, void *textOut);
s32 RemoveBuddyRecord(u8 recordIndex);
BOOL SetBuddyRecordFlag(u8 recordIndex, s32 flag);
BOOL GetBuddyRecordName(u8 recordIndex, void *nameOut);
BOOL GetBuddyRecordDate(u8 recordIndex, u8 *dateOut);
s32 GetBuddyRecordMatchKind2SecondCount(u8 recordIndex);
s32 GetBuddyRecordMatchKind2FirstCount(u8 recordIndex);
s32 GetBuddyRecordMatchKind1SecondCount(u8 recordIndex);
s32 GetBuddyRecordMatchKind1FirstCount(u8 recordIndex);
s32 GetBuddyRecordMatchKind0SecondCount(u8 recordIndex);
s32 GetBuddyRecordMatchKind0FirstCount(u8 recordIndex);
s32 IsBuddyRecordFlagged(u8 recordIndex);
BOOL IsBuddyRecordFilled(u8 recordIndex);
s32 GetGrandPrixRecordGrade(s32 cup, s32 engineClass);
s32 IsGrandPrixRecordFilled(s32 cup, s32 engineClass);
s32 GetGrandPrixRecordCupRank(s32 cup, s32 engineClass);
s32 GetGrandPrixRecordCharacterIndex(s32 cup, s32 engineClass);
s32 GetGrandPrixRecordKartIndex(s32 cup, s32 engineClass);
s32 GetGrandPrixRecordTotalPoints(s32 cup, s32 engineClass);
BOOL GetGrandPrixRecordTime(s32 cup, s32 engineClass, void *timeOut);
BOOL IsTimeRecordFilled(s32 courseId, s32 recordIndex);
s32 GetTimeRecordCharacterIndex(s32 courseId, s32 recordIndex);
s32 GetTimeRecordKartIndex(s32 courseId, s32 recordIndex);
BOOL GetTimeRecordTime(s32 courseId, s32 recordIndex, void *timeRecord);
BOOL GetTimeRecordName(s32 courseId, s32 recordIndex, void *timeRecord);
s32 IsCourseCupMessageFlagSet(s32 courseId);
void MergeBuddyRecords(u8 keptIndex, u8 mergedIndex);
void RefreshNotYetBuddyFlags(void);
void CopyWiFiBuddiesToRecordBlock(DWCAccFriendData *buddies);
