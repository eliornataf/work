About The Project

Smart-home simulator
Simulate how a central smart-unit controls a set of smart-devices in order to create a smart-home experience (relies entirely on server-side component).
The system was built with a multithreading library to make the best solution for multi smart-home no blocking devices.

The smart home solution includes 3 components:

1. Central unit - is the “brain” of the smart-home.
2. Data provider - is a third party api weather provider (to fetch current weather data).
3. Smart device - can be any of the followings:
    Switch - turn light or on off
    Air-Conditioner - manipulate room temperature
    Water-Heater - boil water for a specific amount of time

The smart home fetch weather data every hour from a data provider (openweathermap API), analyze the income data, and send signal to the smart home devices:
    Whenever temperature is higher than 30 degrees - send “hot” signal
    Whenever temperature is lower than 15 degrees - send “cold” signal
    In any other case - send “normal” signal

Every smart device can react to signal according to the following logic:
    Switch
        “hot” signal - turn off the light
        “cold” signal - turn on the light 
    Air-conditioner
        “hot” signal - decrease temperature by 10 degrees
        “cold” signal - increase temperature by 13 degrees
        “normal” signal - turn off air-conditioner
    Water-heater
        “cold” signal - if there is less than an hour until someone is coming back home (these values will be predefined) - turn on heater for 25 minutes (then turn it off)


Built With

* Python3
* emoji
* termcolor
* requests

Getting Started


Prerequisites

emoji:
pip install emoji

termcolor:
pip install termcolor

requests:
pip install requests


Installation

1. Get a free API Key at https://openweathermap.org/api
2. Clone the repo
3. Install emoji, termcolor, requests packages
4. Enter those values in config.py:
    API_KEY = "ENTER YOUR API KEY"
    CITY = "ENTER CITY TO COLLECT WEATHER (SPACE BETWEEN WORDS)"
    HOUR_OF_COMING_BACK_HOME = "ENTER THE HOUR ([0-23]) YOU ARE COMING BACK HOME"
    MINUTE_OF_COMING_BACK_HOME = "ENTER THE MINUTE ([0-59]) YOU ARE COMING BACK HOME"
5. Run smart_home.py (main file) as the root account

Contact

Elior Nataf - https://www.linkedin.com/in/elior - eliorn23@gmail.com

Project Link: https://github.com/your_username/repo_name