#ifndef DOOMDATE_PLAYDATE_SYS_H
#define DOOMDATE_PLAYDATE_SYS_H

#include "DOOM.h"

void register_playdate_sys_functions(void);

void playdate_printfn(const char* str);
void* playdate_malloc(int size);
void playdate_free(void* ptr);
SDFile* playdate_fopen(const char* filename, const char* mode);
void playdate_fclose(SDFile* handle);
int playdate_read(SDFile* handle, void *buf, int count);
int playdate_write(SDFile* handle, const void *buf, int count);
int playdate_seek(SDFile* handle, int offset, doom_seek_t origin);
int playdate_tell(SDFile* handle);
int playdate_eof(SDFile* handle);
void playdate_get_time(int* sec, int* usec);
void playdate_exit(int code);
char* playdate_getenv(const char* var);

#endif //DOOMDATE_PLAYDATE_SYS_H
