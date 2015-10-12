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
-- TODO sdl_lua("ffi_sdl_hints.lua")

-- create package
local sdl = {}
-- get all exported function names
local sdl_names = readfile('ffi_sdl_index.txt')
-- bind each name stripped of 'SDL_' prefix with sdl2 function
local mt_sdl2 = getmetatable(sdl2)
for sdl_name in sdl_names:gmatch("%S+") do
  if sdl_name:sub(1, 1) ~= '#' then -- skip commented lines
    name = sdl_name:gsub("SDL_", "")
    rawset(sdl, name, mt_sdl2.__index(sdl2, sdl_name))
  end
end
-- search in sdl2 symbols not found in sdl
local mt_sdl = { __index = function (t, k)
  return mt_sdl2.__index(sdl2, k) end
}
setmetatable(sdl, mt_sdl)

return sdl
