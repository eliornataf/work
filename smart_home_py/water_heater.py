from datetime import datetime, time
from keyboard import on_press_key
from termcolor import colored
from threading import Thread, Timer
from time import sleep

from device import Device
from event import Event
from timer_thread import TimerThread

class WaterHeater(Device):
    """Class to create a new smart home water heater device"""

    def __init__(self, hour, minute):
        super().__init__()
        self._time_coming_back_home = time(hour, minute)

    def _heater_finish_message(self):
        print(colored(f"{time(datetime.now().hour, datetime.now().minute)}, Device: Water Heater, ID: {self.id}, Turned off after 25 minutes", color="cyan"))

    def execute(self, event):
        difference_time = (self._time_coming_back_home.hour * 60 + self._time_coming_back_home.minute) - (event.current_time.hour * 60 + event.current_time.minute)
        if (event.signal == "cold") and (0 <= difference_time and difference_time <= 60):
                self.is_running = True
                print(colored(f"{event.current_time}, Device: Water Heater, ID: {self.id}, Turned on for 25 minutes", color="cyan"))
                timer = TimerThread(1500, self._heater_finish_message) # 25 minute
                on_press_key("esc", lambda _: timer.cancel())
                timer.run_once()
        else:
            print(colored(f"{event.current_time}, Device: Water Heater, ID: {self.id}, Is off", color="cyan"))