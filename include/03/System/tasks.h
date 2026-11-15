#pragma once

#include "types.h"

typedef struct PointerStack PointerStack;

struct TaskEntry;

// Priority of the end node of a task list, after every task.
#define TASK_PRIORITY_LIST_END 0xff

typedef void (*TaskCallback)(struct TaskEntry *task, void *arg);

// A scheduled task: its list links, callback and argument, priority and whether the argument is freed with it.
typedef struct TaskEntry {
    /* 00 */ struct TaskEntry *mPrev;
    /* 04 */ struct TaskEntry *mNext;
    /* 08 */ TaskCallback mCallback;
    /* 0c */ void *mArg;
    /* 10 */ u8 mPriority;
    /* 11 */ u8 mFreesArg;
    /* 12 */ u8 mUnk_12[2];
} TaskEntry;

// A list of tasks: the free entry stack, the linked list ends, the capacity and the entry storage.
typedef struct TaskList {
    /* 00 */ PointerStack *mFreeEntries;
    /* 04 */ struct PointerStack *mResource;
    /* 08 */ void *mList;
    /* 0c */ TaskEntry mListStart;
    /* 20 */ TaskEntry mListEnd;
    /* 34 */ s32 mCapacity;
    /* 38 */ TaskEntry *mEntryStorage;
} TaskList;

void RemoveTaskEntry(int listIndex, TaskEntry *entry);
void RemoveTaskEntryWrapper(u32 listIndex, TaskEntry *entry);
void RequestTaskRemoval(u32 listIndex, TaskEntry *entry);
void SetTaskCallback(TaskEntry *taskEntry, TaskCallback function);
TaskEntry *AddTaskEx(u32 listIndex, TaskCallback function, void *arg, u32 priority, u8 freesArg);
TaskEntry *AddTask(u32 listIndex, TaskCallback function, void *arg, u32 priority);
void RunTasksAndRemoveRequested(int listIndex);
void ReleaseTasks(void);
void InitTasks(void);

extern const u8 gTaskListCapacities[2];
extern struct TaskList *gTaskLists;
