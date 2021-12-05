from termcolor import colored
from device import Device
from event import Event

class Switch(Device):
    """Class to create a new smart home switch device"""

    def __init__(self):
        super().__init__()

    def execute(self, event):
        if event.signal == "hot":
            self.is_running = False
        elif event.signal == "cold":
            self.is_running = True
        light_status = "on" if self.is_running else "off"
        print(colored(f"{event.current_time}, Device: Switch, ID: {self.id}, Turned {light_status} the light", color="yellow"))