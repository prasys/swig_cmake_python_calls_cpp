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
    packages=[''],
    package_dir={'': '.'}, # the . is important else package_data option gets ignored 
   package_data={'': ['_example.so']},
   classifiers=[
       'Programming Language :: Python :: 3',
       'Operating System :: MacOS :: MacOS X',
       'Operating System :: POSIX :: Linux', # WSL will be treated as Linux so it's not a problem
   ],
   python_requires='>=3.5'
   distclass=BinaryDistribution

)