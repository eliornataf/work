from abc import abstractmethod

class Device():
    """Class to create a new smart home device"""

    _active_devices = 0

    def __init__(self): 
        self._id = Device._active_devices
        Device._active_devices += 1
        self._is_running = False

    @property
    def id(self):
        return self._id

    @property
    def is_running(self):
        return self._is_running

    @is_running.setter
    def is_running(self, value):
        self._is_running = value

    @abstractmethod
    def execute(self, event):
        raise NotImplementedError("derived classes must override execute method")