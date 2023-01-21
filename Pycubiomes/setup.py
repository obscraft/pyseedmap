from distutils.core import setup, Extension

module1 = Extension('overwold',
                    sources = ['wrap.c','overworld.c'],
                    #extra_objects = ['hello.o'],
                    )

setup(name = 'overworld', version = '1.0.0', ext_modules = [module1])