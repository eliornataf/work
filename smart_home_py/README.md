<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://www.sifis-home.eu/wp-content/uploads/2021/01/AdobeStock_304073455-Converted_smarthome.jpg" alt="Logo" width="600" height="300">
  </a>

<h3 align="center">Smart-home simulator</h3>

  <p align="center">
    Smart-home simulator
simulates how a central smart-unit controls a set of smart-devices in order to create a smart-home experience (relies entirely on server-side component).
The system was built with a multithreading library to make the best solution for multi smart-home no blocking devices.
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

The smart home solution includes 3 components:

1. Central unit - is the “brain” of the smart-home.
2. Data provider - is a third party api weather provider (to fetch current weather data).
3. Smart device - can be any of the followings:
    Switch - turn light on or off
    Air-Conditioner - manipulates room temperature
    Water-Heater - boils water for a specific amount of time
    
The smart home fetches weather data every hour from a data provider (openweathermap API), analyzes the income data, and sends a signal to the smart home devices:
- Whenever temperature is higher than 30 degrees - send “hot” signal
- Whenever temperature is lower than 15 degrees - send “cold” signal
- In any other case - send “normal” signal
    
Every smart device can react to signal according to the following logic:

- Switch:
    - “hot” signal - turn off the light
    - “cold” signal - turn on the light    
    
- Air-conditioner:
    - “hot” signal - decrease temperature by 10 degrees
    - “cold” signal - increase temperature by 13 degrees
    - “normal” signal - turn off air-conditioner      
       
- Water-heater:
    - “cold” signal - if there is less than an hour until someone is coming back home (these values will be predefined) - turn on heater for 25 minutes (then turn it off)


### Built With

* [Python3](https://www.python.org/)
* [emoji](https://pypi.org/project/emoji/)
* [requests](https://pypi.org/project/requests/)
* [termcolor](https://pypi.org/project/termcolor/)



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

* emoji:
  ```sh
  pip install emoji
  ```

* requests:
  ```sh
  pip install requests
  ```

* termcolor:
  ```sh
  pip install termcolor
  ```

### Installation
   
1. Get a free API Key at [https://openweathermap.org/api](https://openweathermap.org/api)
2. Clone the repo
3. Install emoji, requests, termcolor packages
4. Enter those values in 'config.py':
    ```
    API_KEY = "ENTER YOUR API KEY"
    CITY = "ENTER CITY TO COLLECT WEATHER (SPACE BETWEEN WORDS)"
    HOUR_OF_COMING_BACK_HOME = "ENTER THE HOUR ([0-23]) YOU ARE COMING BACK HOME"
    MINUTE_OF_COMING_BACK_HOME = "ENTER THE MINUTE ([0-59]) YOU ARE COMING BACK HOME"
    ```
5. Optional: add devices to smart_home.py (deafult is one device from each type)
6. Run smart_home.py (main file) as the root account
7. Optional: you can press the Esc key to exit the program at any time



<!-- USAGE EXAMPLES -->
## Usage

<h3 align="center">UML Diagram</h3>
</div>

<br />
<div align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://i.ibb.co/hYxjc24/UML-diagram.jpg" alt="UML" width="1200" height="1200">
  </a>

<h3 align="center">Output Sample Screenshot</h3>
</div>

<br />
<div align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://i.ibb.co/rGd6RZY/screenshot.png" alt="UML" width="800" height="400">
  </a>
  
  
  
<!-- CONTACT -->
## Contact

Elior Nataf - [@linkedin](https://www.linkedin.com/in/elior) - eliorn23@gmail.com
