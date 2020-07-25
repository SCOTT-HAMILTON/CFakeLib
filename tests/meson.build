lib_inc = include_directories('.')

exe1 = executable('test1', 'main.c',
  dependencies : [ libcfake_dep ],
  install : true)

test('Fetch Sink List test', exe1)
