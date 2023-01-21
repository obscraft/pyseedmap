from distutils.core import setup, Extension

module1 = Extension('isvillage',
                    sources = ['./Pycubiomes/wrap.c'],
                    #extra_objects = ['hello.o'],
                    )

setup(name = 'isvillage', version = '1.0.0', ext_modules = [module1])
