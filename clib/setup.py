from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

extensions = [
	Extension("text", ["text.pyx", "./text/text.c"],
		include_dirs=["./text/"]),
	Extension("queue", ["queue.pyx"],
		include_dirs=["./c-algorithms/src/"],
		library_dirs=["./c-algorithms/src/"],
		libraries=["calg"])
]

#ext_modules=cythonize([Extension("text", ["text.pyx"])])
setup(
	name = 'Cython C Test',
	version = '0.1',
	author = 'Ryan P. Daly',
	author_email = 'mathemaphysics@gmail.com',
	long_description = '''
	I'm just trying this out for the first time.
	''',
    ext_modules = cythonize(extensions)
)

# vim: ts=4:sts=4:sw=4:noet:sta
