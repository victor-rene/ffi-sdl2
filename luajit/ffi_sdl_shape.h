/*
#define SDL_NONSHAPEABLE_WINDOW -1
#define SDL_INVALID_SHAPE_ARGUMENT -2
#define SDL_WINDOW_LACKS_SHAPE -3
*/

SDL_Window * SDL_CreateShapedWindow(const char *title,unsigned int x,unsigned int y,unsigned int w,unsigned int h,Uint32 flags);
SDL_bool SDL_IsShapedWindow(const SDL_Window *window);

typedef enum {
    ShapeModeDefault,
    ShapeModeBinarizeAlpha,
    ShapeModeReverseBinarizeAlpha,
    ShapeModeColorKey
} WindowShapeMode;

/*
#define SDL_SHAPEMODEALPHA(mode) (mode == ShapeModeDefault || mode == ShapeModeBinarizeAlpha || mode == ShapeModeReverseBinarizeAlpha)
*/

typedef union {
    Uint8 binarizationCutoff;
    SDL_Color colorKey;
} SDL_WindowShapeParams;

typedef struct SDL_WindowShapeMode {
    WindowShapeMode mode;
    SDL_WindowShapeParams parameters;
} SDL_WindowShapeMode;

int SDL_SetWindowShape(SDL_Window *window,SDL_Surface *shape,SDL_WindowShapeMode *shape_mode);
int SDL_GetShapedWindowMode(SDL_Window *window,SDL_WindowShapeMode *shape_mode);
