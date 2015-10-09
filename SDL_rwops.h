typedef struct SDL_RWops {
    Sint64 (*size) (struct SDL_RWops *context);
    Sint64 (*seek) (struct SDL_RWops *context, Sint64 offset,
                             int whence);
    size_t (*read) (struct SDL_RWops *context, void *ptr,
                             size_t size, size_t maxnum);
    size_t (*write) (struct SDL_RWops *context, const void *ptr,
                              size_t size, size_t num);
    int (*close) (struct SDL_RWops *context);
    Uint32 type;
    union {
        /*
        struct {
            void *fileNameRef;
            void *inputStreamRef;
            void *readableByteChannelRef;
            void *readMethod;
            void *assetFileDescriptorRef;
            long position;
            long size;
            long offset;
            int fd;
        } androidio;
        */
        struct {
            SDL_bool append;
            void *h;
            struct
            {
                void *data;
                size_t size;
                size_t left;
            } buffer;
        } windowsio;
        /*
        struct {
            SDL_bool autoclose;
            FILE *fp;
        } stdio;
        */
        struct
        {
            Uint8 *base;
            Uint8 *here;
            Uint8 *stop;
        } mem;
        struct
        {
            void *data1;
            void *data2;
        } unknown;
    } hidden;
} SDL_RWops;

SDL_RWops *SDL_RWFromFile(const char *file, const char *mode);
SDL_RWops *SDL_RWFromFP(void *fp, SDL_bool autoclose);
SDL_RWops *SDL_RWFromMem(void *mem, int size);
SDL_RWops *SDL_RWFromConstMem(const void *mem, int size);

SDL_RWops *SDL_AllocRW(void);
void SDL_FreeRW(SDL_RWops *area);

int SDL_RWclose(struct SDL_RWops *context);
size_t SDL_RWread(struct SDL_RWops *context,
                  void             *ptr,
                  size_t            size,
                  size_t            maxnum);
Sint64 SDL_RWseek(SDL_RWops *context,
                  Sint64     offset,
                  int        whence);
Sint64 SDL_RWtell(struct SDL_RWops *context);
size_t SDL_RWwrite(struct SDL_RWops *context,
                   const void       *ptr,
                   size_t            size,
                   size_t            num);
Sint64 SDL_RWsize(SDL_RWops *context);

Uint8 SDL_ReadU8(SDL_RWops *src);
Uint16 SDL_ReadLE16(SDL_RWops *src);
Uint16 SDL_ReadBE16(SDL_RWops *src);
Uint32 SDL_ReadLE32(SDL_RWops *src);
Uint32 SDL_ReadBE32(SDL_RWops *src);
Uint64 SDL_ReadLE64(SDL_RWops *src);
Uint64 SDL_ReadBE64(SDL_RWops *src);

size_t SDL_WriteU8(SDL_RWops *dst, Uint8 value);
size_t SDL_WriteLE16(SDL_RWops *dst, Uint16 value);
size_t SDL_WriteBE16(SDL_RWops *dst, Uint16 value);
size_t SDL_WriteLE32(SDL_RWops *dst, Uint32 value);
size_t SDL_WriteBE32(SDL_RWops *dst, Uint32 value);
size_t SDL_WriteLE64(SDL_RWops *dst, Uint64 value);
size_t SDL_WriteBE64(SDL_RWops *dst, Uint64 value);
