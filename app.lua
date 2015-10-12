local ffi = require 'ffi'
local sdl = require 'sdl'

local window = sdl.CreateWindow("Luxons",
                                sdl.SDL_WINDOWPOS_CENTERED,
                                sdl.SDL_WINDOWPOS_CENTERED, 
                                1600, 900, sdl.SDL_WINDOW_BORDERLESS)
local renderer = sdl.CreateRenderer(window, -1, sdl.SDL_RENDERER_ACCELERATED)
sdl.SetRenderDrawColor(renderer, 127, 127, 127, 255)
local run = true
local evt = ffi.new('SDL_Event')

function input()
  if sdl.PollEvent(evt) then 
     if evt.type == sdl.SDL_QUIT then
       run = false
     end
  end
end

function update()
end

function draw()
  sdl.RenderClear(renderer)
  --sdl.RenderCopy(renderer)
  sdl.RenderPresent(renderer)
end

function quit()
  sdl.DestroyRenderer(renderer)
  sdl.DestroyWindow(window)
  sdl.Quit()
end

while run do
  ticks = sdl.GetTicks()
  input()
  update()
  draw()
  dt = sdl.GetTicks() - ticks
  if dt < 16 then
    sdl.Delay(16 - dt)
  end
end

quit()
