import os, sys
import setuptools

import pybind11

package_name = 'x52'
module_name = '_x52'

sources = ['main.cpp', 'stdafx.cpp', 'utils.cpp', 'X52.cpp', 'X52Device.cpp', 'X52Page.cpp', 'x52_python_wrapper.cpp']

cpp_args = ['-std=c++11', '-stdlib=libc++', '-mmacosx-version-min=10.7']
libraries = ['DirectOutput']
library_dirs = ['dependencies/DirectOutput/Lib/']
define_macros = [('PYBIND_BUILD', 1)]

package_data = {'': ['DirectOutput.dll']}

sfc_module = setuptools.Extension(
    module_name, sources=sources,
    libraries=libraries,
    library_dirs=library_dirs,
    include_dirs=[pybind11.get_include()],
    language='c++',
    define_macros=define_macros,
    extra_compile_args=cpp_args,
    )

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name=package_name,
    version="0.0.3",
    author="rafl",
    # author_email="placeholder.author@example.com",
    description="A simple to use package to utilize the MFD on the Throttle of the X52 and X52 Pro.",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/raflchan/x52",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: Microsoft :: Windows",
    ],
    python_requires='>=3.6',
    ext_modules=[sfc_module],
    include_package_data=True,
    package_data=package_data
)
