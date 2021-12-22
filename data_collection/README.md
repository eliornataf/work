<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://blog.gembaacademy.com/wp-content/uploads/2016/11/statistics.jpg" alt="Logo" width="600" height="300">
  </a>

<h3 align="center">Data Collection</h3>

  <p align="center">
    In this project, web scraping software was used to extract data from websites. The software provides an automated process for those seeking access to structured web data. The automated process collects structured web data using a multithreading library to provide a fast solution for large-scale web scraping without being blocked or blacklisted. Finally, the webpage is converted to a CSV file. 
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

There are three main components to the project:

1. Data Collection - is the “brain” of the project.
2. Scraping Manager - manages different scrapers.
3. Serializer - transforms a solution into a CSV file.

In order to obtain all URLs, the software gathers all zip codes from the free website zip code database. It creates a thread for each zip code, which receives the HTML from the URL, locates the data within the HTML and parses it. After the data is parsed, the software produces a CSV file.


### Built With

* [python3](https://www.python.org/)
* [pandas](https://pypi.org/project/pandas/)
* [scraperapi-sdk](https://pypi.org/project/scraperapi-sdk/)
* [BeautifulSoup](https://pypi.org/project/beautifulsoup4/)
* [threading](https://docs.python.org/3/library/threading.html)
* [concurrent.futures](https://docs.python.org/3/library/concurrent.futures.html)

<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

* pandas:
  ```sh
  pip install pandas
  ```

* scraperapi-sdk:
  ```sh
  pip install scraperapi-sdk
  ```

* BeautifulSoup:
  ```sh
  pip install beautifulsoup4
  ```

### Installation
   
1. Get a free zip code Database at [https://www.unitedstateszipcodes.org](https://www.unitedstateszipcodes.org/zip_code_database.csv?download_auth=d95a522e5c4252790ce36b1148fbed94)
2. Get a free API Key at [https://www.scraperapi.com](https://www.scraperapi.com/)
3. Clone the repo
4. Install pandas, scraperapi-sdk, BeautifulSoup packages
5. Enter those values in 'config.py':
    ```
    CSV_FILE_PATH = "THE PATH TO YOUR ZIP CODE DATABASE CSV"
    SCRAPERAPI_API_KEY = ""YOUR API KEY"
    ```
6. Run main.py
  
<!-- CONTACT -->
## Contact

Elior Nataf - [@linkedin](https://www.linkedin.com/in/elior) - eliorn23@gmail.com
