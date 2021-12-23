from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
from config import DRIVER_PATH

URL = "https://www.google.com/covid19/mobility/"    

def web_browser_instance_and_configuration():
    options = Options()
    options.add_experimental_option("detach", True)
    return webdriver.Chrome(DRIVER_PATH, chrome_options=options)

def scrape_us_states_xpath_download_identifier(source):
    soup = BeautifulSoup(source, "html.parser")
    elements = soup.find(id="sub-219").find_all(class_="glue-button glue-button--low-emphasis glue-button--icon hidden-large")
    return [element["id"][9:] for element in elements]

def main():
    driver = web_browser_instance_and_configuration()
    driver.get(URL)
    us_states_xpath_download_identifier = scrape_us_states_xpath_download_identifier(driver.page_source)
    driver.implicitly_wait(5)
    driver.find_element_by_xpath('//*[@id="reports-result-container"]/div[169]').click()
    for value in us_states_xpath_download_identifier:
        xpath = '//*[@id="download-' + value + '"]'
        driver.find_element_by_xpath(xpath).click()

if __name__ == '__main__':
    main()
