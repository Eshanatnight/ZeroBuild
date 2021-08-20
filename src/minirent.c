//
// Created by eshan on 20-08-2021.
//
#include "minirent.h"

#ifdef _Win32

struct DIR
{
    HANDLE hFind;
    WIN32_FIND_DATA data;
    struct dirent *dirent;
};

DIR *opendir(const char *dirpath)
{
    assert(dirpath);

    char buffer[MAX_PATH];
    snprintf(buffer, MAX_PATH, "%s\\*", dirpath);

    DIR *dir = (DIR*)calloc(1, sizeof(DIR));

    dir->hFind = FindFirstFile(buffer, &dir->data);
    if (dir->hFind == INVALID_HANDLE_VALUE)
    {
        errno = ENOSYS;
        goto fail;
    }

    return dir;

    fail:
    if (dir)
    {
        free(dir);
    }

    return NULL;
}

struct dirent *readdir(DIR *dirp)
{
    assert(dirp);

    if (dirp->dirent == NULL)
    {
        dirp->dirent = (struct dirent*)calloc(1, sizeof(struct dirent));
    }
    else
    {
        if(!FindNextFile(dirp->hFind, &dirp->data))
        {
            if (GetLastError() != ERROR_NO_MORE_FILES)
            {
                errno = ENOSYS;
            }

            return NULL;
        }
    }

    memset(dirp->dirent->d_name, 0, sizeof(dirp->dirent->d_name));

    strncpy(dirp->dirent->d_name, dirp->data.cFileName, sizeof(dirp->dirent->d_name) - 1);

    return dirp->dirent;
}

int closedir(DIR *dirp)
{
    assert(dirp);

    if(!FindClose(dirp->hFind))
    {
        errno = ENOSYS;
        return -1;
    }

    if (dirp->dirent)
    {
        free(dirp->dirent);
    }
    free(dirp);

    return 0;
}
        // minirent.h IMPLEMENTATION END ////////////////////////////////////////
#endif