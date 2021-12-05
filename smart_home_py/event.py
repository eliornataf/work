from datetime import datetime, time

class Event:
    """Class to make an event from openweathermap.org API response"""

    def __init__(self, temperature):
        self._temperature = temperature
        self._signal = self._analyze_temperature()
        self._current_time = self._import_current_time()

    @property
    def temperature(self):
        return self._temperature

    @property
    def signal(self):
        return self._signal

    @property
    def current_time(self):
        return self._current_time

    def _analyze_temperature(self):        
        if self.temperature < 15:
            return "cold"
        elif 30 < self.temperature:
            return  "hot"
        return "normal"

    def _import_current_time(self):
        now = datetime.now()
        return time(now.hour, now.minute) 
    
