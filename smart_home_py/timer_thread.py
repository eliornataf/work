from threading import Timer

class TimerThread:
    """Class that represents an action that should be run only after a certain amount of time has passed"""

    def __init__(self, delay_time, thread_function):
        self._delay_time = delay_time
        self._thread_function = thread_function
        self._timer = None

    def run_once(self):
        self._timer = Timer(self._delay_time, self._thread_function)
        self._timer.start() 

    def run_repeatedly(self):
        self._thread_function()
        self._timer = Timer(self._delay_time, self.run_repeatedly)
        self._timer.start()

    def cancel(self):
        if self._timer is not None:
            self._timer.cancel()
