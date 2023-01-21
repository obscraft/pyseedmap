from distutils.core import setup, Extension

module1 = Extension('mclib',
                    sources = ['./pyseedmap/wrap.c'],
                    #extra_objects = ['hello.o'],
                    )

setup(name = 'mclib', version = '1.0.0', ext_modules = [module1])
