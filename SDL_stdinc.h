// Basic types
typedef enum {
    SDL_FALSE = 0,
    SDL_TRUE = 1
} SDL_bool;
 
typedef int8_t Sint8;
typedef uint8_t Uint8;
typedef int16_t Sint16;
typedef uint16_t Uint16;
typedef int32_t Sint32;
typedef uint32_t Uint32;
typedef int64_t Sint64;
typedef uint64_t Uint64;

// Structures
typedef struct _SDL_iconv_t *SDL_iconv_t;

// Functions
void *SDL_malloc(size_t size);
void *SDL_calloc(size_t nmemb, size_t size);
void *SDL_realloc(void *mem, size_t size);
void SDL_free(void *mem);
char *SDL_getenv(const char *name);
int SDL_setenv(const char *name, const char *value, int overwrite);
void SDL_qsort(void *base,
               size_t nmemb,
               size_t size,
               int(*compare)(const void *, const void *));
int	SDL_abs(int x);
int	SDL_isdigit(int x);
int	SDL_isspace(int x);
int	SDL_toupper(int x);
int	SDL_tolower(int x);
void *SDL_memset(void *dst, int c, size_t len);
void SDL_memset4(void *dst, Uint32 val, size_t dwords);
void *SDL_memcpy(void *dst, const void *src, size_t len);
void *SDL_memcpy4(void *dst, const void *src, size_t dwords);
void *SDL_memmove(void *dst, const void *src, size_t len);
int SDL_memcmp(const void *s1, const void *s2, size_t len);
size_t SDL_wcslen(const wchar_t *wstr);
size_t SDL_wcslcpy(wchar_t *dst, const wchar_t *src, size_t maxlen);
size_t SDL_wcslcat(wchar_t *dst, const wchar_t *src, size_t maxlen);
size_t SDL_strlen(const char *str);
size_t SDL_strlcpy(char *dst, const char *src, size_t maxlen);
size_t SDL_utf8strlcpy(char *dst, const char *src, size_t dst_bytes);
size_t SDL_strlcat(char *dst, const char *src, size_t maxlen);
char *SDL_strdup(const char *str);
char *SDL_strrev(char *str);
char *SDL_strupr(char *str);
char *SDL_strlwr(char *str);
char *SDL_strchr(const char *str, int c);
char *SDL_strrchr(const char *str, int c);
char *SDL_strstr(const char *haystack, const char *needle);
char *SDL_itoa(int value, char *str, int radix);
char *SDL_uitoa(unsigned int value, char *str, int radix);
char *SDL_ltoa(long value, char *str, int radix);
char *SDL_ultoa(unsigned long value, char *str, int radix);
char *SDL_lltoa(Sint64 value, char *str, int radix);
char *SDL_ulltoa(Uint64 value, char *str, int radix);
int SDL_atoi(const char *str);
double SDL_atof(const char *str);
long SDL_strtol(const char *str, char **endp, int base);
unsigned long SDL_strtoul(const char *str, char **endp, int base);
Sint64 SDL_strtoll(const char *str, char **endp, int base);
Uint64 SDL_strtoull(const char *str, char **endp, int base);
double SDL_strtod(const char *str, char **endp);
int SDL_strcmp(const char *str1, const char *str2);
int SDL_strncmp(const char *str1, const char *str2, size_t maxlen);
int SDL_strcasecmp(const char *str1, const char *str2);
int SDL_strncasecmp(const char *str1, const char *str2, size_t len);
int SDL_sscanf(const char *text, const char *fmt, ...);
int SDL_vsscanf(const char *text, const char *fmt, va_list ap);
int SDL_snprintf(char *text, size_t maxlen, const char *fmt, ...);
int SDL_vsnprintf(char *text, size_t maxlen, const char *fmt, va_list ap);
double SDL_acos(double x);
double SDL_asin(double x);
double SDL_atan(double x);
double SDL_atan2(double x, double y);
double SDL_ceil(double x);
double SDL_copysign(double x, double y);
double SDL_cos(double x);
float SDL_cosf(float x);
double SDL_fabs(double x);
double SDL_floor(double x);
double SDL_log(double x);
double SDL_pow(double x, double y);
double SDL_scalbn(double x, int n);
double SDL_sin(double x);
float SDL_sinf(float x);
double SDL_sqrt(double x);
SDL_iconv_t SDL_iconv_open(const char *tocode, const char *fromcode);
int SDL_iconv_close(SDL_iconv_t cd);
size_t SDL_iconv(SDL_iconv_t cd,
                 const char **inbuf,
                 size_t *inbytesleft,
                 char **outbuf,
                 size_t *outbytesleft);
char *SDL_iconv_string(const char *tocode,
                       const char *fromcode,
                       const char *inbuf,
                       size_t inbytesleft);;
