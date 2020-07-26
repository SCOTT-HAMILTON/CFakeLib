project('CFakeLib', 'cpp', 'c', default_options : ['cpp_std=c++17'])

libfake = dependency('fake', required: true)

lib_inc = include_directories('include')
lib_src = [ 'CFakeLib.cpp', 'CFakeLibUtils.cpp' ]

libcfake = shared_library('CFake', lib_src,
  include_directories : lib_inc,
  dependencies : [ libfake ], 
  install : true)

libcfake_dep = declare_dependency(
  link_with: libcfake,
  include_directories: lib_inc)

subdir('tests')

install_headers('include/CFakeLib.h', 'include/CFakeLibUtils.h')

install_data('pkg-config/cfake.pc',
  install_dir: get_option('libdir')+'/pkgconfig')

install_data('pkg-config/cfake.pc',
  install_dir: get_option('datadir')+'/pkgconfig')
