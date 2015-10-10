local ffi = require 'ffi'
local sdl2 = ffi.load("SDL2")
local ffi_dir = './'

local function readfile(filename)
  local f = assert(io.open(filename, 'r'))
  s = f:read('*all')
  f:close()
  return s
end

local function sdl_h(filename)
  s = readfile(filename)
  ffi.cdef(s)
end

local function sdl_lua(filename)
  local f = io.open(filename, 'r')
  if f ~= nil then
    dofile(filename)
  end
  f:close()
end

sdl_h(ffi_dir .. "ffi_sdl.h")
sdl_h(ffi_dir .. "ffi_sdl_shape.h")
sdl_h(ffi_dir .. "ffi_sdl_flags.h")
--sdl_lua("ffi_sdl_hints.lua")

local sdl = {}
local mt = getmetatable(sdl2)
text = readfile('ffi_sdl_index.txt')
for sdl_name in text:gmatch("%S+") do
  if sdl_name:sub(1, 1) ~= '#' then
    name = sdl_name:gsub("SDL_", "")
    rawset(sdl, name, mt.__index(sdl2, sdl_name))
  end
end

return sdl
