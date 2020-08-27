from ctypes import cdll
import os
__dllname = 'DirectOutput.dll'
__dirname = os.path.dirname(__file__)
__lib = cdll.LoadLibrary(os.path.join(__dirname, __dllname))
from _x52 import *
