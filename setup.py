from setuptools import setup, Extension
setup(
    name='PACKAGENAME',
    version='PACKAGEVERSION',  # specified elsewhere
    packages=[''],
    package_dir={'': '.'}, # the . is important else package_data option gets ignored 
   package_data={'': ['_example.so']},

)