from termcolor import colored
from device import Device
from event import Event

class AirConditioner(Device):
    """Class to create a new smart home air conditioner device"""

    def __init__(self):
        super().__init__()
        self._temperature = None

    def execute(self, event):
        if event.signal == "normal":
            self.is_running = False
            self._temperature = None
            print(colored(f"{event.current_time}, Device: Air Conditioner, ID: {self.id}, Is off", color="red"))
        else:
            self.is_running = True
            if event.signal == "hot":
                self._temperature = event._temperature - 10
            else:
                self._temperature = event._temperature + 13
            print(colored(f"{event.current_time}, Device: Air Conditioner, ID: {self.id}, Turned on. Temperature set to {self._temperature}C", color="red"))