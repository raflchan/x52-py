# X52
![build](https://github.com/raflchan/x52-py/workflows/build/badge.svg)

A easy-to-use package to utilize the MFD on the Throttle of the X52 and X52 Pro, with features like displaying text, navigating pages of content and callbacks.

The Package is available on [PyPi](https://pypi.org/project/x52/)

## Usage Example

```python
from sys import exit

# import necessary items from the x52 package
from x52 import X52, X52Page

# Setup callback functions for later use
def callback_func_1():
    print('hello from callback_func_1')

def callback_func_2():
    print('hello from callback_func_2')

def callback_func_3():
    print('hello from callback_func_3')


# instantiate an X52 Object and initialize it
# if the X52 Object gets garbage collected it gets
# deinitialized
x52 = X52()
x52.init()

x52Devices = x52.get_x52devices()

# Exit if there is no X52 connected
if not x52Devices:
    exit(-1)

# Select the first detected device
x52Device = x52Devices[0]

# Create pages using the X52Page Constructor
page1 = X52Page(
    ('This is Item1', callback_func_1),
    ('This is Item2', callback_func_2),
    ('This is Item3', callback_func_3), True)
    
page2 = X52Page(
    ('This is a non', None),
    ('non interactive', None),
    ('Page, with cycling text', None), False)

# Add pages to the MFD
x52Device.page_add(page1)
x52Device.page_add(page2)

# Endless loop, else program exits
while True:
    pass

```
