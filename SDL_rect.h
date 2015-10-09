typedef struct SDL_Point {
    int x;
    int y;
} SDL_Point;

typedef struct SDL_Rect {
    int x, y;
    int w, h;
} SDL_Rect;

SDL_bool SDL_RectEmpty(const SDL_Rect* r);
SDL_bool SDL_RectEquals(const SDL_Rect* a,
                        const SDL_Rect* b);
SDL_bool SDL_HasIntersection(const SDL_Rect * A,
                             const SDL_Rect * B);
SDL_bool SDL_IntersectRect(const SDL_Rect * A,
                           const SDL_Rect * B,
                           SDL_Rect * result);
void SDL_UnionRect(const SDL_Rect * A,
                   const SDL_Rect * B,
                   SDL_Rect * result);
SDL_bool SDL_EnclosePoints(const SDL_Point * points,
                           int count,
                           const SDL_Rect * clip,
                           SDL_Rect * result);
SDL_bool SDL_IntersectRectAndLine(const SDL_Rect *rect,
                                  int *X1, int *Y1,
                                  int *X2, int *Y2);
