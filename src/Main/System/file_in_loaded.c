#include "Main/System/file_in_loaded.h"
#include "Main/System/result_archive_path.h"

void *FindFileInLoadedArchivesWrapper(const char *name) {
    return FindFileInLoadedArchives(name);
}

void *FindSceneFileWrapper(const char *name) {
    return FindSceneFile(name);
}

void *FindCourseFileWrapper(const char *path) {
    return FindCourseFile(path);
}
