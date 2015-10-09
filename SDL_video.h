typedef struct {
    Uint32 format;
    int w;       
    int h;      
    int refresh_rate;
    void *driverdata;
} SDL_DisplayMode;

typedef struct SDL_Window SDL_Window;

typedef enum {
    SDL_WINDOW_FULLSCREEN = 0x00000001,
    SDL_WINDOW_OPENGL = 0x00000002,
    SDL_WINDOW_SHOWN = 0x00000004,
    SDL_WINDOW_HIDDEN = 0x00000008,
    SDL_WINDOW_BORDERLESS = 0x00000010,
    SDL_WINDOW_RESIZABLE = 0x00000020,
    SDL_WINDOW_MINIMIZED = 0x00000040,
    SDL_WINDOW_MAXIMIZED = 0x00000080,
    SDL_WINDOW_INPUT_GRABBED = 0x00000100,
    SDL_WINDOW_INPUT_FOCUS = 0x00000200,
    SDL_WINDOW_MOUSE_FOCUS = 0x00000400,
    SDL_WINDOW_FULLSCREEN_DESKTOP = ( SDL_WINDOW_FULLSCREEN | 0x00001000 ),
    SDL_WINDOW_FOREIGN = 0x00000800,
    SDL_WINDOW_ALLOW_HIGHDPI = 0x00002000
} SDL_WindowFlags;

enum {
    SDL_WINDOWPOS_UNDEFINED_MASK = 0x1FFF0000,
    SDL_WINDOWPOS_CENTERED = 0xFFFF0000
};

typedef enum {
    SDL_WINDOWEVENT_NONE,
    SDL_WINDOWEVENT_SHOWN,
    SDL_WINDOWEVENT_HIDDEN,
    SDL_WINDOWEVENT_EXPOSED,
    SDL_WINDOWEVENT_MOVED,
    SDL_WINDOWEVENT_RESIZED,
    SDL_WINDOWEVENT_SIZE_CHANGED,
    SDL_WINDOWEVENT_MINIMIZED,
    SDL_WINDOWEVENT_MAXIMIZED,
    SDL_WINDOWEVENT_RESTORED,
    SDL_WINDOWEVENT_ENTER,
    SDL_WINDOWEVENT_LEAVE,
    SDL_WINDOWEVENT_FOCUS_GAINED,
    SDL_WINDOWEVENT_FOCUS_LOST,
    SDL_WINDOWEVENT_CLOSE
} SDL_WindowEventID;

typedef void *SDL_GLContext;

typedef enum {
    SDL_GL_RED_SIZE,
    SDL_GL_GREEN_SIZE,
    SDL_GL_BLUE_SIZE,
    SDL_GL_ALPHA_SIZE,
    SDL_GL_BUFFER_SIZE,
    SDL_GL_DOUBLEBUFFER,
    SDL_GL_DEPTH_SIZE,
    SDL_GL_STENCIL_SIZE,
    SDL_GL_ACCUM_RED_SIZE,
    SDL_GL_ACCUM_GREEN_SIZE,
    SDL_GL_ACCUM_BLUE_SIZE,
    SDL_GL_ACCUM_ALPHA_SIZE,
    SDL_GL_STEREO,
    SDL_GL_MULTISAMPLEBUFFERS,
    SDL_GL_MULTISAMPLESAMPLES,
    SDL_GL_ACCELERATED_VISUAL,
    SDL_GL_RETAINED_BACKING,
    SDL_GL_CONTEXT_MAJOR_VERSION,
    SDL_GL_CONTEXT_MINOR_VERSION,
    SDL_GL_CONTEXT_EGL,
    SDL_GL_CONTEXT_FLAGS,
    SDL_GL_CONTEXT_PROFILE_MASK,
    SDL_GL_SHARE_WITH_CURRENT_CONTEXT,
    SDL_GL_FRAMEBUFFER_SRGB_CAPABLE
} SDL_GLattr;

typedef enum {
    SDL_GL_CONTEXT_PROFILE_CORE           = 0x0001,
    SDL_GL_CONTEXT_PROFILE_COMPATIBILITY  = 0x0002,
    SDL_GL_CONTEXT_PROFILE_ES             = 0x0004
} SDL_GLprofile;

typedef enum {
    SDL_GL_CONTEXT_DEBUG_FLAG              = 0x0001,
    SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG = 0x0002,
    SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG      = 0x0004,
    SDL_GL_CONTEXT_RESET_ISOLATION_FLAG    = 0x0008
} SDL_GLcontextFlag;

int SDL_GetNumVideoDrivers(void);
const char *SDL_GetVideoDriver(int index);
int SDL_VideoInit(const char *driver_name);
void SDL_VideoQuit(void);
const char *SDL_GetCurrentVideoDriver(void);
int SDL_GetNumVideoDisplays(void);
const char *SDL_GetDisplayName(int displayIndex);
int SDL_GetDisplayBounds(int displayIndex, SDL_Rect *rect);
int SDL_GetNumDisplayModes(int displayIndex);
int SDL_GetDisplayMode(int displayIndex, int modeIndex, SDL_DisplayMode *mode);
int SDL_GetDesktopDisplayMode(int displayIndex, SDL_DisplayMode *mode);
int SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode * mode);
SDL_DisplayMode *SDL_GetClosestDisplayMode(int displayIndex, const SDL_DisplayMode *mode, SDL_DisplayMode *closest);
int SDL_GetWindowDisplayIndex(SDL_Window *window);
int SDL_SetWindowDisplayMode(SDL_Window *window, const SDL_DisplayMode *mode);
int SDL_GetWindowDisplayMode(SDL_Window *window, SDL_DisplayMode *mode);
Uint32 SDL_GetWindowPixelFormat(SDL_Window *window);
SDL_Window *SDL_CreateWindow(const char *title,
                             int x, int y, int w,
                             int h, Uint32 flags);
SDL_Window *SDL_CreateWindowFrom(const void *data);
Uint32 SDL_GetWindowID(SDL_Window *window);
SDL_Window *SDL_GetWindowFromID(Uint32 id);
Uint32 SDL_GetWindowFlags(SDL_Window *window);
void SDL_SetWindowTitle(SDL_Window *window, const char *title);
const char *SDL_GetWindowTitle(SDL_Window *window);
void SDL_SetWindowIcon(SDL_Window *window, SDL_Surface *icon);
void *SDL_SetWindowData(SDL_Window *window, const char *name, void *userdata);
void *SDL_GetWindowData(SDL_Window *window, const char *name);
void SDL_SetWindowPosition(SDL_Window *window, int x, int y);
void SDL_GetWindowPosition(SDL_Window *window, int *x, int *y);
void SDL_SetWindowSize(SDL_Window *window, int w, int h);
void SDL_GetWindowSize(SDL_Window *window, int *w, int *h);
void SDL_SetWindowMinimumSize(SDL_Window *window, int min_w, int min_h);
void SDL_GetWindowMinimumSize(SDL_Window *window, int *w, int *h);
void SDL_SetWindowMaximumSize(SDL_Window *window, int max_w, int max_h);
void SDL_GetWindowMaximumSize(SDL_Window *window, int *w, int *h);
void SDL_SetWindowBordered(SDL_Window *window, SDL_bool bordered); 
void SDL_ShowWindow(SDL_Window *window);
void SDL_HideWindow(SDL_Window *window);
void SDL_RaiseWindow(SDL_Window *window);
void SDL_MaximizeWindow(SDL_Window *window);
void SDL_MinimizeWindow(SDL_Window *window);
void SDL_RestoreWindow(SDL_Window *window);
int SDL_SetWindowFullscreen(SDL_Window *window, Uint32 flags);
SDL_Surface *SDL_GetWindowSurface(SDL_Window *window);
int SDL_UpdateWindowSurface(SDL_Window *window);
int SDL_UpdateWindowSurfaceRects(SDL_Window *window,
                                 const SDL_Rect *rects,
                                 int numrects);
void SDL_SetWindowGrab(SDL_Window *window, SDL_bool grabbed);
SDL_bool SDL_GetWindowGrab(SDL_Window *window);
int SDL_SetWindowBrightness(SDL_Window *window, float brightness);
float SDL_GetWindowBrightness(SDL_Window *window);
int SDL_SetWindowGammaRamp(SDL_Window *window,
                           const Uint16 *red,
                           const Uint16 *green,
                           const Uint16 *blue);
int SDL_GetWindowGammaRamp(SDL_Window *window,
                           Uint16 *red,
                           Uint16 *green,
                           Uint16 *blue);
void SDL_DestroyWindow(SDL_Window *window);
SDL_bool SDL_IsScreenSaverEnabled(void);
void SDL_EnableScreenSaver(void);
void SDL_DisableScreenSaver(void);
int SDL_GL_LoadLibrary(const char *path);
void *SDL_GL_GetProcAddress(const char *proc);
void SDL_GL_UnloadLibrary(void);
SDL_bool SDL_GL_ExtensionSupported(const char *extension);
void SDL_GL_ResetAttributes(void);
int SDL_GL_SetAttribute(SDL_GLattr attr, int value);
int SDL_GL_GetAttribute(SDL_GLattr attr, int *value);
SDL_GLContext SDL_GL_CreateContext(SDL_Window *window);
int SDL_GL_MakeCurrent(SDL_Window *window, SDL_GLContext context);
SDL_Window *SDL_GL_GetCurrentWindow(void);
SDL_GLContext SDL_GL_GetCurrentContext(void);
void SDL_GL_GetDrawableSize(SDL_Window *window, int *w, int *h);
int SDL_GL_SetSwapInterval(int interval);
int SDL_GL_GetSwapInterval(void);
void SDL_GL_SwapWindow(SDL_Window *window);
void SDL_GL_DeleteContext(SDL_GLContext context);
