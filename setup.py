from setuptools import setup, Extension

class BinaryDistribution(Distribution):
    def has_ext_modules(foo):
        return True

setup(
    name='PACKAGENAME',
    version='PACKAGEVERSION',  # specified elsewhere
    author='',
    author_email='',
    download_url='',
    packages=['output'],
   # package_dir={'': '.'},
   package_data={'': ['_example.so']}, #replace me with your package data
   classifiers=[
       'Programming Language :: Python :: 3',
       'Operating System :: MacOS :: MacOS X',
       'Operating System :: POSIX :: Linux', # WSL will be treated as Linux so it's not a problem
   ],
   python_requires='>=3.6'
   distclass=BinaryDistribution

)