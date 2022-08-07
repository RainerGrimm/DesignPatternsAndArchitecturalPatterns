from abc import ABCMeta, abstractmethod

# Product
class Window(metaclass=ABCMeta):
    @abstractmethod
    def clone(self): return
	
# Concrete Products
class DefaultWindow(Window):
    def clone(self): return DefaultWindow()
	
class FancyWindow(Window):
    def clone(self): return FancyWindow()
	
# Concrete Creator or Client
def getNewWindow(window):
    return window.clone()

defaultWindow = DefaultWindow()
fancyWindow = FancyWindow()
	
	