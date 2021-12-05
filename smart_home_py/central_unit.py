from keyboard import on_press_key
from emoji import emojize
from termcolor import colored
from threading import Thread, Timer
from time import sleep
from event import Event
from timer_thread import TimerThread

class CentralUnit():
    """Class to create a new central unit that manages all smart home devices"""

    def __init__(self, data_provider):
        self._data_provider = data_provider
        self._devices = []

    def add_device(self, device):
        self._devices.append(device)
        return True

    def remove_device(self, id):
        try:
            i = self._devices.index(id)
        except ValueError: # id not found
            return False
        else:
            self._devices.pop(i)
            return True

    def count_devices(self):
        return len(self._devices)        

    def _analyze_and_excute_api_income_data(self):
        temperature = round(self._data_provider.fetch_data())
        new_event = Event(temperature)
        emoji = ":sun:" if new_event.signal == "hot" else ":cloud_with_rain:" if new_event.signal == "cold" else ":sun_behind_small_cloud:"
        print(colored(f"\n{new_event.current_time}, {self._data_provider.city}, {temperature}C {emojize(emoji)}\n---------------------", color="blue")) 

        threads = []
        for device in self._devices:
            new_thread = Thread(target=device.execute(new_event))
            threads.append(new_thread)
            new_thread.start()

        (thread.join() for thread in threads)

    def run(self):
        print(colored(f"System is running. To quit press esc", color="white"))
        timer = TimerThread(3600, self._analyze_and_excute_api_income_data) # 60 minute
        on_press_key("esc", lambda _: timer.cancel())
        timer.run_repeatedly()