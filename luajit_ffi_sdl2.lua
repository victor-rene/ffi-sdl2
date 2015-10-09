ffi = require 'ffi'

local sdl_dir = './'

local function readfile(filename)
  local f = assert(io.open(filename, 'r'))
  return f:read('*all')
end

local function sdl_h(filename)
  s = readfile(sdl_dir .. filename)
  ffi.cdef(s)
end

local function sdl_lua(filename)
  local f = io.open(filename, 'r')
  if f ~= nil then
    dofile(sdl_dir .. filename)
  end
end

local names = readfile(sdl_dir .. 'luajit_ffi_sdl2.ini')
for name in string.gmatch(names, '%S+') do
  sdl_h(name .. '.h')
  sdl_lua(name .. '.lua')
end
