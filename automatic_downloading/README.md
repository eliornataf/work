<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://d33wubrfki0l68.cloudfront.net/2d12446f148533a20e1d9271da57012ca4c27766/69e14/blog/selenium-python/header_selenium_python_hu858c713577cea0e612703bbde5071118_85692_825x0_resize_catmullrom_2.png" alt="Logo" width="600" height="300">
  </a>

<h3 align="center">Automatic Downloading</h3>

  <p align="center">
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
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

In this project, PDF files relevant to US states is automatically downloaded from the google mobility platform, in order to evaluate how communities is moving around differently due to COVID-19.
During the development of this project, Selenium and BeautifulSoup libraries were used. Selenium was used to automate web browser interaction, and Beautiful Soup was used to scrape information from the webpage.


### Built With

* [Python3](https://www.python.org/)
* [selenium](https://pypi.org/project/selenium/)
* [BeautifulSoup](https://pypi.org/project/beautifulsoup4/)

<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

* selenium:
  ```sh
  pip install selenium
  ```

* BeautifulSoup:
  ```sh
  pip install beautifulsoup4
  ```
  

### Installation
   
1. Open Google Chrome and click the attached link to see what version you're using [what-version-of-chrome-do-i-have](https://www.whatismybrowser.com/detect/what-version-of-chrome-do-i-have)
2. Download the ChromeDriver that matches your version from [https://chromedriver.chromium.org](https://chromedriver.chromium.org/)
3. Clone the repo
4. Install selenium, BeautifulSoup packages
5. Enter those values in 'config.py':
    ```
    DRIVER_PATH = "YOUR COMPUTER'S CHROME DRIVER PATH"
    ```
6. Run automatic_downloading.py
  
<!-- CONTACT -->
## Contact

Elior Nataf - [@linkedin](https://www.linkedin.com/in/elior) - eliorn23@gmail.com
