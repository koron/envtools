scriptencoding utf-8

let s:nr_modes = { 'Reload': 1 }

function! Envtools(mode, arg)
  let path = s:get_path()
  if s:is_nr(a:mode)
    return libcallnr(path, a:mode, a:arg)
  else
    return libcall(path, a:mode, a:arg)
  endif
endfunction

function! s:is_nr(mode)
  return has_key(s:nr_modes, a:mode)
endfunction

function s:get_path()
  return expand('<sfile>:p:h') . '/envtools.dll'
endfunction
