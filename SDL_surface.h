typedef struct SDL_Surface {
    Uint32 flags;            
    SDL_PixelFormat *format;  
    int w, h;                  
    int pitch;                  
    void *pixels;               
    void *userdata;           
    int locked;              
    void *lock_data;         
    SDL_Rect clip_rect;       
    struct SDL_BlitMap *map;   
    int refcount;               
} SDL_Surface;

typedef int (*SDL_blit) (struct SDL_Surface *src, SDL_Rect *srcrect,
                         struct SDL_Surface *dst, SDL_Rect *dstrect);

SDL_Surface *SDL_CreateRGBSurface
    (Uint32 flags, int width, int height, int depth,
     Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels,
                                      int width,
                                      int height,
                                      int depth,
                                      int pitch,
                                      Uint32 Rmask,
                                      Uint32 Gmask,
                                      Uint32 Bmask,
                                      Uint32 Amask);
void SDL_FreeSurface(SDL_Surface *surface);
int SDL_SetSurfacePalette(SDL_Surface *surface, SDL_Palette * palette);
int SDL_LockSurface(SDL_Surface *surface);
void SDL_UnlockSurface(SDL_Surface *surface);
SDL_Surface *SDL_LoadBMP_RW(SDL_RWops *src, int freesrc);
int SDL_SaveBMP_RW(SDL_Surface *surface, SDL_RWops *dst, int freedst);
int SDL_SetSurfaceRLE(SDL_Surface *surface, int flag);
int SDL_SetColorKey(SDL_Surface *surface, int flag, Uint32 key);
int SDL_GetColorKey(SDL_Surface *surface, Uint32 *key);
int SDL_SetSurfaceColorMod(SDL_Surface *surface, Uint8 r, Uint8 g, Uint8 b);
int SDL_GetSurfaceColorMod(SDL_Surface *surface, Uint8 *r, Uint8 *g, Uint8 *b);
int SDL_SetSurfaceAlphaMod(SDL_Surface *surface, Uint8 alpha);
int SDL_GetSurfaceAlphaMod(SDL_Surface *surface, Uint8 *alpha);
int SDL_SetSurfaceBlendMode(SDL_Surface *surface, SDL_BlendMode blendMode);
int SDL_GetSurfaceBlendMode(SDL_Surface *surface, SDL_BlendMode *blendMode);
SDL_bool SDL_SetClipRect(SDL_Surface *surface, const SDL_Rect *rect);
void SDL_GetClipRect(SDL_Surface *surface, SDL_Rect *rect);
SDL_Surface *SDL_ConvertSurface
    (SDL_Surface *src, const SDL_PixelFormat *fmt, Uint32 flags);
SDL_Surface *SDL_ConvertSurfaceFormat
    (SDL_Surface *src, Uint32 pixel_format, Uint32 flags);
int SDL_ConvertPixels(int width, int height,
                      Uint32 src_format,
                      const void *src, int src_pitch,
                      Uint32 dst_format,
                      void *dst, int dst_pitch);
int SDL_FillRect(SDL_Surface *dst, const SDL_Rect *rect, Uint32 color);
int SDL_FillRects(SDL_Surface *dst, const SDL_Rect *rects,
                  int count, Uint32 color);
int SDL_UpperBlit (SDL_Surface *src, const SDL_Rect *srcrect,
                   SDL_Surface *dst, SDL_Rect *dstrect);
int SDL_LowerBlit (SDL_Surface *src, SDL_Rect *srcrect,
                   SDL_Surface *dst, SDL_Rect *dstrect);
int SDL_SoftStretch(SDL_Surface *src,
                    const SDL_Rect *srcrect,
                    SDL_Surface *dst,
                    const SDL_Rect *dstrect);
int SDL_UpperBlitScaled(SDL_Surface *src, const SDL_Rect *srcrect,
                        SDL_Surface *dst, SDL_Rect *dstrect);
int SDL_LowerBlitScaled(SDL_Surface *src, SDL_Rect *srcrect,
                        SDL_Surface *dst, SDL_Rect *dstrect);
