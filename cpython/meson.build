project('spam', 'c')
deps = dependency('python3')
lib = library('spam', 'spam.c', dependencies : [deps])
executable('test01', 'test01.c', link_with : lib)

