enum {
    SDL_PIXELTYPE_UNKNOWN,
    SDL_PIXELTYPE_INDEX1,
    SDL_PIXELTYPE_INDEX4,
    SDL_PIXELTYPE_INDEX8,
    SDL_PIXELTYPE_PACKED8,
    SDL_PIXELTYPE_PACKED16,
    SDL_PIXELTYPE_PACKED32,
    SDL_PIXELTYPE_ARRAYU8,
    SDL_PIXELTYPE_ARRAYU16,
    SDL_PIXELTYPE_ARRAYU32,
    SDL_PIXELTYPE_ARRAYF16,
    SDL_PIXELTYPE_ARRAYF32
};

enum {
    SDL_BITMAPORDER_NONE,
    SDL_BITMAPORDER_4321,
    SDL_BITMAPORDER_1234
};

enum {
    SDL_PACKEDORDER_NONE,
    SDL_PACKEDORDER_XRGB,
    SDL_PACKEDORDER_RGBX,
    SDL_PACKEDORDER_ARGB,
    SDL_PACKEDORDER_RGBA,
    SDL_PACKEDORDER_XBGR,
    SDL_PACKEDORDER_BGRX,
    SDL_PACKEDORDER_ABGR,
    SDL_PACKEDORDER_BGRA
};

enum {
    SDL_ARRAYORDER_NONE,
    SDL_ARRAYORDER_RGB,
    SDL_ARRAYORDER_RGBA,
    SDL_ARRAYORDER_ARGB,
    SDL_ARRAYORDER_BGR,
    SDL_ARRAYORDER_BGRA,
    SDL_ARRAYORDER_ABGR
};

enum {
    SDL_PACKEDLAYOUT_NONE,
    SDL_PACKEDLAYOUT_332,
    SDL_PACKEDLAYOUT_4444,
    SDL_PACKEDLAYOUT_1555,
    SDL_PACKEDLAYOUT_5551,
    SDL_PACKEDLAYOUT_565,
    SDL_PACKEDLAYOUT_8888,
    SDL_PACKEDLAYOUT_2101010,
    SDL_PACKEDLAYOUT_1010102
};

typedef struct SDL_Color {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} SDL_Color;

typedef struct SDL_Palette {
    int ncolors;
    SDL_Color *colors;
    Uint32 version;
    int refcount;
} SDL_Palette;

typedef struct SDL_PixelFormat {
    Uint32 format;
    SDL_Palette *palette;
    Uint8 BitsPerPixel;
    Uint8 BytesPerPixel;
    Uint8 padding[2];
    Uint32 Rmask;
    Uint32 Gmask;
    Uint32 Bmask;
    Uint32 Amask;
    Uint8 Rloss;
    Uint8 Gloss;
    Uint8 Bloss;
    Uint8 Aloss;
    Uint8 Rshift;
    Uint8 Gshift;
    Uint8 Bshift;
    Uint8 Ashift;
    int refcount;
    struct SDL_PixelFormat *next;
} SDL_PixelFormat;

const char *SDL_GetPixelFormatName(Uint32 format);
SDL_bool SDL_PixelFormatEnumToMasks(Uint32 format,
                                    int *bpp,
                                    Uint32 * Rmask,
                                    Uint32 * Gmask,
                                    Uint32 * Bmask,
                                    Uint32 * Amask);
Uint32 SDL_MasksToPixelFormatEnum(int bpp,
                                  Uint32 Rmask,
                                  Uint32 Gmask,
                                  Uint32 Bmask,
                                  Uint32 Amask);
SDL_PixelFormat *SDL_AllocFormat(Uint32 pixel_format);
void SDL_FreeFormat(SDL_PixelFormat *format);
SDL_Palette *SDL_AllocPalette(int ncolors);
int SDL_SetPixelFormatPalette(SDL_PixelFormat * format, SDL_Palette *palette);
int SDL_SetPaletteColors(SDL_Palette * palette,
                         const SDL_Color * colors,
                         int firstcolor, int ncolors);
void SDL_FreePalette(SDL_Palette * palette);
Uint32 SDL_MapRGB(const SDL_PixelFormat * format,
                  Uint8 r, Uint8 g, Uint8 b);
Uint32 SDL_MapRGBA(const SDL_PixelFormat * format,
                   Uint8 r, Uint8 g, Uint8 b,
                   Uint8 a);
void SDL_GetRGB(Uint32 pixel,
                const SDL_PixelFormat * format,
                Uint8 * r, Uint8 * g, Uint8 * b);
void SDL_GetRGBA(Uint32 pixel,
                 const SDL_PixelFormat * format,
                 Uint8 * r, Uint8 * g, Uint8 * b,
                 Uint8 * a);
void SDL_CalculateGammaRamp(float gamma, Uint16 * ramp);
